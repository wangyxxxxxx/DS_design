/****************************************************************************
** Meta object code from reading C++ file 'Graph.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Graph.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Graph.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS = QtMocHelpers::stringData(
    "AdjacencyMatrix",
    "addVertex",
    "",
    "vertexId",
    "removeVertex",
    "addEdge",
    "from",
    "to",
    "weight",
    "removeEdge",
    "v1",
    "v2",
    "showMatrix"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[16];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[13];
    char stringdata5[8];
    char stringdata6[5];
    char stringdata7[3];
    char stringdata8[7];
    char stringdata9[11];
    char stringdata10[3];
    char stringdata11[3];
    char stringdata12[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "AdjacencyMatrix"
        QT_MOC_LITERAL(16, 9),  // "addVertex"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 8),  // "vertexId"
        QT_MOC_LITERAL(36, 12),  // "removeVertex"
        QT_MOC_LITERAL(49, 7),  // "addEdge"
        QT_MOC_LITERAL(57, 4),  // "from"
        QT_MOC_LITERAL(62, 2),  // "to"
        QT_MOC_LITERAL(65, 6),  // "weight"
        QT_MOC_LITERAL(72, 10),  // "removeEdge"
        QT_MOC_LITERAL(83, 2),  // "v1"
        QT_MOC_LITERAL(86, 2),  // "v2"
        QT_MOC_LITERAL(89, 10)   // "showMatrix"
    },
    "AdjacencyMatrix",
    "addVertex",
    "",
    "vertexId",
    "removeVertex",
    "addEdge",
    "from",
    "to",
    "weight",
    "removeEdge",
    "v1",
    "v2",
    "showMatrix"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAdjacencyMatrixENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   44,    2, 0x0a,    1 /* Public */,
       4,    0,   47,    2, 0x0a,    3 /* Public */,
       5,    3,   48,    2, 0x0a,    4 /* Public */,
       9,    2,   55,    2, 0x0a,    8 /* Public */,
      12,    0,   60,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject AdjacencyMatrix::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAdjacencyMatrixENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AdjacencyMatrix, std::true_type>,
        // method 'addVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'removeVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'removeEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showMatrix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AdjacencyMatrix::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdjacencyMatrix *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->removeVertex(); break;
        case 2: _t->addEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->removeEdge((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->showMatrix(); break;
        default: ;
        }
    }
}

const QMetaObject *AdjacencyMatrix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdjacencyMatrix::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AdjacencyMatrix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAdjacencyListENDCLASS = QtMocHelpers::stringData(
    "AdjacencyList",
    "showstruct",
    "",
    "showresult",
    "resetcolor",
    "setvertexcolor",
    "setedgecolor",
    "addVertex",
    "vertexId",
    "removeVertex",
    "addEdge",
    "from",
    "to",
    "weight",
    "removeEdge",
    "showList",
    "DFT",
    "startVertex",
    "BFT",
    "MST",
    "findVertexIndex",
    "id",
    "changeDelay",
    "d"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t {
    uint offsetsAndSizes[48];
    char stringdata0[14];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[11];
    char stringdata5[15];
    char stringdata6[13];
    char stringdata7[10];
    char stringdata8[9];
    char stringdata9[13];
    char stringdata10[8];
    char stringdata11[5];
    char stringdata12[3];
    char stringdata13[7];
    char stringdata14[11];
    char stringdata15[9];
    char stringdata16[4];
    char stringdata17[12];
    char stringdata18[4];
    char stringdata19[4];
    char stringdata20[16];
    char stringdata21[3];
    char stringdata22[12];
    char stringdata23[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t qt_meta_stringdata_CLASSAdjacencyListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "AdjacencyList"
        QT_MOC_LITERAL(14, 10),  // "showstruct"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 10),  // "showresult"
        QT_MOC_LITERAL(37, 10),  // "resetcolor"
        QT_MOC_LITERAL(48, 14),  // "setvertexcolor"
        QT_MOC_LITERAL(63, 12),  // "setedgecolor"
        QT_MOC_LITERAL(76, 9),  // "addVertex"
        QT_MOC_LITERAL(86, 8),  // "vertexId"
        QT_MOC_LITERAL(95, 12),  // "removeVertex"
        QT_MOC_LITERAL(108, 7),  // "addEdge"
        QT_MOC_LITERAL(116, 4),  // "from"
        QT_MOC_LITERAL(121, 2),  // "to"
        QT_MOC_LITERAL(124, 6),  // "weight"
        QT_MOC_LITERAL(131, 10),  // "removeEdge"
        QT_MOC_LITERAL(142, 8),  // "showList"
        QT_MOC_LITERAL(151, 3),  // "DFT"
        QT_MOC_LITERAL(155, 11),  // "startVertex"
        QT_MOC_LITERAL(167, 3),  // "BFT"
        QT_MOC_LITERAL(171, 3),  // "MST"
        QT_MOC_LITERAL(175, 15),  // "findVertexIndex"
        QT_MOC_LITERAL(191, 2),  // "id"
        QT_MOC_LITERAL(194, 11),  // "changeDelay"
        QT_MOC_LITERAL(206, 1)   // "d"
    },
    "AdjacencyList",
    "showstruct",
    "",
    "showresult",
    "resetcolor",
    "setvertexcolor",
    "setedgecolor",
    "addVertex",
    "vertexId",
    "removeVertex",
    "addEdge",
    "from",
    "to",
    "weight",
    "removeEdge",
    "showList",
    "DFT",
    "startVertex",
    "BFT",
    "MST",
    "findVertexIndex",
    "id",
    "changeDelay",
    "d"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAdjacencyListENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       3,    1,  107,    2, 0x06,    3 /* Public */,
       4,    0,  110,    2, 0x06,    5 /* Public */,
       5,    2,  111,    2, 0x06,    6 /* Public */,
       6,    3,  116,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,  123,    2, 0x0a,   13 /* Public */,
       9,    0,  126,    2, 0x0a,   15 /* Public */,
      10,    3,  127,    2, 0x0a,   16 /* Public */,
      14,    2,  134,    2, 0x0a,   20 /* Public */,
      15,    0,  139,    2, 0x0a,   23 /* Public */,
      16,    1,  140,    2, 0x0a,   24 /* Public */,
      18,    1,  143,    2, 0x0a,   26 /* Public */,
      19,    1,  146,    2, 0x0a,   28 /* Public */,
      20,    1,  149,    2, 0x0a,   30 /* Public */,
      22,    1,  152,    2, 0x0a,   32 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   11,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Int, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Int,   23,

       0        // eod
};

Q_CONSTINIT const QMetaObject AdjacencyList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSAdjacencyListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAdjacencyListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AdjacencyList, std::true_type>,
        // method 'showstruct'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'showresult'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'resetcolor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setvertexcolor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setedgecolor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'addVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'removeVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'removeEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'showList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DFT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BFT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'MST'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'findVertexIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'changeDelay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void AdjacencyList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdjacencyList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showstruct((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->showresult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->resetcolor(); break;
        case 3: _t->setvertexcolor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->setedgecolor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 5: _t->addVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->removeVertex(); break;
        case 7: _t->addEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->removeEdge((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->showList(); break;
        case 10: _t->DFT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->BFT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->MST((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: { int _r = _t->findVertexIndex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->changeDelay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdjacencyList::*)(QString );
            if (_t _q_method = &AdjacencyList::showstruct; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdjacencyList::*)(QString );
            if (_t _q_method = &AdjacencyList::showresult; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AdjacencyList::*)();
            if (_t _q_method = &AdjacencyList::resetcolor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AdjacencyList::*)(QString , QString );
            if (_t _q_method = &AdjacencyList::setvertexcolor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AdjacencyList::*)(QString , QString , const QColor & );
            if (_t _q_method = &AdjacencyList::setedgecolor; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject *AdjacencyList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdjacencyList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAdjacencyListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AdjacencyList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void AdjacencyList::showstruct(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AdjacencyList::showresult(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AdjacencyList::resetcolor()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AdjacencyList::setvertexcolor(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AdjacencyList::setedgecolor(QString _t1, QString _t2, const QColor & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
