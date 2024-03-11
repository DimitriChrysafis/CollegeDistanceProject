#ifndef ASUDIALOG_H
#define ASUDIALOG_H

#include <QDialog>

namespace Ui {
class ASUDialog;
}

/**
 * @brief The ASUDialog class represents a dialog window for inputting the number of colleges to visit.
 */
class ASUDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a new ASUDialog object.
     * @param parent Pointer to the parent widget.
     */
    explicit ASUDialog(QWidget *parent = nullptr);

    /**
     * @brief Destroys the ASUDialog object.
     */
    ~ASUDialog();

    /**
     * @brief Gets the number of colleges to visit.
     * @return The number of colleges to visit.
     */
    int getNum();

    /**
     * @brief Gets the status of the OK button.
     * @return True if the OK button is clicked, otherwise false.
     */
    bool getOk();

    /**
     * @brief Sets the maximum number of colleges that can be input.
     * @param max The maximum number of colleges.
     */
    void setMax(int max);

    /**
     * @brief Resets the number of colleges to visit to the default value (1).
     */
    void reset();

private slots:
    /**
     * @brief Handles the click event of the OK button.
     * Sets the number of colleges to visit and closes the dialog.
     */
    void on_button_ok_clicked();

    /**
     * @brief Handles the click event of the Cancel button.
     * Closes the dialog without saving any changes.
     */
    void on_button_cancel_clicked();

private:
    Ui::ASUDialog *ui; /**< The UI object pointer. */
    int _num; /**< The number of colleges to visit. */
    bool _ok; /**< Flag indicating whether the OK button is clicked. */
};

#endif // ASUDIALOG_H
