#include "formpark.h"
#include "ui_formpark.h"

Formpark::Formpark(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formpark)
{
    ui->setupUi(this);
}

Formpark::~Formpark()
{
    delete ui;
}
