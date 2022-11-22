#ifndef POPADDBOOK_H
#define POPADDBOOK_H

#include <QDialog>

namespace Ui {
class popaddbook;
}

class popaddbook : public QDialog
{
    Q_OBJECT

public:
    explicit popaddbook(QWidget *parent = nullptr);
    ~popaddbook();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_clicked();

private:
    Ui::popaddbook *ui;

};

#endif // POPADDBOOK_H
