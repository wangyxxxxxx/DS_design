/****************************************************************************
** Meta object code from reading C++ file 'SortWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SortWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SortWidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSortWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSortWidgetENDCLASS = QtMocHelpers::stringData(
    "SortWidget",
    "sendData",
    "",
    "DisplayTime",
    "usingtime",
    "submitData",
    "creatGraph",
    "ClearAll",
    "RectSwap",
    "n",
    "m",
    "s"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSortWidgetENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[9];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[10];
    char stringdata5[11];
    char stringdata6[11];
    char stringdata7[9];
    char stringdata8[9];
    char stringdata9[2];
    char stringdata10[2];
    char stringdata11[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSortWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSortWidgetENDCLASS_t qt_meta_stringdata_CLASSSortWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "SortWidget"
        QT_MOC_LITERAL(11, 8),  // "sendData"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 11),  // "DisplayTime"
        QT_MOC_LITERAL(33, 9),  // "usingtime"
        QT_MOC_LITERAL(43, 10),  // "submitData"
        QT_MOC_LITERAL(54, 10),  // "creatGraph"
        QT_MOC_LITERAL(65, 8),  // "ClearAll"
        QT_MOC_LITERAL(74, 8),  // "RectSwap"
        QT_MOC_LITERAL(83, 1),  // "n"
        QT_MOC_LITERAL(85, 1),  // "m"
        QT_MOC_LITERAL(87, 1)   // "s"
    },
    "SortWidget",
    "sendData",
    "",
    "DisplayTime",
    "usingtime",
    "submitData",
    "creatGraph",
    "ClearAll",
    "RectSwap",
    "n",
    "m",
    "s"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSortWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   55,    2, 0x08,    4 /* Private */,
       5,    0,   58,    2, 0x08,    6 /* Private */,
       6,    0,   59,    2, 0x08,    7 /* Private */,
       7,    0,   60,    2, 0x08,    8 /* Private */,
       8,    3,   61,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject SortWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSSortWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSortWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSortWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SortWidget, std::true_type>,
        // method 'sendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'DisplayTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'submitData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'creatGraph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ClearAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RectSwap'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void SortWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SortWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->DisplayTime((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->submitData(); break;
        case 3: _t->creatGraph(); break;
        case 4: _t->ClearAll(); break;
        case 5: _t->RectSwap((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SortWidget::*)(QString , int );
            if (_t _q_method = &SortWidget::sendData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *SortWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSortWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SortWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void SortWidget::sendData(QString _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
