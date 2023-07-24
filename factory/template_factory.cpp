#include <iostream>

class Shoes {
 public:
  Shoes() {}
  virtual ~Shoes() {}
  virtual void Show() = 0;
};

class NikeShoes : public Shoes {
 public:
  void Show() { std::cout << "I'm Nike \n"; }
};

class AdidasShoes : public Shoes {
 public:
  void Show() { std::cout << "I'm adidas \n"; }
};

class LiNingShoes : public Shoes {
 public:
  void Show() { std::cout << "I'm Lining \n"; }
};

class Clothe {
 public:
  virtual void Show() = 0;
  virtual ~Clothe() {}
};

class NikeClothe : public Clothe {
 public:
  void Show() { std::cout << "I'm nike clothe \n"; }
};

class AdidasClothe : public Clothe {
 public:
  void Show() { std::cout << "I'm adidas clothe \n"; }
};

class LiNingClothe : public Clothe {
 public:
  void Show() { std::cout << "I'm lining clothe \n"; }
};

template <class AbstractProduct_t>
class AbstractFactory {
 public:
  virtual ~AbstractFactory() {}
  virtual AbstractProduct_t* CreateProduct() = 0;
};

template <class AbstractProduct_t, class ConcreteProduct_t>
class ConcreteFactory : public AbstractFactory<AbstractProduct_t> {
 public:
  AbstractProduct_t* CreateProduct() { return new ConcreteProduct_t(); }
};

int main() {
  ConcreteFactory<Shoes, NikeShoes> nikeShoesFactory;
  Shoes* pNikeShoes = nikeShoesFactory.CreateProduct();
  pNikeShoes->Show();

  delete pNikeShoes;

  ConcreteFactory<Clothe, LiNingClothe> liningClotheFactory;
  Clothe* pLiNingClothe = liningClotheFactory.CreateProduct();
  pLiNingClothe->Show();
  delete pLiNingClothe;
}