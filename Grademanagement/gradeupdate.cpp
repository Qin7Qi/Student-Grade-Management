#include "gradeupdate.h"
#include "ui_gradeupdate.h"

Gradeupdate::Gradeupdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gradeupdate)
{
    ui->setupUi(this);
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
    QStringList str;
    query.exec("SELECT name FROM subject");
    str<<"";
    while (query.next()) {
        str<<query.value(0).toString();
    }
    ui->comboBox->clear();
    ui->comboBox->addItems(str);
}

Gradeupdate::~Gradeupdate()
{
    delete ui;
}

void Gradeupdate::on_pushButton_clicked()
{
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
    query.exec("SELECT Sno FROM student");
    QString sno = ui->lineEdit->text();
    QString subject = ui->comboBox->currentText();
    QString grade = ui->lineEdit_2->text();
    bool p = 0;
    while (query.next()) {
        if (sno.compare(query.value(0).toString())==0){
            p = 1;
        }
    }
    if(p==0){
        QMessageBox::information(NULL,"infor","该学号不存在");
    }else{
        if(QString(subject).isEmpty()){
            QMessageBox::information(NULL,"infor","请选择科目");
        }else {
            if(QString(grade).isEmpty()){
                QMessageBox::information(NULL,"infor","请输入成绩");
            }else{
                QString sql = "UPDATE grade SET grade = '"+grade+"' WHERE Sno = '"+sno+"' AND subject = '"+subject+"'";
                bool ok = query.exec(sql);
                if(ok){
                    ui->label_4->setText(sno +":"+subject+"成绩已修改");
                }
            }
        }
    }

}

void Gradeupdate::on_pushButton_2_clicked()
{
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
    query.exec("SELECT Sno FROM student");
    QString sno = ui->lineEdit->text();
    QString subject = ui->comboBox->currentText();
    QString grade = ui->lineEdit_2->text();
    bool p = 0;
    while (query.next()) {
        if (sno.compare(query.value(0).toString())==0){
            p = 1;
        }
    }
    if(p==0){
        QMessageBox::information(NULL,"infor","该学号不存在");
    }else{
        if(QString(subject).isEmpty()){
            QMessageBox::information(NULL,"infor","请选择科目");
        }else {
            if(QString(grade).isEmpty()){
                QMessageBox::information(NULL,"infor","请输入成绩");
            }else{
                QString sql = "INSERT INTO grade VALUES ('"+sno+"','"+subject+"','"+grade+"')";
                bool ok = query.exec(sql);
                if(ok){
                    ui->label_4->setText(sno +":"+subject+"成绩添加");
                }
            }
        }
    }

}
