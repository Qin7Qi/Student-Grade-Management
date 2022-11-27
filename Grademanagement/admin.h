#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include "user.h"
#include "studentinfo.h"
#include "teainfo.h"
#include "login.h"
namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
