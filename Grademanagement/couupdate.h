#ifndef COUUPDATE_H
#define COUUPDATE_H

#include <QWidget>
#include "sysmysql.h"
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class couupdate;
}

class couupdate : public QWidget
{
    Q_OBJECT

public:
    explicit couupdate(QWidget *parent = 0);
    ~couupdate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::couupdate *ui;
};

#endif // COUUPDATE_H
