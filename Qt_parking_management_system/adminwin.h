#ifndef ADMINWIN_H
#define ADMINWIN_H

#include <QMainWindow>

namespace Ui {
class AdminWin;
}

class AdminWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWin(QWidget *parent = nullptr);
    ~AdminWin();

private slots:


    void on_quitBt_clicked();

    void on_logBt_clicked();

    void on_pushButton_clicked();

signals:  //声明自定义的信号
    void mysignal();
private:
    Ui::AdminWin *ui;
    int flag;
};

#endif // ADMINWIN_H
