#ifndef ADMINLOGWIN_H
#define ADMINLOGWIN_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidget>

namespace Ui {
class AdminLogWin;
}

class AdminLogWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminLogWin(QWidget *parent = nullptr);
    ~AdminLogWin();

private slots:
    void on_actionquit_triggered();

    void on_leftBt_clicked();

    void on_rightBt_clicked();

    void on_updataBt_clicked();

    void on_carBt_clicked();

    void on_monBt_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_deleteBt_clicked();

    void on_cheCar_clicked();

private:
    Ui::AdminLogWin *ui;

    QSqlDatabase mybase; //数据库

    int carnum;
};

#endif // ADMINLOGWIN_H
