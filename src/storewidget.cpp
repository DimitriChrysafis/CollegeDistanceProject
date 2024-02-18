#include "storewidget.h"

//Default Constructor
Souvenir::Souvenir(QString name, QString desc, double price, QWidget* parent): QWidget(parent) {
  itemName = name;
  itemDescription = desc;
  itemPrice = price;
  cartQuantity = 0;
  createLayout();
}

//Getters
int Souvenir::getQuantity() const { return cartQuantity; }
double Souvenir::getPrice() const { return itemPrice * cartQuantity; }
bool Souvenir::isInCart() const { return inCart; }

//"AddToCart" and "Remove From Cart" button handler
void Souvenir::cartClicked() {
  if (cartQuantity <= 0 && !inCart) return; //if not eligible for move, don't do anything
  inCart = !inCart;
  if(inCart) moveCart->setText("Remove From Cart");
  else {
    moveCart->setText("Add To Cart");
    amountInCart->setValue(0);
  }
  emit moveMe(this);
}

//Called on Construction, builds layout of item
void Souvenir::createLayout() {
  QHBoxLayout* layout_ = new QHBoxLayout(this);
  QLabel* name = new QLabel(itemName);
  name->setMinimumWidth(200);
  name->setWordWrap(true);
  name->setAlignment(Qt::AlignCenter);
  amountInCart = new QSpinBox;
  connect(amountInCart, QOverload<int>::of(&QSpinBox::valueChanged), 
      [=](int i){ cartQuantity = i; if(i == 0) cartClicked(); }); 
  moveCart = new QPushButton("Add To Cart");
  connect(moveCart, &QPushButton::clicked, this, &Souvenir::cartClicked);
  amountInCart->setRange(0, 99);

  layout_->addWidget(name);
  layout_->addWidget(new QLabel("$" + QString::number(itemPrice)));
  layout_->addWidget(amountInCart);
  layout_->addWidget(moveCart);
  
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  QPalette pal = QPalette();
  pal.setColor(QPalette::Window, Qt::black);
  setAutoFillBackground(true);
  setPalette(pal);
}

//Default Constructor
CampusStore::CampusStore(QWidget* parent): QWidget(parent) {
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

  QVBoxLayout* storeItems = new QVBoxLayout();
  QVBoxLayout* cartItems = new QVBoxLayout();
  cartShelf->setLayout(cartItems);
  storeShelf->setLayout(storeItems);
  addItem("jacket", "", 70);
  addItem("mug", "", 70);
  addItem("t-shirt", "", 70);
  addItem("socks", "", 70);
}

//Add item to store shelf
void CampusStore::addItem(QString name, QString desc, double price) {
  Souvenir* item = new Souvenir(name, desc, price);
  storeShelf->layout()->addWidget(item);
  connect(item, &Souvenir::moveMe, this, &CampusStore::moveToCart);
}

//Called in Souvenir::cartClicked, moved item from ui storeshelf to cartshelf
void CampusStore::moveToCart(Souvenir* guyToMove) {
  if(guyToMove->isInCart()) {
    cart.push_back(guyToMove);
    storeShelf->layout()->removeWidget(guyToMove);
    cartShelf->layout()->addWidget(guyToMove);
  } else {
    auto iter = std::find(cart.begin(), cart.end(), guyToMove);
    if(iter != cart.end()) cart.erase(iter);
    cartShelf->layout()->removeWidget(guyToMove);
    storeShelf->layout()->addWidget(guyToMove);
  }
  updateCart();
}

//Update total receipt price
void CampusStore::updateCart() {
  double sum = 0;
  for(auto& item: cart) {
    sum += item->getPrice();
  }
  std::cout << "$" << sum << '\n';
}
