#include "taestu.h"
#include "ui_taestu.h"

Taestu::Taestu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Taestu)
{
    ui->setupUi(this);
}

Taestu::~Taestu()
{
    delete ui;
}
