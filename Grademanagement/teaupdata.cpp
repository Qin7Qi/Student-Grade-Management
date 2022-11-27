#include "teaupdata.h"
#include "ui_teaupdata.h"

Teaupdata::Teaupdata(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teaupdata)
{
    ui->setupUi(this);
}

Teaupdata::~Teaupdata()
{
    delete ui;
}

void Teaupdata::on_pushButton_clicked()
{
    QString id = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }

    if(!db.open()){
        qDebug()<<"打开失败";
    }
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");
    if(QString(id).isEmpty()){
        QMessageBox::information(NULL,"infor","请输入ID");
    }else{
        if(!QString(password).isEmpty()){
            QString sql = "UPDATE teacher SET password = '"+password+"' WHERE id = '"+id+"'";
            bool ok = query.exec(sql);
            if(ok){
                ui->label_4->setText(id+":信息已修改");
            }
        }
        if(!QString(name).isEmpty()){
            QString sql = "UPDATE teacher SET name = '"+name+"' WHERE id = '"+id+"'";
            bool ok = query.exec(sql);
            if(ok){
                ui->label_4->setText(id+":信息已修改");
            }
        }
    }
}



void Teaupdata::on_pushButton_2_clicked()
{
    QString id = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    QString password = ui->lineEdit_3->text();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }

    if(!db.open()){
        qDebug()<<"打开失败";
    }
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");
    bool p = 0;
    query.exec("SELECT id FROM teacher");
    while (query.next()) {
        if(id.compare(query.value(0).toString())==0){
            p = 1;
        }
    }
    if(QString(id).isEmpty()){
        QMessageBox::information(NULL,"infor","请输入ID");
    }else{
        if(p){
            QMessageBox::information(NULL,"infor","ID已存在");
        }else{
            if(QString(name).isEmpty()){
                QMessageBox::information(NULL,"infor","请输入姓名");
            }else{
                if(QString(password).isEmpty()){
                    QMessageBox::information(NULL,"infor","请输入密码");
                }else {
                    QString sql = "INSERT INTO teacher VALUES ('"+id+"','"+name+"','"+password+"')";
                    bool ok = query.exec(sql);
                    if(ok){
                        ui->label_4->setText(id + ":信息已添加");
                    }
                }
            }
        }
    }
}

void Teaupdata::on_pushButton_3_clicked()
{
    this->hide();
}
