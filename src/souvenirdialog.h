#ifndef SOUVENIRDIALOG_H
#define SOUVENIRDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
    class SouvenirDialog;
}

/**
 * @brief The SouvenirDialog class represents a dialog for adding or editing souvenir items.
 */
class SouvenirDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new SouvenirDialog object.
     *
     * @param parent The parent widget.
     */
    explicit SouvenirDialog(QWidget *parent = nullptr);

    /**
     * @brief Destroys the SouvenirDialog object.
     */
    ~SouvenirDialog();

    /**
     * @brief Sets the item name and price for editing.
     *
     * @param name The item name.
     * @param price The price.
     */
    void editSouvenir(QString name, double price);

    /**
     * @brief Gets the item name entered in the dialog.
     *
     * @return QString The item name.
     */
    QString getItem();

    /**
     * @brief Gets the price entered in the dialog.
     *
     * @return double The price.
     */
    double getPrice();

    /**
     * @brief Gets the status of the dialog (OK or not).
     *
     * @return true If the OK button was clicked.
     * @return false If the Cancel button was clicked.
     */
    bool getOk();

private slots:
            /**
             * @brief Handles the Cancel button click event.
             */
            void on_button_cancel_clicked();

    /**
     * @brief Handles the OK button click event.
     *
     * Validates input and sets the item name and price.
     */
    void on_button_ok_clicked();

private:
    Ui::SouvenirDialog *ui; /**< Pointer to the UI object. */
    QString _item; /**< Stores the item name. */
    double _price; /**< Stores the item price. */
    bool _ok; /**< Stores the status of the dialog (OK or not). */
};

#endif // SOUVENIRDIALOG_H
