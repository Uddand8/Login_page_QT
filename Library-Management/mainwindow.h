#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "popupwindowsignin.h"
#include "popuploginwindow.h"
#include "popwindownewcreatepassword.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_login_clicked();

    void on_pushButton_createaccount_clicked();



    void on_pushButton_forgotpassword_clicked();

private:
    Ui::MainWindow *ui;
    popupwindowSignIn *popupsigin;
    popuploginwindow *poplogin;
    popwindownewcreatepassword *newctreatepassword;
};
#endif // MAINWINDOW_H
