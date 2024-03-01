#ifndef ASUDIALOG_H
#define ASUDIALOG_H

#include <QDialog>

namespace Ui {
class ASUDialog;
}

class ASUDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ASUDialog(QWidget *parent = nullptr);
    ~ASUDialog();

    int getNum();
    bool getOk();
    void reset();

private slots:
    void on_button_ok_clicked();

    void on_button_cancel_clicked();

private:
    Ui::ASUDialog *ui;

    int _num;
    bool _ok;
};

#endif // ASUDIALOG_H
