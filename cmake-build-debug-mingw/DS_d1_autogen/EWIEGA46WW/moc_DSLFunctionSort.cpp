/****************************************************************************
** Meta object code from reading C++ file 'DSLFunctionSort.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DSLFunctionSort.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DSLFunctionSort.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDSLSortENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDSLSortENDCLASS = QtMocHelpers::stringData(
    "DSLSort",
    "sendSEQ",
    "",
    "sendSelectSort",
    "creatSEQ",
    "std::vector<std::string>",
    "args",
    "executeIS",
    "executeSS",
    "executeQS",
    "execute",
    "string",
    "code"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDSLSortENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[8];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[9];
    char stringdata5[25];
    char stringdata6[5];
    char stringdata7[10];
    char stringdata8[10];
    char stringdata9[10];
    char stringdata10[8];
    char stringdata11[7];
    char stringdata12[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDSLSortENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDSLSortENDCLASS_t qt_meta_stringdata_CLASSDSLSortENDCLASS = {
    {
        QT_MOC_LITERAL(0, 7),  // "DSLSort"
        QT_MOC_LITERAL(8, 7),  // "sendSEQ"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 14),  // "sendSelectSort"
        QT_MOC_LITERAL(32, 8),  // "creatSEQ"
        QT_MOC_LITERAL(41, 24),  // "std::vector<std::string>"
        QT_MOC_LITERAL(66, 4),  // "args"
        QT_MOC_LITERAL(71, 9),  // "executeIS"
        QT_MOC_LITERAL(81, 9),  // "executeSS"
        QT_MOC_LITERAL(91, 9),  // "executeQS"
        QT_MOC_LITERAL(101, 7),  // "execute"
        QT_MOC_LITERAL(109, 6),  // "string"
        QT_MOC_LITERAL(116, 4)   // "code"
    },
    "DSLSort",
    "sendSEQ",
    "",
    "sendSelectSort",
    "creatSEQ",
    "std::vector<std::string>",
    "args",
    "executeIS",
    "executeSS",
    "executeQS",
    "execute",
    "string",
    "code"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDSLSortENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       3,    1,   59,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   62,    2, 0x0a,    5 /* Public */,
       7,    1,   65,    2, 0x0a,    7 /* Public */,
       8,    1,   68,    2, 0x0a,    9 /* Public */,
       9,    1,   71,    2, 0x0a,   11 /* Public */,
      10,    1,   74,    2, 0x0a,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject DSLSort::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDSLSortENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDSLSortENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDSLSortENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DSLSort, std::true_type>,
        // method 'sendSEQ'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendSelectSort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'creatSEQ'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executeIS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executeSS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'executeQS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const std::vector<std::string> &, std::false_type>,
        // method 'execute'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const string &, std::false_type>
    >,
    nullptr
} };

void DSLSort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DSLSort *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendSEQ((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sendSelectSort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->creatSEQ((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 3: _t->executeIS((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 4: _t->executeSS((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 5: _t->executeQS((*reinterpret_cast< std::add_pointer_t<std::vector<std::string>>>(_a[1]))); break;
        case 6: _t->execute((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DSLSort::*)(QString );
            if (_t _q_method = &DSLSort::sendSEQ; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DSLSort::*)(QString );
            if (_t _q_method = &DSLSort::sendSelectSort; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *DSLSort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DSLSort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDSLSortENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DSLSort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DSLSort::sendSEQ(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DSLSort::sendSelectSort(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
