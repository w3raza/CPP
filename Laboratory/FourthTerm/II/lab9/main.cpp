/*
Celem zadania jest przecwiczenie definiowania uogólnionych funkcji za pomocą mechanizmów programowania obiektowego (bez wykorzystania rzutowania na void *) oraz funkcji szablonowych. 
To pierwsze polega na zdefiniowaniu ogólnego typu dla obiektów, które mogą być porównywane, a następnie zdefiniowanie wyspecjalizowanych klas. Jest to zadanie żmudne, nieopłacalne (o czym mogliśmy się przekonać w projekcie 1) i posiadające duże ograniczenia, podobnie jak przeładowanie funkcji max dla różnych argumentów, dlatego  zamiast tego wykorzystamy również proste funkcje szablonowe.

Funkcja max jest już zdefiniowana.
Wskazówka do pierwszej części: zdefiniować operator< jako wirtualny i zastować rzutowanie.
Można zdefiniować klasę String za pomocą std::string, trzeba tylko do konwersji do char* trzeba wykorzystać c_str()
*/

#include "greaterclass.h"
#include "greatertemp.h"

#include <iostream>
// #define ERROR
// #define EXTENDED


using std::cout;
using std::endl;

int main() {
  
  cout << "*** Etap 1 - zabawa z klasami ***" << endl;
  const Int a(1),b(2);
  Int c;
  const char* str1="Ala";
  String s1(str1),s2("Ula"); 

  c = (Int&)::max(a,b);
  c.print();
  cout << endl << s1 << endl;
#ifdef ERROR
  c = max(15,10); //zwróci błąd
#endif
  Int d = static_cast<const Int&>(max(Int(15),Int(10)));
  cout << d << endl;
  (static_cast<const String&>(max(s1,s2))).print();
  cout << endl;
  
  cout << "\n*** Etap 2 - funkcje szablonowe ***" << endl;
  cout << Tmax<double>(2.5,1.) << endl;
  cout << Tmax<char>('a','z') << endl;
  cout << static_cast<int>(Tmax<Int>(a,b)) << endl;
  cout << static_cast<const char*>(Tmax<String>(s1,s2)) << endl;

  std::initializer_list<char> tab1 = {'a','c','w','e','u'};
  std::initializer_list<Int> tab2 = {a,b,Int(4),Int(3)};
  const char maks1 = Tmax<char>(tab1);
  const Int maks2 = Tmax<Int>(tab2);
  cout << maks1 << " - " << maks2 << endl;
  std::initializer_list<String> tab = {s1,s2,String("Zuza"),String("Ola")};
  const String maks3 = Tmax<String>(tab);
  cout << maks3 << endl;
  
  c = 5, d = 6;
  cout << "c = " << c << " d = " << d << endl;
  Tswap (c, d);
  cout << "c = " << c << " d = " << d << endl;
  cout << "s1 = " << s1 << " s2 = " << s2 << endl;
  Tswap (s1, s2);
  cout << "s1 = " << s1 << " s2 = " << s2 << endl;
  
  cout << "\n*** Etap 3 - zabawy z konwersja ***" << endl;
  cout << convert<char>(static_cast<int>('A')) << endl; //takie samo działanie
  cout << convert<int,char>('A') << endl;
  for (int i=65;i<91;i++)
    cout << convert<char>(i);
  cout << endl;
  cout << convert<char>(static_cast<Int>('A')) << endl;
  cout << convert<char*,String>(s1) << endl;
  s2 = convert<String>("Mój String");
  cout << s2 << endl;

#ifdef EXTENDED 
  //Jak zdefiniować uogólnione swap(Greater&,Greater&) bez użycia szablonów
  Int aa=a, bb=b;
  cout << "aa = " << aa << " bb = " << bb << endl;
  swap (aa, bb);
  cout << "aa = " << aa << " bb = " << bb << endl;
#endif

  return 0;
}

/* Oczekiwany wynik:

*** Etap 1 - zabawa z klasami ***
2
Ala
15
Ula

*** Etap 2 - funkcje szablonowe ***
2.5
z
2
Ula
w - 4
Zuza
c = 5 d = 6
c = 6 d = 5
s1 = Ala s2 = Ula
s1 = Ula s2 = Ala

*** Etap 3 - zabawy z konwersja ***
A
65
ABCDEFGHIJKLMNOPQRSTUVWXYZ
A
Ula
Mój String
//EXTENDED
aa = 1 bb = 2
aa = 2 bb = 1
*/