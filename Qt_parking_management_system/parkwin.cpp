#include "adminwin.h"
#include "parkonewin.h"
#include "parktwowin.h"
#include "parkwin.h"
#include "ui_parkwin.h"

#include "formpark.h"
#include "rfid.h"

#include <QDate>

using namespace std;

ParkWin::ParkWin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ParkWin)
{
    ui->setupUi(this);

    //关联信号与槽函数
    connect(ui->btn1,&QPushButton::clicked,this,&ParkWin::incar);
    connect(ui->btn2,&QPushButton::clicked,this,&ParkWin::incar);
    connect(ui->btn3,&QPushButton::clicked,this,&ParkWin::incar);
    connect(ui->btn4,&QPushButton::clicked,this,&ParkWin::incar);
    connect(ui->btn5,&QPushButton::clicked,this,&ParkWin::incar);
    connect(ui->btn6,&QPushButton::clicked,this,&ParkWin::incar);
    connect(ui->btn7,&QPushButton::clicked,this,&ParkWin::incar);
    connect(ui->btn8,&QPushButton::clicked,this,&ParkWin::incar);
    //将显示时间和显示日期传递给摄像头
    cam.getLabel(ui->dataLa,ui->lcdNumber);
    //给数据库安装驱动
    mybase=QSqlDatabase::addDatabase("QSQLITE");

    //设置数据库路径名
    mybase.setDatabaseName("./park.db");

    //打开数据库
    bool ret=mybase.open();
    if(!ret)
    {
        string str = mybase.lastError().text().toStdString();
        const char* ch = str.c_str();
        printf("打开数据库失败，原因是:%s",ch);
        return;
    }

    //在数据库中新建一个表格
    QSqlQuery query(mybase);
    //车牌，卡号，时间，车位
    ret=query.exec("create table if not exists parktable (name text unique,card text unique,time text,car int unique,mon int);");
    if(!ret)
    {
        string str = mybase.lastError().text().toStdString();
        const char* ch = str.c_str();
        printf("新建表格失败，原因是:%s",ch);
        return;
    }

    //将停车时间隐藏
    ui->widget->hide();

    ui->widget3->hide();

    cardid = 0;
    carflag = 1;
    carnum = 8;
    QString str = QString("%1").arg(carnum);
    ui->carLa->setText(str);

    for(int i=0;i<9;i++)
    {
        buf[i] = 0;
    }

    ret=query.exec("select * from parktable;");
    if(!ret)
    {
        perror("查询失败:\n");
        return;
    }
    //打印查询结果-->由于我不清楚查询的结果究竟有几条
    QString str2;
    int num = 0;
    int mone = 0;
    while(query.next())
    {
        str2 = query.value(1).toString();
        num = query.value(3).toUInt();
        mone = query.value(4).toInt();

        if(num == ui->btn1->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn1->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn2->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn2->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn3->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn3->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn4->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn4->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn5->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn5->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn6->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn6->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn7->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn7->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn8->text().toInt()) //说明车位和车牌一样
        {
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn8->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
    }
    if(mone <= 0)
    {
        carmon = 1;
    }
    else
    {
        carmon = mone;
    }
    //构造函数初始化摄像头
    cam.camera_init();

    cam.start();
    //获取天气预报的网址
    QString str3= "http://www.weather.com.cn/data/cityinfo/101010100.html";
    QUrl url(str3);
    //创建http请求
    QNetworkRequest quest(url);

    //发送请求
    manager.get(quest);

    //提前关联好finished(QNetworkReply *reply)信号
    connect(&manager,SIGNAL(finished(QNetworkReply *)),this,SLOT(getweather(QNetworkReply *)));

    mytime.start(1000);
    //绑定定时器，获取时间
    connect(&mytime,&QTimer::timeout,this,&ParkWin::getData);

    card.start(1000);
    //绑定定时器，获取卡号
    connect(&card,&QTimer::timeout,this,&ParkWin::getcard);
}

ParkWin::~ParkWin()
{
    //析构函数关闭摄像头
    cam.camera_uninit();
    mytime.stop();
    card.stop();
    //关闭数据库

    mybase.close();
    delete ui;
}


//下一个停车场
void ParkWin::on_rightBt_clicked()
{
    ParkTwoWin *w = new ParkTwoWin(this);

    w->show();
    card.stop();

    this->hide();
}

//上一个停车场
void ParkWin::on_upBt_clicked()
{
    ParkOneWin *w = new ParkOneWin(this);

    w->show();

    card.stop();

    this->hide();
}

//退出
void ParkWin::on_actionexit_triggered()
{
    mytime.stop();

    cam.terminate();

    cam.wait();

    this->close();
}

//获取时间和日期
void ParkWin::getData()
{
    //显示年月日
    QString d = QDate::currentDate().toString("yyyy-MM-dd");
    ui->dataLa->setText(d);
    //显示时间
    QString t = QTime::currentTime().toString("hh:mm:ss");
    ui->lcdNumber->display(t);
}
//获取天气信息
void ParkWin::getweather(QNetworkReply *p)
{
    //读取网址回复的应答信息
    QByteArray buf=p->readAll();

    //由于我获取天气预报，所以现在网站回复给我的应答信息就是天气预报信息
    //ui->textBrowser->setText(buf);

    //把网站回复的json数据规格化存储
    QJsonParseError err;
    QJsonDocument mydoc=QJsonDocument::fromJson(buf,&err);

    //严格依照你看到的json数据的格式一步步剥洋葱解析
    //最外面是个对象
    QJsonObject obj1=mydoc.object();
    //obj1就是"weatherinfo":{"city":"北京","cityid":"101010100","temp1":"18℃","temp2":"31℃","weather":"多云转阴","img1":"n1.gif","img2":"d2.gif","ptime":"18:00"}
    //继续，是个键值对
    QJsonValue val1=obj1.value("weatherinfo"); //获取"weatherinfo"对应的值
    //val1就是{"city":"北京","cityid":"101010100","temp1":"18℃","temp2":"31℃","weather":"多云转阴","img1":"n1.gif","img2":"d2.gif","ptime":"18:00"}
    QJsonObject obj2=val1.toObject();
    //继续
    QJsonValue val2=obj2.value("temp1");
    ui->weaLa->setText(val2.toString());
    //qDebug()<<"temp1对应的值是: "<<val2.toString();
}

//进入管理员界面
void ParkWin::on_adminBt_clicked()
{
    AdminWin *w = new AdminWin(this);

    w->show();
    //关闭刷卡
    card.stop();
    //关闭摄像头
    cam.terminate();
    cam.wait();
    //析构函数关闭摄像头
    cam.camera_uninit();
    this->hide();
}
//点击车库
void ParkWin::incar()
{

    ui->widget->hide();
    ui->widget3->hide();
    carflag = 0;
    //获取信号的发送者
    QObject *p=sender();
    //转换成QPushButton
    QPushButton *btp=qobject_cast<QPushButton *>(p);
    //获取按钮的字面值
    newcarnum = btp->text().toUInt();
    //获取入库时间
    QString t = QDateTime::currentDateTime().toString();
    //QString t = QTime::currentTime().toString("hh:mm:ss");
    std::string str = t.toStdString();
    const char* ch = str.c_str(); //入库时间

    unsigned int ab = cardid;
    QString car = QString("%1").arg(ab); //卡号
    std::string str4 = car.toStdString();
    const char* ch1 = str4.c_str(); //入库卡号
    if(car == 0 || newcarnum == 0 || cardid == 0)
    {
        QMessageBox::warning(this,"操作提示","没有车牌");
        carflag = 1;
        return;
    }
    else
    {
        if(buf[newcarnum] == 0)
        {
            //拼接得到完整的SQL语句
            QString cmd=QString("insert into parktable values(\"%1\",\"%2\",\"%3\",%4,%5);").arg(ch1).arg(ch1).arg(ch).arg(newcarnum).arg(carmon);
            QSqlQuery query(mybase);
            bool ret=query.exec(cmd);
            if(!ret)
            {
                //perror("插入失败，原因是: \n");
                QSqlQuery query(mybase); //查找语句
                bool ret=query.exec("select * from parktable;");
                if(!ret)
                {
                    perror("查询失败:\n");
                    return;
                }
                //打印查询结果-->由于我不清楚查询的结果究竟有几条
                QString str;
                QString time; //入库的时间
                int num = 0;
                int mone = 0;
                while(query.next())
                {
                    str = query.value(1).toString();
                    time = query.value(2).toString();
                    num = query.value(3).toUInt();
                    mone = query.value(4).toInt();
                    if(str == ch1 && num == ui->btn1->text().toInt()) //说明车位和车牌一样
                    {
                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);

                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn1->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                    if(str == ch1 && num == ui->btn2->text().toInt())
                    {

                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);


                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn2->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                    if(str == ch1 && num == ui->btn3->text().toInt())
                    {
                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);
                            printf("时间为：%d\n",mec);

                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn3->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                    if(str == ch1 && num == ui->btn4->text().toInt())
                    {
                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);
                            printf("时间为：%d\n",mec);

                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn4->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                    if(str == ch1 && num == ui->btn5->text().toInt())
                    {
                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);
                            printf("时间为：%d\n",mec);

                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn5->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                    if(str == ch1 && num == ui->btn6->text().toInt())
                    {
                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);
                            printf("时间为：%d\n",mec);

                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn6->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                    if(str == ch1 && num == ui->btn7->text().toInt())
                    {
                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);
                            printf("时间为：%d\n",mec);

                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn7->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                    if(str == ch1 && num == ui->btn8->text().toInt())
                    {
                        //拼接得到完整的SQL语句，删除
                        QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                        QSqlQuery query(mybase);
                        bool ret=query.exec(cmd);
                        if(!ret)
                        {
                            perror("删除失败，原因是: \n");
                            return;
                        }
                        else  //出库成功
                        {
                            //显示车费
                            ui->widget->show();
                            ui->widget3->show();
                            ui->kahao->setText(car);

                            QDateTime starttime = QDateTime::fromString(time);
                            QDateTime endtime = QDateTime::currentDateTime();
                            int mec = starttime.secsTo(endtime);
                            QString stopt = QString("%1秒").arg(mec);
                            ui->parkDaLa->setText(stopt);
                            printf("时间为：%d\n",mec);

                            int mon = mone * mec;
                            if(mon >= 45)
                            {
                                mon = 45;
                            }
                            QString caron = QString("%1元").arg(mon);
                            ui->monLa->setText(caron);

                            carflag = 1; //出库成功标志位复位
                            cardid = 0;  //出库成功卡号清零
                            carnum++; //删除成功，车库加1
                            QString str1 = QString("%1").arg(carnum);
                            ui->carLa->setText(str1);
                            //改变按钮的背景
                            ui->btn8->setStyleSheet("background-image: url(:/image/car.jpeg);");

                            buf[num] = 0;
                            QMessageBox::warning(this,"操作提示","请支付车费");
                            QMessageBox::information(this,"操作提示","出库成功");
                        }
                        return;
                    }
                }


             }
            else //入库成功
            {
                carflag = 1; //入库成功标志位复位
                cardid = 0;  //入库成功卡号清零
                ui->widget3->show();
                ui->kahao->setText(car);
                //改变按钮的背景
                btp->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
                QMessageBox::information(this,"操作提示","入库成功");
                buf[newcarnum] = 1;
                carnum--;
                QString str1 = QString("%1").arg(carnum);
                ui->carLa->setText(str1);
            }
        }
        else
        {
            carflag = 1;
            QSqlQuery query(mybase);
            bool ret=query.exec("select * from parktable;");
            if(!ret)
            {
                perror("查询失败:\n");
                return;
            }

            //打印查询结果-->由于我不清楚查询的结果究竟有几条
            QString str;
            QString time;
            int num = 0;
            int mone = 0;
            while(query.next())
            {
                str = query.value(1).toString();
                time = query.value(2).toString();
                num = query.value(3).toUInt();
                mone = query.value(4).toInt();
                printf("num is :%d\n",num);

                if(str == ch1 && num == newcarnum) //说明车位和车牌一样
                {
                    //拼接得到完整的SQL语句，删除
                    QString cmd=QString("delete from parktable where card=\"%1\";").arg(car);
                    QSqlQuery query(mybase);
                    bool ret=query.exec(cmd);
                    if(!ret)
                    {
                        perror("删除失败，原因是: \n");
                        return;
                    }
                    else  //出库成功
                    {
                        //显示车费
                        ui->widget->show();
                        ui->widget3->show();
                        ui->kahao->setText(car);

                        QDateTime starttime = QDateTime::fromString(time);
                        QDateTime endtime = QDateTime::currentDateTime();
                        int mec = starttime.secsTo(endtime);
                        QString stopt = QString("%1秒").arg(mec);
                        ui->parkDaLa->setText(stopt);
                        printf("时间为：%d\n",mec);

                        int mon = mone * mec;
                        if(mon >= 45)
                        {
                            mon = 45;
                        }
                        QString caron = QString("%1元").arg(mon);
                        ui->monLa->setText(caron);

                        carflag = 1; //出库成功标志位复位
                        cardid = 0;  //出库成功卡号清零
                        carnum++; //删除成功，车库加1
                        QString str1 = QString("%1").arg(carnum);
                        ui->carLa->setText(str1);
                        //改变按钮的背景
                        btp->setStyleSheet("background-image: url(:/image/car.jpeg);");

                        buf[newcarnum] = 0;
                        QMessageBox::warning(this,"操作提示","请支付车费");
                        QMessageBox::information(this,"操作提示","出库成功");
                    }
                }
            }
            if(str != ch1 || num != newcarnum)
            {
                carflag = 1;
                QMessageBox::warning(this,"操作提示","车位已占用");
            }
            //carflag = 1;
        }
    }
}

//获取卡号
void ParkWin::getcard()
{
    if(carnum <= 0)
    {
        QMessageBox::warning(this,"操作提示","1号车库已满");
        return;
    }

    //printf("carfalg is :%d\n",carflag);
    if(carflag == 1)
    {
        //获取卡号
        unsigned int ab = mycard.read_card();
        cardid = ab;
        if(cardid == 0)
        {
            return;
        }
        carflag = 0;
    }
}

void ParkWin::fun()
{
    card.start(1000);
}

//管理员窗口到停车窗口
void ParkWin::adfun()
{
    //printf("-----------1---------\n");
    //开启刷卡
    card.start(1000);
    //开启摄像头
    cam.camera_init();
    cam.start();
    carnum = 8;
    QString str1 = QString("%1").arg(carnum);
    ui->carLa->setText(str1);

    QSqlQuery query(mybase);;
    bool ret=query.exec("select * from parktable;");
    if(!ret)
    {
        perror("查询失败:\n");
        return;
    }
    //打印查询结果-->由于我不清楚查询的结果究竟有几条
    QString str2;
    int num = 0;
    int mone = 0;
    if(query.next() == false)
    {
        ui->btn1->setStyleSheet("background-image: url(:/image/car.jpeg);");
        ui->btn2->setStyleSheet("background-image: url(:/image/car.jpeg);");
        ui->btn3->setStyleSheet("background-image: url(:/image/car.jpeg);");
        ui->btn4->setStyleSheet("background-image: url(:/image/car.jpeg);");
        ui->btn5->setStyleSheet("background-image: url(:/image/car.jpeg);");
        ui->btn6->setStyleSheet("background-image: url(:/image/car.jpeg);");
        ui->btn7->setStyleSheet("background-image: url(:/image/car.jpeg);");
        ui->btn8->setStyleSheet("background-image: url(:/image/car.jpeg);");
        return;
    }

    int car_num[9] = {0};
    ret=query.exec("select * from parktable;");
    if(!ret)
    {
       perror("查询失败:\n");
       return;
    }
    while(query.next())
    {
        str2 = query.value(1).toString();
        num = query.value(3).toUInt();
        mone = query.value(4).toInt();

        if(mone != 0)
        {
            carmon = mone;
        }
        else
            carmon = 1;
        if(num == ui->btn1->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn1->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn2->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn2->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn3->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn3->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn4->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn4->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn5->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn5->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn6->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn6->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn7->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn7->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
        if(num == ui->btn8->text().toInt()) //说明车位和车牌一样
        {
            car_num[num] = 1;
            carnum--; //车库减1
            QString str1 = QString("%1").arg(carnum);
            ui->carLa->setText(str1);
            //改变按钮的背景
            ui->btn8->setStyleSheet("background-image: url(:/image/car.jpeg);image: url(:/image/car.jpeg);");
            buf[num] = 1;
        }
    }
    if(car_num[1] == 0)
    {
        ui->btn1->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[1] = 0;
    }
    if(car_num[2] == 0)
    {
        ui->btn2->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[2] = 0;
    }
    if(car_num[3] == 0)
    {
        ui->btn3->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[3] = 0;
    }
    if(car_num[4] == 0)
    {
        ui->btn4->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[4] = 0;
    }
    if(car_num[5] == 0)
    {
        ui->btn5->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[5] = 0;
    }
    if(car_num[6] == 0)
    {
        ui->btn6->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[6] = 0;
    }
    if(car_num[7] == 0)
    {
        ui->btn7->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[7] = 0;
    }
    if(car_num[8] == 0)
    {
        ui->btn8->setStyleSheet("background-image: url(:/image/car.jpeg);");
        buf[8] = 0;
    }
}
