/*  
  Proszę dopisać kod, dodać nowe pliki, tak aby program się wykonywał a wynik jego działania był taki sam, jak podany na końcu tego pliku.

  Klasa Element reprezentuje element listy jednokierunkowej i posiada prywatne pole wskaźnika na dynamiczną tablicę int oraz wskaźnik na następny element.
  Ponadto posiada potrzebne konstruktory i destruktory oraz metody.
  
  Klasa MyList i zawiera prywatny wskaźnik na head oraz publiczne metody:
  * konstruktor - ustawiający wskaźniki na NULL i ew. nadający nazwę (dawne initList),
  * destruktor - usuwający wszystkie elementy listy oraz samą listę,
  * add - wstawia wartość int*  lub Element na początek listy,
  * removeFirst - usuwa pierwszy element z listy wraz z dealokacją pamięci obiektu typu Element,
  * print - drukuje całą listę w postaci <el1 el2 el3>
  * copyRev - wykonująca kopię listy podanej jako argument.
*/

#include "MyList.h"
#include "Element.h"
#include <iostream>

int main() {
  std::cout << "*** Lista 1 ***" << std::endl;
  MyList list1; 
  int p1[] = {1,2,3};

  Element *pp1=new Element(p1,3); //konstruktor
  pp1->printElem();
  std::cout << std::endl;
  p1[1]=-2;
  list1.add(pp1); //podpinamy element na poczatek listy
  std::cout << "Pierwszy: ";
  list1.getHead()-> printElem();
  std::cout << std::endl;
  list1.add(p1,2);
  p1[0]=-1;
  const int* q1 = p1;
  list1.add(q1,3);

  const MyList* ptr1 = &list1;
  std::cout << "Pierwszy: ";
  ptr1->getHead()-> printElem();
  std::cout << std::endl;

  const MyList *ptrc=ptr1;
  std::cout << "Czy lista 1 jest pusta? " 
            << (ptrc->isEmpty()?"Tak":"Nie") << std::endl;
  ptrc->print("Lista1");
  
  std::cout << "\n*** Lista 2 ***" <<std::endl;
  MyList* plist2=new MyList;
  plist2->copyRev(&list1);
  plist2->print("Lista2");

  std::cout << "\n*** Usuwanie po elemencie ***" << std::endl; 
  list1.print("Lista1");
  list1.removeFirst();
  list1.print("Lista1");
  list1.removeFirst();
  list1.print("Lista1");
  list1.removeFirst();
  list1.print("Lista1");
  list1.removeFirst(); //próba usunięcia z pustej listy
  std::cout << "Czy lista 1 jest pusta? " 
            << (ptrc->isEmpty()?"Tak":"Nie") << std::endl;
  const MyList *p2list2=plist2;
  p2list2->print("Lista2");  
  delete plist2;
  return 0;
}

/* Oczekiwany wynik: ./main
*** Lista 1 ***
(1,2,3)
Pierwszy: (1,2,3)
Pierwszy: (-1,-2,3)
Czy lista 1 jest pusta? Nie
Lista1 = <(-1,-2,3) (1,-2) (1,2,3)>

*** Lista 2 ***
Lista2 = <(1,2,3) (1,-2) (-1,-2,3)>

*** Usuwanie po elemencie ***
Lista1 = <(-1,-2,3) (1,-2) (1,2,3)>
Destruktor Element: (-1,-2,3)
Lista1 = <(1,-2) (1,2,3)>
Destruktor Element: (1,-2)
Lista1 = <(1,2,3)>
Destruktor Element: (1,2,3)
Lista1 = <>
Czy lista 1 jest pusta? Tak
Lista2 = <(1,2,3) (1,-2) (-1,-2,3)>
Destruktor MyList 
Destruktor Element: (1,2,3)
Destruktor Element: (1,-2)
Destruktor Element: (-1,-2,3)
Destruktor MyList 
*/
//if(!isEmpty()){
//         Element* next = _head;

//         while(next != nullptr){
//             if(next->getNext() == nullptr){
//                 std::cout << "Destruktor Element: ";
//                 next->printElem(); 
//                 std::cout << std::endl;
//                 delete[] next;
//                 break;
//             }else{
//                 next = next->getNext();
//             }
//         }
//     }