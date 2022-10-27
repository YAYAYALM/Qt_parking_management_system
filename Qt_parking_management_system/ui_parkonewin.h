/********************************************************************************
** Form generated from reading UI file 'parkonewin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARKONEWIN_H
#define UI_PARKONEWIN_H

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

class Ui_ParkOneWin
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QLabel *weaLa;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn8;
    QPushButton *btn5;
    QPushButton *btn7;
    QPushButton *btn1;
    QLabel *label_6;
    QPushButton *btn2;
    QLCDNumber *lcdNumber;
    QLabel *dataLa;
    QPushButton *upBt;
    QWidget *widget;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *parkDaLa;
    QLabel *monLa;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btn6;
    QLabel *label_3;
    QPushButton *adminBt;
    QPushButton *rightBt;
    QLabel *carLa;
    QWidget *widget3;
    QLabel *kahao;
    QLabel *label_4;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *ParkOneWin)
    {
        if (ParkOneWin->objectName().isEmpty())
            ParkOneWin->setObjectName(QStringLiteral("ParkOneWin"));
        ParkOneWin->resize(800, 480);
        ParkOneWin->setMinimumSize(QSize(800, 480));
        ParkOneWin->setMaximumSize(QSize(800, 480));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/car.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        ParkOneWin->setWindowIcon(icon);
        actionquit = new QAction(ParkOneWin);
        actionquit->setObjectName(QStringLiteral("actionquit"));
        centralwidget = new QWidget(ParkOneWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        weaLa = new QLabel(centralwidget);
        weaLa->setObjectName(QStringLiteral("weaLa"));
        weaLa->setGeometry(QRect(90, 100, 101, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(18);
        weaLa->setFont(font);
        weaLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setGeometry(QRect(190, 270, 93, 181));
        btn3->setStyleSheet(QLatin1String("background-image: url(:/image/car.jpeg);\n"
""));
        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setGeometry(QRect(280, 270, 93, 181));
        btn4->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName(QStringLiteral("btn8"));
        btn8->setGeometry(QRect(710, 270, 93, 181));
        btn8->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setGeometry(QRect(440, 270, 93, 181));
        btn5->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setGeometry(QRect(620, 270, 93, 181));
        btn7->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setGeometry(QRect(10, 270, 93, 181));
        btn1->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 150, 131, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        label_6->setFont(font1);
        label_6->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setGeometry(QRect(100, 270, 93, 181));
        btn2->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(90, 52, 101, 31));
        lcdNumber->setFont(font);
        lcdNumber->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        lcdNumber->setDigitCount(8);
        dataLa = new QLabel(centralwidget);
        dataLa->setObjectName(QStringLiteral("dataLa"));
        dataLa->setGeometry(QRect(90, 10, 171, 31));
        dataLa->setFont(font);
        dataLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        upBt = new QPushButton(centralwidget);
        upBt->setObjectName(QStringLiteral("upBt"));
        upBt->setGeometry(QRect(0, 210, 41, 41));
        upBt->setStyleSheet(QStringLiteral("border-image: url(:/image/left.jpeg);"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 190, 251, 81));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 0, 131, 41));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 40, 131, 41));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        parkDaLa = new QLabel(widget);
        parkDaLa->setObjectName(QStringLiteral("parkDaLa"));
        parkDaLa->setGeometry(QRect(140, 0, 111, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        parkDaLa->setFont(font2);
        parkDaLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        monLa = new QLabel(widget);
        monLa->setObjectName(QStringLiteral("monLa"));
        monLa->setGeometry(QRect(140, 40, 111, 41));
        monLa->setFont(font2);
        monLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 121, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(20);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 50, 121, 41));
        label_2->setFont(font3);
        label_2->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setGeometry(QRect(530, 270, 93, 181));
        btn6->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 100, 91, 41));
        label_3->setFont(font3);
        label_3->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        adminBt = new QPushButton(centralwidget);
        adminBt->setObjectName(QStringLiteral("adminBt"));
        adminBt->setGeometry(QRect(0, 150, 93, 41));
        adminBt->setFont(font);
        adminBt->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:2px solid#000000;\n"
"color: rgb(0, 255, 255);"));
        rightBt = new QPushButton(centralwidget);
        rightBt->setObjectName(QStringLiteral("rightBt"));
        rightBt->setGeometry(QRect(750, 220, 41, 41));
        rightBt->setStyleSheet(QStringLiteral("border-image: url(:/image/right.jpeg);"));
        carLa = new QLabel(centralwidget);
        carLa->setObjectName(QStringLiteral("carLa"));
        carLa->setGeometry(QRect(240, 150, 111, 41));
        carLa->setFont(font2);
        carLa->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(280, 0, 211, 101));
        kahao = new QLabel(widget3);
        kahao->setObjectName(QStringLiteral("kahao"));
        kahao->setGeometry(QRect(10, 50, 191, 31));
        kahao->setFont(font);
        kahao->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_4 = new QLabel(widget3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 231, 41));
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        ParkOneWin->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(ParkOneWin);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        ParkOneWin->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(ParkOneWin);

        QMetaObject::connectSlotsByName(ParkOneWin);
    } // setupUi

    void retranslateUi(QMainWindow *ParkOneWin)
    {
        ParkOneWin->setWindowTitle(QApplication::translate("ParkOneWin", "\345\201\234\350\275\246\345\234\2721", 0));
        actionquit->setText(QApplication::translate("ParkOneWin", "\351\200\200\345\207\272", 0));
        weaLa->setText(QString());
        btn3->setText(QApplication::translate("ParkOneWin", "3", 0));
        btn4->setText(QApplication::translate("ParkOneWin", "4", 0));
        btn8->setText(QApplication::translate("ParkOneWin", "8", 0));
        btn5->setText(QApplication::translate("ParkOneWin", "5", 0));
        btn7->setText(QApplication::translate("ParkOneWin", "7", 0));
        btn1->setText(QApplication::translate("ParkOneWin", "1", 0));
        label_6->setText(QApplication::translate("ParkOneWin", "\345\211\251\344\275\231\350\275\246\344\275\215:", 0));
        btn2->setText(QApplication::translate("ParkOneWin", "2", 0));
        dataLa->setText(QString());
        upBt->setText(QString());
        label_9->setText(QApplication::translate("ParkOneWin", "\345\201\234\350\275\246\346\227\266\351\227\264:", 0));
        label_10->setText(QApplication::translate("ParkOneWin", "\345\201\234\350\275\246\350\264\271\347\224\250\357\274\232", 0));
        parkDaLa->setText(QString());
        monLa->setText(QString());
        label->setText(QApplication::translate("ParkOneWin", "\346\227\245\346\234\237:", 0));
        label_2->setText(QApplication::translate("ParkOneWin", "\346\227\266\351\227\264\357\274\232", 0));
        btn6->setText(QApplication::translate("ParkOneWin", "6", 0));
        label_3->setText(QApplication::translate("ParkOneWin", "\345\244\251\346\260\224\357\274\232", 0));
        adminBt->setText(QApplication::translate("ParkOneWin", "\347\256\241\347\220\206\345\221\230", 0));
        rightBt->setText(QString());
        carLa->setText(QString());
        kahao->setText(QString());
        label_4->setText(QApplication::translate("ParkOneWin", "\345\275\223\345\211\215\350\275\246\347\211\214\345\215\241\345\217\267", 0));
        menu->setTitle(QApplication::translate("ParkOneWin", "\347\254\254\344\272\214\345\201\234\350\275\246\345\234\272", 0));
    } // retranslateUi

};

namespace Ui {
    class ParkOneWin: public Ui_ParkOneWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARKONEWIN_H
