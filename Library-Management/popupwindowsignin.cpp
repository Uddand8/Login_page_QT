#include "popupwindowsignin.h"
#include "ui_popupwindowsignin.h"
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
popupwindowSignIn::popupwindowSignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::popupwindowSignIn)
{
    ui->setupUi(this);
    setWindowTitle("SIGNIN ");
    ui->label->setText("<font color='white', size='3'>Username :</font>");
    ui->label_2->setText("<font color='white', size='3'>PassWord :</font>");
    ui->label_3->setText("<font color='white', size='3'>Rety-password :</font>");
    ui->groupBox->setTitle("CREATE ACCOUNT ");

    QFile file("C:/Users/DTIOT0005/Documents/Library-Management/SignInData.xls");
    if(file.open(QFile::WriteOnly | QFile::Append)){
        if(file.pos()==0){
            QTextStream Out(&file);
            QString text = "User Name";
            QString text1 = "PassWord";
            Out<<text<<" "<<text1<<endl;
        }
    }
    file.close();
}
popupwindowSignIn::~popupwindowSignIn()
{
    delete ui;
}
QString username1;
QString password1;
QString retypassword1;
int passworlength;
void popupwindowSignIn::on_pushButton_clicked()
{
    QString UserName=ui->lineEdit->text();
    QString PassWord=ui->lineEdit_2->text();
    QString Retypassword=ui->lineEdit_3->text();
    int passwordLen = ui->lineEdit_2->text().length();
    username1=UserName;
    password1=PassWord;
    retypassword1=Retypassword;
    passworlength=passwordLen;
    if(passworlength >= 8)
    {
        if(( password1>='A' || password1<='Z') && ( password1>='a' ||  password1<='z') && ( password1>='48' ||  password1<='57') && ( password1>='32' ||  password1<='47')
                && ( password1>='56' || password1<='64') && ( password1>='91' || password1<='96') && ( password1>='123' ||  password1<='126')){
            if (password1 ==retypassword1 && username1 != password1){
                QString test=UserName + " " + PassWord;
                checkforsinginornot(test);
            } else{
                QMessageBox::warning(this,"","LogIn Failed");
            }
        }
        else {
            QMessageBox::warning(this,"password","UserName & PassWord Must Not be Same ! ");
        }
    }

    else {
         QMessageBox::warning(this,"","password must be at least 8 - 12 characters ");
    }
}
void popupwindowSignIn::checkforsinginornot(QString text)
{
    int count=0;
    QFile file("C:/Users/DTIOT0005/Documents/Library-Management/SignInData.xls");
    if(file.open(QFile::ReadOnly)){
        QTextStream In(&file);
        while (!In.atEnd()) {
            QString text2=In.readLine();
            if(text==text2) {
                count++;
            }
        }
        file.close();
        loginor(count);
    }
    close();
}

void popupwindowSignIn::loginor(int count)
{
    if(count==0){
        QFile file("C:/Users/DTIOT0005/Documents/Library-Management/SignInData.xls");
        if(file.open(QFile::WriteOnly | QFile::Append)) {
            QTextStream out(&file);
            out<<username1<<" "<<password1<<endl;
            file.close();
        }
    }
    else {
        QMessageBox::information(this,"","User Already exist ");
    }
}

