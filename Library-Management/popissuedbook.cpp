#include "popissuedbook.h"
#include "ui_popissuedbook.h"

popissuedbook::popissuedbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popissuedbook)
{
    ui->setupUi(this);
}

popissuedbook::~popissuedbook()
{
    delete ui;
}
