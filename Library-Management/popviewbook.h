#ifndef POPVIEWBOOK_H
#define POPVIEWBOOK_H

#include <QDialog>

namespace Ui {
class popviewbook;
}

class popviewbook : public QDialog
{
    Q_OBJECT

public:
    explicit popviewbook(QWidget *parent = nullptr);
    ~popviewbook();

private slots:
    void on_pushButton_clicked();

private:
    Ui::popviewbook *ui;
};

#endif // POPVIEWBOOK_H
