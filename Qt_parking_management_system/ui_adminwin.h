/********************************************************************************
** Form generated from reading UI file 'adminwin.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIN_H
#define UI_ADMINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWin
{
public:
    QWidget *centralwidget;
    QLineEdit *nameEd;
    QLabel *label;
    QLineEdit *passEd;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *logBt;
    QPushButton *quitBt;
    QPushButton *pushButton;

    void setupUi(QMainWindow *AdminWin)
    {
        if (AdminWin->objectName().isEmpty())
            AdminWin->setObjectName(QStringLiteral("AdminWin"));
        AdminWin->resize(800, 480);
        AdminWin->setMinimumSize(QSize(800, 480));
        AdminWin->setMaximumSize(QSize(800, 480));
        centralwidget = new QWidget(AdminWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        nameEd = new QLineEdit(centralwidget);
        nameEd->setObjectName(QStringLiteral("nameEd"));
        nameEd->setGeometry(QRect(230, 90, 301, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(18);
        nameEd->setFont(font);
        nameEd->setStyleSheet(QLatin1String("border-radius:25px;\n"
"border:4px solid#00ffff;"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 10, 301, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(24);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        passEd = new QLineEdit(centralwidget);
        passEd->setObjectName(QStringLiteral("passEd"));
        passEd->setGeometry(QRect(230, 190, 301, 51));
        passEd->setFont(font);
        passEd->setStyleSheet(QLatin1String("border-radius:25px;\n"
"border:4px solid#00ffff;"));
        passEd->setMaxLength(12);
        passEd->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 100, 72, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 200, 72, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color: rgb(0, 255, 255);"));
        logBt = new QPushButton(centralwidget);
        logBt->setObjectName(QStringLiteral("logBt"));
        logBt->setGeometry(QRect(100, 290, 151, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(20);
        logBt->setFont(font2);
        logBt->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:4px solid#00ffff;"));
        quitBt = new QPushButton(centralwidget);
        quitBt->setObjectName(QStringLiteral("quitBt"));
        quitBt->setGeometry(QRect(470, 290, 151, 41));
        quitBt->setFont(font2);
        quitBt->setStyleSheet(QLatin1String("border-radius:15px;\n"
"border:4px solid#00ffff;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 190, 51, 41));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/image/eyeClose.png);\n"
""));
        AdminWin->setCentralWidget(centralwidget);

        retranslateUi(AdminWin);

        QMetaObject::connectSlotsByName(AdminWin);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWin)
    {
        AdminWin->setWindowTitle(QApplication::translate("AdminWin", "MainWindow", 0));
        label->setText(QApplication::translate("AdminWin", "\345\201\234\350\275\246\345\234\272\347\256\241\347\220\206\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("AdminWin", "\350\264\246\345\217\267\357\274\232", 0));
        label_3->setText(QApplication::translate("AdminWin", "\345\257\206\347\240\201\357\274\232", 0));
        logBt->setText(QApplication::translate("AdminWin", "\347\231\273\345\275\225", 0));
        quitBt->setText(QApplication::translate("AdminWin", "\351\200\200\345\207\272", 0));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdminWin: public Ui_AdminWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIN_H
