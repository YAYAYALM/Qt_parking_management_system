/********************************************************************************
** Form generated from reading UI file 'parkwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARKWIN_H
#define UI_PARKWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParkWin
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *dataLa;
    QLCDNumber *lcdNumber;
    QLabel *weaLa;
    QPushButton *adminBt;
    QPushButton *upBt;
    QPushButton *rightBt;
    QLabel *label_6;
    QWidget *widget;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *parkDaLa;
    QLabel *monLa;
    QLabel *carLa;
    QWidget *widget_2;
    QPushButton *btn3;
    QPushButton *btn1;
    QPushButton *btn4;
    QPushButton *btn2;
    QPushButton *btn6;
    QPushButton *btn8;
    QPushButton *btn7;
    QPushButton *btn5;
    QWidget *widget3;
    QLabel *kahao;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *ParkWin)
    {
        if (ParkWin->objectName().isEmpty())
            ParkWin->setObjectName(QStringLiteral("ParkWin"));
        ParkWin->resize(800, 480);
        ParkWin->setMinimumSize(QSize(800, 480));
        ParkWin->setMaximumSize(QSize(800, 480));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/car.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        ParkWin->setWindowIcon(icon);
        ParkWin->setStyleSheet(QLatin1String("QMainWindow{background-image: url(:/image/park.jpeg);}\n"
""));
        actionexit = new QAction(ParkWin);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        centralwidget = new QWidget(ParkWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 50, 121, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 100, 91, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        dataLa = new QLabel(centralwidget);
        dataLa->setObjectName(QStringLiteral("dataLa"));
        dataLa->setGeometry(QRect(90, 10, 171, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(18);
        dataLa->setFont(font1);
        dataLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(90, 52, 101, 31));
        lcdNumber->setFont(font1);
        lcdNumber->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        lcdNumber->setDigitCount(8);
        weaLa = new QLabel(centralwidget);
        weaLa->setObjectName(QStringLiteral("weaLa"));
        weaLa->setGeometry(QRect(90, 100, 111, 31));
        weaLa->setFont(font1);
        weaLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        adminBt = new QPushButton(centralwidget);
        adminBt->setObjectName(QStringLiteral("adminBt"));
        adminBt->setGeometry(QRect(0, 150, 93, 41));
        adminBt->setFont(font1);
        adminBt->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:2px solid#000000;\n"
"color: rgb(0, 255, 255);"));
        upBt = new QPushButton(centralwidget);
        upBt->setObjectName(QStringLiteral("upBt"));
        upBt->setGeometry(QRect(10, 240, 41, 41));
        upBt->setStyleSheet(QStringLiteral("border-image: url(:/image/left.jpeg);"));
        rightBt = new QPushButton(centralwidget);
        rightBt->setObjectName(QStringLiteral("rightBt"));
        rightBt->setGeometry(QRect(750, 240, 41, 41));
        rightBt->setStyleSheet(QStringLiteral("border-image: url(:/image/right.jpeg);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 150, 131, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(16);
        label_6->setFont(font2);
        label_6->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 200, 251, 81));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(0, 0, 131, 41));
        label_7->setFont(font2);
        label_7->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 40, 131, 41));
        label_8->setFont(font2);
        label_8->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        parkDaLa = new QLabel(widget);
        parkDaLa->setObjectName(QStringLiteral("parkDaLa"));
        parkDaLa->setGeometry(QRect(130, 0, 111, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(14);
        parkDaLa->setFont(font3);
        parkDaLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        monLa = new QLabel(widget);
        monLa->setObjectName(QStringLiteral("monLa"));
        monLa->setGeometry(QRect(130, 40, 111, 41));
        monLa->setFont(font3);
        monLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        carLa = new QLabel(centralwidget);
        carLa->setObjectName(QStringLiteral("carLa"));
        carLa->setGeometry(QRect(240, 150, 111, 41));
        carLa->setFont(font3);
        carLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(0, 290, 791, 161));
        btn3 = new QPushButton(widget_2);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setGeometry(QRect(190, 0, 93, 161));
        btn3->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn3->setCheckable(false);
        btn1 = new QPushButton(widget_2);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setGeometry(QRect(10, 0, 93, 181));
        btn1->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn4 = new QPushButton(widget_2);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setGeometry(QRect(280, 0, 93, 161));
        btn4->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn2 = new QPushButton(widget_2);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setGeometry(QRect(100, 0, 93, 181));
        btn2->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn6 = new QPushButton(widget_2);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setGeometry(QRect(520, -20, 93, 181));
        btn6->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn8 = new QPushButton(widget_2);
        btn8->setObjectName(QStringLiteral("btn8"));
        btn8->setGeometry(QRect(700, -20, 93, 181));
        btn8->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn7 = new QPushButton(widget_2);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setGeometry(QRect(610, -20, 93, 181));
        btn7->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn5 = new QPushButton(widget_2);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setGeometry(QRect(430, -20, 93, 181));
        btn5->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(270, 0, 211, 101));
        kahao = new QLabel(widget3);
        kahao->setObjectName(QStringLiteral("kahao"));
        kahao->setGeometry(QRect(10, 50, 191, 31));
        kahao->setFont(font1);
        kahao->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 231, 41));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        ParkWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ParkWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        ParkWin->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionexit);

        retranslateUi(ParkWin);

        QMetaObject::connectSlotsByName(ParkWin);
    } // setupUi

    void retranslateUi(QMainWindow *ParkWin)
    {
        ParkWin->setWindowTitle(QApplication::translate("ParkWin", "\345\201\234\350\275\246\345\234\272", 0));
        actionexit->setText(QApplication::translate("ParkWin", "\351\200\200\345\207\272", 0));
        label->setText(QApplication::translate("ParkWin", "\346\227\245\346\234\237:", 0));
        label_2->setText(QApplication::translate("ParkWin", "\346\227\266\351\227\264\357\274\232", 0));
        label_3->setText(QApplication::translate("ParkWin", "\345\244\251\346\260\224\357\274\232", 0));
        dataLa->setText(QString());
        weaLa->setText(QString());
        adminBt->setText(QApplication::translate("ParkWin", "\347\256\241\347\220\206\345\221\230", 0));
        upBt->setText(QString());
        rightBt->setText(QString());
        label_6->setText(QApplication::translate("ParkWin", "\345\211\251\344\275\231\350\275\246\344\275\215:", 0));
        label_7->setText(QApplication::translate("ParkWin", "\345\201\234\350\275\246\346\227\266\351\227\264:", 0));
        label_8->setText(QApplication::translate("ParkWin", "\345\201\234\350\275\246\350\264\271\347\224\250\357\274\232", 0));
        parkDaLa->setText(QString());
        monLa->setText(QString());
        carLa->setText(QString());
        btn3->setText(QApplication::translate("ParkWin", "3", 0));
        btn1->setText(QApplication::translate("ParkWin", "1", 0));
        btn4->setText(QApplication::translate("ParkWin", "4", 0));
        btn2->setText(QApplication::translate("ParkWin", "2", 0));
        btn6->setText(QApplication::translate("ParkWin", "6", 0));
        btn8->setText(QApplication::translate("ParkWin", "8", 0));
        btn7->setText(QApplication::translate("ParkWin", "7", 0));
        btn5->setText(QApplication::translate("ParkWin", "5", 0));
        kahao->setText(QString());
        label_4->setText(QApplication::translate("ParkWin", "\345\275\223\345\211\215\350\275\246\347\211\214\345\215\241\345\217\267", 0));
        menu->setTitle(QApplication::translate("ParkWin", "\347\254\254\344\270\200\345\201\234\350\275\246\345\234\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ParkWin: public Ui_ParkWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARKWIN_H
