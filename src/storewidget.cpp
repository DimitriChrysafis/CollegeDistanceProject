#include "storewidget.h"

/**
    * @brief Souvenir Constructor for creating a souvenir item.
    * @param name The name of the souvenir item.
    * @param desc The description of the souvenir item.
    * @param price The price of the souvenir item.
    * @param parent The parent widget.
    */
Souvenir::Souvenir(QString name, QString desc, double price, QWidget *parent)
    : QWidget(parent)
{
    itemName = name;
    itemDescription = desc;
    itemPrice = price;
    cartQuantity = 0;
    createLayout();
}

/**
    * @brief getQuantity Get the quantity of the souvenir item.
    * @return The quantity of the souvenir item.
    */
int Souvenir::getQuantity() const
{
    return cartQuantity;
}
/**
     * @brief getPrice Get the total price of the souvenir item.
     * @return The total price of the souvenir item.
     */
double Souvenir::getPrice() const
{
    return itemPrice * cartQuantity;
}
/**
   * @brief isInCart Check if the souvenir item is in the cart.
   * @return True if the item is in the cart, otherwise false.
   */
bool Souvenir::isInCart() const
{
    return inCart;
}
/**
    * @brief getInfo Get information about the souvenir item.
    * @return Information about the souvenir item.
    */
QString Souvenir::getInfo() const
{
    QString info = itemName + ": " + QString::number(cartQuantity) + "*";
    info.append(QString::number(itemPrice, 'f', 2) + " = $" + QString::number(getPrice(), 'f', 2));
    info.append("\n");
    return info;
}

//"AddToCart" and "Remove From Cart" button handler
/**
 * @brief Souvenir::cartClicked Handles the "Add To Cart" and "Remove From Cart" button clicks.
 * Toggles the item's status in the cart, updates UI accordingly, and emits a signal.
 */
void Souvenir::cartClicked()
{
    inCart = !inCart;
    if (inCart) {
        moveCart->setText("Remove From Cart");
    } else {
        moveCart->setText("Add To Cart");
        amountInCart->setValue(0);
    }
    emit moveMe(this);
    parentWidget()->update();
}

/**
 * @brief Souvenir::amtChanged Handles the change in the quantity of the souvenir item.
 * @param newVal The new value of the quantity.
 */
void Souvenir::amtChanged(int newVal)
{
    cartQuantity = newVal;
    if (inCart && newVal == 0)
        cartClicked();
    if (!inCart && newVal == 0)
        moveCart->setEnabled(false);
    else
        moveCart->setEnabled(true);
}

/**
 * @brief Souvenir::createLayout Constructs the layout of the souvenir item.
 * Creates and configures the UI components for the item, such as labels and buttons.
 */
void Souvenir::createLayout()
{
    QHBoxLayout *layout_ = new QHBoxLayout(this);
    QLabel *name = new QLabel(itemName);
    name->setMinimumWidth(110);
    name->setWordWrap(true);
    name->setAlignment(Qt::AlignCenter);
    amountInCart = new QSpinBox;
    connect(amountInCart, QOverload<int>::of(&QSpinBox::valueChanged), this, &Souvenir::amtChanged);

    moveCart = new QPushButton("Add To Cart");
    moveCart->setEnabled(false);
    connect(moveCart, &QPushButton::clicked, this, &Souvenir::cartClicked);
    amountInCart->setRange(0, 99);

    QLabel *price = new QLabel("$" + QString::number(itemPrice, 'f', 2));
    price->setMinimumWidth(40);

    layout_->addWidget(name);
    layout_->addWidget(price);
    layout_->addWidget(amountInCart);
    layout_->addWidget(moveCart);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

/**
 * @brief CampusStore::CampusStore Constructor for creating a campus store.
 * @param collegeName The name of the college associated with the store.
 * @param parent The parent widget.
 */
CampusStore::CampusStore(QString collegeName, QWidget *parent)
    : QWidget(parent)
    , name(collegeName)
{
    createLayout();
}

/**
 * @brief CampusStore::createLayout Called on construction, builds layout of store.
 */
void CampusStore::createLayout()
{
    storeShelf = new QGroupBox("Souvenirs Store");
    storeShelf->setContentsMargins(10, 10, 10, 10);
    cartShelf = new QGroupBox("Your Cart");
    cartShelf->setContentsMargins(10, 10, 10, 10);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(storeShelf);
    mainLayout->addWidget(cartShelf);
    setMaximumSize(755, 310);
    setMinimumSize(755, 310);
    resize(755, 310);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    storeItems = new QVBoxLayout();
    cartItems = new QVBoxLayout();
    storeItems->addStretch();
    cartItems->addStretch();
    cartShelf->setLayout(cartItems);
    storeShelf->setLayout(storeItems);
}

// Add item to store shelf
/**
 * @brief CampusStore::addItem Add item to store shelf.
 * @param name The name of the souvenir item.
 * @param desc The description of the souvenir item.
 * @param price The price of the souvenir item.
 */
void CampusStore::addItem(QString name, QString desc, double price)
{
    Souvenir *item = new Souvenir(name, desc, price);                  //create new souvenir
    storeItems->insertWidget(storeShelf->layout()->count() - 1, item); //insert before empty stretch
    connect(item, &Souvenir::moveMe, this, &CampusStore::moveToCart);
}

// Called in Souvenir::cartClicked, moved item from ui storeshelf to cartshelf
/**
 * @brief CampusStore::moveToCart Called in Souvenir::cartClicked, moved item from ui storeshelf to cartshelf.
 * @param guyToMove Pointer to the souvenir item to be moved.
 */
void CampusStore::moveToCart(Souvenir *guyToMove)
{
    if (guyToMove->isInCart()) {
        cart.push_back(guyToMove); //Add to vector of items in cart

        storeItems->removeWidget(guyToMove); //Move 'guytomove' from store to cart ui
        cartItems->insertWidget(cartItems->count() - 1, guyToMove);
    } else {
        auto iter = std::find(cart.begin(), cart.end(), guyToMove);
        if (iter != cart.end())
            cart.erase(iter); //Remove from vector of items in cart

        cartItems->removeWidget(guyToMove); //Move 'guytomove' from cart to store ui
        storeItems->insertWidget(storeItems->count() - 1, guyToMove);
    }
    updateCart();
    parentWidget()->update();
}

// Update total receipt price
/**
 * @brief CampusStore::updateCart Update total receipt price.
 */
void CampusStore::updateCart()
{
    double sum = 0;
    for (auto &item : cart)
        sum += item->getPrice();

    std::cout << width() << '\n';
    std::cout << "$" << sum << '\n';
}
