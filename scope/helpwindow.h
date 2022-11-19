#ifndef HELPWINDOW_HPP
#define HELPWINDOW_HPP

#include <QDialog>

namespace Ui {
    class HelpWindow;
}

class HelpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HelpWindow(QWidget *parent = 0);
    ~HelpWindow();

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_HPP
