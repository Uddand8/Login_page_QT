#include "popuploginwindow.h"
#include "ui_popuploginwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
popuploginwindow::popuploginwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popuploginwindow)
{
    ui->setupUi(this);
    setWindowTitle("BOOK MENU ");

}
popuploginwindow::~popuploginwindow()
{
    delete ui;
}
void popuploginwindow::on_pushButton_ADDBOOKS_clicked()
{
    addbook=new popaddbook(this);
    addbook->show();
}
void popuploginwindow::on_pushButton_VIEWBOOKS_clicked()
{
    viewbook=new popviewbook(this);
    viewbook->show();
}
void popuploginwindow::on_pushButton_ISSUEDBOOKS_clicked()
{
    issuebook=new popissuedbook(this);
    issuebook->show();
}
void popuploginwindow::on_pushButton_RETURNBOOKS_clicked()
{
    returnbook=new popreturbook(this);
    returnbook->show();
}

