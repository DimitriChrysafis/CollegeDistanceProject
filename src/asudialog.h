#ifndef ASUDIALOG_H
#define ASUDIALOG_H

#include <QDialog>

namespace Ui {
class ASUDialog;
}

/**
 * @brief The ASUDialog class represents a dialog window for specifying the number of colleges to visit.
 *
 * This dialog allows the user to input the number of colleges they plan to visit in the college distance project.
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
     *
     * This function is typically used to set an upper limit on the number of colleges a user can input in the college distance project.
     */
    void setMax(int max);

    /**
     * @brief Resets the number of colleges to visit to the default value (1).
     *
     * This function is called to reset the number of colleges to visit to its default value whenever needed in the college distance project.
     */
    void reset();

private slots:
    /**
             * @brief Handles the click event of the OK button.
             *
             * Sets the number of colleges to visit and closes the dialog.
             * This function is called when the user clicks the OK button to confirm the input in the college distance project.
             */
    void on_button_ok_clicked();

    /**
     * @brief Handles the click event of the Cancel button.
     *
     * Closes the dialog without saving any changes.
     * This function is called when the user clicks the Cancel button to cancel the input in the college distance project.
     */
    void on_button_cancel_clicked();

private:
    Ui::ASUDialog *ui; /**< UI object for ASUDialog. */
    int _num; /**< Number of colleges to visit. */
    bool _ok; /**< Status of the dialog (OK or Cancel). */
};

#endif // ASUDIALOG_H
