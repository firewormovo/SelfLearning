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

class ShoesFactory {
 public:
  ShoesFactory() {}
  virtual ~ShoesFactory() {}
  virtual Shoes *CreateShoes() = 0;
};

class NikeProducer : public ShoesFactory {
 public:
  Shoes *CreateShoes() { return new NikeShoes(); }
};

class AdidasProducer : public ShoesFactory {
 public:
  Shoes *CreateShoes() { return new AdidasShoes(); }
};

class LiNingProducer : public ShoesFactory {
 public:
  Shoes *CreateShoes() { return new LiNingShoes(); }
};

int main() {
  ShoesFactory *nike_producer = new NikeProducer();
  Shoes *nike_shoes = nike_producer->CreateShoes();
  nike_shoes->Show();

  delete nike_shoes;
  delete nike_producer;
}
