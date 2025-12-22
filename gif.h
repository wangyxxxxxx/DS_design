#ifndef GIF_H
#define GIF_H

#pragma message("[using gif.h fixed giflib-LZW]")

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    FILE* f;
    int width;
    int height;

    // LZW state
    int init_bits;        // minCodeSize+1
    int n_bits;
    int maxbits;
    int maxcode;
    int maxmaxcode;
    int clearcode;
    int eofcode;
    int free_ent;
    int clear_flg;

    int32_t htab[5003];
    int16_t codetab[5003];

    // sub-block buffer
    uint8_t accum[256];
    int a_count;

    // bit buffer
    uint32_t cur_accum;
    int cur_bits;

    // index buffer
    uint8_t* idx;

    int started;
} GifWriter;

static void _gif_putc(FILE* f, uint8_t c){ fputc((int)c, f); }
static void _gif_putw(FILE* f, uint16_t w){ fputc(w & 255, f); fputc((w>>8)&255, f); }
static void _gif_write(FILE* f, const void* p, size_t n){ fwrite(p,1,n,f); }

static void _gif_write_palette_rgb332(FILE* f){
    for(int r=0;r<8;r++){
        for(int g=0;g<8;g++){
            for(int b=0;b<4;b++){
                uint8_t R=(uint8_t)((r*255+3)/7);
                uint8_t G=(uint8_t)((g*255+3)/7);
                uint8_t B=(uint8_t)((b*255+1)/3);
                _gif_putc(f,R); _gif_putc(f,G); _gif_putc(f,B);
            }
        }
    }
}

// ------------ LZW (giflib style) ------------

#define _GIF_BITS 12
#define _GIF_HSIZE 5003
#define _GIF_MAXCODE(n_bits) (((int)1 << (n_bits)) - 1)

static void _gif_cl_hash(GifWriter* w){
    for(int i=0;i<_GIF_HSIZE;i++) w->htab[i] = -1;
}

static void _gif_flush_char(GifWriter* w){
    if(w->a_count>0){
        _gif_putc(w->f, (uint8_t)w->a_count);
        _gif_write(w->f, w->accum, (size_t)w->a_count);
        w->a_count = 0;
    }
}

static void _gif_char_out(GifWriter* w, uint8_t c){
    w->accum[w->a_count++] = c;
    if(w->a_count >= 255) _gif_flush_char(w);
}

static void _gif_output(GifWriter* w, int code){
    w->cur_accum &= ((w->cur_bits == 0) ? 0u : ((1u << w->cur_bits) - 1u));
    if(w->cur_bits > 0) w->cur_accum |= ((uint32_t)code << w->cur_bits);
    else w->cur_accum = (uint32_t)code;

    w->cur_bits += w->n_bits;

    while(w->cur_bits >= 8){
        _gif_char_out(w, (uint8_t)(w->cur_accum & 0xFFu));
        w->cur_accum >>= 8;
        w->cur_bits -= 8;
    }

    // bump code size?
    if(w->free_ent > w->maxcode || w->clear_flg){
        if(w->clear_flg){
            w->n_bits = w->init_bits;
            w->maxcode = _GIF_MAXCODE(w->n_bits);
            w->clear_flg = 0;
        } else {
            w->n_bits++;
            if(w->n_bits == w->maxbits) w->maxcode = w->maxmaxcode;
            else w->maxcode = _GIF_MAXCODE(w->n_bits);
        }
    }

    if(code == w->eofcode){
        // flush remaining bits
        while(w->cur_bits > 0){
            _gif_char_out(w, (uint8_t)(w->cur_accum & 0xFFu));
            w->cur_accum >>= 8;
            w->cur_bits -= 8;
        }
        _gif_flush_char(w);
    }
}

static void _gif_cl_block(GifWriter* w){
    _gif_cl_hash(w);
    w->free_ent = w->clearcode + 2;
    w->clear_flg = 1;
    _gif_output(w, w->clearcode);
}

static void _gif_compress(GifWriter* w, const uint8_t* data, int len){
    int hshift = 0;
    for(int fcode=_GIF_HSIZE; fcode<65536; fcode*=2) ++hshift;
    hshift = 8 - hshift;

    w->clear_flg = 0;
    w->n_bits = w->init_bits;
    w->maxbits = _GIF_BITS;
    w->maxmaxcode = 1 << _GIF_BITS;
    w->maxcode = _GIF_MAXCODE(w->n_bits);

    w->clearcode = 1 << (w->init_bits - 1);
    w->eofcode = w->clearcode + 1;
    w->free_ent = w->clearcode + 2;

    w->a_count = 0;
    w->cur_accum = 0;
    w->cur_bits = 0;

    _gif_cl_hash(w);
    _gif_output(w, w->clearcode);

    int ent = data[0];

    for(int i=1;i<len;i++){
        int c = data[i];
        int fcode = (c << _GIF_BITS) + ent;
        int h = ((c << hshift) ^ ent);
        h %= _GIF_HSIZE;

        if(w->htab[h] == fcode){
            ent = w->codetab[h];
            continue;
        } else if(w->htab[h] >= 0){
            int disp = _GIF_HSIZE - h;
            if(h == 0) disp = 1;
            while(1){
                h -= disp;
                if(h < 0) h += _GIF_HSIZE;
                if(w->htab[h] == fcode){
                    ent = w->codetab[h];
                    goto continue_outer;
                }
                if(w->htab[h] < 0) break;
            }
        }

        // not found
        _gif_output(w, ent);
        ent = c;
        if(w->free_ent < w->maxmaxcode){
            w->codetab[h] = (int16_t)w->free_ent++;
            w->htab[h] = fcode;
        } else {
            _gif_cl_block(w);
        }

continue_outer:
        ;
    }

    _gif_output(w, ent);
    _gif_output(w, w->eofcode);
}

static int _gif_write_image_data(GifWriter* w, const uint8_t* indices, int width, int height){
    // LZW min code size for 8-bit palette
    _gif_putc(w->f, 8);
    w->init_bits = 9; // minCodeSize+1
    _gif_compress(w, indices, width*height);
    _gif_putc(w->f, 0); // sub-block terminator
    return 1;
}

// ------------ Public API ------------

static int GifBegin(GifWriter* w, const char* filename, int width, int height, int delayCs){
    (void)delayCs;
    if(!w) return 0;
    memset(w,0,sizeof(*w));
    w->f = fopen(filename, "wb");
    if(!w->f) return 0;
    w->width=width; w->height=height;

    _gif_write(w->f, "GIF89a", 6);
    _gif_putw(w->f, (uint16_t)width);
    _gif_putw(w->f, (uint16_t)height);
    _gif_putc(w->f, 0xF7);
    _gif_putc(w->f, 0);
    _gif_putc(w->f, 0);
    _gif_write_palette_rgb332(w->f);

    // Netscape loop (infinite)
    _gif_putc(w->f, 0x21); _gif_putc(w->f, 0xFF); _gif_putc(w->f, 11);
    _gif_write(w->f, "NETSCAPE2.0", 11);
    _gif_putc(w->f, 3); _gif_putc(w->f, 1);
    _gif_putw(w->f, 0);
    _gif_putc(w->f, 0);

    w->started=1;
    return 1;
}

static int GifWriteFrame(GifWriter* w, const uint8_t* rgba, int width, int height, int delayCs){
    if(!w||!w->f||!w->started||!rgba) return 0;
    if(width!=w->width||height!=w->height) return 0;

    // GCE
    _gif_putc(w->f, 0x21); _gif_putc(w->f, 0xF9); _gif_putc(w->f, 4);
    _gif_putc(w->f, 0x00);
    _gif_putw(w->f, (uint16_t)delayCs);
    _gif_putc(w->f, 0);
    _gif_putc(w->f, 0);

    // Image descriptor
    _gif_putc(w->f, 0x2C);
    _gif_putw(w->f, 0); _gif_putw(w->f, 0);
    _gif_putw(w->f, (uint16_t)width);
    _gif_putw(w->f, (uint16_t)height);
    _gif_putc(w->f, 0);

    if(!w->idx){
        w->idx = (uint8_t*)malloc((size_t)width*(size_t)height);
        if(!w->idx) return 0;
    }

    int n = width*height;
    for(int i=0;i<n;i++){
        uint8_t r = rgba[i*4+0];
        uint8_t g = rgba[i*4+1];
        uint8_t b = rgba[i*4+2];
        uint8_t ri = (uint8_t)(r>>5);
        uint8_t gi = (uint8_t)(g>>5);
        uint8_t bi = (uint8_t)(b>>6);
        w->idx[i] = (uint8_t)((ri<<5)|(gi<<2)|bi);
    }

    _gif_write_image_data(w, w->idx, width, height);
    return 1;
}

static int GifEnd(GifWriter* w){
    if(!w) return 0;
    if(w->f){
        _gif_putc(w->f, 0x3B);
        fclose(w->f);
        w->f=NULL;
    }
    if(w->idx){ free(w->idx); w->idx=NULL; }
    w->started=0;
    return 1;
}

#ifdef __cplusplus
}
#endif

#endif
