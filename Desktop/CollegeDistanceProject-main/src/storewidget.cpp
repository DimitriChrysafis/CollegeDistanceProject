#include "storewidget.h"

/**
 * @brief Constructs a new Souvenir object.
 * @param name The name of the souvenir.
 * @param desc The description of the souvenir.
 * @param price The price of the souvenir.
 * @param parent Pointer to the parent widget.
 */
Souvenir::Souvenir(QString name, QString desc, double price, QWidget* parent): QWidget(parent) {
    itemName = name;
    itemDescription = desc;
    itemPrice = price;
    cartQuantity = 0;
    createLayout();
}

/**
 * @brief Gets the quantity of the souvenir in the cart.
 * @return The quantity of the souvenir in the cart.
 */
int Souvenir::getQuantity() const { return cartQuantity; }

/**
 * @brief Gets the total price of the souvenir in the cart.
 * @return The total price of the souvenir in the cart.
 */
double Souvenir::getPrice() const { return itemPrice * cartQuantity; }

/**
 * @brief Checks if the souvenir is in the cart.
 * @return True if the souvenir is in the cart, otherwise false.
 */
bool Souvenir::isInCart() const { return inCart; }

/**
 * @brief Gets the information of the souvenir.
 * @return The information of the souvenir.
 */
QString Souvenir::getInfo() const {
    QString info = itemName + ": " + QString::number(cartQuantity) + "*";
    info.append(QString::number(itemPrice) + " = " + QString::number(getPrice()));
    info.append("\n");
    return info;
}

/**
 * @brief Handles the "Add To Cart" and "Remove From Cart" button click.
 * Emits the moveMe signal to notify the parent to move the souvenir.
 */
void Souvenir::cartClicked() {
    inCart = !inCart;
    if(inCart) {
        moveCart->setText("Remove From Cart");
    } else {
        moveCart->setText("Add To Cart");
        amountInCart->setValue(0);
    }
    emit moveMe(this);
}

/**
 * @brief Handles the quantity spin box value change.
 * Updates the cart quantity and enables/disables the "Add To Cart" button.
 * @param newVal The new value of the quantity spin box.
 */
void Souvenir::amtChanged(int newVal) {
    cartQuantity = newVal;
    if(inCart && newVal == 0) cartClicked();
    if(!inCart && newVal == 0) moveCart->setEnabled(false);
    else moveCart->setEnabled(true);
}

/**
 * @brief Creates the layout of the souvenir item.
 */
void Souvenir::createLayout() {
    QHBoxLayout* layout_ = new QHBoxLayout(this);
    QLabel* name = new QLabel(itemName);
    name->setMinimumWidth(110);
    name->setWordWrap(true);
    name->setAlignment(Qt::AlignCenter);
    amountInCart = new QSpinBox;
    connect(amountInCart, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &Souvenir::amtChanged);

    moveCart = new QPushButton("Add To Cart");
    moveCart->setEnabled(false);
    connect(moveCart, &QPushButton::clicked, this, &Souvenir::cartClicked);
    amountInCart->setRange(0, 99);

    QLabel* price = new QLabel("$" + QString::number(itemPrice));
    price->setMinimumWidth(40);

    layout_->addWidget(name);
    layout_->addWidget(price);
    layout_->addWidget(amountInCart);
    layout_->addWidget(moveCart);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

/**
 * @brief Constructs a new CampusStore object.
 * @param collegeName The name of the college store.
 * @param parent Pointer to the parent widget.
 */
CampusStore::CampusStore(QString collegeName, QWidget* parent): QWidget(parent), name(collegeName) {
    createLayout();
}

/**
 * @brief Creates the layout of the store widget.
 */
void CampusStore::createLayout() {
    storeShelf = new QGroupBox("Souvenirs Store");
    storeShelf->setContentsMargins(10, 10, 10, 10);
    cartShelf = new QGroupBox("Your Cart");
    cartShelf->setContentsMargins(10, 10, 10, 10);

    QHBoxLayout* mainLayout = new QHBoxLayout(this);
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

/**
 * @brief Adds an item to the store shelf.
 * @param name The name of the souvenir item.
 * @param desc The description of the souvenir item.
 * @param price The price of the souvenir item.
 */
void CampusStore::addItem(QString name, QString desc, double price) {
    Souvenir* item = new Souvenir(name, desc, price);
    storeItems->insertWidget(storeShelf->layout()->count() - 1, item);
    connect(item, &Souvenir::moveMe, this, &CampusStore::moveToCart);
}

/**
 * @brief Gets the information of items in the cart.
 * @return The information of items in the cart.
 */
QString CampusStore::getCartInfo() const {
    QString info = name;
    info.append("\n");
    for(auto& item: cart)
        info.append(item->getInfo());
    if(cart.empty()) info.append("Nothing Bought Here\n");
    else info.append("Total: " + QString::number(getCartTotal()) + "\n");
    info.append("\n");
    return info;
}

/**
 * @brief Gets the total price of items in the cart.
 * @return The total price of items in the cart.
 */
double CampusStore::getCartTotal() const {
    double total = 0.0;
    for(auto& item: cart) total += item->getPrice();
    return total;
}

/**
 * @brief Moves a souvenir item between the store shelf and the cart shelf.
 * @param guyToMove Pointer to the Souvenir object to move.
 */
void CampusStore::moveToCart(Souvenir* guyToMove) {
    if(guyToMove->isInCart()) {
        cart.push_back(guyToMove);

        storeItems->removeWidget(guyToMove);
        cartItems->insertWidget(cartItems->count() - 1, guyToMove);
    } else {
        auto iter = std::find(cart.begin(), cart.end(), guyToMove);
        if(iter != cart.end()) cart.erase(iter);

        cartItems->removeWidget(guyToMove);
        storeItems->insertWidget(storeItems->count() - 1, guyToMove);
    }
    updateCart();
}

/**
 * @brief Updates the total receipt price in the cart.
 */
void CampusStore::updateCart() {
    double sum = 0;
    for(auto& item: cart)
        sum += item->getPrice();

    std::cout << width() << '\n';
    std::cout << "$" << sum << '\n';
}
