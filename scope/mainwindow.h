#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void parabola();  //抛物线绘制测试
    void twocurve();  //两条曲线绘制测试
    void multicurve();//多种曲线绘制
    void Histogram(); //绘制柱状图
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
