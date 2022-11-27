#include "grade.h"
#include "ui_grade.h"

grade::grade(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::grade)
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
    QStringList str,str1;
    str<<"";
    str1<<"";
    query.exec("SELECT Mname FROM major");
    while (query.next()) {
        str<<query.value(0).toString();
    }
    query.exec("SELEct name FROM subject");
    while (query.next()) {
        str1<<query.value(0).toString();
    }
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox->addItems(str);
    ui->comboBox_2->addItems(str1);
}

grade::~grade()
{
    delete ui;
}

void grade::on_pushButton_clicked()
{
    QString major = ui->comboBox->currentText();
    QString subject = ui->comboBox_2->currentText();
    QString sclass = ui->spinBox->text();
    QVariantList grade_info;
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
    for(int i=ui->tableWidget->rowCount();i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
    if(QString(major).isEmpty()){
        QMessageBox::information(NULL,"infor","请选择专业");
    }else {
        if(QString(subject).isEmpty()){
            QMessageBox::information(NULL,"infor","请选择科目");
        }else {
            QString sql = "SELECT Sno,Sname,grade FROM (SELECT student.Sno,student.Sname,student.major,student.Sclass,grade FROM student INNER JOIN grade ON student.Sno = grade.Sno WHERE Sclass = '"+sclass+"' AND major = '"+major+"' AND subject = '"+subject+"') AS gs";
            query.exec(sql);
            while (query.next()) {
                QStringList sl;
                QString sno = query.value(0).toString();
                QString sname = query.value(1).toString();
                QString grade = query.value(2).toString();
                sl<<sno<<sname<<grade;
                grade_info.append(sl);
            }
            for(int i=0;i<grade_info.size();i++){
                qDebug()<<grade_info[i];
                int row = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(row);
                QStringList rowdata = grade_info[i].toStringList();
                for(int j=0;j<rowdata.size();j++){
                    QTableWidgetItem* item = new QTableWidgetItem;
                    item->setText(rowdata.at(j));
                    ui->tableWidget->setItem(row,j,item);
                }
            }
        }
    }
}

void grade::on_pushButton_2_clicked()
{
    this->on_pushButton_clicked();
}

void grade::on_pushButton_3_clicked()
{
    Gradeupdate* g = new Gradeupdate();
    g->show();
}
