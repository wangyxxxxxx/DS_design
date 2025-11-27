/****************************************************************************
** Meta object code from reading C++ file 'GraphWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../GraphWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GraphWidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGraphWidgetENDCLASS = QtMocHelpers::stringData(
    "GraphWidget",
    "sendVertex",
    "",
    "sendEdge",
    "sendDFT",
    "sendBFT",
    "sendKruskal",
    "sendPrim",
    "sendDelay",
    "sendRemoveVertex",
    "sendRemoveEdge",
    "clear",
    "sendDataDSL",
    "string",
    "sendNatural",
    "sendDirect",
    "setDirect",
    "setAPI",
    "getapi",
    "executeNatural",
    "showNaturalToDSL",
    "str",
    "DSLsetdirect",
    "d",
    "executeDSL",
    "DSLaddVertex",
    "v",
    "DSLdelVertex",
    "DSLaddEdge",
    "from",
    "to",
    "weight",
    "DSLdelEdge",
    "DSLSelect",
    "s",
    "addVertex",
    "removeVertex",
    "addEdge",
    "removeEdge1",
    "removeEdge2",
    "clearall",
    "traverseGraph",
    "showStruct",
    "showMatrix",
    "showResult",
    "result",
    "resetColor",
    "setVertexColor",
    "vertex",
    "color",
    "setEdgeColor",
    "saveData",
    "fileName",
    "saveFile",
    "findVertexByNumber",
    "Vertex*",
    "number",
    "loadData",
    "openFile",
    "updateDisplay"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t {
    uint offsetsAndSizes[120];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[8];
    char stringdata5[8];
    char stringdata6[12];
    char stringdata7[9];
    char stringdata8[10];
    char stringdata9[17];
    char stringdata10[15];
    char stringdata11[6];
    char stringdata12[12];
    char stringdata13[7];
    char stringdata14[12];
    char stringdata15[11];
    char stringdata16[10];
    char stringdata17[7];
    char stringdata18[7];
    char stringdata19[15];
    char stringdata20[17];
    char stringdata21[4];
    char stringdata22[13];
    char stringdata23[2];
    char stringdata24[11];
    char stringdata25[13];
    char stringdata26[2];
    char stringdata27[13];
    char stringdata28[11];
    char stringdata29[5];
    char stringdata30[3];
    char stringdata31[7];
    char stringdata32[11];
    char stringdata33[10];
    char stringdata34[2];
    char stringdata35[10];
    char stringdata36[13];
    char stringdata37[8];
    char stringdata38[12];
    char stringdata39[12];
    char stringdata40[9];
    char stringdata41[14];
    char stringdata42[11];
    char stringdata43[11];
    char stringdata44[11];
    char stringdata45[7];
    char stringdata46[11];
    char stringdata47[15];
    char stringdata48[7];
    char stringdata49[6];
    char stringdata50[13];
    char stringdata51[9];
    char stringdata52[9];
    char stringdata53[9];
    char stringdata54[19];
    char stringdata55[8];
    char stringdata56[7];
    char stringdata57[9];
    char stringdata58[9];
    char stringdata59[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t qt_meta_stringdata_CLASSGraphWidgetENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "GraphWidget"
        QT_MOC_LITERAL(12, 10),  // "sendVertex"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 8),  // "sendEdge"
        QT_MOC_LITERAL(33, 7),  // "sendDFT"
        QT_MOC_LITERAL(41, 7),  // "sendBFT"
        QT_MOC_LITERAL(49, 11),  // "sendKruskal"
        QT_MOC_LITERAL(61, 8),  // "sendPrim"
        QT_MOC_LITERAL(70, 9),  // "sendDelay"
        QT_MOC_LITERAL(80, 16),  // "sendRemoveVertex"
        QT_MOC_LITERAL(97, 14),  // "sendRemoveEdge"
        QT_MOC_LITERAL(112, 5),  // "clear"
        QT_MOC_LITERAL(118, 11),  // "sendDataDSL"
        QT_MOC_LITERAL(130, 6),  // "string"
        QT_MOC_LITERAL(137, 11),  // "sendNatural"
        QT_MOC_LITERAL(149, 10),  // "sendDirect"
        QT_MOC_LITERAL(160, 9),  // "setDirect"
        QT_MOC_LITERAL(170, 6),  // "setAPI"
        QT_MOC_LITERAL(177, 6),  // "getapi"
        QT_MOC_LITERAL(184, 14),  // "executeNatural"
        QT_MOC_LITERAL(199, 16),  // "showNaturalToDSL"
        QT_MOC_LITERAL(216, 3),  // "str"
        QT_MOC_LITERAL(220, 12),  // "DSLsetdirect"
        QT_MOC_LITERAL(233, 1),  // "d"
        QT_MOC_LITERAL(235, 10),  // "executeDSL"
        QT_MOC_LITERAL(246, 12),  // "DSLaddVertex"
        QT_MOC_LITERAL(259, 1),  // "v"
        QT_MOC_LITERAL(261, 12),  // "DSLdelVertex"
        QT_MOC_LITERAL(274, 10),  // "DSLaddEdge"
        QT_MOC_LITERAL(285, 4),  // "from"
        QT_MOC_LITERAL(290, 2),  // "to"
        QT_MOC_LITERAL(293, 6),  // "weight"
        QT_MOC_LITERAL(300, 10),  // "DSLdelEdge"
        QT_MOC_LITERAL(311, 9),  // "DSLSelect"
        QT_MOC_LITERAL(321, 1),  // "s"
        QT_MOC_LITERAL(323, 9),  // "addVertex"
        QT_MOC_LITERAL(333, 12),  // "removeVertex"
        QT_MOC_LITERAL(346, 7),  // "addEdge"
        QT_MOC_LITERAL(354, 11),  // "removeEdge1"
        QT_MOC_LITERAL(366, 11),  // "removeEdge2"
        QT_MOC_LITERAL(378, 8),  // "clearall"
        QT_MOC_LITERAL(387, 13),  // "traverseGraph"
        QT_MOC_LITERAL(401, 10),  // "showStruct"
        QT_MOC_LITERAL(412, 10),  // "showMatrix"
        QT_MOC_LITERAL(423, 10),  // "showResult"
        QT_MOC_LITERAL(434, 6),  // "result"
        QT_MOC_LITERAL(441, 10),  // "resetColor"
        QT_MOC_LITERAL(452, 14),  // "setVertexColor"
        QT_MOC_LITERAL(467, 6),  // "vertex"
        QT_MOC_LITERAL(474, 5),  // "color"
        QT_MOC_LITERAL(480, 12),  // "setEdgeColor"
        QT_MOC_LITERAL(493, 8),  // "saveData"
        QT_MOC_LITERAL(502, 8),  // "fileName"
        QT_MOC_LITERAL(511, 8),  // "saveFile"
        QT_MOC_LITERAL(520, 18),  // "findVertexByNumber"
        QT_MOC_LITERAL(539, 7),  // "Vertex*"
        QT_MOC_LITERAL(547, 6),  // "number"
        QT_MOC_LITERAL(554, 8),  // "loadData"
        QT_MOC_LITERAL(563, 8),  // "openFile"
        QT_MOC_LITERAL(572, 13)   // "updateDisplay"
    },
    "GraphWidget",
    "sendVertex",
    "",
    "sendEdge",
    "sendDFT",
    "sendBFT",
    "sendKruskal",
    "sendPrim",
    "sendDelay",
    "sendRemoveVertex",
    "sendRemoveEdge",
    "clear",
    "sendDataDSL",
    "string",
    "sendNatural",
    "sendDirect",
    "setDirect",
    "setAPI",
    "getapi",
    "executeNatural",
    "showNaturalToDSL",
    "str",
    "DSLsetdirect",
    "d",
    "executeDSL",
    "DSLaddVertex",
    "v",
    "DSLdelVertex",
    "DSLaddEdge",
    "from",
    "to",
    "weight",
    "DSLdelEdge",
    "DSLSelect",
    "s",
    "addVertex",
    "removeVertex",
    "addEdge",
    "removeEdge1",
    "removeEdge2",
    "clearall",
    "traverseGraph",
    "showStruct",
    "showMatrix",
    "showResult",
    "result",
    "resetColor",
    "setVertexColor",
    "vertex",
    "color",
    "setEdgeColor",
    "saveData",
    "fileName",
    "saveFile",
    "findVertexByNumber",
    "Vertex*",
    "number",
    "loadData",
    "openFile",
    "updateDisplay"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGraphWidgetENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  272,    2, 0x06,    1 /* Public */,
       3,    3,  275,    2, 0x06,    3 /* Public */,
       4,    1,  282,    2, 0x06,    7 /* Public */,
       5,    1,  285,    2, 0x06,    9 /* Public */,
       6,    1,  288,    2, 0x06,   11 /* Public */,
       7,    1,  291,    2, 0x06,   13 /* Public */,
       8,    1,  294,    2, 0x06,   15 /* Public */,
       9,    1,  297,    2, 0x06,   17 /* Public */,
      10,    2,  300,    2, 0x06,   19 /* Public */,
      11,    0,  305,    2, 0x06,   22 /* Public */,
      12,    1,  306,    2, 0x06,   23 /* Public */,
      14,    1,  309,    2, 0x06,   25 /* Public */,
      15,    1,  312,    2, 0x06,   27 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    0,  315,    2, 0x0a,   29 /* Public */,
      17,    1,  316,    2, 0x0a,   30 /* Public */,
      19,    0,  319,    2, 0x0a,   32 /* Public */,
      20,    1,  320,    2, 0x0a,   33 /* Public */,
      22,    1,  323,    2, 0x0a,   35 /* Public */,
      24,    0,  326,    2, 0x0a,   37 /* Public */,
      25,    1,  327,    2, 0x0a,   38 /* Public */,
      27,    1,  330,    2, 0x0a,   40 /* Public */,
      28,    3,  333,    2, 0x0a,   42 /* Public */,
      32,    2,  340,    2, 0x0a,   46 /* Public */,
      33,    2,  345,    2, 0x0a,   49 /* Public */,
      35,    0,  350,    2, 0x0a,   52 /* Public */,
      36,    0,  351,    2, 0x0a,   53 /* Public */,
      37,    0,  352,    2, 0x0a,   54 /* Public */,
      38,    1,  353,    2, 0x0a,   55 /* Public */,
      39,    0,  356,    2, 0x0a,   57 /* Public */,
      40,    0,  357,    2, 0x0a,   58 /* Public */,
      41,    0,  358,    2, 0x0a,   59 /* Public */,
      42,    1,  359,    2, 0x0a,   60 /* Public */,
      43,    1,  362,    2, 0x0a,   62 /* Public */,
      44,    1,  365,    2, 0x0a,   64 /* Public */,
      46,    0,  368,    2, 0x0a,   66 /* Public */,
      47,    2,  369,    2, 0x0a,   67 /* Public */,
      50,    3,  374,    2, 0x0a,   70 /* Public */,
      51,    1,  381,    2, 0x0a,   74 /* Public */,
      53,    0,  384,    2, 0x0a,   76 /* Public */,
      54,    1,  385,    2, 0x0a,   77 /* Public */,
      57,    1,  388,    2, 0x0a,   79 /* Public */,
      58,    0,  391,    2, 0x0a,   81 /* Public */,
      59,    0,  392,    2, 0x0a,   82 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   29,   30,   31,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   29,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   34,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   21,
    QMetaType::Void, 0x80000000 | 13,   21,
    QMetaType::Void, QMetaType::QString,   45,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   48,   49,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,   29,   30,   49,
    QMetaType::Bool, QMetaType::QString,   52,
    QMetaType::Void,
    0x80000000 | 55, QMetaType::QString,   56,
    QMetaType::Bool, QMetaType::QString,   52,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GraphWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGraphWidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGraphWidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGraphWidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GraphWidget, std::true_type>,
        // method 'sendVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendDFT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendBFT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendKruskal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendPrim'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendDelay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendRemoveVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sendRemoveEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'clear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendDataDSL'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<string, std::false_type>,
        // method 'sendNatural'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<string, std::false_type>,
        // method 'sendDirect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setDirect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setAPI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'executeNatural'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showNaturalToDSL'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DSLsetdirect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'executeDSL'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DSLaddVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DSLdelVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DSLaddEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DSLdelEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DSLSelect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'addVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeVertex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addEdge'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeEdge1'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'removeEdge2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearall'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'traverseGraph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showStruct'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<string, std::false_type>,
        // method 'showMatrix'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<string, std::false_type>,
        // method 'showResult'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'resetColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setVertexColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setEdgeColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>,
        // method 'saveData'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'saveFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findVertexByNumber'
        QtPrivate::TypeAndForceComplete<Vertex *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loadData'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'openFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDisplay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GraphWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GraphWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->sendEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->sendDFT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->sendBFT((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->sendKruskal((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sendPrim((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->sendDelay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->sendRemoveVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->sendRemoveEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 9: _t->clear(); break;
        case 10: _t->sendDataDSL((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 11: _t->sendNatural((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 12: _t->sendDirect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->setDirect(); break;
        case 14: _t->setAPI((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->executeNatural(); break;
        case 16: _t->showNaturalToDSL((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->DSLsetdirect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->executeDSL(); break;
        case 19: _t->DSLaddVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->DSLdelVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 21: _t->DSLaddEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 22: _t->DSLdelEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 23: _t->DSLSelect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 24: _t->addVertex(); break;
        case 25: _t->removeVertex(); break;
        case 26: _t->addEdge(); break;
        case 27: _t->removeEdge1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->removeEdge2(); break;
        case 29: _t->clearall(); break;
        case 30: _t->traverseGraph(); break;
        case 31: _t->showStruct((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 32: _t->showMatrix((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 33: _t->showResult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->resetColor(); break;
        case 35: _t->setVertexColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 36: _t->setEdgeColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 37: { bool _r = _t->saveData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: _t->saveFile(); break;
        case 39: { Vertex* _r = _t->findVertexByNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vertex**>(_a[0]) = std::move(_r); }  break;
        case 40: { bool _r = _t->loadData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 41: _t->openFile(); break;
        case 42: _t->updateDisplay(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendVertex; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString , QString , int );
            if (_t _q_method = &GraphWidget::sendEdge; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendDFT; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendBFT; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendKruskal; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendPrim; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(int );
            if (_t _q_method = &GraphWidget::sendDelay; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendRemoveVertex; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString , QString );
            if (_t _q_method = &GraphWidget::sendRemoveEdge; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)();
            if (_t _q_method = &GraphWidget::clear; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(string );
            if (_t _q_method = &GraphWidget::sendDataDSL; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(string );
            if (_t _q_method = &GraphWidget::sendNatural; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(int );
            if (_t _q_method = &GraphWidget::sendDirect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
    }
}

const QMetaObject *GraphWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGraphWidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GraphWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 43;
    }
    return _id;
}

// SIGNAL 0
void GraphWidget::sendVertex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphWidget::sendEdge(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphWidget::sendDFT(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphWidget::sendBFT(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphWidget::sendKruskal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GraphWidget::sendPrim(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GraphWidget::sendDelay(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GraphWidget::sendRemoveVertex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GraphWidget::sendRemoveEdge(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void GraphWidget::clear()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void GraphWidget::sendDataDSL(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GraphWidget::sendNatural(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void GraphWidget::sendDirect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
