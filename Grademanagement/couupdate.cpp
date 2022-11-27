#include "couupdate.h"
#include "ui_couupdate.h"

couupdate::couupdate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::couupdate)
{
    ui->setupUi(this);
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }
    QStringList str,str1;
    db.open();
    QSqlQuery query(db);
    db.exec("SET NAMES 'UTF-8'");

    str<<"";
    str1<<"";
    query.exec("SELECT Mname FROM major");
    while (query.next()) {
        str<<query.value(0).toString();
    }
    query.exec("SELECT name FROM subject");
    while (query.next()) {
        str1<<query.value(0).toString();
    }
    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox->addItems(str);
    ui->comboBox_2->addItems(str1);
}

couupdate::~couupdate()
{
    delete ui;
}

void couupdate::on_pushButton_clicked()
{
    QString mname = ui->comboBox->currentText();
    QString sname = ui->comboBox_2->currentText();
    QString term = ui->spinBox->text();
    QString class_ = ui->lineEdit->text();

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }
    db.open();
    db.exec("SET NAMES 'UTF-8'");
    QSqlQuery query(db);

    if(QString(mname).isEmpty()){
        QMessageBox::information(NULL,"infor","专业为空");
    }else {
        if(QString(sname).isEmpty()){
            QMessageBox::information(NULL,"infor","课程为空");
        }else {
            if(term.compare("0")!=0){
                QString sql = "UPDATE exam SET term = '"+term+"' WHERE major = '"+mname+"' AND subject = '"+sname+"'";
                bool ok = query.exec(sql);
                if(ok){
                    qDebug()<<"修改成功";
                    ui->label_5->setText(mname+"专业"+sname+"课程信息已修改");
                }
            }
            if(!QString(class_).isEmpty()){
                QString sql = "UPDATE exam SET class = '"+class_+"' WHERE major = '"+mname+"' AND subject = '"+sname+"'";
                bool ok = query.exec(sql);
                if(ok){
                    qDebug()<<"修改成功";
                    ui->label_5->setText(mname+"专业"+sname+"课程信息已修改");
                }
            }
        }
    }

}

void couupdate::on_pushButton_3_clicked()
{
    QString mname = ui->comboBox->currentText();
    QString sname = ui->comboBox_2->currentText();
    QString term = ui->spinBox->text();
    QString class_ = ui->lineEdit->text();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        db = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        Sysmysql s;
        db = s.db;
    }
    db.open();
    db.exec("SET NAMES 'UTF-8'");
    QSqlQuery query(db);
    if(QString(mname).isEmpty()){
        QMessageBox::information(NULL,"infor","专业为空");
    }else {
        if(QString(sname).isEmpty()){
            QMessageBox::information(NULL,"infor","课程为空");
        }else {
            if(term.compare("0")==0){
                QMessageBox::information(NULL,"infor","请设置学期");
            }else{
                if(QString(class_).isEmpty()){
                    QMessageBox::information(NULL,"infor","请输入考试类型");
                }else {
                    QString sql = "INSERT INTO exam VALUES ('"+mname+"','"+sname+"','"+term+"','"+class_+"')";
                    bool ok = query.exec(sql);
                    if(ok){
                        qDebug()<<"添加成功";
                        ui->label_5->setText(mname+"专业"+sname+"课程信息已添加");
                    }
                }
            }
        }
    }
}
