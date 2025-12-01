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
    "showmatrixstruct",
    "",
    "string",
    "addVertex",
    "vertexId",
    "removeVertex",
    "v",
    "addEdge",
    "from",
    "to",
    "weight",
    "setWeight",
    "removeEdge",
    "clearall",
    "showMatrix"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[16];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[10];
    char stringdata5[9];
    char stringdata6[13];
    char stringdata7[2];
    char stringdata8[8];
    char stringdata9[5];
    char stringdata10[3];
    char stringdata11[7];
    char stringdata12[10];
    char stringdata13[11];
    char stringdata14[9];
    char stringdata15[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS_t qt_meta_stringdata_CLASSAdjacencyMatrixENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "AdjacencyMatrix"
        QT_MOC_LITERAL(16, 16),  // "showmatrixstruct"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 6),  // "string"
        QT_MOC_LITERAL(41, 9),  // "addVertex"
        QT_MOC_LITERAL(51, 8),  // "vertexId"
        QT_MOC_LITERAL(60, 12),  // "removeVertex"
        QT_MOC_LITERAL(73, 1),  // "v"
        QT_MOC_LITERAL(75, 7),  // "addEdge"
        QT_MOC_LITERAL(83, 4),  // "from"
        QT_MOC_LITERAL(88, 2),  // "to"
        QT_MOC_LITERAL(91, 6),  // "weight"
        QT_MOC_LITERAL(98, 9),  // "setWeight"
        QT_MOC_LITERAL(108, 10),  // "removeEdge"
        QT_MOC_LITERAL(119, 8),  // "clearall"
        QT_MOC_LITERAL(128, 10)   // "showMatrix"
    },
    "AdjacencyMatrix",
    "showmatrixstruct",
    "",
    "string",
    "addVertex",
    "vertexId",
    "removeVertex",
    "v",
    "addEdge",
    "from",
    "to",
    "weight",
    "setWeight",
    "removeEdge",
    "clearall",
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   65,    2, 0x0a,    3 /* Public */,
       6,    1,   68,    2, 0x0a,    5 /* Public */,
       8,    3,   71,    2, 0x0a,    7 /* Public */,
      12,    3,   78,    2, 0x0a,   11 /* Public */,
      13,    2,   85,    2, 0x0a,   15 /* Public */,
      14,    0,   90,    2, 0x0a,   18 /* Public */,
      15,    0,   91,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    9,   10,
    QMetaType::Void,
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
        // method 'showmatrixstruct'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<string, std::false_type>,
        // method 'addVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'removeVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setWeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'removeEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clearall'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 0: _t->showmatrixstruct((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 1: _t->addVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->removeVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->addEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->setWeight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->removeEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->clearall(); break;
        case 7: _t->showMatrix(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdjacencyMatrix::*)(string );
            if (_t _q_method = &AdjacencyMatrix::showmatrixstruct; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AdjacencyMatrix::showmatrixstruct(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAdjacencyListENDCLASS = QtMocHelpers::stringData(
    "AdjacencyList",
    "showresult",
    "",
    "showstruct",
    "string",
    "resetcolor",
    "setvertexcolor",
    "setedgecolor",
    "setDirect",
    "d",
    "addVertex",
    "vertexId",
    "removeVertex",
    "v",
    "addEdge",
    "from",
    "to",
    "weight",
    "setWeight",
    "removeEdge2",
    "removeEdge1",
    "showList",
    "clearall",
    "DFT",
    "startVertex",
    "DFSFromVertex",
    "startIndex",
    "vector<QString>&",
    "result",
    "markReverseEdge",
    "BFT",
    "Kruskal",
    "Prim",
    "findVertexIndex",
    "id",
    "changeDelay"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t {
    uint offsetsAndSizes[72];
    char stringdata0[14];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[7];
    char stringdata5[11];
    char stringdata6[15];
    char stringdata7[13];
    char stringdata8[10];
    char stringdata9[2];
    char stringdata10[10];
    char stringdata11[9];
    char stringdata12[13];
    char stringdata13[2];
    char stringdata14[8];
    char stringdata15[5];
    char stringdata16[3];
    char stringdata17[7];
    char stringdata18[10];
    char stringdata19[12];
    char stringdata20[12];
    char stringdata21[9];
    char stringdata22[9];
    char stringdata23[4];
    char stringdata24[12];
    char stringdata25[14];
    char stringdata26[11];
    char stringdata27[17];
    char stringdata28[7];
    char stringdata29[16];
    char stringdata30[4];
    char stringdata31[8];
    char stringdata32[5];
    char stringdata33[16];
    char stringdata34[3];
    char stringdata35[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAdjacencyListENDCLASS_t qt_meta_stringdata_CLASSAdjacencyListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "AdjacencyList"
        QT_MOC_LITERAL(14, 10),  // "showresult"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 10),  // "showstruct"
        QT_MOC_LITERAL(37, 6),  // "string"
        QT_MOC_LITERAL(44, 10),  // "resetcolor"
        QT_MOC_LITERAL(55, 14),  // "setvertexcolor"
        QT_MOC_LITERAL(70, 12),  // "setedgecolor"
        QT_MOC_LITERAL(83, 9),  // "setDirect"
        QT_MOC_LITERAL(93, 1),  // "d"
        QT_MOC_LITERAL(95, 9),  // "addVertex"
        QT_MOC_LITERAL(105, 8),  // "vertexId"
        QT_MOC_LITERAL(114, 12),  // "removeVertex"
        QT_MOC_LITERAL(127, 1),  // "v"
        QT_MOC_LITERAL(129, 7),  // "addEdge"
        QT_MOC_LITERAL(137, 4),  // "from"
        QT_MOC_LITERAL(142, 2),  // "to"
        QT_MOC_LITERAL(145, 6),  // "weight"
        QT_MOC_LITERAL(152, 9),  // "setWeight"
        QT_MOC_LITERAL(162, 11),  // "removeEdge2"
        QT_MOC_LITERAL(174, 11),  // "removeEdge1"
        QT_MOC_LITERAL(186, 8),  // "showList"
        QT_MOC_LITERAL(195, 8),  // "clearall"
        QT_MOC_LITERAL(204, 3),  // "DFT"
        QT_MOC_LITERAL(208, 11),  // "startVertex"
        QT_MOC_LITERAL(220, 13),  // "DFSFromVertex"
        QT_MOC_LITERAL(234, 10),  // "startIndex"
        QT_MOC_LITERAL(245, 16),  // "vector<QString>&"
        QT_MOC_LITERAL(262, 6),  // "result"
        QT_MOC_LITERAL(269, 15),  // "markReverseEdge"
        QT_MOC_LITERAL(285, 3),  // "BFT"
        QT_MOC_LITERAL(289, 7),  // "Kruskal"
        QT_MOC_LITERAL(297, 4),  // "Prim"
        QT_MOC_LITERAL(302, 15),  // "findVertexIndex"
        QT_MOC_LITERAL(318, 2),  // "id"
        QT_MOC_LITERAL(321, 11)   // "changeDelay"
    },
    "AdjacencyList",
    "showresult",
    "",
    "showstruct",
    "string",
    "resetcolor",
    "setvertexcolor",
    "setedgecolor",
    "setDirect",
    "d",
    "addVertex",
    "vertexId",
    "removeVertex",
    "v",
    "addEdge",
    "from",
    "to",
    "weight",
    "setWeight",
    "removeEdge2",
    "removeEdge1",
    "showList",
    "clearall",
    "DFT",
    "startVertex",
    "DFSFromVertex",
    "startIndex",
    "vector<QString>&",
    "result",
    "markReverseEdge",
    "BFT",
    "Kruskal",
    "Prim",
    "findVertexIndex",
    "id",
    "changeDelay"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAdjacencyListENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  146,    2, 0x06,    1 /* Public */,
       3,    1,  149,    2, 0x06,    3 /* Public */,
       5,    0,  152,    2, 0x06,    5 /* Public */,
       6,    2,  153,    2, 0x06,    6 /* Public */,
       7,    3,  158,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  165,    2, 0x0a,   13 /* Public */,
      10,    1,  168,    2, 0x0a,   15 /* Public */,
      12,    1,  171,    2, 0x0a,   17 /* Public */,
      14,    3,  174,    2, 0x0a,   19 /* Public */,
      18,    3,  181,    2, 0x0a,   23 /* Public */,
      19,    2,  188,    2, 0x0a,   27 /* Public */,
      20,    1,  193,    2, 0x0a,   30 /* Public */,
      21,    0,  196,    2, 0x0a,   32 /* Public */,
      22,    0,  197,    2, 0x0a,   33 /* Public */,
      23,    1,  198,    2, 0x0a,   34 /* Public */,
      25,    2,  201,    2, 0x0a,   36 /* Public */,
      29,    2,  206,    2, 0x0a,   39 /* Public */,
      30,    1,  211,    2, 0x0a,   42 /* Public */,
      31,    1,  214,    2, 0x0a,   44 /* Public */,
      32,    1,  217,    2, 0x0a,   46 /* Public */,
      33,    1,  220,    2, 0x0a,   48 /* Public */,
      35,    1,  223,    2, 0x0a,   50 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   15,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 27,   26,   28,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Int, QMetaType::QString,   34,
    QMetaType::Void, QMetaType::Int,    9,

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
        // method 'showresult'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'showstruct'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<string, std::false_type>,
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
        // method 'setDirect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'removeVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setWeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'removeEdge2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'removeEdge1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'showList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearall'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DFT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DFSFromVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<vector<QString> &, std::false_type>,
        // method 'markReverseEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BFT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Kruskal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Prim'
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
        case 0: _t->showresult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->showstruct((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 2: _t->resetcolor(); break;
        case 3: _t->setvertexcolor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->setedgecolor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 5: _t->setDirect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->addVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->removeVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->addEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 9: _t->setWeight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 10: _t->removeEdge2((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 11: _t->removeEdge1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->showList(); break;
        case 13: _t->clearall(); break;
        case 14: _t->DFT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->DFSFromVertex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<vector<QString>&>>(_a[2]))); break;
        case 16: _t->markReverseEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 17: _t->BFT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->Kruskal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->Prim((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: { int _r = _t->findVertexIndex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->changeDelay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AdjacencyList::*)(QString );
            if (_t _q_method = &AdjacencyList::showresult; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AdjacencyList::*)(string );
            if (_t _q_method = &AdjacencyList::showstruct; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void AdjacencyList::showresult(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AdjacencyList::showstruct(string _t1)
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
