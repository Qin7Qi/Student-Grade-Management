#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
#include "login.h"
namespace Ui {
class Student;
}

class Student : public QWidget
{
    Q_OBJECT

public:
    QString sid;
    QString smajor;
    explicit Student(QString id,QWidget *parent = 0);
    ~Student();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Student *ui;
};

#endif // STUDENT_H
