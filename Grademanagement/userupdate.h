#ifndef USERUPDATE_H
#define USERUPDATE_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class Userupdate;
}

class Userupdate : public QWidget
{
    Q_OBJECT

public:
    explicit Userupdate(QWidget *parent = 0);
    ~Userupdate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Userupdate *ui;
};

#endif // USERUPDATE_H
