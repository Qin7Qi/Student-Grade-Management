#ifndef USER_H
#define USER_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include "userupdate.h"
#include "admin.h"
namespace Ui {
class User;
}

class User : public QWidget
{
    Q_OBJECT

public:
    explicit User(QWidget *parent = 0);
    ~User();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::User *ui;
};

#endif // USER_H
