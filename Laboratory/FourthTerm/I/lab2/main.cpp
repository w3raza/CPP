// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.

// Proszę zaimplementować klasę MyString do przechowywania napisu
// (można skorzystać lub nie z std::string)
// Prosze napisac odpowiednie funktory które mogą być wykorzystane w ramach std::sort
// Uwaga: w definicji tych funktorów należy skorzystać z operatorów relacyjnych dla typu MyString,
//        które odpowiednio należy zaimplementować.


#include <iostream>
#include <algorithm>
#include "StringFun.h"

int main() {

  // Na start porównanie MyString z wykorzystaniem funktora:
  MyString nameA = "Abigale";
  MyString nameB = "Allesandro";

  Less less;
  std::string name = less.operator()(nameA,nameB) ? nameA.str() : nameB.str();
  std::cout << "Name alphabetically going first:\n" << name << "\n" << std::endl;
  
  // Operacje na napisach przechowywanych w  std::vector, oraz z wykorzystaniem funktorów:
  std::vector<MyString> names = { "Abe", "Andrew", "Aaron", "Arthur", "Alfred", "Al", 
                      "Abdul", "Adrian", "Albert", "Alessandro" };

  std::cout << "Original unsorted names:" << std::endl;
  PrintNames(names);

  std::sort( names.begin(), names.end(), Less() ); // to jest ten sam funkctor co w linii 36
  std::cout << "Sorted names (alphabetical, ascending):" << std::endl;
  PrintNames(names);
  
  std::sort( names.begin(), names.end(), Greater() );
  std::cout << "Sorted names (alphabetical, descending):" << std::endl;
  PrintNames(names);

  std::sort( names.begin(), names.end(), Length() );
  std::cout << "Sorted names (string length, ascending):" << std::endl;
  PrintNames(names);
  
  return 0;  
}
/* wynik:
Name alphabetically going first:
Abigale

Original unsorted names:
Abe Andrew Aaron Arthur Alfred Al Abdul Adrian Albert Alessandro 

Sorted names (alphabetical, ascending):
Aaron Abdul Abe Adrian Al Albert Alessandro Alfred Andrew Arthur 

Sorted names (alphabetical, descending):
Arthur Andrew Alfred Alessandro Albert Al Adrian Abe Abdul Aaron 

Sorted names (string length, ascending):
Al Abe Abdul Aaron Arthur Andrew Alfred Albert Adrian Alessandro 

*/
