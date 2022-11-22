#ifndef POPUPLOGINWINDOW_H
#define POPUPLOGINWINDOW_H

#include <QDialog>
#include "popaddbook.h"
#include "popviewbook.h"
#include "popissuedbook.h"
#include "popreturbook.h"

namespace Ui {
class popuploginwindow;
}

class popuploginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit popuploginwindow(QWidget *parent = nullptr);
    ~popuploginwindow();

private slots:
    void on_pushButton_ADDBOOKS_clicked();

    void on_pushButton_VIEWBOOKS_clicked();

    void on_pushButton_ISSUEDBOOKS_clicked();

    void on_pushButton_RETURNBOOKS_clicked();

private:
    Ui::popuploginwindow *ui;
    popaddbook *addbook;
    popviewbook *viewbook;
    popissuedbook *issuebook;
    popreturbook *returnbook;

};

#endif // POPUPLOGINWINDOW_H
