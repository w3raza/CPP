// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest rozszerzenie jego wersji podstawowej, polimorficznej listy:
//   https://upel.agh.edu.pl/mod/assign/view.php?id=136110
//   Rozszerzenie obejmuje:
//   - Definicję szablonu klasy Pair (typu aggregate, patrz niżej), której zadaniem
//     jest jedynie przechowywanie dwóch danych numertycznych. Klasa ta musi zawierać
//     słownik dedukcji typów CTAD (z założenia)
//   - Definicję szablonu klasy Rational dziedziczącym po klasie Pair
//     z odpowiednią funkcjonalnością (patrz main) oraz słownikiem dedukcji typów CTAD.
//     Uwaga: klasa Rational nie zawiera własnych atrybutów! Wykorzystuje to, co dziedziczy!
//   - modyfikację definicji klasy List (jeśli konieczne) tak aby kolejne 
//     instancje TNode tworzone były bez podawania argumentów szablonowych

/* 
  What are aggregates and why they are special?
  https://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special
  Formal definition from the C++ standard (C++03 8.5.1 §1):
    "An aggregate is an array or a class (clause 9) with no user-declared constructors (12.1), 
    no private or protected non-static data members (clause 11), no base classes (clause 10), 
    and no virtual functions (10.3)."
    template<class T,class U> class AggregateExample {
      public:
        T first;
        U second;
    };
*/

#include <iostream>
#include "Rational.h"
#include "List.h"

int main() {
  Pair<int,int> p0{3,1};        // Pair jest typem "aggregate", 
  std::cout << p0 << std::endl; // czyli structure bez zdefiniowanych konstruktorów!
                                // Dokładniej, w tym przypadku szablonem struktury/klasy.
  
  Pair p1{3,1.3};               // Ryzyko: CTAD doesn’t know how to deduce 
                                //         the template arguments for aggregate class templates
  std::cout << p1 << std::endl; 

  Rational<float> r0{1,2};   
  std::cout << r0 << std::endl;
  std::cout << static_cast<double>(r0) << std::endl;

  Rational r1{5.5,2};      
  std::cout << r1 << std::endl;
  std::cout << static_cast<double>(r1) << std::endl;                   

  auto r2 = r0.Inverse(); // X / Y -> Y / X
  std::cout << r2 << std::endl;
  std::cout << static_cast<double>(r2) << std::endl;

  List list;
  list.add(7);             // Uwaga: domyślne działanie CTAD, nie ma potrzeby dodawania arg. szablonu dla:
                           //        new TNode<T>{v}; => new TNode{v};
  list.add(r2);
  
  const Node* r2h = list.head();
  std::cout<<" is float "<<std::boolalpha << r2h->isType<float>() << std::endl;

  auto r2hd1 = dynamic_cast<const TNode<Rational<float>>*>( r2h );
  r2hd1 ? std::cout << r2hd1->get() : std::cout<<" cast type error... ";
  std::cout<<std::endl; 

  auto r2hd2 = dynamic_cast<const TNode<Rational<double>>*>( r2h );
  r2hd2 ? std::cout << r2hd2->get() : std::cout<<" cast type error... ";
  std::cout<<std::endl; 
}
/* wynik
3,1
3,1.3
1/2
0.5
5.5/2
2.75
2/1
2
 is float false
2/1
 cast type error...
*/