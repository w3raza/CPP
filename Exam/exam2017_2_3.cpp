//Proszę omowic poprawnosc ponizszego kodu oraz podac dokladne wyjscie z programu. prosze dokladnie uzasadnic odpowiedz.

#include<iostream>

struct A{ A() {std::cout << "A, ";} };
struct B{ B() {std::cout << "B, ";} };
struct X : virtual public A, private B { X() {std::cout << "X, ";} };
struct Y : virtual public A, private B{ Y() {std::cout << "Y, ";} };
struct Z : public Y, public X { Z() {std::cout << "Z, ";} };

int main() { Z test; }
// A, B, Y, B, X, Z,

/*
Definiuje on pięć struktur: A, B, X, Y, i Z. Struktury X i Y są dziedziczone z A i B, a Z dziedziczy z X i Y. 
Wszystkie te struktury mają konstruktory, które wypisują literę odpowiadającą ich nazwie, kiedy są inicjowane. 
Wywołując Z test; w main(), inicjujesz instancję klasy Z, co prowadzi do wywołania jej konstruktora, a także konstruktorów klas, z których dziedziczy.

Co do sekwencji wywołań konstruktorów, w C++ konstruktory klas bazowych są wywoływane przed konstruktorem klasy pochodnej. 
Jeżeli klasy bazowe są dziedziczone wirtualnie, jak w tym przypadku dla klasy A, konstruktor tej klasy jest wywoływany tylko raz i jest to pierwszy konstruktor,
który jest wywoływany.

Pamiętaj też, że kolejność wywołania konstruktorów dla klas bazowych jest zgodna z kolejnością, w jakiej te klasy są wymienione w definicji klasy pochodnej, 
a nie z kolejnością inicjalizacji obiektów w programie.

Biorąc pod uwagę powyższe zasady, oto sekwencja wywołań konstruktorów:
1. Z jest inicjowane, więc najpierw są wywoływane konstruktory klas bazowych. Klasa Y jest wymieniona jako pierwsza, 
więc jej konstruktory są wywoływane jako pierwsze.

2. Y dziedziczy wirtualnie z A i prywatnie z B. Zgodnie z zasadami dziedziczenia wirtualnego, konstruktor A jest wywoływany jako pierwszy. 
Wypisuje "A, ".

3. Następnie, ponieważ Y dziedziczy również z B, jest wywoływany konstruktor B, który wypisuje "B, ".

4. Teraz, kiedy wszystkie klasy bazowe dla Y zostały zainicjowane, jest wywoływany konstruktor Y, który wypisuje "Y, ".

5. Następnie są wywoływane konstruktory dla X. Ale ponieważ X dziedziczy wirtualnie z A, a A już zostało zainicjowane, 
konstruktor A nie jest wywoływany ponownie. Dlatego następny jest konstruktor B (X także dziedziczy prywatnie z B), który wypisuje "B, ".

6. Kiedy klasy bazowe dla X są już zainicjowane, wywoływany jest konstruktor X, który wypisuje "X, ".

7. Na koniec, kiedy wszystkie klasy bazowe dla Z są już zainicjowane, wywoływany jest konstruktor Z, który wypisuje "Z, ".
*/

//Example:

#include<iostream>

struct S{ S() {std::cout << "S, ";} };
struct A{ A() {std::cout << "A, ";} };
struct B{ B() {std::cout << "B, ";} };
struct X :  virtual public A, virtual private B { X() {std::cout << "X, ";} };
struct Y : virtual S, virtual public A,  private B{ Y() {std::cout << "Y, ";} };
struct Z :  public X, virtual public Y,  B { Z() {std::cout << "Z, ";} };

int main() { Z test; }
// A, B, S, B, Y, X, B, Z, 