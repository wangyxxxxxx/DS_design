/****************************************************************************
** Meta object code from reading C++ file 'DSLFunctionGraph.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DSLFunctionGraph.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DSLFunctionGraph.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDSLGraphENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDSLGraphENDCLASS = QtMocHelpers::stringData(
    "DSLGraph",
    "sendV",
    "",
    "delV",
    "sendE",
    "delE",
    "sendSelect",
    "senddirect",
    "setdirect",
    "std::vector<std::string>",
    "args",
    "creatVertex",
    "deletVertex",
    "creatEdge",
    "deletEdge",
    "executeDFS",
    "executeBFS",
    "executePrim",
    "executeKruskal",
    "executeDijkstra",
    "execute",
    "string",
    "code"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDSLGraphENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[9];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[5];
    char stringdata6[11];
    char stringdata7[11];
    char stringdata8[10];
    char stringdata9[25];
    char stringdata10[5];
    char stringdata11[12];
    char stringdata12[12];
    char stringdata13[10];
    char stringdata14[10];
    char stringdata15[11];
    char stringdata16[11];
    char stringdata17[12];
    char stringdata18[15];
    char stringdata19[16];
    char stringdata20[8];
    char stringdata21[7];
    char stringdata22[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDSLGraphENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDSLGraphENDCLASS_t qt_meta_stringdata_CLASSDSLGraphENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "DSLGraph"
        QT_MOC_LITERAL(9, 5),  // "sendV"
        QT_MOC_LITERAL(15, 0),  // ""
        QT_MOC_LITERAL(16, 4),  // "delV"
        QT_MOC_LITERAL(21, 5),  // "sendE"
        QT_MOC_LITERAL(27, 4),  // "delE"
        QT_MOC_LITERAL(32, 10),  // "sendSelect"
        QT_MOC_LITERAL(43, 10),  // "senddirect"
        QT_MOC_LITERAL(54, 9),  // "setdirect"
        QT_MOC_LITERAL(64, 24),  // "std::vector<std::string>"
        QT_MOC_LITERAL(89, 4),  // "args"
        QT_MOC_LITERAL(94, 11),  // "creatVertex"
        QT_MOC_LITERAL(106, 11),  // "deletVertex"
        QT_MOC_LITERAL(118, 9),  // "creatEdge"
        QT_MOC_LITERAL(128, 9),  // "deletEdge"
        QT_MOC_LITERAL(138, 10),  // "executeDFS"
        QT_MOC_LITERAL(149, 10),  // "executeBFS"
        QT_MOC_LITERAL(160, 11),  // "executePrim"
        QT_MOC_LITERAL(172, 14),  // "executeKruskal"
        QT_MOC_LITERAL(187, 15),  // "executeDijkstra"
        QT_MOC_LITERAL(203, 7),  // "execute"
        QT_MOC_LITERAL(211, 6),  // "string"
        QT_MOC_LITERAL(218, 4)   // "code"
    },
    "DSLGraph",
    "sendV",
    "",
    "delV",
    "sendE",
    "delE",
    "sendSelect",
    "senddirect",
    "setdirect",
    "std::vector<std::string>",
    "args",
    "creatVertex",
    "deletVertex",
    "creatEdge",
    "deletEdge",
    "executeDFS",
    "executeBFS",
    "executePrim",
    "executeKruskal",
    "executeDijkstra",
    "execute",
    "string",
    "code"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDSLGraphENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x06,    1 /* Public */,
       3,    1,  119,    2, 0x06,    3 /* Public */,
       4,    3,  122,    2, 0x06,    5 /* Public */,
       5,    2,  129,    2, 0x06,    9 /* Public */,
       6,    2,  134,    2, 0x06,   12 /* Public */,
       7,    1,  139,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  142,    2, 0x0a,   17 /* Public */,
      11,    1,  145,    2, 0x0a,   19 /* Public */,
      12,    1,  148,    2, 0x0a,   21 /* Public */,
      13,    1,  151,    2, 0x0a,   23 /* Public */,
      14,    1,  154,    2, 0x0a,   25 /* Public */,
      15,    1,  157,    2, 0x0a,   27 /* Public */,
      16,    1,  160,    2, 0x0a,   29 /* Public */,
      17,    1,  163,    2, 0x0a,   31 /* Public */,
      18,    1,  166,    2, 0x0a,   33 /* Public */,
      19,    1,  169,    2, 0x0a,   35 /* Public */,
      20,    1,  172,    2, 0x0a,   37 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

Q_CONSTINIT const QMetaObject DSLGraph::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDSLGraphENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDSLGraphENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDSLGraphENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DSLGraph, std::true_type>,
        // method 'sendV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'delV'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendE'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'delE'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendSelect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'senddirect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setdirect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'creatVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'deletVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'creatEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'deletEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executeDFS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executeBFS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executePrim'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executeKruskal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executeDijkstra'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'execute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const string &, std::false_type>
    >,
    nullptr
} };

void DSLGraph::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DSLGraph *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendV((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->delV((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->sendE((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 3: _t->delE((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->sendSelect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->senddirect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setdirect((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 7: _t->creatVertex((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 8: _t->deletVertex((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 9: _t->creatEdge((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 10: _t->deletEdge((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 11: _t->executeDFS((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 12: _t->executeBFS((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 13: _t->executePrim((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 14: _t->executeKruskal((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 15: _t->executeDijkstra((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 16: _t->execute((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DSLGraph::*)(QString );
            if (_t _q_method = &DSLGraph::sendV; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DSLGraph::*)(QString );
            if (_t _q_method = &DSLGraph::delV; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DSLGraph::*)(QString , QString , QString );
            if (_t _q_method = &DSLGraph::sendE; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DSLGraph::*)(QString , QString );
            if (_t _q_method = &DSLGraph::delE; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DSLGraph::*)(QString , QString );
            if (_t _q_method = &DSLGraph::sendSelect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DSLGraph::*)(int );
            if (_t _q_method = &DSLGraph::senddirect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject *DSLGraph::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DSLGraph::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDSLGraphENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DSLGraph::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void DSLGraph::sendV(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DSLGraph::delV(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DSLGraph::sendE(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void DSLGraph::delE(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void DSLGraph::sendSelect(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DSLGraph::senddirect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
