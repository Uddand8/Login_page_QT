#ifndef POPISSUEDBOOK_H
#define POPISSUEDBOOK_H

#include <QDialog>

namespace Ui {
class popissuedbook;
}

class popissuedbook : public QDialog
{
    Q_OBJECT

public:
    explicit popissuedbook(QWidget *parent = nullptr);
    ~popissuedbook();

private:
    Ui::popissuedbook *ui;
};

#endif // POPISSUEDBOOK_H
