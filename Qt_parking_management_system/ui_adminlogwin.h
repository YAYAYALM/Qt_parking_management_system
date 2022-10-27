/********************************************************************************
** Form generated from reading UI file 'adminlogwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGWIN_H
#define UI_ADMINLOGWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminLogWin
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *carLa;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QPushButton *carBt;
    QPushButton *updataBt;
    QPushButton *leftBt;
    QPushButton *rightBt;
    QLineEdit *monEd;
    QLabel *label_5;
    QPushButton *monBt;
    QLineEdit *begins;
    QLabel *label_6;
    QPushButton *deleteBt;
    QLineEdit *carEd;
    QLabel *label_7;
    QPushButton *cheCar;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *AdminLogWin)
    {
        if (AdminLogWin->objectName().isEmpty())
            AdminLogWin->setObjectName(QStringLiteral("AdminLogWin"));
        AdminLogWin->resize(800, 480);
        AdminLogWin->setMinimumSize(QSize(800, 480));
        AdminLogWin->setMaximumSize(QSize(800, 480));
        actionquit = new QAction(AdminLogWin);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        centralwidget = new QWidget(AdminLogWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(210, 0, 591, 381));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 40, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(170, 170, 255);"));
        carLa = new QLabel(centralwidget);
        carLa->setObjectName(QStringLiteral("carLa"));
        carLa->setGeometry(QRect(130, 50, 71, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        carLa->setFont(font1);
        carLa->setStyleSheet(QStringLiteral("color: rgb(85, 170, 127);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 181, 41));
        label_3->setFont(font1);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 85, 127);"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 110, 151, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(18);
        lineEdit->setFont(font2);
        lineEdit->setStyleSheet(QStringLiteral(""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 80, 111, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(14);
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        carBt = new QPushButton(centralwidget);
        carBt->setObjectName(QStringLiteral("carBt"));
        carBt->setGeometry(QRect(160, 110, 41, 41));
        carBt->setFont(font3);
        carBt->setStyleSheet(QStringLiteral("border-image: url(:/image/left.jpeg);"));
        updataBt = new QPushButton(centralwidget);
        updataBt->setObjectName(QStringLiteral("updataBt"));
        updataBt->setGeometry(QRect(480, 390, 61, 51));
        updataBt->setStyleSheet(QStringLiteral("border-image: url(:/image/return.png);"));
        leftBt = new QPushButton(centralwidget);
        leftBt->setObjectName(QStringLiteral("leftBt"));
        leftBt->setGeometry(QRect(210, 390, 81, 61));
        leftBt->setStyleSheet(QStringLiteral("border-image: url(:/image/left.jpeg);"));
        rightBt = new QPushButton(centralwidget);
        rightBt->setObjectName(QStringLiteral("rightBt"));
        rightBt->setGeometry(QRect(720, 390, 81, 61));
        rightBt->setStyleSheet(QLatin1String("\n"
"border-image: url(:/image/right.jpeg);"));
        monEd = new QLineEdit(centralwidget);
        monEd->setObjectName(QStringLiteral("monEd"));
        monEd->setGeometry(QRect(0, 190, 151, 41));
        monEd->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 160, 111, 31));
        label_5->setFont(font3);
        label_5->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        monBt = new QPushButton(centralwidget);
        monBt->setObjectName(QStringLiteral("monBt"));
        monBt->setGeometry(QRect(160, 190, 41, 41));
        monBt->setFont(font3);
        monBt->setStyleSheet(QStringLiteral("border-image: url(:/image/left.jpeg);"));
        begins = new QLineEdit(centralwidget);
        begins->setObjectName(QStringLiteral("begins"));
        begins->setGeometry(QRect(0, 270, 151, 41));
        begins->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 240, 111, 31));
        label_6->setFont(font3);
        label_6->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        deleteBt = new QPushButton(centralwidget);
        deleteBt->setObjectName(QStringLiteral("deleteBt"));
        deleteBt->setGeometry(QRect(160, 270, 41, 41));
        deleteBt->setFont(font3);
        deleteBt->setStyleSheet(QStringLiteral("border-image: url(:/image/left.jpeg);"));
        carEd = new QLineEdit(centralwidget);
        carEd->setObjectName(QStringLiteral("carEd"));
        carEd->setGeometry(QRect(0, 340, 151, 41));
        carEd->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 310, 111, 31));
        label_7->setFont(font3);
        label_7->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        cheCar = new QPushButton(centralwidget);
        cheCar->setObjectName(QStringLiteral("cheCar"));
        cheCar->setGeometry(QRect(160, 340, 41, 41));
        cheCar->setFont(font3);
        cheCar->setStyleSheet(QStringLiteral("border-image: url(:/image/left.jpeg);"));
        AdminLogWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminLogWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        AdminLogWin->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(AdminLogWin);

        QMetaObject::connectSlotsByName(AdminLogWin);
    } // setupUi

    void retranslateUi(QMainWindow *AdminLogWin)
    {
        AdminLogWin->setWindowTitle(QApplication::translate("AdminLogWin", "MainWindow", 0));
        actionquit->setText(QApplication::translate("AdminLogWin", "\351\200\200\345\207\272", 0));
        label->setText(QApplication::translate("AdminLogWin", "\345\211\251\344\275\231\350\275\246\344\275\215\357\274\232", 0));
        carLa->setText(QString());
        label_3->setText(QApplication::translate("AdminLogWin", "\347\254\254\344\270\200\345\201\234\350\275\246\345\234\272", 0));
        label_4->setText(QApplication::translate("AdminLogWin", "\344\277\256\346\224\271\350\275\246\347\211\214:", 0));
        carBt->setText(QString());
        updataBt->setText(QString());
        leftBt->setText(QString());
        rightBt->setText(QString());
        label_5->setText(QApplication::translate("AdminLogWin", "\344\277\256\346\224\271\350\264\271\347\224\250:", 0));
        monBt->setText(QString());
        label_6->setText(QApplication::translate("AdminLogWin", "\345\275\223\345\211\215\350\275\246\347\211\214:", 0));
        deleteBt->setText(QString());
        label_7->setText(QApplication::translate("AdminLogWin", "\344\277\256\346\224\271\350\275\246\344\275\215\357\274\232", 0));
        cheCar->setText(QString());
        menu->setTitle(QApplication::translate("AdminLogWin", "\351\200\211\346\213\251", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminLogWin: public Ui_AdminLogWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGWIN_H
