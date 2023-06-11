#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include <array>



template<typename T>
void my_print_el(T &text)
{
  std::cout << std::endl << text << std::endl;

}
//-tylko tu cout
//tylko jeden arg przyjmuje

template<typename T1>
void my_print(T1 &arr, const char* text_1 = ";", const char* text_2 = " -> " )
{
  std::cout << "[" << *arr[0] << text_1 << *arr[1] << text_1 << "]" << text_2;
}

template<typename T>
void my_swap(T &el_1, T &el_2)
{
  std::swap(el_1, el_2);
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
//[1;2;] -> [2;1;] -> [1;2;]