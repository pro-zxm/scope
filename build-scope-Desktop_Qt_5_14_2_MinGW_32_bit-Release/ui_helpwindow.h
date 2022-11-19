/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QString::fromUtf8("HelpWindow"));
        HelpWindow->resize(491, 234);
        HelpWindow->setMinimumSize(QSize(491, 234));
        HelpWindow->setMaximumSize(QSize(538, 234));
        textEdit = new QTextEdit(HelpWindow);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 20, 491, 211));

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QWidget *HelpWindow)
    {
        HelpWindow->setWindowTitle(QCoreApplication::translate("HelpWindow", "\344\270\262\345\217\243\347\244\272\346\263\242\345\231\250\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        textEdit->setHtml(QCoreApplication::translate("HelpWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">    \346\234\254\344\270\262\345\217\243\347\244\272\346\263\242\345\231\250v1.0\350\203\275\347\273\230\345\210\266\344\273\216\344\270\262\345\217\243\344\274\240\345\205\245\347\232\204\345\256\236\346\227\266\346\225\260\346\215\256\357\274\214\345\217\257\344\270\216\344\273\273\344\275\225\345\205\267\346\234\211\344\270\262\345\217\243\345\212\237\350\203\275\347\232\204\345\244\204\347\220\206\345\231\250\350\201\224\345\220\210\344\275\277\347\224\250\343\200\202\344\273\216\350\277\234\347\253\257\350\256\276\345\244\207\345"
                        "\217\221\351\200\201\347\232\204\346\225\260\346\215\256\351\234\200\350\246\201\346\234\211\344\270\200\345\256\232\347\232\204\346\240\274\345\274\217\357\274\214\346\241\242\345\244\264'$'\345\274\200\345\244\264\357\274\214\344\273\245';'\347\273\223\345\260\276\343\200\202\345\217\226\345\200\274\345\277\205\351\241\273\344\273\245\347\251\272\346\240\274\345\210\206\351\232\224\343\200\202\344\273\216\345\265\214\345\205\245\345\274\217\350\256\276\345\244\207\345\217\221\351\200\201\346\225\260\346\215\256\345\210\260\350\277\231\344\270\252\345\272\224\347\224\250\347\250\213\345\272\217\347\232\204\344\276\213\345\255\220:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#ff0000;\">    printf(&quot;$%d %d;"
                        "&quot;, ADC1, ADC2);</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#ff0000;\">    delay_ms(10);</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
