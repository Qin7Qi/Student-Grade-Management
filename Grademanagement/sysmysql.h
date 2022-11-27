#ifndef SYSMYSQL_H
#define SYSMYSQL_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

class Sysmysql
{

public:
    QSqlDatabase db;
    Sysmysql();
};

#endif // SYSMYSQL_H
