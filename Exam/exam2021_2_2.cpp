#include <iostream>
#include <memory>
#include <array>

/*
* Funkcja my_print_el służy do wydruku pojedynczego łańcucha znaków.
*/
void my_print_el(const char* line){
  std::cout << std::endl << line;
}

/*
* Funkcja my_print iteruje przez tablicę i drukuje wartość wskazywaną przez każdy std::unique_ptr. 
* Bez template musielibyśmy napisać specyficzną funkcję my_print dla std::array<std::unique_ptr<int>, 2>.
  Zastosowanie szablonów pozwala więc na napisanie jednej wersji funkcji, która jest bardziej uniwersalna i reużywalna.
*/
template<typename T, size_t N>
void my_print(const std::array<T,N>& _array, const char* separator = ";", const char* next = ""){
  std::cout << "[";
  
  for(int i = 0; i < N; i++){
      std::cout << *_array[i] << separator;
  }
  
  std::cout << "]" << next;
}

/*
* Funkcja my_swap została zaimplementowana w celu zamiany miejscami elementów.
* Bez template musielibyśmy napisać dwie różne funkcje my_swap, jedną dla std::unique_ptr<int> i jedną dla int.
  Zastosowanie szablonów pozwala więc na napisanie jednej wersji funkcji, która jest bardziej uniwersalna i reużywalna.
* Metody std::move, aby przesunąć obiekt z jednej lokalizacji do drugiej, umożliwiając efektywne przesuwanie zasobów, zamiast ich kopiowania. 
*/
template <typename T>
void my_swap(T& a, T& b)
{
  T temp = std::move(a);
  a = std::move(b);
  b = std::move(temp);
}

int main()
{
  std::array<std::unique_ptr<int>,2>a={std::unique_ptr<int>(new int {1}), std::unique_ptr<int>(new int {2})};

  my_print_el("----------------\n");
  my_print(a,";"," -> ");
  my_swap(a[0],a[1]);
  my_print(a,";"," -> ");
  my_swap(*a[0],*a[1]);
  my_print(a);
  my_print_el("----------------");
}
/*
----------------
[1;2;] -> [2;1;] -> [1;2;]
----------------
*/