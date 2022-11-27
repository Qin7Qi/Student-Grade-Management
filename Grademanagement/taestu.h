#ifndef TAESTU_H
#define TAESTU_H

#include <QWidget>

namespace Ui {
class Taestu;
}

class Taestu : public QWidget
{
    Q_OBJECT

public:
    explicit Taestu(QWidget *parent = 0);
    ~Taestu();

private:
    Ui::Taestu *ui;
};

#endif // TAESTU_H
