/********************************************************************************
** Form generated from reading UI file 'formpark.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMPARK_H
#define UI_FORMPARK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formpark
{
public:
    QPushButton *btn3;
    QPushButton *btn1;
    QPushButton *btn8;
    QPushButton *btn4;
    QPushButton *btn7;
    QPushButton *btn6;
    QPushButton *btn5;
    QPushButton *btn2;

    void setupUi(QWidget *Formpark)
    {
        if (Formpark->objectName().isEmpty())
            Formpark->setObjectName(QStringLiteral("Formpark"));
        Formpark->resize(800, 160);
        Formpark->setMinimumSize(QSize(800, 160));
        Formpark->setMaximumSize(QSize(800, 160));
        btn3 = new QPushButton(Formpark);
        btn3->setObjectName(QStringLiteral("btn3"));
        btn3->setGeometry(QRect(190, 0, 93, 161));
        btn3->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn1 = new QPushButton(Formpark);
        btn1->setObjectName(QStringLiteral("btn1"));
        btn1->setGeometry(QRect(10, 0, 93, 161));
        btn1->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn8 = new QPushButton(Formpark);
        btn8->setObjectName(QStringLiteral("btn8"));
        btn8->setGeometry(QRect(690, 0, 93, 161));
        btn8->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn4 = new QPushButton(Formpark);
        btn4->setObjectName(QStringLiteral("btn4"));
        btn4->setGeometry(QRect(280, 0, 93, 161));
        btn4->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn7 = new QPushButton(Formpark);
        btn7->setObjectName(QStringLiteral("btn7"));
        btn7->setGeometry(QRect(600, 0, 93, 161));
        btn7->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn6 = new QPushButton(Formpark);
        btn6->setObjectName(QStringLiteral("btn6"));
        btn6->setGeometry(QRect(510, 0, 93, 161));
        btn6->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn5 = new QPushButton(Formpark);
        btn5->setObjectName(QStringLiteral("btn5"));
        btn5->setGeometry(QRect(420, 0, 93, 161));
        btn5->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));
        btn2 = new QPushButton(Formpark);
        btn2->setObjectName(QStringLiteral("btn2"));
        btn2->setGeometry(QRect(100, 0, 93, 161));
        btn2->setStyleSheet(QStringLiteral("background-image: url(:/image/car.jpeg);"));

        retranslateUi(Formpark);

        QMetaObject::connectSlotsByName(Formpark);
    } // setupUi

    void retranslateUi(QWidget *Formpark)
    {
        Formpark->setWindowTitle(QApplication::translate("Formpark", "Form", 0));
        btn3->setText(QString());
        btn1->setText(QApplication::translate("Formpark", "123", 0));
        btn8->setText(QString());
        btn4->setText(QString());
        btn7->setText(QString());
        btn6->setText(QString());
        btn5->setText(QString());
        btn2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Formpark: public Ui_Formpark {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMPARK_H
