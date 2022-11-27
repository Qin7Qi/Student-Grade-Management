#include "studentinfo.h"
#include "ui_studentinfo.h"
#include "stuupdate.h"
Studentinfo::Studentinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Studentinfo)
{
    ui->setupUi(this);
    setWindowTitle(QString("学生信息"));
    QVariantList student_info;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        this->sdb = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        this->sdb = s.db;
    }

    //QSqlDatabase db = s->db;

    if(!this->sdb.open()){
        qDebug()<<"打开失败";
    }
    QSqlQuery query(this->sdb);
    this->sdb.exec("SET NAMES 'UTF-8'");

    QStringList str;
    str<<"";
    query.exec("SELECT Mname FROM major");
    while (query.next()) {
        str<<query.value(0).toString();
    }
    ui->comboBox->clear();
    ui->comboBox->addItems(str);

    query.exec("SELECT Sno,Sname,born,Sclass,major FROM student;");
    while (query.next()) {
        QStringList sl;
        sl.clear();
        QString Sno = query.value(0).toString();
        QString Sname = query.value(1).toString();
        QString born = query.value(2).toString();
        QString Sclass = query.value(3).toString();
        QString Smajor = query.value(4).toString();
        sl<<Sno<<Sname<<born<<Sclass<<Smajor;
        student_info.append(sl);
    }

    for(int i=0;i<student_info.size();i++){
        qDebug()<<student_info[i];
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = student_info[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }

}

Studentinfo::~Studentinfo()
{
    delete ui;
}

void Studentinfo::on_pushButton_clicked()
{
    this->on_pushButton_4_clicked();
}

void Studentinfo::on_pushButton_2_clicked()
{
    Stuupdate* update = new Stuupdate();
    update->show();
}

void Studentinfo::on_pushButton_3_clicked()
{
    this->hide();
    Admin* ad = new Admin();
    ad->show();
}

void Studentinfo::on_pushButton_4_clicked()
{
    QSqlDatabase db;
    QVariantList student_info;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }
    if(db.open()){
        qDebug()<<"打开成功";
    }
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8");
    QString class_ = ui->spinBox->text();
    QString major = ui->comboBox->currentText();
    for(int i=ui->tableWidget->rowCount();i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
    if(class_.compare("0")==0){
        if(QString(major).isEmpty()){
            query.exec("SELECT Sno,Sname,born,Sclass,major FROM student;");
            while (query.next()) {
                QStringList sl;
                sl.clear();
                QString Sno = query.value(0).toString();
                QString Sname = query.value(1).toString();
                QString born = query.value(2).toString();
                QString Sclass = query.value(3).toString();
                QString Smajor = query.value(4).toString();
                sl<<Sno<<Sname<<born<<Sclass<<Smajor;
                student_info.append(sl);
            }

            for(int i=0;i<student_info.size();i++){
                qDebug()<<student_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = student_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }
        }else{
            query.exec("SELECT Sno,Sname,born,Sclass,major FROM student WHERE major = '"+major+"'");
            while (query.next()) {
                QStringList sl;
                sl.clear();
                QString Sno = query.value(0).toString();
                QString Sname = query.value(1).toString();
                QString born = query.value(2).toString();
                QString Sclass = query.value(3).toString();
                QString Smajor = query.value(4).toString();
                sl<<Sno<<Sname<<born<<Sclass<<Smajor;
                student_info.append(sl);
            }

            for(int i=0;i<student_info.size();i++){
                qDebug()<<student_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = student_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }
        }
    }else {
        if(QString(major).isEmpty()){
            query.exec("SELECT Sno,Sname,born,Sclass,major FROM student WHERE Sclass = '"+class_+"'");
            while (query.next()) {
                QStringList sl;
                sl.clear();
                QString Sno = query.value(0).toString();
                QString Sname = query.value(1).toString();
                QString born = query.value(2).toString();
                QString Sclass = query.value(3).toString();
                QString Smajor = query.value(4).toString();
                sl<<Sno<<Sname<<born<<Sclass<<Smajor;
                student_info.append(sl);
            }

            for(int i=0;i<student_info.size();i++){
                qDebug()<<student_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = student_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }
        }else {
            query.exec("SELECT Sno,Sname,born,Sclass,major FROM student WHERE Sclass = '"+class_+"' AND major = '"+major+"'");
            while (query.next()) {
                QStringList sl;
                sl.clear();
                QString Sno = query.value(0).toString();
                QString Sname = query.value(1).toString();
                QString born = query.value(2).toString();
                QString Sclass = query.value(3).toString();
                QString Smajor = query.value(4).toString();
                sl<<Sno<<Sname<<born<<Sclass<<Smajor;
                student_info.append(sl);
            }

            for(int i=0;i<student_info.size();i++){
                qDebug()<<student_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = student_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }
        }
    }
}
