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

enum class SHOES_TYPE { NIKE, ADIDAS, LINING };

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

class Factory {
 public:
  Factory() {}
  virtual ~Factory() {}
  virtual Shoes *CreateShoes() = 0;
  virtual Clothe *CreateClothe() = 0;
};

class NikeProducer : public Factory {
 public:
  Shoes *CreateShoes() { return new NikeShoes(); }
  Clothe *CreateClothe() { return new NikeClothe(); }
};

class AdidasProducer : public Factory {
 public:
  Shoes *CreateShoes() { return new AdidasShoes(); }
  Clothe *CreateClothe() { return new AdidasClothe(); }
};

class LiNingProducer : public Factory {
 public:
  Shoes *CreateShoes() { return new LiNingShoes(); }
  Clothe *CreateClothe() { return new LiNingClothe(); }
};

int main() {
  Factory *nike_producer = new NikeProducer();
  Shoes *nike_shoes = nike_producer->CreateShoes();
  nike_shoes->Show();
  Clothe *nike_clothe = nike_producer->CreateClothe();
  nike_clothe->Show();

  delete nike_shoes;
  delete nike_clothe;
  delete nike_producer;
}
