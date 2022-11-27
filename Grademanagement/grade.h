#ifndef GRADE_H
#define GRADE_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
#include "gradeupdate.h"
namespace Ui {
class grade;
}

class grade : public QWidget
{
    Q_OBJECT

public:
    explicit grade(QWidget *parent = 0);
    ~grade();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::grade *ui;
};

#endif // GRADE_H
