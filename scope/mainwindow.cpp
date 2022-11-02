#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->parabola();
//    this->twocurve();
//    this->multicurve();
    this->Histogram();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//抛物线绘制测试
void MainWindow::parabola()
{
    // 生成数据，画出的是抛物线
    QVector<double> x(21), y(21); //初始化向量x和y,即拥有21个数据
    for (int i= 0; i<21; i++)
    {
      x[i] = i-10;          // x范围[-10,10]
      y[i] = x[i]*x[i];     // y=x*x
    }
    ui->customPlot->addGraph();//添加数据曲线（一个图像可以有多个数据曲线）

    // graph(0);可以获取某个数据曲线（按添加先后排序）
    // setData();为数据曲线关联数据
    ui->customPlot->graph(0)->setData(x, y);
    ui->customPlot->graph(0)->setName("第一个示例");// 设置图例名称
    // 为坐标轴添加标签
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // 设置坐标轴的范围，以看到所有数据
    ui->customPlot->xAxis->setRange(-10, 10);
    ui->customPlot->yAxis->setRange(0, 100);
    ui->customPlot->legend->setVisible(true); // 显示图例
    // 重画图像
    ui->customPlot->replot();
}

//两条曲线绘制测试
void MainWindow::twocurve()
{
    //每条曲线都会独占一个graph()
    // graph(0);可以获取某个数据曲线（按添加先后排序）
    // setData();为数据曲线关联数据
    QCustomPlot *customPlot = ui->customPlot;//创建customPlot
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue)); // 曲线的颜色
    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // 曲线与X轴包围区的颜色

    customPlot->addGraph();//添加graph等价于添加一条新曲线
    customPlot->graph(1)->setPen(QPen(Qt::red)); // 曲线的颜色

    // 生成模拟数据点 (x-y0 第一条曲线, x-y1为第2条曲线):
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i)
    {
       x[i] = i;
       /*
        * qExp(a):e(^a),即e的a次幂
        * qCos(a):余弦函数
        */
       y0[i] = qExp(-i/150.0)*qCos(i/10.0); // 第一条曲线：y0衰减cos
       y1[i] = qExp(-i/150.0);              // 第二条曲线：y1衰减指数
    }
    // 以下内容为坐标轴的相关设置，包括刻度及坐标轴的范围等
    // 边框右侧和上侧均显示刻度线，但不显示刻度值:
    // xAxis:一般意义上的x轴，位于下侧
    // yAxis:一般意义上的y轴，位于左侧
    customPlot->xAxis2->setVisible(true);    //显示上侧的刻度线
    customPlot->xAxis2->setTickLabels(false);//上侧不显示x轴标号
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);
    // 使上下两个X轴的范围总是相等，使左右两个Y轴的范围总是相等
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
    // 把已存在的数据填充进graph的数据区
    customPlot->graph(0)->setData(x, y0);
    customPlot->graph(1)->setData(x, y1);
    //自动调整XY轴的范围，以便显示出graph(0)中所有的点（下面会单独讲到这个函数）
    customPlot->graph(0)->rescaleAxes();
    //自动调整XY轴的范围，以便显示出graph(1)中所有的点
    customPlot->graph(1)->rescaleAxes(true);
    // 支持鼠标拖拽轴的范围、滚动缩放轴的范围，左键点选图层（每条曲线独占一个图层）
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    // 立即刷新图像
    ui->customPlot->replot();

}
//利用Qcustomplot完成多种曲线的绘制
void MainWindow::multicurve()
{
    QCustomPlot *customPlot = ui->customPlot;//创建customPlot
    QPen pen;
    QStringList lineNames;
    lineNames << "lsNone" << "lsLine" << "lsStepLeft" << "lsStepRight" << "lsStepCenter" << "lsImpulse";
    for (int i = QCPGraph::lsNone; i <= QCPGraph::lsImpulse; ++i)
    {
       customPlot->addGraph();
       pen.setColor(QColor(qSin(i*1+1.2)*80+80, qSin(i*0.3+0)*80+80, qSin(i*0.3+1.5)*80+80));
       customPlot->graph()->setPen(pen);       // 设置画笔
       customPlot->graph()->setName(lineNames.at(i-QCPGraph::lsNone));//图例名称
       customPlot->graph()->setLineStyle((QCPGraph::LineStyle)i);  // 线段风格
       customPlot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 5));//设置散点形状
       customPlot->legend->setVisible(true); // 显示图例

       QVector<double> x(15), y(15);
       for (int j=0; j<15; ++j)
       {
           x[j] = j/15.0 * 5*3.14 + 0.01;
            y[j] = 7*qSin(x[j])/x[j] - (i-QCPGraph::lsNone)*5 + (QCPGraph::lsImpulse)*5 + 2;
        }
        customPlot->graph()->setData(x, y);//x和y
        customPlot->graph()->rescaleAxes(true);//自动调整XY轴的范围
    }
}
//利用QCustomPlot绘制柱状图
void MainWindow::Histogram()
{
    //绘制柱状图
    QCPAxis *xAxis = ui->customPlot->xAxis;//x轴
    QCPAxis *yAxis = ui->customPlot->yAxis;//y轴
    QCPBars *bars = new QCPBars(xAxis, yAxis);  // 使用xAxis作为柱状图的x轴，yAxis作为y轴

    bars->setAntialiased(false); // 为了更好的边框效果，关闭抗齿锯
    bars->setName("Bars"); // 设置图例
    bars->setPen(QPen(QColor(0, 160, 140).lighter(130))); // 设置柱状图的边框颜色
    bars->setBrush(QColor(20,68,106));  // 设置柱状图的画刷颜色

    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;//轴的范围
    labels << "A" << "B" << "C" << "D" << "E" << "F" << "G";//轴的刻度文字显示
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    xAxis->setTicker(textTicker);        // 设置为文字轴
    xAxis->setTickLabelRotation(60);     // 轴刻度文字旋转60度
    xAxis->setSubTicks(false);           // 不显示子刻度
    xAxis->setTickLength(0, 4);          // 轴内外刻度的长度分别是0,4,也就是轴内的刻度线不显示
    xAxis->setRange(0, 8);               // 设置x轴范围
    xAxis->setLabel("x");
    xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    yAxis->setRange(0, 12.1);          //设置y轴范围
    yAxis->setPadding(35);             // 轴的内边距
    yAxis->setLabel("y");
    yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QVector<double> fossilData;
    fossilData  << 10 << 9 << 2 << 5 << 7 << 4 << 1;//y轴坐标值
    bars->setData(ticks, fossilData);
}

