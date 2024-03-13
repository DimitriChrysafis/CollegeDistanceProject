#ifndef STORE_H
#define STORE_H

#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QListView>
#include <QPushButton>
#include <QScrollArea>
#include <QSpinBox>
#include <QString>
#include <QWidget>
#include <iostream>

/**
 * @brief The Souvenir class represents a souvenir item in the store.
 */
class Souvenir : public QWidget
{
    Q_OBJECT;

public:
    /**
     * @brief Constructor for creating a souvenir item.
     * @param name The name of the souvenir item.
     * @param desc The description of the souvenir item.
     * @param price The price of the souvenir item.
     * @param parent The parent widget.
     */
    explicit Souvenir(QString name, QString desc, double price, QWidget *parent = nullptr);
    int getQuantity() const; /**< Get the quantity of the souvenir item. */
    double getPrice() const; /**< Get the total price of the souvenir item. */
    bool isInCart() const;   /**< Check if the souvenir item is in the cart. */

    /**
     * @brief Get information about the souvenir item.
     * @return Information about the souvenir item.
     */
    QString getInfo() const;

public slots:
    /**
             * @brief Handles the "Add To Cart" and "Remove From Cart" button clicks.
             * Toggles the item's status in the cart, updates UI accordingly, and emits a signal.
             */
    void cartClicked();

    /**
     * @brief Handles the change in the quantity of the souvenir item.
     * @param newVal The new value of the quantity.
     */
    void amtChanged(int newVal);

signals:
    /**
             * @brief Signal emitted when the item needs to be moved to/from the cart.
             * @param me Pointer to the Souvenir object.
             */
    void moveMe(Souvenir *me);

private:
    /**
     * @brief Constructs the layout of the souvenir item.
     * Creates and configures the UI components for the item, such as labels and buttons.
     */
    void createLayout();

    QString itemName;
    QString itemDescription;

    QLabel *price;
    QSpinBox *amountInCart;
    QPushButton *moveCart;
    double itemPrice;
    int cartQuantity;
    bool inCart = false;
};

/**
 * @brief The CampusStore class represents a store that sells souvenirs.
 */
class CampusStore : public QWidget
{
    Q_OBJECT;

public:
    /**
     * @brief Constructor for creating a campus store.
     * @param collegeName The name of the college.
     * @param parent The parent widget.
     */
    explicit CampusStore(QString collegeName, QWidget *parent = nullptr);

    /**
     * @brief Adds an item to the store shelf.
     * @param name The name of the item.
     * @param desc The description of the item.
     * @param price The price of the item.
     */
    void addItem(QString name, QString desc, double price);

    /**
     * @brief Gets information about the items in the cart.
     * @return Information about the items in the cart.
     */
    QString getCartInfo() const;

    /**
     * @brief Gets the total price of the items in the cart.
     * @return The total price of the items in the cart.
     */
    double getCartTotal() const;

public slots:
    /**
             * @brief Moves an item to/from the cart.
             * @param guyToMove Pointer to the Souvenir object to be moved.
             */
    void moveToCart(Souvenir *guyToMove);

protected:
    /**
     * @brief Updates the total price of the items in the cart.
     */
    void updateCart();

private:
    /**
     * @brief Constructs the layout of the campus store.
     * Creates and configures the UI components for the store layout.
     */
    void createLayout();

    QString name;
    std::vector<Souvenir *> cart;
    QLabel receipt;

    QVBoxLayout *storeItems;
    QVBoxLayout *cartItems;

    QGroupBox *storeShelf;
    QGroupBox *cartShelf;
};

#endif
