#ifndef PARKONEWIN_H
#define PARKONEWIN_H

#include "rfid.h"

#include <QMainWindow>
#include <QMessageBox>


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QButtonGroup>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonParseError>

namespace Ui {
class ParkOneWin;
}

class ParkOneWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ParkOneWin(QWidget *parent = nullptr);
    ~ParkOneWin();

protected slots:
    void getweather(QNetworkReply *p);
private slots:
    void on_rightBt_clicked();

    void on_upBt_clicked();

    void getData();

    void on_actionquit_triggered();

    void incar();
    void getcard();

signals:  //声明自定义的信号
    void mysignal();

private:
    Ui::ParkOneWin *ui;
    int carnum; //剩余车位
    int newcarnum; //选择的车位
    unsigned int cardid; //卡号
    int carflag;
    QSqlDatabase mybase; //数据库
    rfid mycard; //获取卡号
    QTimer card;

    int buf[9];
    QNetworkAccessManager manager;
    QTimer mytime;

    int carmon;  //停车费用
};

#endif // PARKONEWIN_H
