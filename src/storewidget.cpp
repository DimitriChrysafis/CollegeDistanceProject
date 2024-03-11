#include "storewidget.h"

//Overloaded Constructor
Souvenir::Souvenir(QString name, QString desc, double price, QWidget* parent): QWidget(parent) {
  itemName = name;
  itemDescription = desc;
  itemPrice = price;
  cartQuantity = 0;
  createLayout();
}

//Accessor functions
int Souvenir::getQuantity() const { return cartQuantity; }
double Souvenir::getPrice() const { return itemPrice * cartQuantity; }
bool Souvenir::isInCart() const { return inCart; }

QString Souvenir::getInfo() const {
  QString info = itemName + ": " + QString::number(cartQuantity) + "*";
  info.append(QString::number(itemPrice, 'f', 2) + " = " + QString::number(getPrice(), 'f', 2));
  info.append("\n");
  return info;
}

//"AddToCart" and "Remove From Cart" button handler
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

void Souvenir::amtChanged(int newVal) {
  cartQuantity = newVal;
  if(inCart && newVal == 0) cartClicked();
  if(!inCart && newVal == 0) moveCart->setEnabled(false);
  else moveCart->setEnabled(true);
}

//Called on Construction, builds layout of item
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

  QLabel* price = new QLabel("$" + QString::number(itemPrice, 'f', 2));
  price->setMinimumWidth(40);

  layout_->addWidget(name);
  layout_->addWidget(price);
  layout_->addWidget(amountInCart);
  layout_->addWidget(moveCart);
  
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

//Default Constructor
CampusStore::CampusStore(QString collegeName, QWidget* parent): QWidget(parent), name(collegeName) {
  createLayout();
}

//Called on construction, builds layout of store
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

  //addItem("License plate cover", "", 11.85);
  //addItem("License plate cover", "", 11.85);
  //addItem("socks", "", 70);
  //addItem("t-shirt", "", 70);
  //addItem("socks", "", 70);
}

//Add item to store shelf
void CampusStore::addItem(QString name, QString desc, double price) {
  Souvenir* item = new Souvenir(name, desc, price); //create new souvenir
  storeItems->insertWidget(storeShelf->layout()->count() - 1, item); //insert before empty stretch
  connect(item, &Souvenir::moveMe, this, &CampusStore::moveToCart);
}

QString CampusStore::getCartInfo() const {
  QString info = name;
  info.append("\n");
  for(auto& item: cart)
    info.append(item->getInfo());
  if(cart.empty()) info.append("Nothing Bought Here\n");
  else info.append("Total: " + QString::number(getCartTotal(), 'f', 2) + "\n");
  info.append("\n");
  return info;
}

double CampusStore::getCartTotal() const {
  double total = 0.0;
  for(auto& item: cart) total += item->getPrice();
  return total;
}

//Called in Souvenir::cartClicked, moved item from ui storeshelf to cartshelf
void CampusStore::moveToCart(Souvenir* guyToMove) {
  if(guyToMove->isInCart()) {
    cart.push_back(guyToMove); //Add to vector of items in cart

    storeItems->removeWidget(guyToMove); //Move 'guytomove' from store to cart ui
    cartItems->insertWidget(cartItems->count() - 1, guyToMove);
  } else {
    auto iter = std::find(cart.begin(), cart.end(), guyToMove);
    if(iter != cart.end()) cart.erase(iter); //Remove from vector of items in cart

    cartItems->removeWidget(guyToMove); //Move 'guytomove' from cart to store ui
    storeItems->insertWidget(storeItems->count() - 1, guyToMove);
  }
  updateCart();
}

//Update total receipt price
void CampusStore::updateCart() {
  double sum = 0;
  for(auto& item: cart) 
    sum += item->getPrice();

  std::cout << width() << '\n';
  std::cout << "$" << sum << '\n';
}
