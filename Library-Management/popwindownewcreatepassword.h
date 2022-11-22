#ifndef POPWINDOWNEWCREATEPASSWORD_H
#define POPWINDOWNEWCREATEPASSWORD_H

#include <QDialog>

namespace Ui {
class popwindownewcreatepassword;
}

class popwindownewcreatepassword : public QDialog
{
    Q_OBJECT

public:
    explicit popwindownewcreatepassword(QWidget *parent = nullptr);
    ~popwindownewcreatepassword();

private slots:
    void on_pushButton_clicked();

private:
    Ui::popwindownewcreatepassword *ui;

};

#endif // POPWINDOWNEWCREATEPASSWORD_H
