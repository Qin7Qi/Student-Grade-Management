#ifndef GRADEUPDATE_H
#define GRADEUPDATE_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class Gradeupdate;
}

class Gradeupdate : public QWidget
{
    Q_OBJECT

public:
    explicit Gradeupdate(QWidget *parent = 0);
    ~Gradeupdate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Gradeupdate *ui;
};

#endif // GRADEUPDATE_H
