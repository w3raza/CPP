/*
Przed nami druga część zadania - rekrutacja uzupełniająca.
Aby ją zrealizować, należy rozbudować istniejące klasy.
Na tym etapie uczniowie mogą się wypisywać ze szkół i na nowo rekrutować do wybranych.
Proces samej rekrutacji przebiega tak samo, więc jeśli został prawidłowo zaimplementowany, powinien działać.
Zadanie jest podzielone na dwie części. Pierwsza trochę zmieniona, ale powinna działać,
dlatego też na początek zadania warto sobie zakomentować linię #define EXTENDED
Proszę uważnie prześledzić output, bo zaszła mała zmiana w wypisywaniu klasy:
nazwa - liczba_zajętych_miejsc/liczba_wszystkich_miejsc.
UWAGA!
*/

#include <iostream>
#include <vector>
#include <memory>

#include "school.h"
#include "student.h"
#include "edusys.h"

#define EXTENDED // można zakomentować tylko dla celów przetestowania wersji BASIC zrobionej w domu

int main() 
{  
  // tworzenie klas rekrutacyjnych
  std::shared_ptr<SchoolClass>
      l1a = std::make_shared<SchoolClass>("LO1-A", 2), // (nazwa, liczba miejsc)
      l2a = std::make_shared<SchoolClass>("LO2-A", 3),
      l2b = std::make_shared<SchoolClass>("LO2-B", 3);
  std::vector<std::shared_ptr<SchoolClass>> szkoly = {l1a, l2a, l2b};
  // lista kandydatów z wynikiem i wyborem szkół
  std::vector<std::shared_ptr<Student>> kandydaci = {
          std::make_shared<Student>("Uczen__1", 151, std::vector<std::shared_ptr<SchoolClass>>{l1a, l2a, l2b}),
          std::make_shared<Student>("Uczen__2", 130, std::vector<std::shared_ptr<SchoolClass>>{l2a, l2b}),
          std::make_shared<Student>("Uczen__3", 120, std::vector<std::shared_ptr<SchoolClass>>{l1a, l2a, l2b}),
          std::make_shared<Student>("Uczen__4", 119, std::vector<std::shared_ptr<SchoolClass>>{l1a, l2a, l2b}),
          std::make_shared<Student>("Uczen__5", 118, std::vector<std::shared_ptr<SchoolClass>>{l2b, l2a}),
          std::make_shared<Student>("Uczen__6", 121, std::vector<std::shared_ptr<SchoolClass>>{l2a, l2b}),
          std::make_shared<Student>("Uczen__7", 110, std::vector<std::shared_ptr<SchoolClass>>{l1a, l2a}),
          std::make_shared<Student>("Uczen__8", 100, std::vector<std::shared_ptr<SchoolClass>>{l2b, l2a}),
          std::make_shared<Student>("Uczen__9", 90, std::vector<std::shared_ptr<SchoolClass>>{l2b})
  };

  std::cout << l1a->getclass() << " miejsc " << l1a->getlimit() << std::endl;
  kandydaci[3]->print(); // przydział szkoły == nullptr -> wypisujemy "--> kandydat"
  l1a->print(); // lista przyjetych pusta - > wypisujemy "brak przyjetych"
  std::cout << std::endl;
  for(auto item : kandydaci) item->print();
  std::cout << std::endl;

  EduSys rekrutacja(szkoly,kandydaci);
  rekrutacja += std::make_shared<Student>("Uczen_10",149, std::vector<std::shared_ptr<SchoolClass>>{l2a, l2b});
  rekrutacja.sortpoints();
  rekrutacja += std::make_shared<Student>("Uczen_11", 99, std::vector<std::shared_ptr<SchoolClass>>{l2b, l2a});
  rekrutacja.recruit(); //funkcja rekrutująca
  std::cout << "---Po rekrutacji:---" << std::endl;
  rekrutacja.printStud();
  std::cout << "---Przydzial dla klasy A LO 1---\n";
  l1a->print();
  std::cout << "---Przydzialy w klasach:---\n";
  rekrutacja.printRecruit();
//-------------------- EXTENDED --------------------//
#ifdef EXTENDED
  std::cout << "============ WERSJA EXTENDED ============\n";
  std::cout << "Srednia kandydatow: " << rekrutacja.getAverageStudScore() <<std::endl;
  rekrutacja.printPlaces(); //brak miejsc
  std::shared_ptr<SchoolClass> l1b = std::make_shared<SchoolClass>("LO1-B", 2);
  rekrutacja += l1b; //stwórz nową klasę i dodaj do rekrutacji
  l1a->setlimit(4); //dodaj miejsca w klasie, zmień z 2 na 4
  std::cout << "LO1-A: " << l1a->getfree() << std::endl;
  std::cout << "---Lista wolnych miejsc---\n";
  rekrutacja.printPlaces();
  std::cout << "\n---Rezygnacje---" << std::endl;
  l2a->print();
  kandydaci[1]->dropout();
  kandydaci[1]->print();
  kandydaci[5]->dropout();
  kandydaci[5]->print();
  l2a->print();
  std::cout << "---Lista wolnych miejsc---\n";
  rekrutacja.printPlaces();
  std::cout << "\n---Kandydaci niezrekrutowani---\n";
  rekrutacja.printApplicants();
  kandydaci[1]-> apply(l1a);
  kandydaci[5]-> apply(l1a);
  if (auto fs = rekrutacja.findStudent("Uczen__7"))
    fs->apply(std::vector<std::shared_ptr<SchoolClass>>{l1a, l2a, l1b} );
  if (auto fs = rekrutacja.findStudent("Uczen__9"))
    fs->apply(std::vector<std::shared_ptr<SchoolClass>>{l1a, l1b, l2a});
  if (auto fs = rekrutacja.findStudent("Uczen_11"))
    fs->apply(std::vector<std::shared_ptr<SchoolClass>>{l1b, l1a, l2a});
  std::cout << "\n---Rekrutacja uzupelniajaca---\n";
  rekrutacja.recruit();
  rekrutacja.printRecruit();
#endif
  return 0;
}

/* Oczekiwany output:
LO1 miejsc 2
Uczen__4: 119 [ LO1-A LO2-A LO2-B ] --> kandydat
LO1-A - 0/2: brak przyjetych

Uczen__1: 151 [ LO1-A LO2-A LO2-B ] --> kandydat
Uczen__2: 130 [ LO2-A LO2-B ] --> kandydat
Uczen__3: 120 [ LO1-A LO2-A LO2-B ] --> kandydat
Uczen__4: 119 [ LO1-A LO2-A LO2-B ] --> kandydat
Uczen__5: 118 [ LO2-B LO2-A ] --> kandydat
Uczen__6: 121 [ LO2-A LO2-B ] --> kandydat
Uczen__7: 110 [ LO1-A LO2-A ] --> kandydat
Uczen__8: 100 [ LO2-B LO2-A ] --> kandydat
Uczen__9: 90 [ LO2-B ] --> kandydat

---Po rekrutacji:---
Uczen__1: 151 [ ] --> LO1-A
Uczen_10: 149 [ ] --> LO2-A
Uczen__2: 130 [ ] --> LO2-A
Uczen__6: 121 [ ] --> LO2-A
Uczen__3: 120 [ ] --> LO1-A
Uczen__4: 119 [ ] --> LO2-B
Uczen__5: 118 [ ] --> LO2-B
Uczen__7: 110 [ ] --> kandydat
Uczen__8: 100 [ ] --> LO2-B
Uczen_11: 99 [ ] --> kandydat
Uczen__9: 90 [ ] --> kandydat

---Przydzial dla klasy A LO 1---
LO1-A - 2/2:
Uczen__1: 151 [ ] --> LO1-A
Uczen__3: 120 [ ] --> LO1-A

---Przydzialy w klasach---
LO1-A - 2/2:
Uczen__1: 151 [ ] --> LO1-A
Uczen__3: 120 [ ] --> LO1-A

LO2-A - 3/3:
Uczen_10: 149 [ ] --> LO2-A
Uczen__2: 130 [ ] --> LO2-A
Uczen__6: 121 [ ] --> LO2-A

LO2-B - 3/3:
Uczen__4: 119 [ ] --> LO2-B
Uczen__5: 118 [ ] --> LO2-B
Uczen__8: 100 [ ] --> LO2-B

============ WERSJA EXTENDED ============
Srednia kandydatow: 118.818
Brak miejsc
LO1-A: 2
---Lista wolnych miejsc---
LO1-A - 2
LO1-B - 2

---Rezygnacje---
LO2-A - 3/3:
Uczen_10: 149 [ ] --> LO2-A
Uczen__2: 130 [ ] --> LO2-A
Uczen__6: 121 [ ] --> LO2-A

Uczen__2 wypisuje sie ze szkoly LO2-A
Uczen__2: 130 [ ] --> kandydat
Uczen__6 wypisuje sie ze szkoly LO2-A
Uczen__6: 121 [ ] --> kandydat
LO2-A - 1/3:
Uczen_10: 149 [ ] --> LO2-A

---Lista wolnych miejsc---
LO1-A - 2
LO2-A - 2
LO1-B - 2

---Kandydaci niezrekrutowani---
Uczen__2: 130 [ ] --> kandydat
Uczen__6: 121 [ ] --> kandydat
Uczen__7: 110 [ ] --> kandydat
Uczen_11: 99 [ ] --> kandydat
Uczen__9: 90 [ ] --> kandydat

---Rekrutacja uzupelniajaca---
LO1-A - 4/4:
Uczen__1: 151 [ ] --> LO1-A
Uczen__3: 120 [ ] --> LO1-A
Uczen__2: 130 [ ] --> LO1-A
Uczen__6: 121 [ ] --> LO1-A

LO2-A - 2/3:
Uczen_10: 149 [ ] --> LO2-A
Uczen__7: 110 [ ] --> LO2-A

LO2-B - 3/3:
Uczen__4: 119 [ ] --> LO2-B
Uczen__5: 118 [ ] --> LO2-B
Uczen__8: 100 [ ] --> LO2-B

LO1-B - 2/2:
Uczen_11: 99 [ ] --> LO1-B
Uczen__9: 90 [ ] --> LO1-B


*/
