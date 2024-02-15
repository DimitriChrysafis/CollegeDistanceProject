#include "storewidget.h"

Souvenir::Souvenir(QWidget* parent): QWidget(parent) {
  itemName = "Mascot Hotplate";
  itemDescription = "This hotplate has a picture of a tiger in a 10 liter hat printed on it. Perfect for making ramen in your dorm! Yum!";
  itemPrice = 99.99;
  createLayout();
}

Souvenir::Souvenir(QString name, QString desc, double price, QWidget* parent): QWidget(parent) {
  itemName = name;
  itemDescription = desc;
  itemPrice = price;
  createLayout();
}

int Souvenir::getQuantity() const { return cartQuantity; }
double Souvenir::getPrice() const { return itemPrice * cartQuantity; }
bool Souvenir::isInCart() const { return inCart; }

void Souvenir::cartClicked() {
  emit moveMe(this);
  std::cout << "HI I WANNA BE MOVED!\n";
  inCart = !inCart;
  if(inCart) moveCart->setText("Remove From Cart");
  else {
    moveCart->setText("Add To Cart");
    amountInCart->setValue(0);
  }
}

void Souvenir::createLayout() {
  QHBoxLayout* layout_ = new QHBoxLayout(this);
  QLabel* name = new QLabel(itemName);
  name->setMaximumWidth(200);
  name->setWordWrap(true);
  name->setAlignment(Qt::AlignCenter);
  amountInCart = new QSpinBox;
  connect(amountInCart, QOverload<int>::of(&QSpinBox::valueChanged), 
      [=](int i){ cartQuantity = i; }); 
  moveCart = new QPushButton("Add To Cart");
  connect(moveCart, &QPushButton::clicked, this, &Souvenir::cartClicked);
  amountInCart->setRange(0, 99);

  layout_->addWidget(name);
  layout_->addWidget(new QLabel("$" + QString::number(itemPrice)));
  layout_->addWidget(amountInCart);
  layout_->addWidget(moveCart);
  setFixedSize();
}

CampusStore::CampusStore(QWidget* parent): QWidget(parent) {
  createLayout();
  /*QGridLayout* layout_ = new QGridLayout(this);
  QVBoxLayout* shelf_ = new QVBoxLayout();
  shelf_->addWidget(new Souvenir());
  shelf_->addWidget(new Souvenir());
  shelf_->addWidget(new Souvenir());
  shelf_->addWidget(new Souvenir());

  layout_->addLayout(shelf_, 0, 0, 1, 1);
  layout_->addWidget(new QLabel("Cart: ", this), 0, 1, 1, 1, Qt::AlignLeft | Qt::AlignTop);*/
}

void CampusStore::createLayout() {
  storeShelf = new QGroupBox("Souvenirs Store");
  storeShelf->setContentsMargins(0, 0, 0, 0);
  cartShelf = new QGroupBox("Your Cart");
  cartShelf->setContentsMargins(0, 0, 0, 0);

  QHBoxLayout* mainLayout = new QHBoxLayout(this);
  mainLayout->addWidget(storeShelf);
  mainLayout->addWidget(cartShelf);

  QVBoxLayout* cartItems = new QVBoxLayout();
  QVBoxLayout* storeItems = new QVBoxLayout();
  cartShelf->setLayout(cartItems);
  storeShelf->setLayout(storeItems);
  addItem("jacket", "", 70);
  addItem("mug", "", 70);
  addItem("t-shirt", "", 70);
  addItem("socks", "", 70);
}

void CampusStore::addItem(QString name, QString desc, double price) {
  Souvenir* item = new Souvenir(name, desc, price);
  storeShelf->layout()->addWidget(item);
  connect(item, &Souvenir::moveMe, this, &CampusStore::moveToCart);
}

void CampusStore::moveToCart(Souvenir* guyToMove) {
  if(!guyToMove->isInCart()) {
    storeShelf->layout()->removeWidget(guyToMove);
    cartShelf->layout()->addWidget(guyToMove);
  } else {
    cartShelf->layout()->removeWidget(guyToMove);
    storeShelf->layout()->addWidget(guyToMove);
  }
}

void CampusStore::updateCart() {
}
