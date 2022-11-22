#include "popwindownewcreatepassword.h"
#include "ui_popwindownewcreatepassword.h"
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
popwindownewcreatepassword::popwindownewcreatepassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popwindownewcreatepassword)
{
    ui->setupUi(this);
     ui->label->setText("<font color='white', size='4'>Username :</font>");
     ui->label_2->setText("<font color='white', size='4'>Password :</font>");
     ui->label_3->setText("<font color='white', size='4'>confirm Password :</font>");
}

popwindownewcreatepassword::~popwindownewcreatepassword()
{
    delete ui;
}

void popwindownewcreatepassword::on_pushButton_clicked()
{
    QString UserName=ui->lineEdit->text();
    QString PassWord=ui->lineEdit_2->text();
    QString Retypassword=ui->lineEdit_3->text();
    int usernameLen = ui->lineEdit->text().length();
    int passwordLen = ui->lineEdit_2->text().length();
    QString test=UserName + " " + PassWord;
    if(test == ""){
        QMessageBox::warning(this,"","LogIn Failed");
    }

            if(passwordLen >= 8 || passwordLen <= 12)
            {
                if((PassWord>='A' || PassWord<='Z') && (PassWord>='a' || PassWord<='z') && (PassWord>='48' || PassWord<='57') && (PassWord>='32' || PassWord<='47')
                        && (PassWord>='56' || PassWord<='64') && (PassWord>='91' || PassWord<='96') && (PassWord>='123' || PassWord<='126')){
                    if(PassWord==Retypassword && UserName != PassWord){
                        QFile file("C:/Users/DTIOT0005/Documents/Library-Management/SignInData.xls");
                        if(!file.open(QFile::WriteOnly | QFile::Append)){
                            QMessageBox::warning(this," ","File Not open");
                        }
                        if(file.pos()==0){
                            QTextStream Out(&file);
                            QString text = "User Name";
                            QString text1 = "PassWord";
                            Out<<text<<" "<<text1<<endl;
                        }
                        QTextStream Out(&file);
                        Out<<UserName<<" "<<PassWord<<endl;
                        file.close();
                        close();
                    }
                    else
                    {
                        QMessageBox::warning(this,"password","UserName & PassWord Must Not be Same ! ");
                    }
                }
            }
            else {
                QMessageBox::warning(this,"","password must be at least 8 - 12 characters ");
            }
        }


