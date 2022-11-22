#ifndef POPUPWINDOWSIGNIN_H
#define POPUPWINDOWSIGNIN_H

#include <QDialog>

namespace Ui {
class popupwindowSignIn;
}

class popupwindowSignIn : public QDialog
{
    Q_OBJECT

public:
    explicit popupwindowSignIn(QWidget *parent = nullptr);
    ~popupwindowSignIn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::popupwindowSignIn *ui;
     void checkforsinginornot(QString text);
      void loginor(int count);

};

#endif // POPUPWINDOWSIGNIN_H
