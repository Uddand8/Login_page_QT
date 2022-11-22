#include "popreturbook.h"
#include "ui_popreturbook.h"

popreturbook::popreturbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popreturbook)
{
    ui->setupUi(this);
}

popreturbook::~popreturbook()
{
    delete ui;
}
