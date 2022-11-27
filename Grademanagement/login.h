#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
#include "student.h"
#include "teacher.h"
#include "admin.h"
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
