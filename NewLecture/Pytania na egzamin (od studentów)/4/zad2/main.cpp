#include<iostream>

struct Base {
  typedef double func;
};

//Jakie dwa szablony funkcji trzeba napisać żeby kod zgodnie z zasadą SFINAE kompilował się poprawnie?
//Szablony powinny wypisywać napis "szablon " i numer szablonu


//pierwszy szablon
template <typename T>
void f(typename T::func obj) {
  std::cout<<"szablon 1"<<std::endl;
}

//drugi szablon
template <typename T>
void f(T obj) {
  std::cout<<"szablon 2"<<std::endl;
}

int main() {
  f<Base>(10.0);  
  f<double>(10.0); 
  return 0;
}
/*
szablon 1
szablon 2
*/







































