#include "stuupdate.h"
#include "ui_stuupdate.h"
#include "sysmysql.h"

Stuupdate::Stuupdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stuupdate)
{
    ui->setupUi(this);
    setWindowTitle(QString("修改学生信息"));
    QDate date = QDate::fromString("1900-1-1","yyyy-M-d");
    ui->dateEdit->setDate(date);
}

Stuupdate::~Stuupdate()
{
    delete ui;
}

void Stuupdate::on_pushButton_clicked()
{
    QString sno = ui->lineEdit->text();
    QString sname = ui->lineEdit_2->text();
    QString major = ui->lineEdit_3->text();
    QString born = ui->dateEdit->text();
    QString class_ = ui->spinBox->text();
    qDebug()<<sno<<sname<<major<<born<<class_;
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }
    bool p=0;
    if(!db.open()){
        qDebug()<<"打开失败";
    }
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");
    query.exec("SELECT Sno FROM student");
    while (query.next()) {
        if(sno.compare(query.value(0).toString())==0)
            p=1;
    }
    if(p){
        if(!QString(sname).isEmpty()){
            QString sql = "UPDATE student SET Sname = '"+sname+"' WHERE Sno = '"+sno+"'";
            bool ok = query.exec(sql);
            if(ok){
                qDebug()<<"修改成功";
                ui->label_6->setText("学号"+sno+"修改成功");
            }
        }
        if(!QString(major).isEmpty()){
            QString sql = "UPDATE student SET major = '"+major+"' WHERE Sno = '"+sno+"'";
            bool ok = query.exec(sql);
            if(ok){
                qDebug()<<"修改成功";
                ui->label_6->setText("学号"+sno+"修改成功");
            }
        }
        if(born.compare("1900/1/1")!=0){
            QString sql = "UPDATE student SET born = '"+born+"' WHERE Sno = '"+sno+"'";
            bool ok = query.exec(sql);
            if(ok){
                qDebug()<<"修改成功";
                ui->label_6->setText("学号"+sno+"修改成功");
            }
        }
        if(class_.compare("0")!=0){
            QString sql = "UPDATE student SET Sclass = '"+class_+"' WHERE Sno = '"+sno+"'";
            bool ok = query.exec(sql);
            if(ok){
                qDebug()<<"修改成功";
                ui->label_6->setText("学号"+sno+"修改成功");
            }
        }
    }else{
        qDebug()<<"该学号不存在";
        QMessageBox::information(NULL, "infor", "该学号不存在");
    }
}

void Stuupdate::on_pushButton_2_clicked()
{
    this->close();
}
