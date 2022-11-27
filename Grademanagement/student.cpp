#include "student.h"
#include "ui_student.h"

Student::Student(QString id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    this->sid = id;
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
    query.exec("SELECT Sno,Sname,born,major,Sclass FROM student WHERE Sno = '"+id+"'");
    QStringList str;
    query.next();
    QString sno = query.value(0).toString();
    QString sname = query.value(1).toString();
    QString born = query.value(2).toString();
    QString major = query.value(3).toString();
    this->smajor = major;
    QString sclass = query.value(4).toString();
    str<<sno<<sname<<born<<major<<sclass;
    qDebug()<<sno<<sname<<born<<major<<sclass;
    int column = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(column);
    for(int i=0;i<str.size();i++){
        QTableWidgetItem* item = new QTableWidgetItem;
        item->setText(str.at(i));
        ui->tableWidget->setItem(i,column,item);
    }
}

Student::~Student()
{
    delete ui;
}

void Student::on_pushButton_clicked()
{
    QSqlDatabase db;
    QString term = ui->spinBox->text();
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }
    db.open();
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");
    for(int i=ui->tableWidget_2->rowCount();i>=0;i--){
        ui->tableWidget_2->removeRow(i);
    }
    if(term.compare("0")==0){
        QString sql = "SELECT subject,grade,term "
                      "FROM ("
                        "SELECT grade.Sno,grade.subject,grade.grade,exam.term "
                        "FROM grade INNER JOIN exam ON grade.subject = exam.subject WHERE exam.major = '"+this->smajor+"') "
                      "AS ge WHERE Sno = '"+this->sid+"'";
        query.exec(sql);
        QVariantList grade_info;
        while (query.next()) {
            QStringList sl;
            QString subject = query.value(0).toString();
            QString grade = query.value(1).toString();
            QString term = query.value(2).toString();
            sl<<subject<<grade<<term;
            grade_info.append(sl);
        }

        for(int i=0;i<grade_info.size();i++){
            qDebug()<<grade_info[i];
            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);
            QStringList rowdata = grade_info[i].toStringList();
            for(int j=0;j<rowdata.size();j++){
                QTableWidgetItem* item = new QTableWidgetItem;
                item->setText(rowdata.at(j));
                ui->tableWidget_2->setItem(row,j,item);
            }
        }

    }else {
        QString sql = "SELECT subject,grade,term "
                      "FROM ("
                        "SELECT grade.Sno,grade.subject,grade.grade,exam.term "
                        "FROM grade INNER JOIN exam ON grade.subject = exam.subject WHERE exam.major = '"+this->smajor+"') "
                      "AS ge WHERE Sno = '"+this->sid+"' AND term = '"+term+"'";
        query.exec(sql);
        QVariantList grade_info;
        while (query.next()) {
            QStringList sl;
            QString subject = query.value(0).toString();
            QString grade = query.value(1).toString();
            QString term = query.value(2).toString();
            sl<<subject<<grade<<term;
            grade_info.append(sl);
        }

        for(int i=0;i<grade_info.size();i++){
            qDebug()<<grade_info[i];
            int row = ui->tableWidget_2->rowCount();
            ui->tableWidget_2->insertRow(row);
            QStringList rowdata = grade_info[i].toStringList();
            for(int j=0;j<rowdata.size();j++){
                QTableWidgetItem* item = new QTableWidgetItem;
                item->setText(rowdata.at(j));
                ui->tableWidget_2->setItem(row,j,item);
            }
        }

    }
}

void Student::on_pushButton_2_clicked()
{
    this->hide();
    Login* l = new Login();
    l->show();
}
