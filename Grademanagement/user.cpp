#include "user.h"
#include "ui_user.h"

User::User(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::User)
{
    ui->setupUi(this);

}

User::~User()
{
    delete ui;
}

void User::on_pushButton_clicked()
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
    QVariantList uer_info;
    for(int i=ui->tableWidget->rowCount();i>=0;i--){
        ui->tableWidget->removeRow(i);
    }
    query.exec("SELECT * FROM admin");
    while (query.next()) {
        QStringList sl;
        sl.clear();
        QString id = query.value(0).toString();
        QString password = query.value(1).toString();
        sl<<id<<password;
        uer_info.append(sl);
    }
    for(int i=0;i<uer_info.size();i++){
        qDebug()<<uer_info[i];
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = uer_info[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

void User::on_pushButton_3_clicked()
{
    Userupdate* uu = new Userupdate();
    uu->show();
}

void User::on_pushButton_2_clicked()
{
    this->hide();
    Admin* ad = new Admin();
    ad->show();
}
