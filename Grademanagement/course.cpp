#include "course.h"
#include "ui_course.h"

Course::Course(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Course)
{
    ui->setupUi(this);
    QSqlDatabase db;
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
    query.exec("SELECT Mname FROM major");
    QStringList str;
    str<<"";
    while (query.next()) {
        str<<query.value(0).toString();
    }
    ui->comboBox->clear();
    ui->comboBox->addItems(str);
}

Course::~Course()
{
    delete ui;
}

void Course::on_pushButton_4_clicked()
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
    db.exec("SET NAMES 'UTF-8");
    QString major = ui->comboBox->currentText();
    QString term = ui->spinBox->text();
    QVariantList course_info;
    for(int i=ui->tableWidget->rowCount();i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
    if(QString(major).isEmpty()){
        if(term.compare("0")==0){
            QString sql = "SELECT major,NO,subject,term,class FROM exam INNER JOIN subject ON exam.subject = subject.name";
            query.exec(sql);
            while (query.next()) {
                QStringList sl;
                QString major = query.value(0).toString();
                QString NO = query.value(1).toString();
                QString subject = query.value(2).toString();
                QString term = query.value(3).toString();
                QString class_ = query.value(4).toString();
                sl<<major<<NO<<subject<<term<<class_;
                course_info.append(sl);
            }
            for(int i=0;i<course_info.size();i++){
                qDebug()<<course_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = course_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }

        }else{
            QString sql = "SELECT major,NO,subject,term,class FROM exam INNER JOIN subject ON exam.subject = subject.name WHERE term = '"+term+"'";
            query.exec(sql);
            while (query.next()) {
                QStringList sl;
                QString major = query.value(0).toString();
                QString NO = query.value(1).toString();
                QString subject = query.value(2).toString();
                QString term = query.value(3).toString();
                QString class_ = query.value(4).toString();
                sl<<major<<NO<<subject<<term<<class_;
                course_info.append(sl);
            }
            for(int i=0;i<course_info.size();i++){
                qDebug()<<course_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = course_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }
        }

    }else{
        if(term.compare("0")==0){
            QString sql = "SELECT major,NO,subject,term,class FROM exam INNER JOIN subject ON exam.subject = subject.name WHERE major = '"+major+"'";
            query.exec(sql);
            while (query.next()) {
                QStringList sl;
                QString major = query.value(0).toString();
                QString NO = query.value(1).toString();
                QString subject = query.value(2).toString();
                QString term = query.value(3).toString();
                QString class_ = query.value(4).toString();
                sl<<major<<NO<<subject<<term<<class_;
                course_info.append(sl);
            }
            for(int i=0;i<course_info.size();i++){
                qDebug()<<course_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = course_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }

        }else{
            QString sql = "SELECT major,NO,subject,term,class FROM exam INNER JOIN subject ON exam.subject = subject.name WHERE term = '"+term+"'AND major = '"+major+"'";
            query.exec(sql);
            while (query.next()) {
                QStringList sl;
                QString major = query.value(0).toString();
                QString NO = query.value(1).toString();
                QString subject = query.value(2).toString();
                QString term = query.value(3).toString();
                QString class_ = query.value(4).toString();
                sl<<major<<NO<<subject<<term<<class_;
                course_info.append(sl);
            }
            for(int i=0;i<course_info.size();i++){
                qDebug()<<course_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = course_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }
        }
    }
}

void Course::on_pushButton_clicked()
{
    this->on_pushButton_4_clicked();
}

void Course::on_pushButton_2_clicked()
{
    couupdate* c = new couupdate();
    c->show();
}
