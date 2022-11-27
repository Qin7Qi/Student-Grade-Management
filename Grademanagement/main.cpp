#include "mainwindow.h"
#include "sysmysql.h"
#include <QApplication>
#include "studentinfo.h"
#include "stuupdate.h"
#include "course.h"
#include "grade.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //Studentinfo sinfo;
    //sinfo.show();
    Login c;
    c.show();
    return a.exec();
}
