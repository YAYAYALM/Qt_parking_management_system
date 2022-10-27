#ifndef ADMINTWO_H
#define ADMINTWO_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QTableWidget>


namespace Ui {
class AdminTwo;
}

class AdminTwo : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminTwo(QWidget *parent = nullptr);
    ~AdminTwo();

private slots:
    void on_rightBt_clicked();

    void on_leftBt_clicked();

    void on_carBt_clicked();

    void on_monBt_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_updataBt_clicked();

    void on_deleteBt_clicked();

    void on_chaBt_clicked();

private:
    Ui::AdminTwo *ui;
    QSqlDatabase mybase; //数据库
    int carnum;
};

#endif // ADMINTWO_H
