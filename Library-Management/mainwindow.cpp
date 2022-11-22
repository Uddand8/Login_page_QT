#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
//#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("DELTA IOT LIBRARY MANAGEMENT SYSTEM : ");
//    QPixmap pix(":/resources/img/login-icon.png");
//       int w = ui->label_username->width();
//       int h = ui->label_password->height();
//       ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->label_username->setText("<font color='white', size='8'>Username :</font>");
    ui->label_password->setText("<font color='white', size='8'>Password :</font>");
    ui->labelSingIn->setText("<font color='white', size='5'>Creat New Account :</font>");
  }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    QString test=username + " " + password;
    if(test == ""){
        QMessageBox::warning(this,"","LogIn Failed");
    }
    else{
        QFile file("C:/Users/DTIOT0005/Documents/Library-Management/SignInData.xls");
        if(!file.open(QFile::ReadOnly)){
            QMessageBox::warning(this," ","File not found");
        }
        QTextStream In(&file);
        QString text;
        while (!In.atEnd()) {
            text=In.readLine();
            if(text==test){
                poplogin=new popuploginwindow(this);
                poplogin->show();
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                break;
            }


        }
        if(text!=test){
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            QMessageBox::warning(this,"","LogIn Failed");
        }

        file.close();
    }
}


void MainWindow::on_pushButton_createaccount_clicked()
{
    popupsigin = new popupwindowSignIn(this);
    popupsigin->show();
}


void MainWindow::on_pushButton_forgotpassword_clicked()
{
    newctreatepassword = new popwindownewcreatepassword(this);
    newctreatepassword->show();

}

