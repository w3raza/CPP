// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Zadanie związane jest z podstawami dziedziczenia wielokrotnego.  
// W hierarchii wystepuja 4 klasy. Należy poprawnie odwzorowac zależnosci między nimi.
// UWAGA: Klasa bazowa Person nie moze byc interfejsem (czysto wirtualna).
// UWAGA: Operator << zachowuje sie jak, wirtualna metoda, nalezy to rozwiązac przez przekierowania
//        jego funkcjonalnosci do wirtualnej metody.

#include <iostream>
#include "Person.h"
#include "Faculty.h"
#include "Grade.h"
#include "Student.h"

int main() {
  {
    Person m("Jennifer"); // name
    std::cout << "Just Person: " << m  << std::endl;
  }

  {
    Student* s = new Student("Jennifer",1334);  // name, id
    Person *x  = s;  
    std::cout << "Student: "  << *x << std::endl;
    delete x;
  }
  
  {
    Faculty* l = new Faculty("Jennifer","Physics");  // name, spec
    const Person* x  = l;  
    std::cout << "Faculty: "  << *x << std::endl;
    delete x;
  }

  { // przygoda z wielokrotnym dziedziczeniem
    Grade* k = new Grade("Jennifer",1334,"Physics"); // name, id, spec
    Student* s = k;
    Faculty* l = k; l = k = nullptr;
    std::cout << "Grade:\n" << *s << std::endl;    
    delete s;    
  }
}

/* wynik:
Just Person: Person: name: Jennifer 
~Person (Jennifer)
Student: Student: Person: name: Jennifer  id: 1334
~Student (Jennifer, id=1334)
~Person (Jennifer)
Faculty: Faculty: Person: name: Jennifer  spec: Physics
~Faculty
~Person (Jennifer)
Grade:
jako Person: name: Jennifer 
jako Student: Person: name: Jennifer  id: 1334
jako Faculty: Person: name: Jennifer  spec: Physics
~Grade
~Faculty
~Student (Jennifer, id=1334)
~Person (Jennifer
*/