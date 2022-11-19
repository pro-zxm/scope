/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionPause_Plot;
    QAction *actionDisconnect;
    QAction *actionClear;
    QAction *actionHow_to_use;
    QAction *actionRecord_stream;
    QAction *actionOpenPath;
    QWidget *centralwidget;
    QGroupBox *PortControlsBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelPort;
    QComboBox *comboPort;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelBaud;
    QComboBox *comboBaud;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelData;
    QComboBox *comboData;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelStop;
    QComboBox *comboStop;
    QHBoxLayout *horizontalLayout;
    QLabel *labelParity;
    QComboBox *comboParity;
    QGroupBox *PlotControlsBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *pointsLabel;
    QSpinBox *spinPoints;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelYStep;
    QSpinBox *spinYStep;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QSpinBox *spinAxesMin;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_2;
    QSpinBox *spinAxesMax;
    QPushButton *pushButton_AutoScale;
    QListWidget *listWidget_Channels;
    QPushButton *pushButton_ResetVisible;
    QPushButton *savePNGButton;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_TextEditHide;
    QPushButton *pushButton_ShowallData;
    QPushButton *pushButton_ClearRecv;
    QTextEdit *textEdit_UartWindow;
    QCustomPlot *plot;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(950, 750);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ico/connect.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionPause_Plot = new QAction(MainWindow);
        actionPause_Plot->setObjectName(QString::fromUtf8("actionPause_Plot"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/ico/stop sign.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause_Plot->setIcon(icon1);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionHow_to_use = new QAction(MainWindow);
        actionHow_to_use->setObjectName(QString::fromUtf8("actionHow_to_use"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHow_to_use->setIcon(icon4);
        actionRecord_stream = new QAction(MainWindow);
        actionRecord_stream->setObjectName(QString::fromUtf8("actionRecord_stream"));
        actionRecord_stream->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecord_stream->setIcon(icon5);
        actionOpenPath = new QAction(MainWindow);
        actionOpenPath->setObjectName(QString::fromUtf8("actionOpenPath"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenPath->setIcon(icon6);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        PortControlsBox = new QGroupBox(centralwidget);
        PortControlsBox->setObjectName(QString::fromUtf8("PortControlsBox"));
        PortControlsBox->setGeometry(QRect(10, 30, 210, 174));
        PortControlsBox->setMaximumSize(QSize(220, 16777215));
        PortControlsBox->setFlat(false);
        PortControlsBox->setCheckable(false);
        widget = new QWidget(PortControlsBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(11, 26, 190, 141));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelPort = new QLabel(widget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));

        horizontalLayout_5->addWidget(labelPort);

        comboPort = new QComboBox(widget);
        comboPort->setObjectName(QString::fromUtf8("comboPort"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboPort->sizePolicy().hasHeightForWidth());
        comboPort->setSizePolicy(sizePolicy);
        comboPort->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(comboPort);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelBaud = new QLabel(widget);
        labelBaud->setObjectName(QString::fromUtf8("labelBaud"));

        horizontalLayout_4->addWidget(labelBaud);

        comboBaud = new QComboBox(widget);
        comboBaud->setObjectName(QString::fromUtf8("comboBaud"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBaud->sizePolicy().hasHeightForWidth());
        comboBaud->setSizePolicy(sizePolicy1);
        comboBaud->setMinimumSize(QSize(120, 0));
        comboBaud->setEditable(true);

        horizontalLayout_4->addWidget(comboBaud);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelData = new QLabel(widget);
        labelData->setObjectName(QString::fromUtf8("labelData"));

        horizontalLayout_3->addWidget(labelData);

        comboData = new QComboBox(widget);
        comboData->setObjectName(QString::fromUtf8("comboData"));
        sizePolicy.setHeightForWidth(comboData->sizePolicy().hasHeightForWidth());
        comboData->setSizePolicy(sizePolicy);
        comboData->setMinimumSize(QSize(120, 0));

        horizontalLayout_3->addWidget(comboData);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelStop = new QLabel(widget);
        labelStop->setObjectName(QString::fromUtf8("labelStop"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelStop->sizePolicy().hasHeightForWidth());
        labelStop->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(labelStop);

        comboStop = new QComboBox(widget);
        comboStop->setObjectName(QString::fromUtf8("comboStop"));
        sizePolicy.setHeightForWidth(comboStop->sizePolicy().hasHeightForWidth());
        comboStop->setSizePolicy(sizePolicy);
        comboStop->setMinimumSize(QSize(120, 0));

        horizontalLayout_2->addWidget(comboStop);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelParity = new QLabel(widget);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setEnabled(true);
        sizePolicy2.setHeightForWidth(labelParity->sizePolicy().hasHeightForWidth());
        labelParity->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(labelParity);

        comboParity = new QComboBox(widget);
        comboParity->setObjectName(QString::fromUtf8("comboParity"));
        sizePolicy.setHeightForWidth(comboParity->sizePolicy().hasHeightForWidth());
        comboParity->setSizePolicy(sizePolicy);
        comboParity->setMinimumSize(QSize(120, 0));
        comboParity->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(comboParity);


        verticalLayout->addLayout(horizontalLayout);

        PlotControlsBox = new QGroupBox(centralwidget);
        PlotControlsBox->setObjectName(QString::fromUtf8("PlotControlsBox"));
        PlotControlsBox->setGeometry(QRect(10, 210, 210, 337));
        PlotControlsBox->setMaximumSize(QSize(210, 16777215));
        gridLayout_2 = new QGridLayout(PlotControlsBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pointsLabel = new QLabel(PlotControlsBox);
        pointsLabel->setObjectName(QString::fromUtf8("pointsLabel"));

        horizontalLayout_6->addWidget(pointsLabel);

        spinPoints = new QSpinBox(PlotControlsBox);
        spinPoints->setObjectName(QString::fromUtf8("spinPoints"));
        spinPoints->setMinimumSize(QSize(82, 0));
        spinPoints->setMinimum(0);
        spinPoints->setMaximum(999999999);
        spinPoints->setValue(100);

        horizontalLayout_6->addWidget(spinPoints);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelYStep = new QLabel(PlotControlsBox);
        labelYStep->setObjectName(QString::fromUtf8("labelYStep"));

        horizontalLayout_7->addWidget(labelYStep);

        spinYStep = new QSpinBox(PlotControlsBox);
        spinYStep->setObjectName(QString::fromUtf8("spinYStep"));
        spinYStep->setMinimumSize(QSize(82, 0));
        spinYStep->setMaximumSize(QSize(69, 16777215));
        spinYStep->setMaximum(999999999);
        spinYStep->setSingleStep(1);
        spinYStep->setValue(10);

        horizontalLayout_7->addWidget(spinYStep);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label = new QLabel(PlotControlsBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_8->addWidget(label);

        spinAxesMin = new QSpinBox(PlotControlsBox);
        spinAxesMin->setObjectName(QString::fromUtf8("spinAxesMin"));
        spinAxesMin->setMinimumSize(QSize(82, 0));
        spinAxesMin->setMaximumSize(QSize(69, 16777215));
        spinAxesMin->setMinimum(-999999999);
        spinAxesMin->setMaximum(999999999);
        spinAxesMin->setSingleStep(1);
        spinAxesMin->setValue(0);

        horizontalLayout_8->addWidget(spinAxesMin);


        gridLayout_2->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_2 = new QLabel(PlotControlsBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_9->addWidget(label_2);

        spinAxesMax = new QSpinBox(PlotControlsBox);
        spinAxesMax->setObjectName(QString::fromUtf8("spinAxesMax"));
        spinAxesMax->setMinimumSize(QSize(82, 0));
        spinAxesMax->setMaximumSize(QSize(69, 16777215));
        spinAxesMax->setMinimum(-999999999);
        spinAxesMax->setMaximum(999999999);
        spinAxesMax->setSingleStep(1);
        spinAxesMax->setValue(100);

        horizontalLayout_9->addWidget(spinAxesMax);


        gridLayout_2->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        pushButton_AutoScale = new QPushButton(PlotControlsBox);
        pushButton_AutoScale->setObjectName(QString::fromUtf8("pushButton_AutoScale"));

        gridLayout_2->addWidget(pushButton_AutoScale, 4, 0, 1, 1);

        listWidget_Channels = new QListWidget(PlotControlsBox);
        listWidget_Channels->setObjectName(QString::fromUtf8("listWidget_Channels"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget_Channels->sizePolicy().hasHeightForWidth());
        listWidget_Channels->setSizePolicy(sizePolicy3);
        listWidget_Channels->setMinimumSize(QSize(0, 0));
        listWidget_Channels->setLayoutDirection(Qt::LeftToRight);
        listWidget_Channels->setAutoScroll(false);
        listWidget_Channels->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget_Channels->setAlternatingRowColors(true);
        listWidget_Channels->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget_Channels->setTextElideMode(Qt::ElideMiddle);
        listWidget_Channels->setResizeMode(QListView::Adjust);
        listWidget_Channels->setModelColumn(0);
        listWidget_Channels->setSelectionRectVisible(true);

        gridLayout_2->addWidget(listWidget_Channels, 5, 0, 1, 1);

        pushButton_ResetVisible = new QPushButton(PlotControlsBox);
        pushButton_ResetVisible->setObjectName(QString::fromUtf8("pushButton_ResetVisible"));

        gridLayout_2->addWidget(pushButton_ResetVisible, 6, 0, 1, 1);

        savePNGButton = new QPushButton(PlotControlsBox);
        savePNGButton->setObjectName(QString::fromUtf8("savePNGButton"));

        gridLayout_2->addWidget(savePNGButton, 7, 0, 1, 1);

        gridGroupBox = new QGroupBox(centralwidget);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridGroupBox->setGeometry(QRect(10, 550, 210, 131));
        gridGroupBox->setMaximumSize(QSize(210, 16777215));
        gridLayout_3 = new QGridLayout(gridGroupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_TextEditHide = new QPushButton(gridGroupBox);
        pushButton_TextEditHide->setObjectName(QString::fromUtf8("pushButton_TextEditHide"));
        pushButton_TextEditHide->setCheckable(true);
        pushButton_TextEditHide->setChecked(false);

        gridLayout_3->addWidget(pushButton_TextEditHide, 1, 0, 1, 1);

        pushButton_ShowallData = new QPushButton(gridGroupBox);
        pushButton_ShowallData->setObjectName(QString::fromUtf8("pushButton_ShowallData"));
        pushButton_ShowallData->setCheckable(true);

        gridLayout_3->addWidget(pushButton_ShowallData, 2, 0, 1, 1);

        pushButton_ClearRecv = new QPushButton(gridGroupBox);
        pushButton_ClearRecv->setObjectName(QString::fromUtf8("pushButton_ClearRecv"));
        pushButton_ClearRecv->setCheckable(true);

        gridLayout_3->addWidget(pushButton_ClearRecv, 3, 0, 1, 1);

        textEdit_UartWindow = new QTextEdit(centralwidget);
        textEdit_UartWindow->setObjectName(QString::fromUtf8("textEdit_UartWindow"));
        textEdit_UartWindow->setGeometry(QRect(230, 560, 714, 121));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textEdit_UartWindow->sizePolicy().hasHeightForWidth());
        textEdit_UartWindow->setSizePolicy(sizePolicy4);
        textEdit_UartWindow->setMaximumSize(QSize(16777215, 140));
        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        plot->setGeometry(QRect(230, 30, 714, 511));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy5);
        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionConnect);
        toolBar->addAction(actionPause_Plot);
        toolBar->addAction(actionDisconnect);
        toolBar->addAction(actionClear);
        toolBar->addAction(actionHow_to_use);
        toolBar->addAction(actionRecord_stream);
        toolBar->addAction(actionOpenPath);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", " \344\270\262\345\217\243\347\244\272\346\263\242\345\231\250v1.0", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
#endif // QT_CONFIG(tooltip)
        actionPause_Plot->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
#if QT_CONFIG(tooltip)
        actionPause_Plot->setToolTip(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\347\273\230\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\347\253\257\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        actionClear->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\233\262\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        actionHow_to_use->setText(QCoreApplication::translate("MainWindow", "How_to_use", nullptr));
#if QT_CONFIG(tooltip)
        actionHow_to_use->setToolTip(QCoreApplication::translate("MainWindow", "\345\246\202\344\275\225\344\275\277\347\224\250\346\234\254\350\275\257\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRecord_stream->setText(QCoreApplication::translate("MainWindow", "Record_stream", nullptr));
#if QT_CONFIG(tooltip)
        actionRecord_stream->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\260\206\346\224\266\345\210\260\347\232\204\346\225\260\346\215\256\344\277\235\345\255\230\344\270\272CSV\346\226\207\344\273\266</p><p>\357\274\210\345\277\253\346\215\267\351\224\256\357\274\232Ctrl+S\357\274\211</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRecord_stream->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpenPath->setText(QCoreApplication::translate("MainWindow", "OpenPath", nullptr));
#if QT_CONFIG(tooltip)
        actionOpenPath->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200csv\346\226\207\344\273\266\346\211\200\345\234\250\347\233\256\345\275\225\344\275\215\347\275\256</p><p>\357\274\210\345\277\253\346\215\267\351\224\256\357\274\232Ctrl+O\357\274\211</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpenPath->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        PortControlsBox->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        labelPort->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\351\200\211\346\213\251\357\274\232", nullptr));
        labelBaud->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        labelData->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        labelStop->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        labelParity->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        PlotControlsBox->setTitle(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276\350\256\276\347\275\256", nullptr));
        pointsLabel->setText(QCoreApplication::translate("MainWindow", "\347\202\271  \346\225\260\357\274\232", nullptr));
        labelYStep->setText(QCoreApplication::translate("MainWindow", "\351\227\264  \350\267\235\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\200\274\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\200\274\357\274\232", nullptr));
        pushButton_AutoScale->setText(QCoreApplication::translate("MainWindow", "Y\350\275\264\350\207\252\351\200\202\345\272\224", nullptr));
        pushButton_ResetVisible->setText(QCoreApplication::translate("MainWindow", "\345\244\215\344\275\215\350\247\206\345\233\276", nullptr));
        savePNGButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\345\275\223\345\211\215\350\247\206\345\233\276\344\270\272PNG\345\233\276\347\211\207", nullptr));
        gridGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        pushButton_TextEditHide->setText(QCoreApplication::translate("MainWindow", "\351\232\220\350\227\217\346\216\245\346\224\266\346\241\206", nullptr));
        pushButton_ShowallData->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\345\216\237\345\247\213\346\225\260\346\215\256", nullptr));
        pushButton_ClearRecv->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
