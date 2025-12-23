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
    "setweight",
    "sendDijkstra",
    "setSpeechCred",
    "appid",
    "token",
    "onVoicePressed",
    "onVoiceReleased",
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
    "setWeight",
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
    "showDijkstraTable",
    "tableStr",
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
    uint offsetsAndSizes[140];
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
    char stringdata17[13];
    char stringdata18[14];
    char stringdata19[6];
    char stringdata20[6];
    char stringdata21[15];
    char stringdata22[16];
    char stringdata23[10];
    char stringdata24[7];
    char stringdata25[7];
    char stringdata26[15];
    char stringdata27[17];
    char stringdata28[4];
    char stringdata29[13];
    char stringdata30[2];
    char stringdata31[11];
    char stringdata32[13];
    char stringdata33[2];
    char stringdata34[13];
    char stringdata35[11];
    char stringdata36[5];
    char stringdata37[3];
    char stringdata38[7];
    char stringdata39[11];
    char stringdata40[10];
    char stringdata41[2];
    char stringdata42[10];
    char stringdata43[13];
    char stringdata44[8];
    char stringdata45[10];
    char stringdata46[12];
    char stringdata47[12];
    char stringdata48[9];
    char stringdata49[14];
    char stringdata50[11];
    char stringdata51[11];
    char stringdata52[11];
    char stringdata53[7];
    char stringdata54[11];
    char stringdata55[15];
    char stringdata56[7];
    char stringdata57[6];
    char stringdata58[13];
    char stringdata59[18];
    char stringdata60[9];
    char stringdata61[9];
    char stringdata62[9];
    char stringdata63[9];
    char stringdata64[19];
    char stringdata65[8];
    char stringdata66[7];
    char stringdata67[9];
    char stringdata68[9];
    char stringdata69[14];
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
        QT_MOC_LITERAL(160, 9),  // "setweight"
        QT_MOC_LITERAL(170, 12),  // "sendDijkstra"
        QT_MOC_LITERAL(183, 13),  // "setSpeechCred"
        QT_MOC_LITERAL(197, 5),  // "appid"
        QT_MOC_LITERAL(203, 5),  // "token"
        QT_MOC_LITERAL(209, 14),  // "onVoicePressed"
        QT_MOC_LITERAL(224, 15),  // "onVoiceReleased"
        QT_MOC_LITERAL(240, 9),  // "setDirect"
        QT_MOC_LITERAL(250, 6),  // "setAPI"
        QT_MOC_LITERAL(257, 6),  // "getapi"
        QT_MOC_LITERAL(264, 14),  // "executeNatural"
        QT_MOC_LITERAL(279, 16),  // "showNaturalToDSL"
        QT_MOC_LITERAL(296, 3),  // "str"
        QT_MOC_LITERAL(300, 12),  // "DSLsetdirect"
        QT_MOC_LITERAL(313, 1),  // "d"
        QT_MOC_LITERAL(315, 10),  // "executeDSL"
        QT_MOC_LITERAL(326, 12),  // "DSLaddVertex"
        QT_MOC_LITERAL(339, 1),  // "v"
        QT_MOC_LITERAL(341, 12),  // "DSLdelVertex"
        QT_MOC_LITERAL(354, 10),  // "DSLaddEdge"
        QT_MOC_LITERAL(365, 4),  // "from"
        QT_MOC_LITERAL(370, 2),  // "to"
        QT_MOC_LITERAL(373, 6),  // "weight"
        QT_MOC_LITERAL(380, 10),  // "DSLdelEdge"
        QT_MOC_LITERAL(391, 9),  // "DSLSelect"
        QT_MOC_LITERAL(401, 1),  // "s"
        QT_MOC_LITERAL(403, 9),  // "addVertex"
        QT_MOC_LITERAL(413, 12),  // "removeVertex"
        QT_MOC_LITERAL(426, 7),  // "addEdge"
        QT_MOC_LITERAL(434, 9),  // "setWeight"
        QT_MOC_LITERAL(444, 11),  // "removeEdge1"
        QT_MOC_LITERAL(456, 11),  // "removeEdge2"
        QT_MOC_LITERAL(468, 8),  // "clearall"
        QT_MOC_LITERAL(477, 13),  // "traverseGraph"
        QT_MOC_LITERAL(491, 10),  // "showStruct"
        QT_MOC_LITERAL(502, 10),  // "showMatrix"
        QT_MOC_LITERAL(513, 10),  // "showResult"
        QT_MOC_LITERAL(524, 6),  // "result"
        QT_MOC_LITERAL(531, 10),  // "resetColor"
        QT_MOC_LITERAL(542, 14),  // "setVertexColor"
        QT_MOC_LITERAL(557, 6),  // "vertex"
        QT_MOC_LITERAL(564, 5),  // "color"
        QT_MOC_LITERAL(570, 12),  // "setEdgeColor"
        QT_MOC_LITERAL(583, 17),  // "showDijkstraTable"
        QT_MOC_LITERAL(601, 8),  // "tableStr"
        QT_MOC_LITERAL(610, 8),  // "saveData"
        QT_MOC_LITERAL(619, 8),  // "fileName"
        QT_MOC_LITERAL(628, 8),  // "saveFile"
        QT_MOC_LITERAL(637, 18),  // "findVertexByNumber"
        QT_MOC_LITERAL(656, 7),  // "Vertex*"
        QT_MOC_LITERAL(664, 6),  // "number"
        QT_MOC_LITERAL(671, 8),  // "loadData"
        QT_MOC_LITERAL(680, 8),  // "openFile"
        QT_MOC_LITERAL(689, 13)   // "updateDisplay"
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
    "setweight",
    "sendDijkstra",
    "setSpeechCred",
    "appid",
    "token",
    "onVoicePressed",
    "onVoiceReleased",
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
    "setWeight",
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
    "showDijkstraTable",
    "tableStr",
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
      50,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  314,    2, 0x06,    1 /* Public */,
       3,    3,  317,    2, 0x06,    3 /* Public */,
       4,    1,  324,    2, 0x06,    7 /* Public */,
       5,    1,  327,    2, 0x06,    9 /* Public */,
       6,    1,  330,    2, 0x06,   11 /* Public */,
       7,    1,  333,    2, 0x06,   13 /* Public */,
       8,    1,  336,    2, 0x06,   15 /* Public */,
       9,    1,  339,    2, 0x06,   17 /* Public */,
      10,    2,  342,    2, 0x06,   19 /* Public */,
      11,    0,  347,    2, 0x06,   22 /* Public */,
      12,    1,  348,    2, 0x06,   23 /* Public */,
      14,    1,  351,    2, 0x06,   25 /* Public */,
      15,    1,  354,    2, 0x06,   27 /* Public */,
      16,    3,  357,    2, 0x06,   29 /* Public */,
      17,    1,  364,    2, 0x06,   33 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    2,  367,    2, 0x0a,   35 /* Public */,
      21,    0,  372,    2, 0x0a,   38 /* Public */,
      22,    0,  373,    2, 0x0a,   39 /* Public */,
      23,    0,  374,    2, 0x0a,   40 /* Public */,
      24,    1,  375,    2, 0x0a,   41 /* Public */,
      26,    0,  378,    2, 0x0a,   43 /* Public */,
      27,    1,  379,    2, 0x0a,   44 /* Public */,
      29,    1,  382,    2, 0x0a,   46 /* Public */,
      31,    0,  385,    2, 0x0a,   48 /* Public */,
      32,    1,  386,    2, 0x0a,   49 /* Public */,
      34,    1,  389,    2, 0x0a,   51 /* Public */,
      35,    3,  392,    2, 0x0a,   53 /* Public */,
      39,    2,  399,    2, 0x0a,   57 /* Public */,
      40,    2,  404,    2, 0x0a,   60 /* Public */,
      42,    0,  409,    2, 0x0a,   63 /* Public */,
      43,    0,  410,    2, 0x0a,   64 /* Public */,
      44,    0,  411,    2, 0x0a,   65 /* Public */,
      45,    3,  412,    2, 0x0a,   66 /* Public */,
      46,    1,  419,    2, 0x0a,   70 /* Public */,
      47,    0,  422,    2, 0x0a,   72 /* Public */,
      48,    0,  423,    2, 0x0a,   73 /* Public */,
      49,    0,  424,    2, 0x0a,   74 /* Public */,
      50,    1,  425,    2, 0x0a,   75 /* Public */,
      51,    1,  428,    2, 0x0a,   77 /* Public */,
      52,    1,  431,    2, 0x0a,   79 /* Public */,
      54,    0,  434,    2, 0x0a,   81 /* Public */,
      55,    2,  435,    2, 0x0a,   82 /* Public */,
      58,    3,  440,    2, 0x0a,   85 /* Public */,
      59,    1,  447,    2, 0x0a,   89 /* Public */,
      61,    1,  450,    2, 0x0a,   91 /* Public */,
      63,    0,  453,    2, 0x0a,   93 /* Public */,
      64,    1,  454,    2, 0x0a,   94 /* Public */,
      67,    1,  457,    2, 0x0a,   96 /* Public */,
      68,    0,  460,    2, 0x0a,   98 /* Public */,
      69,    0,  461,    2, 0x0a,   99 /* Public */,

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
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   36,   37,   38,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   36,   37,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   41,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,   36,   37,   38,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   28,
    QMetaType::Void, 0x80000000 | 13,   28,
    QMetaType::Void, QMetaType::QString,   53,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   56,   57,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,   36,   37,   57,
    QMetaType::Void, QMetaType::QString,   60,
    QMetaType::Bool, QMetaType::QString,   62,
    QMetaType::Void,
    0x80000000 | 65, QMetaType::QString,   66,
    QMetaType::Bool, QMetaType::QString,   62,
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
        // method 'setweight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendDijkstra'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'setSpeechCred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'onVoicePressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onVoiceReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        // method 'setWeight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
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
        // method 'showDijkstraTable'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
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
        case 13: _t->setweight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->sendDijkstra((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->setSpeechCred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: _t->onVoicePressed(); break;
        case 17: _t->onVoiceReleased(); break;
        case 18: _t->setDirect(); break;
        case 19: _t->setAPI((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->executeNatural(); break;
        case 21: _t->showNaturalToDSL((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 22: _t->DSLsetdirect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->executeDSL(); break;
        case 24: _t->DSLaddVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 25: _t->DSLdelVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->DSLaddEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 27: _t->DSLdelEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 28: _t->DSLSelect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 29: _t->addVertex(); break;
        case 30: _t->removeVertex(); break;
        case 31: _t->addEdge(); break;
        case 32: _t->setWeight((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 33: _t->removeEdge1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->removeEdge2(); break;
        case 35: _t->clearall(); break;
        case 36: _t->traverseGraph(); break;
        case 37: _t->showStruct((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 38: _t->showMatrix((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 39: _t->showResult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 40: _t->resetColor(); break;
        case 41: _t->setVertexColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 42: _t->setEdgeColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 43: _t->showDijkstraTable((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 44: { bool _r = _t->saveData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 45: _t->saveFile(); break;
        case 46: { Vertex* _r = _t->findVertexByNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vertex**>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->loadData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: _t->openFile(); break;
        case 49: _t->updateDisplay(); break;
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
        {
            using _t = void (GraphWidget::*)(QString , QString , int );
            if (_t _q_method = &GraphWidget::setweight; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendDijkstra; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
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
        if (_id < 50)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 50;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 50)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 50;
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

// SIGNAL 13
void GraphWidget::setweight(QString _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void GraphWidget::sendDijkstra(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}
QT_WARNING_POP
