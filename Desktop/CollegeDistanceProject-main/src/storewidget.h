#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include <QListView>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QString>
#include <QGroupBox>
#include <QScrollArea>
#include <iostream>

/**
 * @brief The Souvenir class represents an individual souvenir item in the campus store.
 */
class Souvenir : public QWidget {
    Q_OBJECT;

public:
    /**
     * @brief Constructs a new Souvenir object.
     * @param name The name of the souvenir.
     * @param desc The description of the souvenir.
     * @param price The price of the souvenir.
     * @param parent Pointer to the parent widget.
     */
    explicit Souvenir(QString name, QString desc, double price, QWidget* parent = nullptr);

    /**
     * @brief Gets the quantity of the souvenir in the cart.
     * @return The quantity of the souvenir in the cart.
     */
    int getQuantity() const;

    /**
     * @brief Gets the price of the souvenir.
     * @return The price of the souvenir.
     */
    double getPrice() const;

    /**
     * @brief Checks if the souvenir is in the cart.
     * @return True if the souvenir is in the cart, otherwise false.
     */
    bool isInCart() const;

    /**
     * @brief Gets information about the souvenir.
     * @return A QString containing information about the souvenir.
     */
    QString getInfo() const;

public slots:
    /**
     * @brief Handles the click event of the cart button.
     */
    void cartClicked();

    /**
     * @brief Handles the change event of the quantity spin box.
     * @param newVal The new value of the quantity.
     */
    void amtChanged(int newVal);

signals:
    /**
     * @brief Signal emitted to move the souvenir.
     * @param me Pointer to the Souvenir object to be moved.
     */
    void moveMe(Souvenir* me);

private:
    /**
     * @brief Creates the layout for the souvenir widget.
     */
    void createLayout();

    QString itemName; /**< The name of the souvenir. */
    QString itemDescription; /**< The description of the souvenir. */
    QLabel* price; /**< Label displaying the price of the souvenir. */
    QSpinBox* amountInCart; /**< Spin box for selecting the quantity in the cart. */
    QPushButton* moveCart; /**< Button to move the souvenir to/from the cart. */
    double itemPrice; /**< The price of the souvenir. */
    int cartQuantity; /**< The quantity of the souvenir in the cart. */
    bool inCart = false; /**< Flag indicating whether the souvenir is in the cart. */
};

/**
 * @brief The CampusStore class represents the campus store containing souvenirs.
 */
class CampusStore : public QWidget {
    Q_OBJECT;

public:
    /**
     * @brief Constructs a new CampusStore object.
     * @param collegeName The name of the college associated with the store.
     * @param parent Pointer to the parent widget.
     */
    explicit CampusStore(QString collegeName, QWidget* parent = nullptr);

    /**
     * @brief Adds a new item to the store.
     * @param name The name of the souvenir.
     * @param desc The description of the souvenir.
     * @param price The price of the souvenir.
     */
    void addItem(QString name, QString desc, double price);

    /**
     * @brief Gets information about items in the cart.
     * @return A QString containing information about items in the cart.
     */
    QString getCartInfo() const;

    /**
     * @brief Gets the total price of items in the cart.
     * @return The total price of items in the cart.
     */
    double getCartTotal() const;

public slots:
    /**
     * @brief Handles moving a souvenir to/from the cart.
     * @param guyToMove Pointer to the Souvenir object to be moved.
     */
    void moveToCart(Souvenir* guyToMove);

protected:
    /**
     * @brief Updates the cart display.
     */
    void updateCart();

private:
    /**
     * @brief Creates the layout for the campus store widget.
     */
    void createLayout();

    QString name; /**< The name of the college associated with the store. */
    std::vector<Souvenir*> cart; /**< Vector of pointers to souvenirs in the cart. */
    QLabel receipt; /**< Label displaying the cart receipt. */
    QVBoxLayout* storeItems; /**< Vertical layout for store items. */
    QVBoxLayout* cartItems; /**< Vertical layout for cart items. */
    QGroupBox* storeShelf; /**< Group box for store items. */
    QGroupBox* cartShelf; /**< Group box for cart items. */
};

#endif // STORE_H
