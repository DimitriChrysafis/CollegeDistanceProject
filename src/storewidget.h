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

class Souvenir: public QWidget {
  Q_OBJECT;

  public:
  explicit Souvenir(QString name, QString desc, double price, QWidget* parent = nullptr);
  int getQuantity() const;
  double getPrice() const;
  bool isInCart() const;

  QString getInfo() const;

  public slots:
  void cartClicked();
  void amtChanged(int newVal);

  signals:
  void moveMe(Souvenir* me);

  private:
  void createLayout();

  QString itemName;
  QString itemDescription;
  
  QLabel* price;
  QSpinBox* amountInCart;
  QPushButton* moveCart;
  double itemPrice;
  int cartQuantity;
  bool inCart = false;
};

class CampusStore: public QWidget {
  Q_OBJECT;

  public:
  explicit CampusStore(QString collegeName, QWidget* parent = nullptr);

  void addItem(QString name, QString desc, double price);

  QString getCartInfo() const;
  double getCartTotal() const;

  public slots:
  void moveToCart(Souvenir* guyToMove);

  protected:
  void updateCart();

  private:
  void createLayout();
  
  QString name;
  std::vector<Souvenir*> cart;
  QLabel receipt;

  QVBoxLayout* storeItems;
  QVBoxLayout* cartItems;

  QGroupBox* storeShelf;
  QGroupBox* cartShelf;
};

#endif
