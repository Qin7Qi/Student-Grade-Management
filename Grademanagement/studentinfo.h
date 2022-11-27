#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QWidget>
#include "sysmysql.h"
#include "admin.h"
namespace Ui {
class Studentinfo;
}

class Studentinfo : public QWidget
{
    Q_OBJECT

public:
    QSqlDatabase sdb;
    explicit Studentinfo(QWidget *parent = 0);
    ~Studentinfo();
private slots:
    //刷新
    void on_pushButton_clicked();
    //修改

    //返回

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Studentinfo *ui;
};

#endif // STUDENTINFO_H
