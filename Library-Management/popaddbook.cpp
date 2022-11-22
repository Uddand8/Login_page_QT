#include "popaddbook.h"
#include "ui_popaddbook.h"
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>

//QVector<QString>ADDBOOKS;
//QVector<QString>BookQty;
//static int count=0;
popaddbook::popaddbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popaddbook)
{
    ui->setupUi(this);
    setWindowTitle("ADD BOOK ");
  //  ui->comboBox->setText("<font color='white', size='8'></font>");
    ui->comboBox->setStyleSheet("background-lineEdit-color:'white'; color:'white';font size='5';");

}

popaddbook::~popaddbook()
{
    delete ui;
}

void popaddbook::on_pushButton_add_clicked()
{
    QString BookName=ui->lineEdit->text();
    QString NoOfQty =ui->comboBox->currentText();
    if(BookName=="" || NoOfQty =="Select Qty"){
        QMessageBox::warning(this,"","pls add book and qty");
    }
    else {
        QFile file("C:/Users/DTIOT0005/Documents/Library-Management/ADDBOOKdata.xls");

        if(!file.open(QFile::ReadOnly | QFile::Append)){
            QMessageBox::warning(this," ","File Not open");
        }
        if(file.pos()==0){
            QTextStream Out(&file);
            QString text = "Name of the Book";
            QString text1 = "Book Quantity";
            Out<<text<<"\t"<<text1<<endl;
        }
        QTextStream Out(&file);
        Out<<BookName<<"\t"<<NoOfQty<<endl;
        file.close();
        close();
        ui->lineEdit->clear();
    }

}


void popaddbook::on_pushButton_clicked()
{
    close();
}

