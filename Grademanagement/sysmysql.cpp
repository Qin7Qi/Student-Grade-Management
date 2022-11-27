#include "sysmysql.h"
#include <QtSql/QSqlError>
Sysmysql::Sysmysql()
{
    this->db = QSqlDatabase::addDatabase("QMYSQL");
    this->db.setHostName("localhost");
    this->db.setPort(3306);
    this->db.setUserName("root");
    this->db.setPassword("010118");
    this->db.setDatabaseName("grademanagement");
    bool ok = this->db.open();
    if(ok){
        qDebug()<<"数据库连接成功";

    }else{
        qDebug()<<"数据库连接失败"<<this->db.lastError().text();
    }
}
