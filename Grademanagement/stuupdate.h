#ifndef STUUPDATE_H
#define STUUPDATE_H

#include <QWidget>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class Stuupdate;
}

class Stuupdate : public QWidget
{
    Q_OBJECT

public:
    explicit Stuupdate(QWidget *parent = 0);
    ~Stuupdate();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Stuupdate *ui;
};

#endif // STUUPDATE_H
