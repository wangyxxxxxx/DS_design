/****************************************************************************
** Meta object code from reading C++ file 'Sort.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Sort.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sort.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSortENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSortENDCLASS = QtMocHelpers::stringData(
    "Sort",
    "numChanged",
    "",
    "str",
    "getData",
    "datastr",
    "insertSort",
    "int[]",
    "arr",
    "size",
    "selectionSort"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSortENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[5];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[8];
    char stringdata5[8];
    char stringdata6[11];
    char stringdata7[6];
    char stringdata8[4];
    char stringdata9[5];
    char stringdata10[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSortENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSortENDCLASS_t qt_meta_stringdata_CLASSSortENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "Sort"
        QT_MOC_LITERAL(5, 10),  // "numChanged"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 3),  // "str"
        QT_MOC_LITERAL(21, 7),  // "getData"
        QT_MOC_LITERAL(29, 7),  // "datastr"
        QT_MOC_LITERAL(37, 10),  // "insertSort"
        QT_MOC_LITERAL(48, 5),  // "int[]"
        QT_MOC_LITERAL(54, 3),  // "arr"
        QT_MOC_LITERAL(58, 4),  // "size"
        QT_MOC_LITERAL(63, 13)   // "selectionSort"
    },
    "Sort",
    "numChanged",
    "",
    "str",
    "getData",
    "datastr",
    "insertSort",
    "int[]",
    "arr",
    "size",
    "selectionSort"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSortENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   41,    2, 0x0a,    3 /* Public */,
       6,    2,   44,    2, 0x0a,    5 /* Public */,
      10,    2,   49,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject Sort::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSortENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSortENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSortENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Sort, std::true_type>,
        // method 'numChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'insertSort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'selectionSort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Sort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Sort *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->numChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->getData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->insertSort((*reinterpret_cast< std::add_pointer_t<int[]>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->selectionSort((*reinterpret_cast< std::add_pointer_t<int[]>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Sort::*)(QString );
            if (_t _q_method = &Sort::numChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Sort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sort::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSortENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Sort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Sort::numChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
