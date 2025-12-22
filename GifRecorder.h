#ifndef GIFRECORDER_H
#define GIFRECORDER_H

#include <QObject>
#include <QTimer>
#include <QWidget>
#include <QImage>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QPainter>
#include <QPalette>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtGlobal>

#include "gif.h"

// 说明：
// 1) 流式写入GIF，不缓存所有帧（避免快排帧多卡退）
// 2) 关键修复：如果 target 是 QGraphicsView，则使用 scene->render() 渲染当前可视区域，保证能录到柱子
// 3) 写入前把 QImage 转成“紧密 RGBA 缓冲区”（去掉 bytesPerLine 行填充），避免彩线/黑屏

class GifRecorder : public QObject {
    Q_OBJECT
public:
    explicit GifRecorder(QObject* parent = nullptr)
        : QObject(parent)
    {
        connect(&timer_, &QTimer::timeout, this, &GifRecorder::captureFrame);
    }

    void setTarget(QWidget* w) { target_ = w; }

    bool isRecording() const { return recording_; }

    QString tempFilePath() const { return tempPath_; }

    bool start(int intervalMs, int maxWidth = 800) {
        if (!target_) return false;

        stop();

        intervalMs_ = qMax(30, intervalMs);
        maxWidth_   = qMax(100, maxWidth);

        tempPath_ = QDir::tempPath() + "/sort_demo_" +
                    QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss_zzz") + ".gif";

        QImage first = captureImage();
        if (first.isNull()) {
            tempPath_.clear();
            return false;
        }

        // 统一输出尺寸（像素）
        width_  = first.width();
        height_ = first.height();

        int delayCs = qMax(1, intervalMs_ / 10);
        QByteArray fn = QFile::encodeName(tempPath_);

        if (!GifBegin(&writer_, fn.constData(), width_, height_, delayCs)) {
            tempPath_.clear();
            return false;
        }

        QByteArray rgba = toTightRGBA(first);
        if (rgba.isEmpty() ||
            !GifWriteFrame(&writer_,
                           reinterpret_cast<const uint8_t*>(rgba.constData()),
                           width_, height_, delayCs)) {
            GifEnd(&writer_);
            QFile::remove(tempPath_);
            tempPath_.clear();
            return false;
        }

        recording_ = true;
        timer_.start(intervalMs_);
        return true;
    }

    void stop() {
        if (!recording_) return;
        timer_.stop();
        GifEnd(&writer_);
        recording_ = false;
    }

    bool saveAs(const QString& fileName) {
        if (tempPath_.isEmpty()) return false;

        QString fn = fileName;
        if (!fn.endsWith(".gif", Qt::CaseInsensitive)) fn += ".gif";

        QFile::remove(fn);
        return QFile::copy(tempPath_, fn);
    }

    void discardTemp() {
        stop();
        if (!tempPath_.isEmpty()) QFile::remove(tempPath_);
        tempPath_.clear();
    }

    // 兼容旧代码
    void clear() { discardTemp(); }

private slots:
    void captureFrame() {
        if (!recording_ || !target_) return;

        // 让界面尽量刷新到最新（尤其你动画可能在同线程）
        target_->update();
        qApp->processEvents();

        QImage img = captureImage();
        if (img.isNull()) return;




        if (img.size() != QSize(width_, height_)) {
            img = img.scaled(width_, height_, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        }

        QByteArray rgba = toTightRGBA(img);
        if (rgba.isEmpty()) return;

        int delayCs = qMax(1, intervalMs_ / 10);
        GifWriteFrame(&writer_,
                      reinterpret_cast<const uint8_t*>(rgba.constData()),
                      width_, height_, delayCs);
    }

private:
    // 核心：优先捕获 QGraphicsView 的 scene（最可靠）
    QImage captureImage() const {
        if (!target_) return QImage();

        // 如果 target 是 QGraphicsView，则用 scene->render 画“当前可视区域”
        if (auto view = qobject_cast<QGraphicsView*>(target_)) {
            QGraphicsScene* sc = view->scene();
            if (!sc) return QImage();

            // 输出尺寸以 viewport 为准（只录内容区，不录边框）
            QWidget* vp = view->viewport();
            int w = vp ? vp->width() : view->width();
            int h = vp ? vp->height() : view->height();
            if (w <= 0 || h <= 0) return QImage();

            QImage img(QSize(w, h), QImage::Format_ARGB32);
            QColor bg = view->palette().color(QPalette::Base);
            if (!bg.isValid()) bg = Qt::white;
            img.fill(bg);

            QPainter p(&img);
            p.setRenderHint(QPainter::Antialiasing, true);
            p.setRenderHint(QPainter::TextAntialiasing, true);

            // 当前可视区域（跟屏幕上看到的一样）
            QRect vpRect = vp ? vp->rect() : QRect(0,0,w,h);
            QRectF src = view->mapToScene(vpRect).boundingRect();

            // 把 src 渲染到整张图
            sc->render(&p, QRectF(0, 0, w, h), src, Qt::IgnoreAspectRatio);
            p.end();

            // 缩放到 maxWidth（可选）
            if (maxWidth_ > 0 && img.width() > maxWidth_) {
                img = img.scaledToWidth(maxWidth_, Qt::SmoothTransformation);
            }
            return img;
        }

        // 其它普通 QWidget：render 到 QImage
        int w = target_->width();
        int h = target_->height();
        if (w <= 0 || h <= 0) return QImage();

        QImage img(QSize(w, h), QImage::Format_ARGB32);
        QColor bg = target_->palette().color(QPalette::Window);
        if (!bg.isValid()) bg = Qt::white;
        img.fill(bg);

        QPainter p(&img);
        p.setRenderHint(QPainter::Antialiasing, true);
        target_->render(&p);
        p.end();

        if (maxWidth_ > 0 && img.width() > maxWidth_) {
            img = img.scaledToWidth(maxWidth_, Qt::SmoothTransformation);
        }
        return img;
    }

    // 转紧密 RGBA（无行填充），并强制 alpha=255
    QByteArray toTightRGBA(const QImage& src) const {
        if (src.isNull()) return {};

        QImage img = src.convertToFormat(QImage::Format_RGBA8888);
        if (img.isNull()) return {};

        int w = img.width();
        int h = img.height();

        // 强制不透明
        for (int y = 0; y < h; ++y) {
            uchar* line = img.scanLine(y);
            for (int x = 0; x < w; ++x) {
                line[x * 4 + 3] = 255;
            }
        }

        // 关键：按行拷贝去掉 bytesPerLine 的填充
        QByteArray out;
        out.resize(w * h * 4);

        for (int y = 0; y < h; ++y) {
            const uchar* srcLine = img.constScanLine(y);
            char* dstLine = out.data() + y * w * 4;
            memcpy(dstLine, srcLine, w * 4);
        }
        return out;
    }

private:
    QWidget* target_ = nullptr;
    QTimer timer_;

    GifWriter writer_{};
    bool recording_ = false;

    QString tempPath_;
    int intervalMs_ = 80;
    int maxWidth_ = 800;
    int width_ = 0;
    int height_ = 0;
};

#endif // GIFRECORDER_H
