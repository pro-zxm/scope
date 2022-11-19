#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QtSerialPort>
#include <QSerialPortInfo>
#include "qcustomplot.h"
#include "ui_mainwindow.h"

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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboPort_currentIndexChanged(const QString &arg1);                           // Slot displays message on status bar
    void portOpenedSuccess();                                                             // Called when port opens OK
    void portOpenedFail();                                                                // Called when port fails to open
    void onPortClosed();                                                                  // Called when closing the port
    void replot();                                                                        // Slot for repainting the plot
    void onNewDataArrived(QStringList newData);                                           // Slot for new data from serial port
    void saveStream(QStringList newData);                                                 // Save the received data to the opened file
    void on_spinAxesMin_valueChanged(int arg1);                                           // Changing lower limit for the plot
    void on_spinAxesMax_valueChanged(int arg1);                                           // Changing upper limit for the plot
    void readData();                                                                      // Slot for inside serial port
    //void on_comboAxes_currentIndexChanged(int index);                                     // Display number of axes and colors in status bar
    void on_spinYStep_valueChanged(int arg1);                                             // Spin box for changing Y axis tick step
    void on_savePNGButton_clicked();                                                      // Button for saving JPG
    void onMouseMoveInPlot (QMouseEvent *event);                                          // Displays coordinates of mouse pointer when clicked in plot in status bar
    void on_spinPoints_valueChanged (int arg1);                                           // Spin box controls how many data points are collected and displayed
    void onMouseWheelInPlot(QWheelEvent *event);                                     // Makes wheel mouse works while plotting

    /* Used when a channel is selected (plot or legend) */
    void channel_selection (void);
    void legend_double_click (QCPLegend *legend, QCPAbstractLegendItem *item, QMouseEvent *event);

    void on_actionConnect_triggered();
    void on_actionDisconnect_triggered();
    void on_actionHow_to_use_triggered();
    void on_actionPause_Plot_triggered();
    void on_actionClear_triggered();
    void on_actionRecord_stream_triggered();

    void on_pushButton_TextEditHide_clicked();

    void on_pushButton_ShowallData_clicked();

    void on_pushButton_AutoScale_clicked();

    void on_pushButton_ResetVisible_clicked();

    void on_listWidget_Channels_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_ClearRecv_clicked();

    void on_actionOpenPath_triggered();

    bool eventFilter(QObject *watched, QEvent *event);

signals:        // 定义自己想要定义的信号
    void portOpenFail();                   // 串口打开失败信号
    void portOpenOK();                     // 串口打开成功信号
    void portClosed();                     // 串口关闭信号
    void newData(QStringList data);        // 新数据到达信号

private:
    Ui::MainWindow *ui;
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
    bool connected = false;        // 反映设备连接状态
    bool plotting = false;         // 反映设备绘图状态
    int dataPointNumber = 0;       // 接受到的点数
    int channels = 0;                  // 通道代码

    /* 数据格式 */
    int data_format;

    /* Textbox Related */
    bool filterDisplayedData = true;

    /* Listview Related */
    QStringListModel *channelListModel;
    QStringList     channelStrList;

    //-- CSV file to save data
    QFile* m_csvFile = nullptr;
    void openCsvFile(void);
    void closeCsvFile(void);

    QTimer updateTimer;          // QTimer定义一个定时器，当开始绘图时则开始计时
    QTime timeOfFirstData;       // Record the time of the first data point
    double timeBetweenSamples;   // Store time between samples
    QSerialPort *serialPort = nullptr;     // 端口
    QString receivedData;        // Used for reading from the port
    int STATE = WAIT_START;      // 从端口接收消息的状态
    int NUMBER_OF_POINTS = 500;                                                                 // Number of points plotted

    void createUI();                                                                      // Populate the controls
    void enable_com_controls (bool enable);                                               // Enable/disable controls
    void setupPlot();                                                                     // Setup the QCustomPlot
                                                                                          // Open the inside serial port with these parameters
    void openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits);
};
#endif // MAINWINDOW_H
