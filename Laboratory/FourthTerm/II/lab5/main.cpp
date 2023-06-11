/**
  Celem zadania jest napisanie polimorficznej kopiowalnej listy,
  która dzięki polimorfizmowi może zawierać elementy różnego typu.
  Begin i End to enumeratory, czyli elementy typu enum.
  Proszę zwrócić uwagę na konstruktor kopiujacy, który ma wykonać kopię całej listy.
  Zadanie proszę przesłać w terminie podanym na UPEL-u.
*/

#include <iostream>
#include "List.h"
#include "Data.h"

int main() {
  List a;
  a.insert(Fraction(2,3), List::Begin); // dodajemy na początek
  a.insert(Fraction(4,3), List::End); // dodajemy na koniec
  std::cout << "--- Drukujemy liste a ---\n";
  a.print();
  // a.insert(StringData("Zaczynamy"),  List::Begin); // dodajemy ponownie na początek
  // a.insert(StringData("2/15"), List::End);
  // a.insert(StringData("-5/7")); // po wyniku można poznać gdzie domyślnie dodawane sa elementy
  // a.insert(Fraction(26)).insert(StringData("Koniec"));
  // std::cout << "--- Lista a ---\n";
  // a.print();

  // std::cout << "--- Kopiujemy liste b=a ---\n";
  // List b = a;
  // b.insert(Fraction(100));
  // std::cout << "Lista a: " << a;
  // std::cout << "Lista b: " << b;

  // std::cout << "--- Zmieniamy liste a ---\n";
  // a.insert(StringData("Hej"), List::Begin);
  // std::cout << "Lista a: " << a;
  // std::cout << "Lista b: " << b;
  // return 0;
}

/* oczekiwany wynik main
--- Drukujemy liste a ---
[ 2/3 4/3 ]
--- Lista a ---
[ Zaczynamy 2/3 4/3 2/15 -5/7 26 Koniec ]
--- Kopiujemy liste b=a ---
Lista a: [ Zaczynamy 2/3 4/3 2/15 -5/7 26 Koniec ]
Lista b: [ Zaczynamy 2/3 4/3 2/15 -5/7 26 Koniec 100 ]
--- Zmieniamy liste a ---
Lista a: [ Hej Zaczynamy 2/3 4/3 2/15 -5/7 26 Koniec ]
Lista b: [ Zaczynamy 2/3 4/3 2/15 -5/7 26 Koniec 100 ]
 */
