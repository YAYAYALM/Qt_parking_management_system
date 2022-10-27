#ifndef ADMINONE_H
#define ADMINONE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidget>


namespace Ui {
class AdminOne;
}

class AdminOne : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminOne(QWidget *parent = nullptr);
    ~AdminOne();

private slots:
    void on_leftBt_clicked();

    void on_rightBt_clicked();

    void on_carBt_clicked();

    void on_updataBt_clicked();

    void on_monBt_clicked();

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_deleteBt_clicked();

    void on_chaCar_clicked();

private:
    Ui::AdminOne *ui;

    QSqlDatabase mybase; //数据库

    int carnum;
};

#endif // ADMINONE_H
