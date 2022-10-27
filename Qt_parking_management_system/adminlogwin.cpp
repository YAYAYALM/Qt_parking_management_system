#include "adminlogwin.h"
#include "adminone.h"
#include "admintwo.h"
#include "ui_adminlogwin.h"


#include <QStringList>
#include <QMessageBox>

AdminLogWin::AdminLogWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminLogWin)
{
    ui->setupUi(this);

    QString str1= QString("2");
    ui->monEd->setText(str1);
    //初始化表格列表框
    ui->tableWidget->setColumnCount(5);
    //设置行数
    ui->tableWidget->setRowCount(8);
    ui->tableWidget->setColumnWidth(3,60);
    ui->tableWidget->setColumnWidth(2,160);
    ui->tableWidget->setColumnWidth(4,60);

    //先清除表格中的数据
    ui->tableWidget->clear();
    //设置表头--》字段名
    QStringList list;
    list.append("车牌");
    list.append("卡号");
    list.append("时间");
    list.append("车位");
    list.append("费用");
    ui->tableWidget->setHorizontalHeaderLabels(list);

    carnum = 8;
    int i=0;
    //执行查询语句
    QSqlQuery query(mybase);
    bool ret=query.exec("select * from parktable;");
    if(ret==false)
    {
        perror("查询失败!\n");
        return;
    }

    //循环遍历打印查询的结果
    while(query.next())
    {
        //把查询的结果在表格列表框中显示出来
        QTableWidgetItem *item1=new QTableWidgetItem(query.value(0).toString());
        ui->tableWidget->setItem(i,0,item1);
        QTableWidgetItem *item2=new QTableWidgetItem(query.value(1).toString());
        ui->tableWidget->setItem(i,1,item2);
        //QTableWidgetItem *item3=new QTableWidgetItem(query.value(2).toString());
        QString str = query.value(2).toString();
        QStringList list = str.split(" ");
        QTableWidgetItem *item3=new QTableWidgetItem(list[4]+":"+list[3]);
        ui->tableWidget->setItem(i,2,item3);
        QTableWidgetItem *item4=new QTableWidgetItem(query.value(3).toString());
        ui->tableWidget->setItem(i,3,item4);
        QTableWidgetItem *item5=new QTableWidgetItem(query.value(4).toString());
        ui->tableWidget->setItem(i,4,item5);
        i++;
        carnum--;
    }

    QString str3 = QString("%1").arg(carnum);
    ui->carLa->setText(str3);
}

AdminLogWin::~AdminLogWin()
{
    delete ui;
}

void AdminLogWin::on_actionquit_triggered()
{
    //printf("-----------1---------\n");
    this->parentWidget()->show();
    //printf("-----------2------------\n");
    this->close();
}
//第二停车场
void AdminLogWin::on_leftBt_clicked()
{
    AdminOne *w = new AdminOne(this);

    w->show();

    this->hide();
}
//第三停车场
void AdminLogWin::on_rightBt_clicked()
{
    AdminTwo *w = new AdminTwo(this);

    w->show();

    this->hide();
}
//更新数据库
void AdminLogWin::on_updataBt_clicked()
{
    //先清除表格中的数据
    ui->tableWidget->clear();
    //设置表头--》字段名
    QStringList list;
    list.append("车牌");
    list.append("卡号");
    list.append("时间");
    list.append("车位");
    list.append("费用");
    ui->tableWidget->setHorizontalHeaderLabels(list);
    int i = 0;
    //执行查询语句
    QSqlQuery query(mybase);
    bool ret=query.exec("select * from parktable;");
    if(ret==false)
    {
        perror("查询失败!\n");
        return;
    }

    //循环遍历打印查询的结果
    while(query.next())
    {
        //把查询的结果在表格列表框中显示出来
        QTableWidgetItem *item1=new QTableWidgetItem(query.value(0).toString());
        ui->tableWidget->setItem(i,0,item1);
        QTableWidgetItem *item2=new QTableWidgetItem(query.value(1).toString());
        ui->tableWidget->setItem(i,1,item2);
        //QTableWidgetItem *item3=new QTableWidgetItem(query.value(2).toString());
        QString str = query.value(2).toString();
        QStringList list = str.split(" ");
        QTableWidgetItem *item3=new QTableWidgetItem(list[4]+":"+list[3]);
        ui->tableWidget->setItem(i,2,item3);
        QTableWidgetItem *item4=new QTableWidgetItem(query.value(3).toString());
        ui->tableWidget->setItem(i,3,item4);
        QTableWidgetItem *item5=new QTableWidgetItem(query.value(4).toString());
        ui->tableWidget->setItem(i,4,item5);
        i++;
    }
    QMessageBox::warning(this,"操作提示","更新成功");
}
//修改车牌
void AdminLogWin::on_carBt_clicked()
{
    QString str1 = ui->begins->text();
    QString str = ui->lineEdit->text();
    if(str == 0 || str1 == 0)
    {
        QMessageBox::warning(this,"操作提示","没有车牌信息");
        return;
    }
    //拼接得到完整的修改语句
    QString cmd=QString("update parktable set card=\"%1\" where card=\"%2\";").arg(str).arg(str1);

    //执行修改语句
    QSqlQuery query(mybase);
    bool ret=query.exec(cmd);
    if(ret==false)
    {
        perror("修改失败!\n");
        QMessageBox::warning(this,"操作提示","修改失败");
        return;
    }
    QMessageBox::warning(this,"操作提示","成功修改车牌");
}
//修改费用
void AdminLogWin::on_monBt_clicked()
{
    QString str = ui->monEd->text();
    if(str == 0)
    {
        QMessageBox::warning(this,"操作提示","没有费用");
        return;
    }
    //拼接得到完整的修改语句
    QString cmd=QString("update parktable set mon=%1;").arg(str);

    //执行修改语句
    QSqlQuery query(mybase);
    bool ret=query.exec(cmd);
    if(ret==false)
    {
        perror("修改失败!\n");
        QMessageBox::warning(this,"操作提示","修改失败");
        return;
    }
    QMessageBox::warning(this,"操作提示","成功修改费用");
}

//点击获取车牌
void AdminLogWin::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->begins->setText(item->text());
}
//删除车牌
void AdminLogWin::on_deleteBt_clicked()
{
    QString str = ui->begins->text();
    if(str == 0)
    {
        QMessageBox::warning(this,"操作提示","没有车牌");
        return;
    }
    //拼接得到完整的SQL语句，删除
    QString cmd=QString("delete from parktable where card=\"%1\";").arg(str);
    QSqlQuery query(mybase);
    bool ret=query.exec(cmd);
    if(!ret)
    {
        QMessageBox::warning(this,"操作提示","删除失败");
        return;
    }
    carnum++;
    QString str3 = QString("%1").arg(carnum);
    ui->carLa->setText(str3);
    QMessageBox::warning(this,"操作提示","成功删除车辆");
}
//修改车位
void AdminLogWin::on_cheCar_clicked()
{
    int num = ui->carEd->text().toInt();  //获取车位
    num = 8;
    QString str = ui->begins->text();  //获取车牌
    if(str == 0 || num == 0)
    {
        QMessageBox::warning(this,"操作提示","没有车位或车牌");
        return;
    }
    //拼接得到完整的SQL语句，删除
    QString cmd=QString("update parktable set car=%1 where card=\"%2\";").arg(num).arg(str);
    QSqlQuery query(mybase);
    bool ret=query.exec(cmd);
    if(!ret)
    {
        QMessageBox::warning(this,"操作提示","删除失败");
        return;
    }
    QMessageBox::information(this,"操作提示","修改车位成功");
}
