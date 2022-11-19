#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <x86intrin.h>

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow (parent),
    ui (new Ui::MainWindow)
{
    ui->setupUi (this);
    createUI();     // 初始化串口相关配置
    setupPlot();    // 设置绘图区域，即X,Y轴范围等并连接控件槽
    /* Channel selection */
    connect (ui->plot, SIGNAL(selectionChangedByUser()), this, SLOT(channel_selection()));
    connect (&updateTimer, SIGNAL (timeout()), this, SLOT (replot()));   // 将计时器连接到replot插槽

    connect (ui->plot, SIGNAL(legendDoubleClick (QCPLegend*, QCPAbstractLegendItem*, QMouseEvent*)),
             this, SLOT(legend_double_click (QCPLegend*, QCPAbstractLegendItem*, QMouseEvent*)));


//    /* Wheel over plot when plotting */
//    connect (ui->plot, SIGNAL (mouseWheel (QWheelEvent*)), this, SLOT (onMouseWheelInPlot(QWheelEvent*)));

//    /* Slot for printing coordinates */
//    connect (ui->plot, SIGNAL (mouseMove (QMouseEvent*)), this, SLOT (onMouseMoveInPlot (QMouseEvent*)));

//    m_csvFile = nullptr;          // 用于保存图像
}

MainWindow::~MainWindow()
{
//    closeCsvFile();

//    if (serialPort != nullptr)
//    {
//        delete serialPort;
//    }

//    /* 此操作为保存对于端口的配置，并保存为config.ini文件 */
//    QSettings settings("config.ini", QSettings::IniFormat);
//    settings.setValue("com", ui->comboPort->currentText());
//    settings.setValue("baudrate",  ui->comboBaud->currentText());
//    settings.setValue("databits", ui->comboData->currentIndex());
//    settings.setValue("stopbits", ui->comboStop->currentIndex());
//    settings.setValue("paritybits", ui->comboParity->currentIndex());

    delete ui;
}

void MainWindow::createUI()
{
    /*判断是否有可用端口*/
    if (QSerialPortInfo::availablePorts().size() == 0)
    {
        enable_com_controls (false);
        ui->statusBar->showMessage ("无可用端口！");
        return;
    }

    /*获取端口名称*/
    for (QSerialPortInfo port : QSerialPortInfo::availablePorts())
    {
        ui->comboPort->addItem (port.portName());
    }

    /*波特率选项*/
    ui->comboBaud->addItem ("1200");
    ui->comboBaud->addItem ("2400");
    ui->comboBaud->addItem ("4800");
    ui->comboBaud->addItem ("9600");
    ui->comboBaud->addItem ("19200");
    ui->comboBaud->addItem ("38400");
    ui->comboBaud->addItem ("57600");
    ui->comboBaud->addItem ("115200");
    /*一些非标准波特率*/
    ui->comboBaud->addItem ("128000");
    ui->comboBaud->addItem ("153600");
    ui->comboBaud->addItem ("230400");
    ui->comboBaud->addItem ("256000");
    ui->comboBaud->addItem ("460800");
    ui->comboBaud->addItem ("921600");

    /*默认波特率为115200*/
    ui->comboBaud->setCurrentIndex (7);

    /*数据位选项*/
    ui->comboData->addItem ("8位");
    ui->comboData->addItem ("7位");

    /*校验选项*/
    ui->comboParity->addItem ("无校验");
    ui->comboParity->addItem ("奇校验");
    ui->comboParity->addItem ("偶校验");

    /* Populate stop bits combo box */
    ui->comboStop->addItem ("1位");
    ui->comboStop->addItem ("2位");

    /* Initialize the listwidget */
    ui->listWidget_Channels->clear();
    ui->comboPort->installEventFilter(this);

//    //创建config.ini文件用于保存端口相关设置
//    QFile file("config.ini");
//    if(!file.exists())
//    {
//        QSettings settings("config.ini", QSettings::IniFormat);
//        settings.setValue("com", "");
//        settings.setValue("baudrate", 115200);
//        settings.setValue("databits", 0);
//        settings.setValue("stopbits", 0);
//        settings.setValue("paritybits", 0);
//        settings.setValue("theme", "light");
//    }
//    QSettings settings("config.ini", QSettings::IniFormat);
//    int index = ui->comboPort->findText(settings.value("com").toString());
//    if(index >= 0)
//    {
//        ui->comboPort->setCurrentIndex(index);
//    }
//    ui->comboBaud->setCurrentText(settings.value("baudrate").toString());
//    ui->comboData->setCurrentIndex(settings.value("databits").toInt());
//    ui->comboStop->setCurrentIndex(settings.value("stopbits").toInt());
//    ui->comboParity->setCurrentIndex(settings.value("paritybits").toInt());

//    QString theme = settings.value("theme").toString();
//    if(theme == QString("light"))
//    {
//        gui_colors[0] = QColor (255,  255,  255,  255); /**<  0: qdark ui dark/background color */
//        gui_colors[1] = QColor (175,  175,  175,  255); /**<  0: qdark ui dark/background color */
//        gui_colors[2] = QColor (85,   85,   85,   255); /**<  0: qdark ui dark/background color */
//        gui_colors[3] = QColor (207,  208,  208,  200); /**<  0: qdark ui dark/background color */

//    }else if(theme == QString("dark"))
//    {
//        gui_colors[0] = QColor (48,  47,  47,  255); /**<  0: qdark ui dark/background color */
//        gui_colors[1] = QColor (80,  80,  80,  255); /**<  1: qdark ui medium/grid color */
//        gui_colors[2] = QColor (170, 170, 170, 255); /**<  2: qdark ui light/text color */
//        gui_colors[3] = QColor (48,  47,  47,  200); /**<  3: qdark ui dark/background color w/transparency */
//    }
}



void MainWindow::setupPlot()
{
    /* 清除曲线 */
    ui->plot->clearItems();

    /* 设置背景板颜色 */
    ui->plot->setBackground (gui_colors[0]);

    /* Used for higher performance (see QCustomPlot real time example) */
    ui->plot->setNotAntialiasedElements (QCP::aeAll);
    QFont font;
    font.setStyleStrategy (QFont::NoAntialias);
    ui->plot->legend->setFont (font);

    /** See QCustomPlot examples / styled demo **/
    /* X Axis: Style */
    // 函数setPen(QPen(gui_colors[2], 1, Qt::DotLine)参数
    // 第一个参数QPen(gui_colors[2]:颜色
    // 第二个参数为设置画笔的粗细
    // 第三个参数为画笔样式
    ui->plot->xAxis->grid()->setPen (QPen(gui_colors[2], 1, Qt::DotLine));        // 网格线(对应刻度)画笔
    ui->plot->xAxis->grid()->setSubGridPen (QPen(gui_colors[1], 1, Qt::DotLine)); // 轴子刻度线的画笔
    ui->plot->xAxis->grid()->setSubGridVisible (true);                            // 显示子网格线
    ui->plot->xAxis->setBasePen (QPen (gui_colors[2]));                           // 设置基础线画笔  基础线是零线，即可以认为是坐标轴刻度为0的线
    ui->plot->xAxis->setTickPen (QPen (gui_colors[2]));                           // 设置绘制的画笔
    ui->plot->xAxis->setSubTickPen (QPen (gui_colors[2]));                        // 设置小刻度画笔
    ui->plot->xAxis->setUpperEnding (QCPLineEnding::esSpikeArrow);                // 坐标轴箭头样式
    ui->plot->xAxis->setTickLabelColor (gui_colors[2]);                           // 设置文本颜色
    ui->plot->xAxis->setTickLabelFont (font);                                     // 设置文本字体
    /* x轴范围*/
    ui->plot->xAxis->setRange (dataPointNumber - ui->spinPoints->value(), dataPointNumber);

    /* Y Axis */
    ui->plot->yAxis->grid()->setPen (QPen(gui_colors[2], 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setSubGridPen (QPen(gui_colors[1], 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setSubGridVisible (true);
    ui->plot->yAxis->setBasePen (QPen (gui_colors[2]));
    ui->plot->yAxis->setTickPen (QPen (gui_colors[2]));
    ui->plot->yAxis->setSubTickPen (QPen (gui_colors[2]));
    ui->plot->yAxis->setUpperEnding (QCPLineEnding::esSpikeArrow);
    ui->plot->yAxis->setTickLabelColor (gui_colors[2]);
    ui->plot->yAxis->setTickLabelFont (font);
    /* y轴范围 */
    ui->plot->yAxis->setRange (ui->spinAxesMin->value(), ui->spinAxesMax->value());

    //ui->plot->yAxis->setAutoTickStep (false);                        //设置是否自动分配刻度间距
    ui->plot->yAxis->ticker()->setTickCount(ui->spinYStep->value());   //设置刻度间距

    /* 用户交互仅允许在X轴上拖动和缩放，Y轴由UI控件手动固定 */
    ui->plot->setInteraction (QCP::iRangeDrag, true);
    //ui->plot->setInteraction (QCP::iRangeZoom, true);
    ui->plot->setInteraction (QCP::iSelectPlottables, true);
    ui->plot->setInteraction (QCP::iSelectLegend, true);
    ui->plot->axisRect()->setRangeDrag (Qt::Horizontal);
    ui->plot->axisRect()->setRangeZoom (Qt::Horizontal);

    /* Legend */
    QFont legendFont;
    legendFont.setPointSize (9);
    ui->plot->legend->setVisible (true);
    ui->plot->legend->setFont (legendFont);
    ui->plot->legend->setBrush (gui_colors[3]);
    ui->plot->legend->setBorderPen (gui_colors[2]);
    /* By default, the legend is in the inset layout of the main axis rect. So this is how we access it to change legend placement */
    ui->plot->axisRect()->insetLayout()->setInsetAlignment (0, Qt::AlignTop|Qt::AlignRight);
}


void MainWindow::enable_com_controls (bool enable)
{
    /* 允许设置波特率等 */
    ui->comboBaud->setEnabled (enable);
    ui->comboData->setEnabled (enable);
    ui->comboParity->setEnabled (enable);
    ui->comboPort->setEnabled (enable);
    ui->comboStop->setEnabled (enable);


    ui->actionConnect->setEnabled (enable);
    ui->actionPause_Plot->setEnabled (!enable);
    ui->actionDisconnect->setEnabled (!enable);
}


/*
 * 打开串口，并连接
 * 相关参数
 * portInfo
 * baudRate
 * dataBits
 * parity
 * stopBits
 */

void MainWindow::openPort (QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
    serialPort = new QSerialPort(portInfo, nullptr); // 创建一个新的串口变量

    // 将信号与槽连接起来，信号为自主定义
    connect (this, SIGNAL(portOpenOK()), this, SLOT(portOpenedSuccess()));
    connect (this, SIGNAL(portOpenFail()), this, SLOT(portOpenedFail()));
    connect (this, SIGNAL(portClosed()), this, SLOT(onPortClosed()));
    connect (this, SIGNAL(newData(QStringList)), this, SLOT(onNewDataArrived(QStringList)));
    connect (serialPort, SIGNAL(readyRead()), this, SLOT(readData()));

    connect (this, SIGNAL(newData(QStringList)), this, SLOT(saveStream(QStringList)));

    if (serialPort->open (QIODevice::ReadWrite))
    {
        serialPort->setBaudRate (baudRate);
        serialPort->setParity (parity);
        serialPort->setDataBits (dataBits);
        serialPort->setStopBits (stopBits);
        emit portOpenOK();
    }
    else
    {
        emit portOpenedFail();
        qDebug() << serialPort->errorString();
    }
}
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*
 * 关闭串口
 */
void MainWindow::onPortClosed()
{
    //qDebug() << "Port closed signal received!";
    updateTimer.stop();
    connected = false;
    plotting = false;

    //--
    closeCsvFile();
    // 断开读取操作信号与槽的连接
    disconnect (serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
    disconnect (this, SIGNAL(portOpenOK()), this, SLOT(portOpenedSuccess()));
    disconnect (this, SIGNAL(portOpenFail()), this, SLOT(portOpenedFail()));
    disconnect (this, SIGNAL(portClosed()), this, SLOT(onPortClosed()));
    disconnect (this, SIGNAL(newData(QStringList)), this, SLOT(onNewDataArrived(QStringList)));

    disconnect (this, SIGNAL(newData(QStringList)), this, SLOT(saveStream(QStringList)));
}

/*
 * 更改组合框时显示所选端口的信息
 */
void MainWindow::on_comboPort_currentIndexChanged (const QString &arg1)
{
    QSerialPortInfo selectedPort (arg1);                                                   // Dislplay info for selected port
    ui->statusBar->showMessage (selectedPort.description());
}

/*
 * 端口成功打开则调用该函数
 */
void MainWindow::portOpenedSuccess()
{
    //qDebug() << "Port opened signal received!";
    setupPlot();                                                // 创建QCustomPlot，绘制图形边框，即坐标轴等相关信息
    ui->statusBar->showMessage ("端口打开成功!");
    enable_com_controls (false);                                // 打开端口后，不允许调节波特率等，断开连接选项启动

    if(ui->actionRecord_stream->isChecked())
    {
        //--> Create new CSV file with current date/timestamp
        openCsvFile();
    }
    /* Lock the save option while recording */
    ui->actionRecord_stream->setEnabled(false);

    updateTimer.start (20);                                      // 图表每秒刷新20次
    connected = true;                                            //设置连接状态、绘图状态为true;
    plotting = true;
}

/*
 * 串口打开失败
 */
void MainWindow::portOpenedFail()
{
    qDebug() << "Port cannot be open signal received!";
    ui->statusBar->showMessage ("打开失败，请检查该端口是否存在或被占用!");
}

/*
 * 设置x坐标范围
 */
void MainWindow::replot()
{
    ui->plot->xAxis->setRange (dataPointNumber - ui->spinPoints->value(), dataPointNumber);
    ui->plot->replot();
}

/*
 * y轴最小值设置
 */
void MainWindow::on_spinAxesMin_valueChanged(int arg1)
{
    ui->plot->yAxis->setRangeLower (arg1);
    ui->plot->replot();
}

/*
 * y轴最大值设置
 */
void MainWindow::on_spinAxesMax_valueChanged(int arg1)
{
    ui->plot->yAxis->setRangeUpper (arg1);
    ui->plot->replot();
}

/*
 * 接收到新数据时调用的槽函数
 */
void MainWindow::onNewDataArrived(QStringList newData)
{
    static int data_members = 0;
    static int channel = 0;
    static int i = 0;
    volatile bool you_shall_NOT_PASS = false;

    /* When a fast baud rate is set (921kbps was the first to starts to bug),
       this method is called multiple times (2x in the 921k tests), so a flag
       is used to throttle
       TO-DO: Separate processes, buffer data (1) and process data (2) */
    while (you_shall_NOT_PASS) {}
    you_shall_NOT_PASS = true;

    if (plotting)
    {
        // 获取数据的长度
        data_members = newData.size();

        // 分析数据
        for (i = 0; i < data_members; i++)
        {
            /* Update number of axes if needed */
            while (ui->plot->plottableCount() <= channel)
            {
                /* Add new channel data */
                ui->plot->addGraph();
                ui->plot->graph()->setPen (line_colors[channels % CUSTOM_LINE_COLORS]);
                ui->plot->graph()->setName (QString("Channel %1").arg(channels));
                if(ui->plot->legend->item(channels))
                {
                    ui->plot->legend->item (channels)->setTextColor (line_colors[channels % CUSTOM_LINE_COLORS]);
                }
                ui->listWidget_Channels->addItem(ui->plot->graph()->name());
                ui->listWidget_Channels->item(channel)->setForeground(QBrush(line_colors[channels % CUSTOM_LINE_COLORS]));
                channels++;
            }

            /* [TODO] Method selection and plotting */
            /* X-Y */
            if (0)
            {

            }
            /* Rolling (v1.0.0 compatible) */
            else
            {
                /* Add data to Graph 0 */
                ui->plot->graph(channel)->addData (dataPointNumber, newData[channel].toDouble());
                /* Increment data number and channel */
                channel++;
            }
        }

        /* Post-parsing */
        /* X-Y */
        if (0)
        {

        }
        /* Rolling (v1.0.0 compatible) */
        else
        {
            dataPointNumber++;
            channel = 0;
        }
    }
    you_shall_NOT_PASS = false;
}

/*
 * 利用信号readyRead，通过串口读取数据
 */
void MainWindow::readData()
{
    if(serialPort->bytesAvailable())
    {                                                    // 串口存在可用字节
        QByteArray data = serialPort->readAll();         // 读取所有字节保存在QByteArray data

        if(!data.isEmpty())
        {                                                // 字节数组不为空
            char *temp = data.data();                    // 获取串口发送终止符'\0'
            if (!filterDisplayedData)
            {
                ui->textEdit_UartWindow->append(data);
            }
            for(int i = 0; temp[i] != '\0'; i++)         // 遍历字符
            {
                switch(STATE)                            // 根据当前信息状态进行相应的操作
                {
                    case WAIT_START:                         // 检查信息是否为所需要的
                        if(temp[i] == START_MSG)             // 如果检测到开始信号符'$'，转换状态
                        {
                            STATE = IN_MESSAGE;
                            receivedData.clear();            // 清除保存消息的临时QString
                            break;
                        }
                        break;

                    case IN_MESSAGE:                         // 已经检测到开始符'$'
                        if(temp[i] == END_MSG)               // 若开始符'$'后为停止符';'
                        {                                    // 状态切换为等待下一次开始
                            STATE = WAIT_START;
                            QStringList incomingData = receivedData.split(' '); //拆分从端口接收的字符串并将其放入列表
                            if(filterDisplayedData)
                            {
                                ui->textEdit_UartWindow->append(receivedData);
                            }
                            emit newData(incomingData);      // 发出与列表一起接收的数据的信号
                            break;
                        }
                        // isdigit是计算机C(C++)语言中的一个函数，主要用于检查其参数是否为十进制数字字符
                        // 计算机函数，主要用于检查参数c是否为空白字符。
                        else if (isdigit (temp[i]) || isspace (temp[i]) || temp[i] =='-' || temp[i] =='.')
                        {
                        // 如果检查的字符是数字，而不是“$”或“；”，将其附加到临时字符串
                            receivedData.append(temp[i]);
                        }
                        break;
                    default: break;
                }
            }
        }
    }
}

//void MainWindow::on_comboAxes_currentIndexChanged(int index)
//{
//    if(index == 0) {
//      ui->statusBar->showMessage("Axis 1: Red");
//    } else if(index == 1) {
//        ui->statusBar->showMessage("Axis 1: Red; Axis 2: Yellow");
//    } else {
//        ui->statusBar->showMessage("Axis 1: Red; Axis 2: Yellow; Axis 3: Green");
//    }
//}
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*
 * Y轴刻度更改
 */
void MainWindow::on_spinYStep_valueChanged(int arg1)
{
    ui->plot->yAxis->ticker()->setTickCount(arg1);
    ui->plot->replot();
    ui->spinYStep->setValue(ui->plot->yAxis->ticker()->tickCount());
}

/*
 * 将绘图的PNG图像保存到当前EXE目录
 */
void MainWindow::on_savePNGButton_clicked()
{
    ui->plot->savePng (QString::number(dataPointNumber) + ".png", 1920, 1080, 2, 50);
}

/*
 * 打印鼠标坐标
 */
void MainWindow::onMouseMoveInPlot(QMouseEvent *event)
{
    int xx = int(ui->plot->xAxis->pixelToCoord(event->x()));
    int yy = int(ui->plot->yAxis->pixelToCoord(event->y()));
    QString coordinates("X: %1 Y: %2");
    coordinates = coordinates.arg(xx).arg(yy);
    ui->statusBar->showMessage(coordinates);
}

/*
 * @brief Send plot wheelmouse to spinbox
 * @param event
 */
void MainWindow::onMouseWheelInPlot(QWheelEvent *event)
{
    QWheelEvent inverted_event = QWheelEvent(event->posF(), event->globalPosF(),
                                             -event->pixelDelta(), -event->angleDelta(),
                                             0, Qt::Vertical, event->buttons(), event->modifiers());
    QApplication::sendEvent (ui->spinPoints, &inverted_event);
}
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/**
 * @brief Select both line and legend (channel)
 * @param plottable
 * @param event
 */
void MainWindow::channel_selection (void)
{
    /* synchronize selection of graphs with selection of corresponding legend items */
    for (int i = 0; i < ui->plot->graphCount(); i++)
    {
        QCPGraph *graph = ui->plot->graph(i);
        QCPPlottableLegendItem *item = ui->plot->legend->itemWithPlottable (graph);
        if (item->selected())
        {
            item->setSelected (true);
            //          graph->set (true);
        }
        else
        {
            item->setSelected (false);
            //        graph->setSelected (false);
        }
    }
}

// 双击更改图表名称
void MainWindow::legend_double_click(QCPLegend *legend, QCPAbstractLegendItem *item, QMouseEvent *event)
{
    Q_UNUSED (legend)
    Q_UNUSED(event)
    // 只有在项目被点击时才做出反应
    if (item)
    {
        QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item);
        bool ok;
#if 0
        //QString newName = QInputDialog::getText (this, "设置通道名称", "名称:", QLineEdit::Normal, plItem->plottable()->name(), &ok, Qt::Popup);
#else
        QString newName;
        QInputDialog dialog;
        dialog.setWindowFlags(Qt::FramelessWindowHint);  // 隐藏顶部标题栏,无框显示
        dialog.setTextEchoMode(QLineEdit::Normal);
        dialog.setLabelText("名称:");
        dialog.setOkButtonText("确定");
        dialog.setCancelButtonText("取消");
        if(dialog.exec() == QDialog::Accepted)
        {
            ok = true;
            newName = dialog.textValue();
        }else
        {
            ok = false;
        }
#endif
        if (ok)
        {
            plItem->plottable()->setName(newName);
            for(int i=0; i<ui->plot->graphCount(); i++)
            {
                ui->listWidget_Channels->item(i)->setText(ui->plot->graph(i)->name());
            }
            ui->plot->replot();
        }
    }
}
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/**
 * @brief Spin box controls how many data points are collected and displayed
 * @param arg1
 */
void MainWindow::on_spinPoints_valueChanged (int arg1)
{
    Q_UNUSED(arg1)
    ui->plot->xAxis->setRange (dataPointNumber - ui->spinPoints->value(), dataPointNumber);
    ui->plot->replot();
}
/** ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*
 * 软件使用参考说明
 */
void MainWindow::on_actionHow_to_use_triggered()
{
//    helpWindow = new HelpWindow (this);
//    helpWindow->setWindowTitle ("本软件使用方法");
//    helpWindow->show();
}

/* 该函数为总体开关，启动时检测设备工作状态,该函数与createUI()联合查看
 * connected:该变量类型为bool，设备连接成功为1，否则为0
 * plotting: 该变量类型为bool，设备若正在绘图为1，否则为0
 * updateTimer为QTimer定义的一个定时器，当开始绘图时则开始计时
 */
void MainWindow::on_actionConnect_triggered()
{
    if (connected)
    {
        /* 设备处于连接状态 */
        if (!plotting)      //判断图像是否正在绘制
        {
            updateTimer.start();  // 打开绘图定时器
            plotting = true;
            ui->actionConnect->setEnabled (false);
            ui->actionPause_Plot->setEnabled (true);
            ui->statusBar->showMessage ("开始绘制!");
        }
    }
    else
    {
        /*设备未连接，进行连接操作*/
        /* 第一步，从各个控件获取相关参数
         * 包括串口名称，波特率，数据位，是否校验，停止位等等
         * 以下操作与串口调试助手雷同，直接读取即可

         * 利用QSerialPortInfo获取有关可用端口信息，该类允许枚举系统
         * 该类允许枚举系统中的所有串行端口
        */
        QSerialPortInfo portInfo (ui->comboPort->currentText());
        int baudRate = ui->comboBaud->currentText().toInt(); // 从控件中读取波特率，并将其转换为int形式
        int dataBitsIndex = ui->comboData->currentIndex();   // 从控件中读取数据位，并和下方switch联用
        int parityIndex = ui->comboParity->currentIndex();   // 读取校验位，并和下方switch联用
        int stopBitsIndex = ui->comboStop->currentIndex();   // 读取停止位，并和下方switch联用
        QSerialPort::DataBits dataBits;    // 定义一个用于控制数据位的参数
        QSerialPort::Parity parity;        // 定义一个用于控制校验位的参数
        QSerialPort::StopBits stopBits;    // 定义一个用于控制停止位的参数

        /* 设置串口数据位 */
        switch (dataBitsIndex)
        {
        case 0:
            dataBits = QSerialPort::Data8;
            break;
        default:
            dataBits = QSerialPort::Data7;
        }

        /* 通过获取的parityIndex设置校验位*/
        switch (parityIndex)
        {
        case 0:
            parity = QSerialPort::NoParity;
            break;
        case 1:
            parity = QSerialPort::OddParity;
            break;
        default:
            parity = QSerialPort::EvenParity;
        }

        /* 停止位设置*/
        switch (stopBitsIndex)
        {
        case 0:
            stopBits = QSerialPort::OneStop;
            break;
        default:
            stopBits = QSerialPort::TwoStop;
        }

        /* 创建串口变量 */
        serialPort = new QSerialPort (portInfo, nullptr);

        /* 打开串口 */
        openPort (portInfo, baudRate, dataBits, parity, stopBits);
    }
}

/*
 * 该函数为停止函数，当图标正在绘制时，停止绘图
 * plotting:该变量类型为bool，设备若正在绘图为1，否则为0
 * updateTimer:定时器，绘制时启动，否则关闭
 */
void MainWindow::on_actionPause_Plot_triggered()
{
    if (plotting)
    {
        updateTimer.stop();
        plotting = false;
        ui->actionConnect->setEnabled (true);
        ui->actionPause_Plot->setEnabled (false);
        ui->statusBar->showMessage ("暂停绘制，新数据将被忽略！");
    }
}

/*
 * 断开串口
 * connected:该变量类型为bool，设备连接成功为1，否则为0
 * receivedData: QString类型，用于接收数据
 */
void MainWindow::on_actionDisconnect_triggered()
{
    if (connected)
    {
        /*
         * 以下串口关闭操作与串口调试助手类似，直接套用即可
         */
        serialPort->close();          // 关闭串口，断开连接
        emit portClosed();            // 发出串口关闭的信号，该信号为自己定义的
        delete serialPort;            // 回收new分配的内存空间
        serialPort = nullptr;         // 设置指针为空

        ui->statusBar->showMessage ("关闭端口!");

        connected = false;            // 串口连接状态设置为 0
        ui->actionConnect->setEnabled (true);

        plotting = false;             // 图表绘制状态设置为 0
        ui->actionPause_Plot->setEnabled (false);
        ui->actionDisconnect->setEnabled (false);
        ui->actionRecord_stream->setEnabled(true);
        receivedData.clear();         // 清除已接收的数据

        enable_com_controls (true);   //断开串口，允许重新设定波特率等
    }
}

/*
 * 该函数功能为图表清除函数
 * dataPointNumber: int类型，可理解为绘制的第X条曲线
   channels: int类型，字面意思
 */
void MainWindow::on_actionClear_triggered()
{
    ui->plot->clearPlottables();
    ui->listWidget_Channels->clear();
    channels = 0;
    dataPointNumber = 0;
    emit setupPlot();   // 设置plot坐标轴等
    ui->plot->replot(); // 下次绘图时重头开始
}



/*
 * 数据接收框显示与关闭
 */
void MainWindow::on_pushButton_TextEditHide_clicked()
{
    if(ui->pushButton_TextEditHide->isChecked())
    {
        ui->textEdit_UartWindow->setVisible(false);
        ui->pushButton_TextEditHide->setText("显示接收框");
    }
    else
    {
        ui->textEdit_UartWindow->setVisible(true);
        ui->pushButton_TextEditHide->setText("隐藏接收框");
    }
}

/*
 * 原始数据的展示与关闭选择
 * filterDisplayedData: 变量类型bool，表示当前数据展示的状态
 */
void MainWindow::on_pushButton_ShowallData_clicked()
{
    if(ui->pushButton_ShowallData->isChecked())
    {
        filterDisplayedData = false;
        ui->pushButton_ShowallData->setText("显示过滤数据");
    }
    else
    {
        filterDisplayedData = true;
        ui->pushButton_ShowallData->setText("显示原始数据");
    }
}

/*
 * Y轴自适应函数
 */
void MainWindow::on_pushButton_AutoScale_clicked()
{
    ui->plot->yAxis->rescale(true);  //qcustomplot的自动缩放函数
    // 用于设置y轴的范围
    ui->spinAxesMax->setValue(int(ui->plot->yAxis->range().upper) + int(ui->plot->yAxis->range().upper*0.1));
    ui->spinAxesMin->setValue(int(ui->plot->yAxis->range().lower) + int(ui->plot->yAxis->range().lower*0.1));
}

void MainWindow::on_pushButton_ResetVisible_clicked()
{
    for(int i=0; i<ui->plot->graphCount(); i++)
    {
        ui->plot->graph(i)->setVisible(true);
        ui->listWidget_Channels->item(i)->setBackground(Qt::NoBrush);
    }
}

void MainWindow::on_listWidget_Channels_itemDoubleClicked(QListWidgetItem *item)
{
    int graphIdx = ui->listWidget_Channels->currentRow();

    if(ui->plot->graph(graphIdx)->visible())
    {
        ui->plot->graph(graphIdx)->setVisible(false);
        item->setBackground(Qt::black);
    }
    else
    {
        ui->plot->graph(graphIdx)->setVisible(true);
        item->setBackground(Qt::NoBrush);
    }
    ui->plot->replot();
}

void MainWindow::on_pushButton_ClearRecv_clicked()
{
    ui->textEdit_UartWindow->clear();
}


/*
 * 保存图表，此时串口保持开启，但停止绘图
 */
void MainWindow::on_actionRecord_stream_triggered()
{
    if (ui->actionRecord_stream->isChecked())
    {
        ui->statusBar->showMessage ("数据将保存到csv格式文件中！");
    }
    else
    {
        ui->statusBar->showMessage ("数据将不在保存到csv格式文件中！");
    }
}

/*
 * 打开已保存的图像
 */
void MainWindow::openCsvFile(void)
{
    QString filename = QApplication::applicationDirPath() + "/" + QDateTime::currentDateTime().toString("yyyy-MM-d-HH-mm-ss-")+"data-out.csv";
    m_csvFile = new QFile(filename);
    if(!m_csvFile)
        return;
    if (!m_csvFile->open(QIODevice::ReadWrite | QIODevice::Text))
        return;
}

/*
 *
 */
void MainWindow::closeCsvFile(void)
{
    if(!m_csvFile) return;
    m_csvFile->close();
    if(m_csvFile) delete m_csvFile;
    m_csvFile = nullptr;
}

/**
 * @brief Open a new CSV file to save received data
 *
 */
void MainWindow::saveStream(QStringList newData)
{
    if(!m_csvFile)
        return;
    if(ui->actionRecord_stream->isChecked())
    {
        QTextStream out(m_csvFile);
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss") << ",";
        foreach (const QString &str, newData) {
            out << str << ",";
        }
        out << "\n";
    }
}

void MainWindow::on_actionOpenPath_triggered()
{
    // 打开应用程序所在目录
    QDesktopServices::openUrl(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + "/"));
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        if(watched == ui->comboPort)
        {
            QComboBox* comboBox = qobject_cast<QComboBox *>(watched);

            comboBox->clear();

            QList<QSerialPortInfo> serials = QSerialPortInfo::availablePorts();
            foreach (QSerialPortInfo info, serials)
            {
                comboBox->addItem(info.portName());
            }
        }
    }
    return QMainWindow::eventFilter(watched, event);
}
