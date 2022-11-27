#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->radioButton->setChecked(true);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }
    db.open();
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");
    if(ui->radioButton->isChecked()){
        query.exec("SELECT Sno,password FROM student");
        bool i=0,j=0;
        while (query.next()) {
            if(id.compare(query.value(0).toString())==0){
                i = 1;
            }
            if(password.compare(query.value(1).toString())==0){
                j = 1;
            }
        }
        //跳转
        if(i && j){
            this->hide();
            Student* stu = new Student(id);
            stu->show();
        }else {
            QMessageBox::information(NULL,"infor","ID或密码错误");
        }
    }
    if(ui->radioButton_2->isChecked()){
        query.exec("SELECT id,password FROM teacher");
        bool i=0,j=0;
        while (query.next()) {
            if(id.compare(query.value(0).toString())==0){
                i = 1;
            }
            if(password.compare(query.value(1).toString())==0){
                j = 1;
            }
        }
        //
        if(i && j){
            this->hide();
            Teacher* tea = new Teacher();
            tea->show();
        }else {
            QMessageBox::information(NULL,"infor","ID或密码错误");
        }
    }
    if(ui->radioButton_3->isChecked()){
        query.exec("SELECT id,password FROM admin");
        bool i=0,j=0;
        while (query.next()) {
            if(id.compare(query.value(0).toString())==0){
                i = 1;
            }
            if(password.compare(query.value(1).toString())==0){
                j = 1;
            }
        }
        //
        if(i && j){
            this->hide();
            Admin* ad = new Admin();
            ad->show();
        }else{
            QMessageBox::information(NULL,"infor","ID或密码错误");
        }
    }
}
