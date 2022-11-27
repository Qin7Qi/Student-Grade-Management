#include "teainfo.h"
#include "ui_teainfo.h"

Teainfo::Teainfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Teainfo)
{
    ui->setupUi(this);
}

Teainfo::~Teainfo()
{
    delete ui;
}

void Teainfo::on_pushButton_clicked()
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
    QVariantList tea_info;
    for(int i=ui->tableWidget->rowCount();i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
    query.exec("SELECT * FROM teacher");
    while (query.next()) {
        QStringList sl;
        sl.clear();
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString password = query.value(2).toString();
        sl<<id<<name<<password;
        tea_info.append(sl);
    }
    for(int i=0;i<tea_info.size();i++){
        qDebug()<<tea_info[i];
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = tea_info[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

void Teainfo::on_pushButton_2_clicked()
{
    Teaupdata* teaup = new Teaupdata();
    teaup->show();
}

void Teainfo::on_pushButton_3_clicked()
{
    this->hide();
    Admin* ad = new Admin();
    ad->show();
}
