#ifndef COURSE_H
#define COURSE_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include "couupdate.h"
namespace Ui {
class Course;
}

class Course : public QWidget
{
    Q_OBJECT

public:
    explicit Course(QWidget *parent = 0);
    ~Course();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Course *ui;
};

#endif // COURSE_H
