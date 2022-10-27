#ifndef FORMPARK_H
#define FORMPARK_H

#include <QWidget>

namespace Ui {
class Formpark;
}

class Formpark : public QWidget
{
    Q_OBJECT

public:
    explicit Formpark(QWidget *parent = nullptr);
    ~Formpark();

private:
    Ui::Formpark *ui;
};

#endif // FORMPARK_H
