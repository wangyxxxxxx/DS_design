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
    "creatVertex",
    "std::vector<std::string>",
    "args",
    "deletVertex",
    "creatEdge",
    "deletEdge",
    "executeDFS",
    "executeBFS",
    "executeMST",
    "execute",
    "string",
    "code"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDSLGraphENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[9];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[6];
    char stringdata5[5];
    char stringdata6[11];
    char stringdata7[12];
    char stringdata8[25];
    char stringdata9[5];
    char stringdata10[12];
    char stringdata11[10];
    char stringdata12[10];
    char stringdata13[11];
    char stringdata14[11];
    char stringdata15[11];
    char stringdata16[8];
    char stringdata17[7];
    char stringdata18[5];
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
        QT_MOC_LITERAL(43, 11),  // "creatVertex"
        QT_MOC_LITERAL(55, 24),  // "std::vector<std::string>"
        QT_MOC_LITERAL(80, 4),  // "args"
        QT_MOC_LITERAL(85, 11),  // "deletVertex"
        QT_MOC_LITERAL(97, 9),  // "creatEdge"
        QT_MOC_LITERAL(107, 9),  // "deletEdge"
        QT_MOC_LITERAL(117, 10),  // "executeDFS"
        QT_MOC_LITERAL(128, 10),  // "executeBFS"
        QT_MOC_LITERAL(139, 10),  // "executeMST"
        QT_MOC_LITERAL(150, 7),  // "execute"
        QT_MOC_LITERAL(158, 6),  // "string"
        QT_MOC_LITERAL(165, 4)   // "code"
    },
    "DSLGraph",
    "sendV",
    "",
    "delV",
    "sendE",
    "delE",
    "sendSelect",
    "creatVertex",
    "std::vector<std::string>",
    "args",
    "deletVertex",
    "creatEdge",
    "deletEdge",
    "executeDFS",
    "executeBFS",
    "executeMST",
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,
       3,    1,   95,    2, 0x06,    3 /* Public */,
       4,    3,   98,    2, 0x06,    5 /* Public */,
       5,    2,  105,    2, 0x06,    9 /* Public */,
       6,    2,  110,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,  115,    2, 0x0a,   15 /* Public */,
      10,    1,  118,    2, 0x0a,   17 /* Public */,
      11,    1,  121,    2, 0x0a,   19 /* Public */,
      12,    1,  124,    2, 0x0a,   21 /* Public */,
      13,    1,  127,    2, 0x0a,   23 /* Public */,
      14,    1,  130,    2, 0x0a,   25 /* Public */,
      15,    1,  133,    2, 0x0a,   27 /* Public */,
      16,    1,  136,    2, 0x0a,   29 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 17,   18,

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
        // method 'executeMST'
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
        case 5: _t->creatVertex((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 6: _t->deletVertex((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 7: _t->creatEdge((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 8: _t->deletEdge((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 9: _t->executeDFS((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 10: _t->executeBFS((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 11: _t->executeMST((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 12: _t->execute((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
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
QT_WARNING_POP
