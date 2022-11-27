#ifndef TEAUPDATA_H
#define TEAUPDATA_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class Teaupdata;
}

class Teaupdata : public QWidget
{
    Q_OBJECT

public:
    explicit Teaupdata(QWidget *parent = 0);
    ~Teaupdata();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();
    
    void on_pushButton_3_clicked();

private:
    Ui::Teaupdata *ui;
};

#endif // TEAUPDATA_H
