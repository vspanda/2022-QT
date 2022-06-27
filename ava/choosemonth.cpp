#include "choosemonth.h"
#include "ui_choosemonth.h"

choosemonth::choosemonth(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::choosemonth)
{
    ui->setupUi(this);
}

choosemonth::~choosemonth()
{
    delete ui;
}

