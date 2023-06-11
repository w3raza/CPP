#include <iostream>

// w całym kodzie można bezpośrednio wywoływać tylko dwie funkcje: printOn i operator <<
// wypisywanie może się odbywać tylko z wykorzystaniem __PRETTY_FUNCTION__ i "\n"
//  __PRETTY_FUNCTION__ zawiera pełną nazwę funkcji w danym miejscu
// użycie gdziekolwiek słowa kluczowego public oznacza 0 punktów za zadanie

struct B {
protected:
  friend std::ostream& operator<<(std::ostream& os, const B& obj);
  virtual void printOn() const;
};
//  U2 - tylko definicje funkcji z U1
std::ostream& operator<<(std::ostream& os, const B& obj){
  obj.printOn();
  return os;
}

void B::printOn() const{
  std::cout << __PRETTY_FUNCTION__  << "\n";
}


class D1 : public B {
protected:
  // U4 - tylko deklaracja albo definicja jednej funkcji
  void printOn()const override{
    std::cout << __PRETTY_FUNCTION__  << "\n";
  }
};

struct D2 : public D1 {};

class D3 : public D1 {
protected:
  // U7 - tylko deklaracja albo definicja jednej funkcji
  void printOn()const override{
    std::cout << __PRETTY_FUNCTION__  << "\n";
  }
};

struct D4 : public D3 {
protected:
  // U9 - tylko deklaracja albo definicja jednej funkcji
  void printOn()const override{
    B::printOn();
    D1::printOn();
    D3::printOn();
    std::cout << __PRETTY_FUNCTION__ << "\n";
  }
};

int main(int argc, char *argv[]) {
  // B b; odkomentowanie powoduje błąd kompilacji
  D1 d1; D2 d2; D3 d3; const D4 d4;
  std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}

/* Output:
d1: [...] D1::printOn[...]
d2: [...] D1::printOn[...]
d3: [...] D3::printOn[...]
d4: [...] B::printOn[...]
[...] D1::printOn[...]
[...] D3::printOn[...]
[...] D4::printOn[...]
*/
