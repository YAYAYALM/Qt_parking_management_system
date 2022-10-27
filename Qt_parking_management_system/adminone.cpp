#include "adminone.h"
#include "ui_adminone.h"

#include <QMessageBox>

AdminOne::AdminOne(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminOne)
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

    int i=0;
    carnum = 8;
    //执行查询语句
    QSqlQuery query(mybase);
    bool ret=query.exec("select * from parkonetable;");
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

AdminOne::~AdminOne()
{
    delete ui;
}

void AdminOne::on_leftBt_clicked()
{
    QMessageBox::information(this,"操作提示","没有上一车库");
}

void AdminOne::on_rightBt_clicked()
{
    this->parentWidget()->show();

    delete this;
}
//修改车牌
void AdminOne::on_carBt_clicked()
{
    QString str1 = ui->begins->text();
    QString str = ui->lineEdit->text();
    if(str == 0 || str1 == 0)
    {
        QMessageBox::warning(this,"操作提示","没有车牌信息");
        return;
    }
    //拼接得到完整的修改语句
    QString cmd=QString("update parkonetable set card=\"%1\" where card=\"%2\";").arg(str).arg(str1);

    //执行修改语句
    QSqlQuery query(mybase);
    bool ret=query.exec(cmd);
    if(ret==false)
    {
        perror("修改失败!\n");
        QMessageBox::warning(this,"操作提示","修改失败");
        return;
    }
    QMessageBox::warning(this,"操作提示","修改成功");
}
//更新数据库
void AdminOne::on_updataBt_clicked()
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
    bool ret=query.exec("select * from parkonetable;");
    if(ret==false)
    {
        perror("查询失败!\n");
        QMessageBox::warning(this,"操作提示","查询失败");
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
}
//修改费用
void AdminOne::on_monBt_clicked()
{
    QString str = ui->monEd->text();
    if(str == 0)
    {
        QMessageBox::warning(this,"操作提示","没有费用");
        return;
    }
    //拼接得到完整的修改语句
    QString cmd=QString("update parkonetable set mon=%1;").arg(str);

    //执行修改语句
    QSqlQuery query(mybase);
    bool ret=query.exec(cmd);
    if(ret==false)
    {
        perror("修改失败!\n");
        QMessageBox::warning(this,"操作提示","修改失败");
        return;
    }
    QMessageBox::warning(this,"操作提示","修改成功");
}

void AdminOne::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    ui->begins->setText(item->text());
}

void AdminOne::on_deleteBt_clicked()
{
    QString str = ui->begins->text();
    if(str == 0)
    {
        QMessageBox::warning(this,"操作提示","没有车牌");
        return;
    }
    //拼接得到完整的SQL语句，删除
    QString cmd=QString("delete from parkonetable where card=\"%1\";").arg(str);
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
    QMessageBox::warning(this,"操作提示","删除成功");
}
//修改车位
void AdminOne::on_chaCar_clicked()
{
    int num = ui->carEd->text().toInt();
    QString str = ui->begins->text();
    if(str == 0 || num == 0)
    {
        QMessageBox::warning(this,"操作提示","没有车位或车牌");
        return;
    }
    //拼接得到完整的SQL语句，删除
    QString cmd=QString("update parkonetable set car=%1 where card=\"%2\";").arg(num).arg(str);
    QSqlQuery query(mybase);
    bool ret=query.exec(cmd);
    if(!ret)
    {
        QMessageBox::warning(this,"操作提示","删除失败");
        return;
    }
    QMessageBox::information(this,"操作提示","修改车位成功");
}
