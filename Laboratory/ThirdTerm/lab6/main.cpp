/*  
Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał a wynik jego działania był taki sam, jak podany na końcu tego pliku. 

Klasy Element i MyList znacie z poprzednich zajęć, można korzystać z kodów (Element), ale mądrze i wybiórczo, optymalizując kod i bez umieszczania niepotrzebnego kodu (będą za to odejmowane punkty).
Przypominam, że klasa Element reprezentuje element listy jednokierunkowej i posiada prywatne pole wskaźnika na dynamiczną tablicę int, rozmiar oraz wskaźnik na następny element. Elementy klasy muszą zostać rozbudowane o odpowiednie liczniki tworzonych obiektów. Funkcja printElem wypisuje ten identyfikator, dodając przedrostek Id_.
Metoda addElemRev tworzy nowy obiekt trzyelementowy, odwracając kolejność składowych.
Klasa MyList i zawiera TYLKO prywatny wskaźnik na head typu klasy Element oraz publiczne metody.
UWAGA! Nastąpiła zmiana, obie metody dodające element do listy, tworzą nowy obiekt, żadna z nich nie przepina tylko wskaźników.

Uzupełnij kody obu klas o odpowiednie konstruktory definiowane przez listy inicjalizacyjne oraz konstruktory delegowane. Obie klasy mają mieć zdefiniowane konstruktory kopiujące i przenoszące. Konstruktory te tworzą obiekty z nowymi identyfikatorami - nie kopiują ich.
Z uwagi na długi output, usunęłam konumikaty w zwykłych konstruktorach i destruktorach, dla ułatwienia zostawiłam tylko te dla kopiującego i przenoszącego.

Należy zadbać o zwolnienie pamięci przy usuwaniu elementów i czyszczeniu listy. Valgrind (make check) nie powinien wykazywać żadnych wycieków pamięci (leap) ani błędów (errors).

Pliku main.cpp, NIE WOLNO modyfikować bez zgody prowadzącego.
Proszę pamietać o dokumentacji kodu.
*/

#include "MyList.h" //to nie jest bład
#include "Element.h"
#include <iostream>

int main() {
  using std::cout;
  using std::endl;
  cout << "Liczba obiektow: " << Element::getObjects() << endl;
  {
  cout << "*** Elementy ***" << endl;
  int p1[] = {1,2,3,4};
  Element *pp1=new Element(p1,3); //konstruktor//powstaje pierszy el
  pp1->printElem(); cout << endl;
  const Element el2(*pp1);//drugi przez kopiujecy
  p1[1]=-2;
  el2.printElem(); cout << endl;//wypisujemy 2!!!!
  Element el3 = Element::addElemRev(*pp1); //tworzy punkt z odwróconą kolejnością współrzędnych el3 staje sie xvalue
  el3.printElem(); cout << endl;
  Element el4 = std::move(el3);
  el4.printElem(); cout << endl; 
  el3.printElem(); cout << endl; 
  cout << "Liczba obiektow: " << Element::getObjects() <<endl;
  return 0;
}

/* Oczekiwany wynik: ./main
Liczba obiektow: 0
*** Elementy ***
Id_1(1,2,3)
Konstruktor kopiujacy 2
Id_2(1,2,3)
Konstruktor kopiujacy 3
Id_3(3,2,1)
Konstruktor przenoszacy 4
Id_4(3,2,1)
Id_3()
Liczba obiektow: 4

*** Lista 1 ***
Pierwszy: Id_5(1,2,3)
Ostatni: Id_7(-1,-2,3)
Lista1 = <Id_5(1,2,3) Id_6(1,-2) Id_7(-1,-2,3)>

*** Lista 2 ***
Lista2 = <Id_8(1,2,3) Id_9(1,-2) Id_10(-1,-2,3)>
Lista3 = <Id_8(1,2,3) Id_9(1,-2) Id_10(-1,-2,3)>
Lista2 = <>
Liczba obiektow: 10

*** Usuwanie po elemencie ***
Lista1 = <Id_5(1,2,3) Id_6(1,-2) Id_7(-1,-2,3)>
Lista1 = <Id_6(1,-2) Id_7(-1,-2,3)>
Lista1 = <Id_7(-1,-2,3)>
Lista1 = <>
Czy lista 1 jest pusta? Tak
Lista3 = <Id_8(1,2,3) Id_9(1,-2) Id_10(-1,-2,3)>
Liczba obiektow: 0
*/
