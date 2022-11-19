/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../scope/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[49];
    char stringdata0[932];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "portOpenFail"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "portOpenOK"
QT_MOC_LITERAL(4, 36, 10), // "portClosed"
QT_MOC_LITERAL(5, 47, 7), // "newData"
QT_MOC_LITERAL(6, 55, 4), // "data"
QT_MOC_LITERAL(7, 60, 32), // "on_comboPort_currentIndexChanged"
QT_MOC_LITERAL(8, 93, 4), // "arg1"
QT_MOC_LITERAL(9, 98, 17), // "portOpenedSuccess"
QT_MOC_LITERAL(10, 116, 14), // "portOpenedFail"
QT_MOC_LITERAL(11, 131, 12), // "onPortClosed"
QT_MOC_LITERAL(12, 144, 6), // "replot"
QT_MOC_LITERAL(13, 151, 16), // "onNewDataArrived"
QT_MOC_LITERAL(14, 168, 10), // "saveStream"
QT_MOC_LITERAL(15, 179, 27), // "on_spinAxesMin_valueChanged"
QT_MOC_LITERAL(16, 207, 27), // "on_spinAxesMax_valueChanged"
QT_MOC_LITERAL(17, 235, 8), // "readData"
QT_MOC_LITERAL(18, 244, 25), // "on_spinYStep_valueChanged"
QT_MOC_LITERAL(19, 270, 24), // "on_savePNGButton_clicked"
QT_MOC_LITERAL(20, 295, 17), // "onMouseMoveInPlot"
QT_MOC_LITERAL(21, 313, 12), // "QMouseEvent*"
QT_MOC_LITERAL(22, 326, 5), // "event"
QT_MOC_LITERAL(23, 332, 26), // "on_spinPoints_valueChanged"
QT_MOC_LITERAL(24, 359, 18), // "onMouseWheelInPlot"
QT_MOC_LITERAL(25, 378, 12), // "QWheelEvent*"
QT_MOC_LITERAL(26, 391, 17), // "channel_selection"
QT_MOC_LITERAL(27, 409, 19), // "legend_double_click"
QT_MOC_LITERAL(28, 429, 10), // "QCPLegend*"
QT_MOC_LITERAL(29, 440, 6), // "legend"
QT_MOC_LITERAL(30, 447, 22), // "QCPAbstractLegendItem*"
QT_MOC_LITERAL(31, 470, 4), // "item"
QT_MOC_LITERAL(32, 475, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(33, 502, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(34, 532, 29), // "on_actionHow_to_use_triggered"
QT_MOC_LITERAL(35, 562, 29), // "on_actionPause_Plot_triggered"
QT_MOC_LITERAL(36, 592, 24), // "on_actionClear_triggered"
QT_MOC_LITERAL(37, 617, 32), // "on_actionRecord_stream_triggered"
QT_MOC_LITERAL(38, 650, 34), // "on_pushButton_TextEditHide_cl..."
QT_MOC_LITERAL(39, 685, 33), // "on_pushButton_ShowallData_cli..."
QT_MOC_LITERAL(40, 719, 31), // "on_pushButton_AutoScale_clicked"
QT_MOC_LITERAL(41, 751, 34), // "on_pushButton_ResetVisible_cl..."
QT_MOC_LITERAL(42, 786, 40), // "on_listWidget_Channels_itemDo..."
QT_MOC_LITERAL(43, 827, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(44, 844, 31), // "on_pushButton_ClearRecv_clicked"
QT_MOC_LITERAL(45, 876, 27), // "on_actionOpenPath_triggered"
QT_MOC_LITERAL(46, 904, 11), // "eventFilter"
QT_MOC_LITERAL(47, 916, 7), // "watched"
QT_MOC_LITERAL(48, 924, 7) // "QEvent*"

    },
    "MainWindow\0portOpenFail\0\0portOpenOK\0"
    "portClosed\0newData\0data\0"
    "on_comboPort_currentIndexChanged\0arg1\0"
    "portOpenedSuccess\0portOpenedFail\0"
    "onPortClosed\0replot\0onNewDataArrived\0"
    "saveStream\0on_spinAxesMin_valueChanged\0"
    "on_spinAxesMax_valueChanged\0readData\0"
    "on_spinYStep_valueChanged\0"
    "on_savePNGButton_clicked\0onMouseMoveInPlot\0"
    "QMouseEvent*\0event\0on_spinPoints_valueChanged\0"
    "onMouseWheelInPlot\0QWheelEvent*\0"
    "channel_selection\0legend_double_click\0"
    "QCPLegend*\0legend\0QCPAbstractLegendItem*\0"
    "item\0on_actionConnect_triggered\0"
    "on_actionDisconnect_triggered\0"
    "on_actionHow_to_use_triggered\0"
    "on_actionPause_Plot_triggered\0"
    "on_actionClear_triggered\0"
    "on_actionRecord_stream_triggered\0"
    "on_pushButton_TextEditHide_clicked\0"
    "on_pushButton_ShowallData_clicked\0"
    "on_pushButton_AutoScale_clicked\0"
    "on_pushButton_ResetVisible_clicked\0"
    "on_listWidget_Channels_itemDoubleClicked\0"
    "QListWidgetItem*\0on_pushButton_ClearRecv_clicked\0"
    "on_actionOpenPath_triggered\0eventFilter\0"
    "watched\0QEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x06 /* Public */,
       3,    0,  190,    2, 0x06 /* Public */,
       4,    0,  191,    2, 0x06 /* Public */,
       5,    1,  192,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  195,    2, 0x08 /* Private */,
       9,    0,  198,    2, 0x08 /* Private */,
      10,    0,  199,    2, 0x08 /* Private */,
      11,    0,  200,    2, 0x08 /* Private */,
      12,    0,  201,    2, 0x08 /* Private */,
      13,    1,  202,    2, 0x08 /* Private */,
      14,    1,  205,    2, 0x08 /* Private */,
      15,    1,  208,    2, 0x08 /* Private */,
      16,    1,  211,    2, 0x08 /* Private */,
      17,    0,  214,    2, 0x08 /* Private */,
      18,    1,  215,    2, 0x08 /* Private */,
      19,    0,  218,    2, 0x08 /* Private */,
      20,    1,  219,    2, 0x08 /* Private */,
      23,    1,  222,    2, 0x08 /* Private */,
      24,    1,  225,    2, 0x08 /* Private */,
      26,    0,  228,    2, 0x08 /* Private */,
      27,    3,  229,    2, 0x08 /* Private */,
      32,    0,  236,    2, 0x08 /* Private */,
      33,    0,  237,    2, 0x08 /* Private */,
      34,    0,  238,    2, 0x08 /* Private */,
      35,    0,  239,    2, 0x08 /* Private */,
      36,    0,  240,    2, 0x08 /* Private */,
      37,    0,  241,    2, 0x08 /* Private */,
      38,    0,  242,    2, 0x08 /* Private */,
      39,    0,  243,    2, 0x08 /* Private */,
      40,    0,  244,    2, 0x08 /* Private */,
      41,    0,  245,    2, 0x08 /* Private */,
      42,    1,  246,    2, 0x08 /* Private */,
      44,    0,  249,    2, 0x08 /* Private */,
      45,    0,  250,    2, 0x08 /* Private */,
      46,    2,  251,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::QStringList,    5,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 25,   22,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28, 0x80000000 | 30, 0x80000000 | 21,   29,   31,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 43,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 48,   47,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->portOpenFail(); break;
        case 1: _t->portOpenOK(); break;
        case 2: _t->portClosed(); break;
        case 3: _t->newData((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->on_comboPort_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->portOpenedSuccess(); break;
        case 6: _t->portOpenedFail(); break;
        case 7: _t->onPortClosed(); break;
        case 8: _t->replot(); break;
        case 9: _t->onNewDataArrived((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 10: _t->saveStream((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 11: _t->on_spinAxesMin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_spinAxesMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->readData(); break;
        case 14: _t->on_spinYStep_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_savePNGButton_clicked(); break;
        case 16: _t->onMouseMoveInPlot((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 17: _t->on_spinPoints_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->onMouseWheelInPlot((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 19: _t->channel_selection(); break;
        case 20: _t->legend_double_click((*reinterpret_cast< QCPLegend*(*)>(_a[1])),(*reinterpret_cast< QCPAbstractLegendItem*(*)>(_a[2])),(*reinterpret_cast< QMouseEvent*(*)>(_a[3]))); break;
        case 21: _t->on_actionConnect_triggered(); break;
        case 22: _t->on_actionDisconnect_triggered(); break;
        case 23: _t->on_actionHow_to_use_triggered(); break;
        case 24: _t->on_actionPause_Plot_triggered(); break;
        case 25: _t->on_actionClear_triggered(); break;
        case 26: _t->on_actionRecord_stream_triggered(); break;
        case 27: _t->on_pushButton_TextEditHide_clicked(); break;
        case 28: _t->on_pushButton_ShowallData_clicked(); break;
        case 29: _t->on_pushButton_AutoScale_clicked(); break;
        case 30: _t->on_pushButton_ResetVisible_clicked(); break;
        case 31: _t->on_listWidget_Channels_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 32: _t->on_pushButton_ClearRecv_clicked(); break;
        case 33: _t->on_actionOpenPath_triggered(); break;
        case 34: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAbstractLegendItem* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPLegend* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::portOpenFail)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::portOpenOK)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::portClosed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::newData)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::portOpenFail()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::portOpenOK()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::portClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::newData(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
