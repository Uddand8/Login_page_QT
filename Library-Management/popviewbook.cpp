#include "popviewbook.h"
#include "ui_popviewbook.h"
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
popviewbook::popviewbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popviewbook)
{
    ui->setupUi(this);
    setWindowTitle("VIEW BOOK ");

    QFile file("C:/Users/DTIOT0005/Documents/Library-Management/ADDBOOKdata.xls");
    if(!file.open(QFile::ReadOnly)){
        QMessageBox::warning(this," ","File Not open");
    }
    QTextStream In(&file);
    QString view = In.readAll();
    ui->textEdit->setText(view);
//    ui->plainTextEdit->text;

    file.close();

}

popviewbook::~popviewbook()
{
    delete ui;

}


void popviewbook::on_pushButton_clicked()
{
    close();
}

