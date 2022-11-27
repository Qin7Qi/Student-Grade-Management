#include "teacher.h"
#include "ui_teacher.h"

Teacher::Teacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teacher)
{
    ui->setupUi(this);
}

Teacher::~Teacher()
{
    delete ui;
}

void Teacher::on_pushButton_clicked()
{

}

void Teacher::on_pushButton_2_clicked()
{
    this->hide();
    Course* cou = new Course();
    cou->show();
}

void Teacher::on_pushButton_3_clicked()
{
    this->hide();
    grade* gra = new grade();
    gra->show();
}

void Teacher::on_pushButton_4_clicked()
{
    this->hide();
    Login* l = new Login();
    l->show();
}
