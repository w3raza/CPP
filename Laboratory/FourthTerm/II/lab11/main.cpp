/* 
Tematem zadania jest dziedziczenie szablonów i specjalizacje klas.
W ramach zadania należy zdefiniować szablon klasy listy jednokierunkowej CustomList, będacej rozszerzeniem listy std::list (tylko i wyłącznie) 
o pewne funkcjonalności jak np łączenie push_back czy specyficzne odwracanie listy oraz UniqList będącej rozszerzeniem CustomList z dwoma specjalizacjami:
Dla bool=true jest to lista bez powtórzeń elementów.
Dla bool=false jest to praktycznie lista CustomList.
Jeśli chodzi o sumAll(), zakładamy, że każda z klas ma zdefiniowany operator + i na tym bazujemy.
UWAGA:
* Klasa CustomList może dziedziczyć tylko i wyłącznie po std::list, zastosowanie innego szablonu będzie zadaniem nie na temat.
* Iterator tail() nie jest tym samym co end()
*/

#include <iostream>
#include <string>

#include "customList.h"
#include "uniqList.h"

#define SPEC
using namespace std;

int main() {
    cout << "***** Lista Integer *****" << endl;
    CustomList<int> intList;    
    intList.push_back(3);
    intList.push_front(2);
    intList.push_back(2).push_front(1);
    intList.push_front(3).push_back(4);

    std::cout << "Lista: ";
    intList.print();    //3 1 2 3 2 4

    cout << (intList.contains(2) ? "Znaleziono" : "Nie znaleziono") << std::endl;

    auto it = intList.find(2);
    if (it!=intList.end()) cout << "Usuwam " <<intList[it] <<endl;
    intList.erase(it);
    intList.pop_front();
    intList.push_front(5);
    cout << "Lista oryginalna: " << intList;
    cout << "Lista odwrócona: " << intList.reverse();
    cout << "Lista oryginalna: " << intList;
    const CustomList<int> constIntList = intList;
    cout << "Lista odwrócona: " << constIntList.copy_reversed();
    intList.push_back(4).push_back(5);
    intList.push_front(2).push_front(0);
    std::cout << "Lista: " << intList;
    intList.removeDuplicates();
    std::cout << "Posortowana lista bez powtorzen: " << intList;
    std::cout << "Wynik dodawania: " << intList.sumAll() << std::endl;
#ifdef SPEC
    // cout << "\n***** Lista String *****" << endl;
    // UniqList<string, true> uniqList;
    // uniqList.push_back("ala").push_front("ola").push_back("ola");
    // uniqList.push_back("ala").push_front("iza").push_back("ola");
    // for (auto it = uniqList.head(); it != uniqList.end(); ++it) {
    //     cout << uniqList[it] << " ";
    // }
    // std::cout << "\nWynik konkatenacji: " << uniqList.sumAll() << std::endl;

    // UniqList<string, false> noUniqList;
    // noUniqList.push_back("ala").push_front("ola").push_back("ola");
    // noUniqList.push_back("ala").push_front("iza").push_back("ola");
    // // eksperymenty, zamiast zastosować rbegin i rend
    // for (auto it = noUniqList.tail(); it != noUniqList.head(); it--) { 
    //     cout << noUniqList[it] << " ";
    // }
    // std::cout << noUniqList.front() << std::endl;
    // std::cout << noUniqList.copy_reversed();    
    // noUniqList.removeDuplicates();
    // std::cout << "Lista bez powtorzen: " << noUniqList;
#endif
    return 0;
}


/* oczekiwany wynik
***** Lista Integer *****
Lista: 3 1 2 3 2 4
Znaleziono
Usuwam 2
Lista oryginalna: 5 1 3 2 4
Lista odwrócona: 4 2 3 1 5
Lista oryginalna: 4 2 3 1 5
Lista odwrócona: 5 1 3 2 4
Lista: 0 2 4 2 3 1 5 4 5
Posortowana lista bez powtorzen: 0 1 2 3 4 5
Wynik dodawania: 15

***** Lista String *****
iza ola ala
Wynik konkatenacji: izaolaala
ola ala ola ala ola iza
ola ala ola ala ola iza
Lista bez powtorzen: ala iza ola
 */
