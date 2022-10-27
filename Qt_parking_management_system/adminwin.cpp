#include "adminlogwin.h"
#include "adminwin.h"
#include "ui_adminwin.h"

AdminWin::AdminWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWin)
{
    ui->setupUi(this);

    QString username = QString("root");
    ui->nameEd->setText(username);
    QString pass = QString("123456");
    ui->passEd->setText(pass);

    flag = 0;
}

AdminWin::~AdminWin()
{
    delete ui;
}

//返回主界面
void AdminWin::on_quitBt_clicked()
{
    this->parentWidget()->show();

    //立马关联信号(登录界面的信号)与槽函数(主界面第二个界面的槽函数)
    connect(this,SIGNAL(mysignal()),this->parentWidget(),SLOT(adfun()));

    //自己主动触发自定义的信号
    emit mysignal();

    delete this;
}
//进入管理员登录成功界面
void AdminWin::on_logBt_clicked()
{
    QString name = ui->nameEd->text();
    QString password = ui->passEd->text();
    if(name == "root" && password == "123456")
    {
        //进入管理界面
        AdminLogWin *w = new AdminLogWin(this);

        w->show();

        this->hide();
    }
}
//显示密码
void AdminWin::on_pushButton_clicked()
{
    flag++;
    if(flag%2==1) //奇数
    {
        //密码显示出来
        ui->passEd->setEchoMode(QLineEdit::Normal);
        //给按钮设置背景图片
        ui->pushButton->setStyleSheet("border-image: url(:/image/eyeOpen.png);");
    }
    else  //偶数
    {
        //密码不显示出来
        ui->passEd->setEchoMode(QLineEdit::Password);
        //给按钮设置背景图片
        ui->pushButton->setStyleSheet("border-image: url(:/image/eyeClose.png);");
    }
}
