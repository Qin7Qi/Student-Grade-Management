#include "userupdate.h"
#include "ui_userupdate.h"

Userupdate::Userupdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Userupdate)
{
    ui->setupUi(this);
}

Userupdate::~Userupdate()
{
    delete ui;
}

void Userupdate::on_pushButton_clicked()
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
    //bool p=0;
    if(!db.open()){
        qDebug()<<"打开失败";
    }
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");
    if(QString(id).isEmpty()){
        QMessageBox::information(NULL,"infor","请输入ID");
    }else {
        if(QString(password).isEmpty()){
            QMessageBox::information(NULL,"infor","请输入密码");
        }else {
            QString sql = "UPDATE admin SET password = '"+password+"' WHERE id = '"+id+"'";
            bool ok = query.exec(sql);
            if(ok){
                ui->label_3->setText(id+":密码已修改");
            }
        }
    }
}

void Userupdate::on_pushButton_2_clicked()
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
    bool p = 0;
    if(!db.open()){
        qDebug()<<"打开失败";
    }
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");
    query.exec("SELECT id FROM admin");
    while (query.next()) {
        if(id.compare(query.value(0).toString())==0){
            p = 1;
        }
    }


    if(QString(id).isEmpty()){
        QMessageBox::information(NULL,"infor","请输入ID");
    }else {
        if(p){
            QMessageBox::information(NULL,"infor","ID已存在");
        }else{
            if(QString(password).isEmpty()){
                QMessageBox::information(NULL,"infor","请输入密码");
            }else {
                QString sql = "INSERT INTO admin VALUES ('"+id+"','"+password+"')";
                bool ok = query.exec(sql);
                if(ok){
                    ui->label_3->setText(id+":已添加");
                }
            }
        }
    }
}

void Userupdate::on_pushButton_3_clicked()
{
    this->hide();
}
