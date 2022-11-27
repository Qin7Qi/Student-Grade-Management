#ifndef TEAINFO_H
#define TEAINFO_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
#include "teaupdata.h"
#include "admin.h"
namespace Ui {
class Teainfo;
}

class Teainfo : public QWidget
{
    Q_OBJECT

public:
    explicit Teainfo(QWidget *parent = 0);
    ~Teainfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Teainfo *ui;
};

#endif // TEAINFO_H
