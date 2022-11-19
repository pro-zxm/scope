#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include "qcustomplot.h"
#include "ui_mainwindow.h"
#include "helpwindow.h"

#define START_MSG       '$'
#define END_MSG         ';'

#define WAIT_START      1
#define IN_MESSAGE      2
#define UNDEFINED       3

#define CUSTOM_LINE_COLORS   14
#define GCP_CUSTOM_LINE_COLORS 4

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    HelpWindow *helpWindow;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboPort_currentIndexChanged(const QString &arg1);// 更改组合框时显示所选端口的信息
    void portOpenedSuccess();                                  // 端口成功打开则调用该函数
    void portOpenedFail();                                     // 串口打开失败
    void onPortClosed();                                       // 关闭串口
    void replot();                                             // 设置x坐标范围
    void UpdateTime();
    void onNewDataArrived(QStringList newData);                // 接收到新数据时调用的槽函数
    void on_spinAxesMin_valueChanged(int arg1);                // y轴最小值设置
    void on_spinAxesMax_valueChanged(int arg1);                // y轴最大值设置
    void readData();                                           // 利用信号readyRead，通过串口读取数据
    void on_spinYStep_valueChanged(int arg1);                  // Y轴刻度更改
    void on_savePNGButton_clicked();                           // 将绘图的PNG图像保存到当前EXE目录
    void onMouseMoveInPlot (QMouseEvent *event);               // 打印鼠标坐标
    void on_spinPoints_valueChanged (int arg1);                // 设置曲线点数
    void onMouseWheelInPlot(QWheelEvent *event);               // 将绘图滚轮鼠标发送到spinbox

    void channel_selection (void);
                                                               // 双击更改图表名称
    void legend_double_click (QCPLegend *legend, QCPAbstractLegendItem *item, QMouseEvent *event);
    void on_actionConnect_triggered();                         // 总体开关
    void on_actionDisconnect_triggered();                      // 断开串口
    void on_actionHow_to_use_triggered();
    void on_actionPause_Plot_triggered();
    void on_actionClear_triggered();

    void on_pushButton_TextEditHide_clicked();

    void on_pushButton_ShowallData_clicked();

    void on_pushButton_AutoScale_clicked();

    void on_listWidget_Channels_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_ClearRecv_clicked();

signals:        // 定义自己想要定义的信号
    void portOpenFail();                   // 串口打开失败信号
    void portOpenOK();                     // 串口打开成功信号
    void portClosed();                     // 串口关闭信号
    void newData(QStringList data);        // 新数据到达信号

private:
    Ui::MainWindow *ui;
    bool connected = false;        // 反映设备连接状态
    bool plotting = false;         // 反映设备绘图状态
    int dataPointNumber = 0;       // 接受到的点数
    int channels = 0;              // 通道代码

    /* 数据格式 */
    int data_format;

    bool filterDisplayedData = true;

    /* Listview Related */
    QStringListModel *channelListModel;
    QStringList     channelStrList;

    QTimer updateTimer;          // QTimer定义一个定时器，当开始绘图时则开始计时
    QDateTime m_dateTime;
    QTimer timer;
    QSerialPort *serialPort = nullptr;     // 端口
    QString receivedData;        // 接收数据
    int STATE = WAIT_START;      // 从端口接收消息的状态
    int NUMBER_OF_POINTS = 500;

    void createUI();
    void enable_com_controls (bool enable);
    void setupPlot();
    void openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits);
    QColor line_colors[CUSTOM_LINE_COLORS] =
    {
        /* 定义曲线颜色*/
        QColor ("#fb4934"),
        QColor ("#b8bb26"),
        QColor ("#fabd2f"),
        QColor ("#83a598"),
        QColor ("#d3869b"),
        QColor ("#8ec07c"),
        QColor ("#fe8019"),
        /* Light */
        QColor ("#cc241d"),
        QColor ("#98971a"),
        QColor ("#d79921"),
        QColor ("#458588"),
        QColor ("#b16286"),
        QColor ("#689d6a"),
        QColor ("#d65d0e"),
    };
    QColor gui_colors[GCP_CUSTOM_LINE_COLORS] =
    {
    #if 0
        /* Monochromatic for axes and ui */
        QColor (48,  47,  47,  255), /**<  0: qdark ui dark/background color */
        QColor (80,  80,  80,  255), /**<  1: qdark ui medium/grid color */
        QColor (170, 170, 170, 255), /**<  2: qdark ui light/text color */
        QColor (48,  47,  47,  200)  /**<  3: qdark ui dark/background color w/transparency */
    #else
        /* Monochromatic for axes and ui */
        QColor (255,  255,  255,  255), /**<  0: qdark ui dark/background color */
        QColor (175,  175,  175,  255), /**<  1: qdark ui medium/grid color */
        QColor (85,   85,   85,   255), /**<  2: qdark ui light/text color */
        QColor (207,  208,  208,  200)  /**<  3: qdark ui dark/background color w/transparency */
    #endif
    };
};
#endif // MAINWINDOW_H
