#ifndef STORE_H
#define STORE_H

#include <memory>
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
  explicit Souvenir(QWidget* parent = nullptr);
  explicit Souvenir(QString name, QString desc, double price, QWidget* parent = nullptr);
  int getQuantity() const;
  double getPrice() const;
  bool isInCart() const;

  public slots:
  void cartClicked();

  signals:
  void moveMe(Souvenir* me);

  private:
  void createLayout();

  QString itemName;
  QString itemDescription;
  QSpinBox* amountInCart;
  QPushButton* moveCart;
  double itemPrice;
  int cartQuantity;
  bool inCart = false;
};

class CampusStore: public QWidget {
  Q_OBJECT;

  public:
  explicit CampusStore(QWidget* parent = nullptr);

  void addItem(QString name, QString desc, double price);

  public slots:
  void moveToCart(Souvenir* guyToMove);

  protected:
  void updateCart();



  private:
  void createLayout();

  std::vector<Souvenir*> cart;
  QLabel receipt;

  QVBoxLayout* storeItems;
  QVBoxLayout* cartItems;

  QGroupBox* storeShelf;
  QGroupBox* cartShelf;
};

#endif
