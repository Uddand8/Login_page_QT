#ifndef POPRETURBOOK_H
#define POPRETURBOOK_H

#include <QDialog>

namespace Ui {
class popreturbook;
}

class popreturbook : public QDialog
{
    Q_OBJECT

public:
    explicit popreturbook(QWidget *parent = nullptr);
    ~popreturbook();

private:
    Ui::popreturbook *ui;
};

#endif // POPRETURBOOK_H
