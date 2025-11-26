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
    "sendMST",
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
    uint offsetsAndSizes[118];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[8];
    char stringdata5[8];
    char stringdata6[8];
    char stringdata7[10];
    char stringdata8[17];
    char stringdata9[15];
    char stringdata10[6];
    char stringdata11[12];
    char stringdata12[7];
    char stringdata13[12];
    char stringdata14[11];
    char stringdata15[10];
    char stringdata16[7];
    char stringdata17[7];
    char stringdata18[15];
    char stringdata19[17];
    char stringdata20[4];
    char stringdata21[13];
    char stringdata22[2];
    char stringdata23[11];
    char stringdata24[13];
    char stringdata25[2];
    char stringdata26[13];
    char stringdata27[11];
    char stringdata28[5];
    char stringdata29[3];
    char stringdata30[7];
    char stringdata31[11];
    char stringdata32[10];
    char stringdata33[2];
    char stringdata34[10];
    char stringdata35[13];
    char stringdata36[8];
    char stringdata37[12];
    char stringdata38[12];
    char stringdata39[9];
    char stringdata40[14];
    char stringdata41[11];
    char stringdata42[11];
    char stringdata43[11];
    char stringdata44[7];
    char stringdata45[11];
    char stringdata46[15];
    char stringdata47[7];
    char stringdata48[6];
    char stringdata49[13];
    char stringdata50[9];
    char stringdata51[9];
    char stringdata52[9];
    char stringdata53[19];
    char stringdata54[8];
    char stringdata55[7];
    char stringdata56[9];
    char stringdata57[9];
    char stringdata58[14];
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
        QT_MOC_LITERAL(49, 7),  // "sendMST"
        QT_MOC_LITERAL(57, 9),  // "sendDelay"
        QT_MOC_LITERAL(67, 16),  // "sendRemoveVertex"
        QT_MOC_LITERAL(84, 14),  // "sendRemoveEdge"
        QT_MOC_LITERAL(99, 5),  // "clear"
        QT_MOC_LITERAL(105, 11),  // "sendDataDSL"
        QT_MOC_LITERAL(117, 6),  // "string"
        QT_MOC_LITERAL(124, 11),  // "sendNatural"
        QT_MOC_LITERAL(136, 10),  // "sendDirect"
        QT_MOC_LITERAL(147, 9),  // "setDirect"
        QT_MOC_LITERAL(157, 6),  // "setAPI"
        QT_MOC_LITERAL(164, 6),  // "getapi"
        QT_MOC_LITERAL(171, 14),  // "executeNatural"
        QT_MOC_LITERAL(186, 16),  // "showNaturalToDSL"
        QT_MOC_LITERAL(203, 3),  // "str"
        QT_MOC_LITERAL(207, 12),  // "DSLsetdirect"
        QT_MOC_LITERAL(220, 1),  // "d"
        QT_MOC_LITERAL(222, 10),  // "executeDSL"
        QT_MOC_LITERAL(233, 12),  // "DSLaddVertex"
        QT_MOC_LITERAL(246, 1),  // "v"
        QT_MOC_LITERAL(248, 12),  // "DSLdelVertex"
        QT_MOC_LITERAL(261, 10),  // "DSLaddEdge"
        QT_MOC_LITERAL(272, 4),  // "from"
        QT_MOC_LITERAL(277, 2),  // "to"
        QT_MOC_LITERAL(280, 6),  // "weight"
        QT_MOC_LITERAL(287, 10),  // "DSLdelEdge"
        QT_MOC_LITERAL(298, 9),  // "DSLSelect"
        QT_MOC_LITERAL(308, 1),  // "s"
        QT_MOC_LITERAL(310, 9),  // "addVertex"
        QT_MOC_LITERAL(320, 12),  // "removeVertex"
        QT_MOC_LITERAL(333, 7),  // "addEdge"
        QT_MOC_LITERAL(341, 11),  // "removeEdge1"
        QT_MOC_LITERAL(353, 11),  // "removeEdge2"
        QT_MOC_LITERAL(365, 8),  // "clearall"
        QT_MOC_LITERAL(374, 13),  // "traverseGraph"
        QT_MOC_LITERAL(388, 10),  // "showStruct"
        QT_MOC_LITERAL(399, 10),  // "showMatrix"
        QT_MOC_LITERAL(410, 10),  // "showResult"
        QT_MOC_LITERAL(421, 6),  // "result"
        QT_MOC_LITERAL(428, 10),  // "resetColor"
        QT_MOC_LITERAL(439, 14),  // "setVertexColor"
        QT_MOC_LITERAL(454, 6),  // "vertex"
        QT_MOC_LITERAL(461, 5),  // "color"
        QT_MOC_LITERAL(467, 12),  // "setEdgeColor"
        QT_MOC_LITERAL(480, 8),  // "saveData"
        QT_MOC_LITERAL(489, 8),  // "fileName"
        QT_MOC_LITERAL(498, 8),  // "saveFile"
        QT_MOC_LITERAL(507, 18),  // "findVertexByNumber"
        QT_MOC_LITERAL(526, 7),  // "Vertex*"
        QT_MOC_LITERAL(534, 6),  // "number"
        QT_MOC_LITERAL(541, 8),  // "loadData"
        QT_MOC_LITERAL(550, 8),  // "openFile"
        QT_MOC_LITERAL(559, 13)   // "updateDisplay"
    },
    "GraphWidget",
    "sendVertex",
    "",
    "sendEdge",
    "sendDFT",
    "sendBFT",
    "sendMST",
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
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  266,    2, 0x06,    1 /* Public */,
       3,    3,  269,    2, 0x06,    3 /* Public */,
       4,    1,  276,    2, 0x06,    7 /* Public */,
       5,    1,  279,    2, 0x06,    9 /* Public */,
       6,    1,  282,    2, 0x06,   11 /* Public */,
       7,    1,  285,    2, 0x06,   13 /* Public */,
       8,    1,  288,    2, 0x06,   15 /* Public */,
       9,    2,  291,    2, 0x06,   17 /* Public */,
      10,    0,  296,    2, 0x06,   20 /* Public */,
      11,    1,  297,    2, 0x06,   21 /* Public */,
      13,    1,  300,    2, 0x06,   23 /* Public */,
      14,    1,  303,    2, 0x06,   25 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      15,    0,  306,    2, 0x0a,   27 /* Public */,
      16,    1,  307,    2, 0x0a,   28 /* Public */,
      18,    0,  310,    2, 0x0a,   30 /* Public */,
      19,    1,  311,    2, 0x0a,   31 /* Public */,
      21,    1,  314,    2, 0x0a,   33 /* Public */,
      23,    0,  317,    2, 0x0a,   35 /* Public */,
      24,    1,  318,    2, 0x0a,   36 /* Public */,
      26,    1,  321,    2, 0x0a,   38 /* Public */,
      27,    3,  324,    2, 0x0a,   40 /* Public */,
      31,    2,  331,    2, 0x0a,   44 /* Public */,
      32,    2,  336,    2, 0x0a,   47 /* Public */,
      34,    0,  341,    2, 0x0a,   50 /* Public */,
      35,    0,  342,    2, 0x0a,   51 /* Public */,
      36,    0,  343,    2, 0x0a,   52 /* Public */,
      37,    1,  344,    2, 0x0a,   53 /* Public */,
      38,    0,  347,    2, 0x0a,   55 /* Public */,
      39,    0,  348,    2, 0x0a,   56 /* Public */,
      40,    0,  349,    2, 0x0a,   57 /* Public */,
      41,    1,  350,    2, 0x0a,   58 /* Public */,
      42,    1,  353,    2, 0x0a,   60 /* Public */,
      43,    1,  356,    2, 0x0a,   62 /* Public */,
      45,    0,  359,    2, 0x0a,   64 /* Public */,
      46,    2,  360,    2, 0x0a,   65 /* Public */,
      49,    3,  365,    2, 0x0a,   68 /* Public */,
      50,    1,  372,    2, 0x0a,   72 /* Public */,
      52,    0,  375,    2, 0x0a,   74 /* Public */,
      53,    1,  376,    2, 0x0a,   75 /* Public */,
      56,    1,  379,    2, 0x0a,   77 /* Public */,
      57,    0,  382,    2, 0x0a,   79 /* Public */,
      58,    0,  383,    2, 0x0a,   80 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   28,   29,   30,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   28,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   33,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   20,
    QMetaType::Void, 0x80000000 | 12,   20,
    QMetaType::Void, QMetaType::QString,   44,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   47,   48,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,   28,   29,   48,
    QMetaType::Bool, QMetaType::QString,   51,
    QMetaType::Void,
    0x80000000 | 54, QMetaType::QString,   55,
    QMetaType::Bool, QMetaType::QString,   51,
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
        // method 'sendMST'
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
        case 4: _t->sendMST((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sendDelay((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->sendRemoveVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->sendRemoveEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->clear(); break;
        case 9: _t->sendDataDSL((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 10: _t->sendNatural((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 11: _t->sendDirect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->setDirect(); break;
        case 13: _t->setAPI((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->executeNatural(); break;
        case 15: _t->showNaturalToDSL((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->DSLsetdirect((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->executeDSL(); break;
        case 18: _t->DSLaddVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->DSLdelVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->DSLaddEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 21: _t->DSLdelEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 22: _t->DSLSelect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 23: _t->addVertex(); break;
        case 24: _t->removeVertex(); break;
        case 25: _t->addEdge(); break;
        case 26: _t->removeEdge1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 27: _t->removeEdge2(); break;
        case 28: _t->clearall(); break;
        case 29: _t->traverseGraph(); break;
        case 30: _t->showStruct((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 31: _t->showMatrix((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 32: _t->showResult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->resetColor(); break;
        case 34: _t->setVertexColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 35: _t->setEdgeColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 36: { bool _r = _t->saveData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->saveFile(); break;
        case 38: { Vertex* _r = _t->findVertexByNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vertex**>(_a[0]) = std::move(_r); }  break;
        case 39: { bool _r = _t->loadData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 40: _t->openFile(); break;
        case 41: _t->updateDisplay(); break;
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
            if (_t _q_method = &GraphWidget::sendMST; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(int );
            if (_t _q_method = &GraphWidget::sendDelay; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString );
            if (_t _q_method = &GraphWidget::sendRemoveVertex; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(QString , QString );
            if (_t _q_method = &GraphWidget::sendRemoveEdge; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)();
            if (_t _q_method = &GraphWidget::clear; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(string );
            if (_t _q_method = &GraphWidget::sendDataDSL; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(string );
            if (_t _q_method = &GraphWidget::sendNatural; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (GraphWidget::*)(int );
            if (_t _q_method = &GraphWidget::sendDirect; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
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
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 42;
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
void GraphWidget::sendMST(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GraphWidget::sendDelay(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void GraphWidget::sendRemoveVertex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void GraphWidget::sendRemoveEdge(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void GraphWidget::clear()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void GraphWidget::sendDataDSL(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void GraphWidget::sendNatural(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void GraphWidget::sendDirect(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
