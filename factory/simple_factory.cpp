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

class LiNineShoes : public Shoes {
 public:
  void Show() { std::cout << "I'm Lining \n"; }
};

enum class SHOES_TYPE { NIKE, ADIDAS, LINING };

class ShoesFactory {
 public:
  Shoes* CreateShoes(const SHOES_TYPE& type) {
    switch (type) {
      case SHOES_TYPE::NIKE:
        return new NikeShoes();
        break;
      case SHOES_TYPE::ADIDAS:
        return new AdidasShoes();
        break;
      case SHOES_TYPE::LINING:
        return new LiNineShoes();
        break;
      default:
        break;
    }
  }
};

int main() {
  ShoesFactory shoes_factory;
  Shoes* lining1 = shoes_factory.CreateShoes(SHOES_TYPE::LINING);
  Shoes* lining2 = shoes_factory.CreateShoes(SHOES_TYPE::LINING);

  if (lining1 == lining2) {
    std::cout << "Is same one \n";
  }

  delete lining1;
  delete lining2;
}
