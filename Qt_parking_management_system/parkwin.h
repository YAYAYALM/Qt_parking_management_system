#ifndef PARKWIN_H
#define PARKWIN_H

#include <QMainWindow>

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

#include "rfid.h"
#include "mycamera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ParkWin; }
QT_END_NAMESPACE



class ParkWin : public QMainWindow
{
    Q_OBJECT

public:
    ParkWin(QWidget *parent = nullptr);
    ~ParkWin();


private slots:
    void on_rightBt_clicked();

    void on_upBt_clicked();

    void on_actionexit_triggered();

    void getData();

    void getweather(QNetworkReply *p);


    void on_adminBt_clicked();

    void incar();

    void getcard();

    void fun();

    void adfun();

private:
    Ui::ParkWin *ui;
    int carnum; //剩余车位
    int newcarnum; //选择的车位
    unsigned int cardid; //卡号
    int carflag;
    QNetworkAccessManager manager; //显示天气
    QTimer mytime;  //获取时间
    mycamera cam;  //显示视频
    QSqlDatabase mybase; //数据库

    rfid mycard; //获取卡号
    QTimer card;

    int buf[9];

    int carmon;  //停车费用
};
#endif // PARKWIN_H
