#include "admin.h"
#include "ui_admin.h"

Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_pushButton_clicked()
{
    this->hide();
    User* u = new User();
    u->show();
}

void Admin::on_pushButton_2_clicked()
{
    this->hide();
    Studentinfo* stu = new Studentinfo();
    stu->show();
}

void Admin::on_pushButton_3_clicked()
{
    this->hide();
    Teainfo* tea = new Teainfo();
    tea->show();
}

void Admin::on_pushButton_4_clicked()
{
    this->hide();
    Login* l = new Login();
    l->show();
}
