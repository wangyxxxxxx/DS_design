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
    "addVertex",
    "removeVertex",
    "addEdge",
    "removeEdge1",
    "v",
    "removeEdge2",
    "showStruct",
    "s",
    "traverseGraph",
    "showResult",
    "result",
    "resetColor",
    "setVertexColor",
    "vertex",
    "color",
    "setEdgeColor",
    "from",
    "to",
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
    uint offsetsAndSizes[76];
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
    char stringdata10[10];
    char stringdata11[13];
    char stringdata12[8];
    char stringdata13[12];
    char stringdata14[2];
    char stringdata15[12];
    char stringdata16[11];
    char stringdata17[2];
    char stringdata18[14];
    char stringdata19[11];
    char stringdata20[7];
    char stringdata21[11];
    char stringdata22[15];
    char stringdata23[7];
    char stringdata24[6];
    char stringdata25[13];
    char stringdata26[5];
    char stringdata27[3];
    char stringdata28[16];
    char stringdata29[9];
    char stringdata30[9];
    char stringdata31[9];
    char stringdata32[19];
    char stringdata33[8];
    char stringdata34[7];
    char stringdata35[9];
    char stringdata36[9];
    char stringdata37[14];
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
        QT_MOC_LITERAL(99, 9),  // "addVertex"
        QT_MOC_LITERAL(109, 12),  // "removeVertex"
        QT_MOC_LITERAL(122, 7),  // "addEdge"
        QT_MOC_LITERAL(130, 11),  // "removeEdge1"
        QT_MOC_LITERAL(142, 1),  // "v"
        QT_MOC_LITERAL(144, 11),  // "removeEdge2"
        QT_MOC_LITERAL(156, 10),  // "showStruct"
        QT_MOC_LITERAL(167, 1),  // "s"
        QT_MOC_LITERAL(169, 13),  // "traverseGraph"
        QT_MOC_LITERAL(183, 10),  // "showResult"
        QT_MOC_LITERAL(194, 6),  // "result"
        QT_MOC_LITERAL(201, 10),  // "resetColor"
        QT_MOC_LITERAL(212, 14),  // "setVertexColor"
        QT_MOC_LITERAL(227, 6),  // "vertex"
        QT_MOC_LITERAL(234, 5),  // "color"
        QT_MOC_LITERAL(240, 12),  // "setEdgeColor"
        QT_MOC_LITERAL(253, 4),  // "from"
        QT_MOC_LITERAL(258, 2),  // "to"
        QT_MOC_LITERAL(261, 15),  // "changeEdgeArrow"
        QT_MOC_LITERAL(277, 8),  // "saveData"
        QT_MOC_LITERAL(286, 8),  // "fileName"
        QT_MOC_LITERAL(295, 8),  // "saveFile"
        QT_MOC_LITERAL(304, 18),  // "findVertexByNumber"
        QT_MOC_LITERAL(323, 7),  // "Vertex*"
        QT_MOC_LITERAL(331, 6),  // "number"
        QT_MOC_LITERAL(338, 8),  // "loadData"
        QT_MOC_LITERAL(347, 8),  // "openFile"
        QT_MOC_LITERAL(356, 13)   // "updateDisplay"
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
    "addVertex",
    "removeVertex",
    "addEdge",
    "removeEdge1",
    "v",
    "removeEdge2",
    "showStruct",
    "s",
    "traverseGraph",
    "showResult",
    "result",
    "resetColor",
    "setVertexColor",
    "vertex",
    "color",
    "setEdgeColor",
    "from",
    "to",
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
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  170,    2, 0x06,    1 /* Public */,
       3,    3,  173,    2, 0x06,    3 /* Public */,
       4,    1,  180,    2, 0x06,    7 /* Public */,
       5,    1,  183,    2, 0x06,    9 /* Public */,
       6,    1,  186,    2, 0x06,   11 /* Public */,
       7,    1,  189,    2, 0x06,   13 /* Public */,
       8,    1,  192,    2, 0x06,   15 /* Public */,
       9,    2,  195,    2, 0x06,   17 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  200,    2, 0x0a,   20 /* Public */,
      11,    0,  201,    2, 0x0a,   21 /* Public */,
      12,    0,  202,    2, 0x0a,   22 /* Public */,
      13,    1,  203,    2, 0x0a,   23 /* Public */,
      15,    0,  206,    2, 0x0a,   25 /* Public */,
      16,    1,  207,    2, 0x0a,   26 /* Public */,
      18,    0,  210,    2, 0x0a,   28 /* Public */,
      19,    1,  211,    2, 0x0a,   29 /* Public */,
      21,    0,  214,    2, 0x0a,   31 /* Public */,
      22,    2,  215,    2, 0x0a,   32 /* Public */,
      25,    3,  220,    2, 0x0a,   35 /* Public */,
      28,    0,  227,    2, 0x0a,   39 /* Public */,
      29,    1,  228,    2, 0x0a,   40 /* Public */,
      31,    0,  231,    2, 0x0a,   42 /* Public */,
      32,    1,  232,    2, 0x0a,   43 /* Public */,
      35,    1,  235,    2, 0x0a,   45 /* Public */,
      36,    0,  238,    2, 0x0a,   47 /* Public */,
      37,    0,  239,    2, 0x0a,   48 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   23,   24,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QColor,   26,   27,   24,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   30,
    QMetaType::Void,
    0x80000000 | 33, QMetaType::QString,   34,
    QMetaType::Bool, QMetaType::QString,   30,
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
        // method 'showStruct'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'traverseGraph'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
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
        case 8: _t->addVertex(); break;
        case 9: _t->removeVertex(); break;
        case 10: _t->addEdge(); break;
        case 11: _t->removeEdge1((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->removeEdge2(); break;
        case 13: _t->showStruct((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->traverseGraph(); break;
        case 15: _t->showResult((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->resetColor(); break;
        case 17: _t->setVertexColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 18: _t->setEdgeColor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[3]))); break;
        case 19: _t->changeEdgeArrow(); break;
        case 20: { bool _r = _t->saveData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: _t->saveFile(); break;
        case 22: { Vertex* _r = _t->findVertexByNumber((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vertex**>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->loadData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->openFile(); break;
        case 25: _t->updateDisplay(); break;
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
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
QT_WARNING_POP
