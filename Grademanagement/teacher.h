#ifndef TEACHER_H
#define TEACHER_H

#include <QWidget>
#include "course.h"
#include "grade.h"
#include "login.h"
namespace Ui {
class Teacher;
}

class Teacher : public QWidget
{
    Q_OBJECT

public:
    explicit Teacher(QWidget *parent = 0);
    ~Teacher();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Teacher *ui;
};

#endif // TEACHER_H
