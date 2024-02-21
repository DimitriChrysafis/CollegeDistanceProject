#include "storewidget.h"

//Default Constructor
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
}

//Default Constructor
CampusStore::CampusStore(QWidget* parent): QWidget(parent) {
  createLayout();
}

//Called on construction, builds layout of store
void CampusStore::createLayout() {
  storeShelf = new QGroupBox("Souvenirs Store");
  storeShelf->setContentsMargins(0, 0, 0, 0);
  cartShelf = new QGroupBox("Your Cart");
  cartShelf->setContentsMargins(0, 0, 0, 0);
  
  QHBoxLayout* mainLayout = new QHBoxLayout(this);
  mainLayout->addWidget(storeShelf);
  mainLayout->addWidget(cartShelf);
  setMaximumSize(1000, 370);
  resize(1000, 370);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  
  storeItems = new QVBoxLayout();
  cartItems = new QVBoxLayout();
  storeItems->addStretch();
  cartItems->addStretch();
  cartShelf->setLayout(cartItems);
  storeShelf->setLayout(storeItems);

  addItem("jacket", "", 70);
  addItem("mug", "", 70);
  addItem("t-shirt", "", 70);
  addItem("socks", "", 70);
  addItem("socks", "", 70);
}

//Add item to store shelf
void CampusStore::addItem(QString name, QString desc, double price) {
  Souvenir* item = new Souvenir(name, desc, price); //create new souvenir
  storeItems->insertWidget(storeShelf->layout()->count() - 1, item); //insert
  connect(item, &Souvenir::moveMe, this, &CampusStore::moveToCart);
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

  std::cout << "$" << sum << '\n';
}
