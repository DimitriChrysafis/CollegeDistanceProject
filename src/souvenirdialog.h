#ifndef SOUVENIRDIALOG_H
#define SOUVENIRDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SouvenirDialog;
}

class SouvenirDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SouvenirDialog(QWidget *parent = nullptr);
    ~SouvenirDialog();
    void editSouvenir(QString name, double price);
    QString getItem();
    double getPrice();
    bool getOk();

private slots:
    void on_button_cancel_clicked();
    void on_button_ok_clicked();

private:
    Ui::SouvenirDialog *ui;
    QString _item;
    double _price;
    bool _ok;
};

#endif // SOUVENIRDIALOG_H
