/*
  Celem zadania jest rozszerzenie funkcjonalności zadanego projektu.
  Rozszerzenie obejmuje:
  * dodatkowy typ CharStr;
  * metodę List::find - zwraca wskaźnik na element znaleziony na liście
  * metodę List::copy_if - kopiuje do listy wybrane elementy (dla text=true tekst i znaki, dla text=false tylko fraction
  * metodę List::eval przy czym:
    - dla StringData zwraca długość napisu przekonwertowaną do double
    - dla Fraction zwraca wartość ułamka w double
    - dla CharData zwraca wartość ascii znaku przekonwertowaną do double
  * opcjonalnie metodę List::reverse - odwraca listę, zmieniając ją i ją zwraca
    (implementujemy na końcu)
  UWAGI:
  * Aby podane wyżej funkcje trzeba rozszerzyć zdefiniowane wcześniej klasy
  * Zadanie ma nie zawierać niepotrzebnych funkcji. Jeśli zostały zaimplementowane "na wszelki wypadek",
    a nie są potrzebne, należy je usunąć.
  * Wszystkie pomocnicze funkcje wykorzystywane wewnątrz w klasie powinny być prywatne.
  * Podstawa to nie zepsuć zadania. Zadanie które prawidłowo zostało wykonane w domu
    i po dodaniu dodatkowej, pustej funkcjonalności nadal będzie się kompilować,
    zostanie ocenione na 50%.

 */
#include <iostream>
#include "List.h"
#include "Data.h"

int main() {
    List a;
    a.print();
    a.insert(Fraction(3,4), List::Begin);
    a.insert(Fraction(4,5), List::End);
    a.insert(StringData("Zaczynamy"),  List::Begin);
    a.insert(StringData("-5/7"));
    a.insert(CharData('K')).insert(StringData("Koniec"));
    a.print();

    std::cout << "--- Operacje ---\n";
    const List b = a;
    a.insert(Fraction(26));
    List c = a.reverse(); //zmienia listę a i przypisuje c implementujemy na samym końcu, tymczasowo zwracamy *this
    a.insert(StringData("Hej"), List::Begin);
    std::cout << "Lista a: " << a;
    std::cout << "Lista b: " << b;
    std::cout << "Lista c: " << c;

    std:: cout << "Sprawdzamy find i eval: " << b.find(Fraction(3,4))->eval() << std::endl;
    std::cout << "Tylko znaki tekstowe: " << b.copy_if(); // = copy_if(true) wykonaj kopie elementów typu StringData i CharData
    std::cout << "Tylko liczby: " << b.copy_if(false); //
    std::cout << "Tylko liczby: " << (List()).copy_if(false); //

    std::vector<double> vec = b.eval();
    std::cout << "Wartosci: | ";
    for (auto el : vec) {
        std::cout << "" << el << " | " ;
    }
    std::cout << std::endl;
}

/* wynik
/// wersja bez odwracania listy
[ ]
[ "Zaczynamy" 3/4 4/5 "-5/7" 'K' "Koniec" ]
--- Operacje ---
Lista a: [ "Hej" "Zaczynamy" 3/4 4/5 "-5/7" 'K' "Koniec" 26 ]
Lista b: [ "Zaczynamy" 3/4 4/5 "-5/7" 'K' "Koniec" ]
Lista c: [ "Zaczynamy" 3/4 4/5 "-5/7" 'K' "Koniec" 26 ]
Sprawdzamy find i eval: 0.75
Tylko znaki tekstowe: [ "Zaczynamy" "-5/7" 'K' "Koniec" ]
Tylko liczby: [ 3/4 4/5 ]
Tylko liczby: [ ]
Wartosci: | 9 | 0.75 | 0.8 | 4 | 75 | 6 |

/// wersja z odwróceniem listy
[ ]
[ "Zaczynamy" 3/4 4/5 "-5/7" 'K' "Koniec" ]
--- Operacje ---
Lista a: [ "Hej" 26 "Koniec" 'K' "-5/7" 4/5 3/4 "Zaczynamy" ]
Lista b: [ "Zaczynamy" 3/4 4/5 "-5/7" 'K' "Koniec" ]
Lista c: [ 26 "Koniec" 'K' "-5/7" 4/5 3/4 "Zaczynamy" ]
Sprawdzamy find i eval: 0.75
Tylko znaki tekstowe: [ "Zaczynamy" "-5/7" 'K' "Koniec" ]
Tylko liczby: [ 3/4 4/5 ]
Tylko liczby: [ ]
Wartosci: | 9 | 0.75 | 0.8 | 4 | 75 | 6 |
*/