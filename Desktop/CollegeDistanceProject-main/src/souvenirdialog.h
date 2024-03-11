#ifndef SOUVENIRDIALOG_H
#define SOUVENIRDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class SouvenirDialog;
}

/**
 * @brief The SouvenirDialog class represents a dialog window for managing souvenirs.
 */
class SouvenirDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new SouvenirDialog object.
     * @param parent Pointer to the parent widget.
     */
    explicit SouvenirDialog(QWidget *parent = nullptr);

    /**
     * @brief Destroys the SouvenirDialog object.
     */
    ~SouvenirDialog();

    /**
     * @brief Edits the details of a souvenir.
     * @param name The name of the souvenir.
     * @param price The price of the souvenir.
     */
    void editSouvenir(QString name, double price);

    /**
     * @brief Gets the name of the souvenir.
     * @return The name of the souvenir.
     */
    QString getItem();

    /**
     * @brief Gets the price of the souvenir.
     * @return The price of the souvenir.
     */
    double getPrice();

    /**
     * @brief Gets the status of the OK button.
     * @return True if the OK button is clicked, otherwise false.
     */
    bool getOk();

private slots:
    /**
     * @brief Handles the click event of the Cancel button.
     * Closes the dialog without saving any changes.
     */
    void on_button_cancel_clicked();

    /**
     * @brief Handles the click event of the OK button.
     * Saves the changes, closes the dialog, and sets the status of the OK button.
     */
    void on_button_ok_clicked();

private:
    Ui::SouvenirDialog *ui; /**< The UI object pointer. */
    QString _item; /**< The name of the souvenir. */
    double _price; /**< The price of the souvenir. */
    bool _ok; /**< Flag indicating whether the OK button is clicked. */
};

#endif // SOUVENIRDIALOG_H
