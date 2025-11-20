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
    "str",
    "showMatrix",
    "showResult",
    "result",
    "resetColor",
    "setVertexColor",
    "vertex",
    "color",
    "setEdgeColor",
    "changeEdgeArrow",
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
    uint offsetsAndSizes[102];
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
    char stringdata13[11];
    char stringdata14[13];
    char stringdata15[2];
    char stringdata16[13];
    char stringdata17[11];
    char stringdata18[5];
    char stringdata19[3];
    char stringdata20[7];
    char stringdata21[11];
    char stringdata22[10];
    char stringdata23[2];
    char stringdata24[10];
    char stringdata25[13];
    char stringdata26[8];
    char stringdata27[12];
    char stringdata28[12];
    char stringdata29[9];
    char stringdata30[14];
    char stringdata31[11];
    char stringdata32[4];
    char stringdata33[11];
    char stringdata34[11];
    char stringdata35[7];
    char stringdata36[11];
    char stringdata37[15];
    char stringdata38[7];
    char stringdata39[6];
    char stringdata40[13];
    char stringdata41[16];
    char stringdata42[9];
    char stringdata43[9];
    char stringdata44[9];
    char stringdata45[19];
    char stringdata46[8];
    char stringdata47[7];
    char stringdata48[9];
    char stringdata49[9];
    char stringdata50[14];
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
        QT_MOC_LITERAL(124, 10),  // "executeDSL"
        QT_MOC_LITERAL(135, 12),  // "DSLaddVertex"
        QT_MOC_LITERAL(148, 1),  // "v"
        QT_MOC_LITERAL(150, 12),  // "DSLdelVertex"
        QT_MOC_LITERAL(163, 10),  // "DSLaddEdge"
        QT_MOC_LITERAL(174, 4),  // "from"
        QT_MOC_LITERAL(179, 2),  // "to"
        QT_MOC_LITERAL(182, 6),  // "weight"
        QT_MOC_LITERAL(189, 10),  // "DSLdelEdge"
        QT_MOC_LITERAL(200, 9),  // "DSLSelect"
        QT_MOC_LITERAL(210, 1),  // "s"
        QT_MOC_LITERAL(212, 9),  // "addVertex"
        QT_MOC_LITERAL(222, 12),  // "removeVertex"
        QT_MOC_LITERAL(235, 7),  // "addEdge"
        QT_MOC_LITERAL(243, 11),  // "removeEdge1"
        QT_MOC_LITERAL(255, 11),  // "removeEdge2"
        QT_MOC_LITERAL(267, 8),  // "clearall"
        QT_MOC_LITERAL(276, 13),  // "traverseGraph"
        QT_MOC_LITERAL(290, 10),  // "showStruct"
        QT_MOC_LITERAL(301, 3),  // "str"
        QT_MOC_LITERAL(305, 10),  // "showMatrix"
        QT_MOC_LITERAL(316, 10),  // "showResult"
        QT_MOC_LITERAL(327, 6),  // "result"
        QT_MOC_LITERAL(334, 10),  // "resetColor"
        QT_MOC_LITERAL(345, 14),  // "setVertexColor"
        QT_MOC_LITERAL(360, 6),  // "vertex"
        QT_MOC_LITERAL(367, 5),  // "color"
        QT_MOC_LITERAL(373, 12),  // "setEdgeColor"
        QT_MOC_LITERAL(386, 15),  // "changeEdgeArrow"
        QT_MOC_LITERAL(402, 8),  // "saveData"
        QT_MOC_LITERAL(411, 8),  // "fileName"
        QT_MOC_LITERAL(420, 8),  // "saveFile"
        QT_MOC_LITERAL(429, 18),  // "findVertexByNumber"
        QT_MOC_LITERAL(448, 7),  // "Vertex*"
        QT_MOC_LITERAL(456, 6),  // "number"
        QT_MOC_LITERAL(463, 8),  // "loadData"
        QT_MOC_LITERAL(472, 8),  // "openFile"
        QT_MOC_LITERAL(481, 13)   // "updateDisplay"
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
    "str",
    "showMatrix",
    "showResult",
    "result",
    "resetColor",
    "setVertexColor",
    "vertex",
    "color",
    "setEdgeColor",
    "changeEdgeArrow",
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
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  230,    2, 0x06,    1 /* Public */,
       3,    3,  233,    2, 0x06,    3 /* Public */,
       4,    1,  240,    2, 0x06,    7 /* Public */,
       5,    1,  243,    2, 0x06,    9 /* Public */,
       6,    1,  246,    2, 0x06,   11 /* Public */,
       7,    1,  249,    2, 0x06,   13 /* Public */,
       8,    1,  252,    2, 0x06,   15 /* Public */,
       9,    2,  255,    2, 0x06,   17 /* Public */,
      10,    0,  260,    2, 0x06,   20 /* Public */,
      11,    1,  261,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    0,  264,    2, 0x0a,   23 /* Public */,
      14,    1,  265,    2, 0x0a,   24 /* Public */,
      16,    1,  268,    2, 0x0a,   26 /* Public */,
      17,    3,  271,    2, 0x0a,   28 /* Public */,
      21,    2,  278,    2, 0x0a,   32 /* Public */,
      22,    2,  283,    2, 0x0a,   35 /* Public */,
      24,    0,  288,    2, 0x0a,   38 /* Public */,
      25,    0,  289,    2, 0x0a,   39 /* Public */,
      26,    0,  290,    2, 0x0a,   40 /* Public */,
      27,    1,  291,    2, 0x0a,   41 /* Public */,
      28,    0,  294,    2, 0x0a,   43 /* Public */,
      29,    0,  295,    2, 0x0a,   44 /* Public */,
      30,    0,  296,    2, 0x0a,   45 /* Public */,
      31,    1,  297,    2, 0x0a,   46 /* Public */,
      33,    1,  300,    2, 0x0a,   48 /* Public */,
      34,    1,  303,    2, 0x0a,   50 /* Public */,
      36,    0,  306,    2, 0x0a,   52 /* Public */,
      37,    2,  307,    2, 0x0a,   53 /* Public */,
      40,    3,  312,    2, 0x0a,   56 /* Public */,
      41,    0,  319,    2, 0x0a,   60 /* Public */,
      42,    1,  320,    2, 0x0a,   61 /* Public */,
      44,    0,  323,    2, 0x0a,   63 /* Public */,
      45,    1,  324,    2, 0x0a,   64 /* Public */,
      48,    1,  327,    2, 0x0a,   66 /* Public */,
      49,    0,  330,    2, 0x0a,   68 /* Public */,
      50,    0,  331,    2, 0x0a,   69 /* Public */,

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

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   18,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   23,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   32,
    QMetaType::Void, 0x80000000 | 12,   32,
    QMetaType::Void, QMetaType::QString,   35,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   38,   39,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,   18,   19,   39,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   43,
    QMetaType::Void,
    0x80000000 | 46, QMetaType::QString,   47,
    QMetaType::Bool, QMetaType::QString,   43,
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
        // method 'changeEdgeArrow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 10: _t->executeDSL(); break;
        case 11: _t->DSLaddVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->DSLdelVertex((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->DSLaddEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 14: _t->DSLdelEdge((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->DSLSelect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 16: _t->addVertex(); break;
        case 17: _t->removeVertex(); break;
        case 18: _t->addEdge(); break;
        case 19: _t->removeEdge1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->removeEdge2(); break;
        case 21: _t->clearall(); break;
        case 22: _t->traverseGraph(); break;
        case 23: _t->showStruct((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 24: _t->showMatrix((*reinterpret_cast< std::add_pointer_t<string>>(_a[1]))); break;
        case 25: _t->showResult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 26: _t->resetColor(); break;
        case 27: _t->setVertexColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 28: _t->setEdgeColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 29: _t->changeEdgeArrow(); break;
        case 30: { bool _r = _t->saveData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 31: _t->saveFile(); break;
        case 32: { Vertex* _r = _t->findVertexByNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vertex**>(_a[0]) = std::move(_r); }  break;
        case 33: { bool _r = _t->loadData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->openFile(); break;
        case 35: _t->updateDisplay(); break;
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
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 36;
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
QT_WARNING_POP
