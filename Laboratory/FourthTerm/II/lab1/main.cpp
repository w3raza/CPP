/*
 Celem zadania jest napisanie kilku klas powiązanych relacją dziedziczenia. 
 Klasy te opisują elementarne operacje matematyczne. 
 Każda z nich ma jakieś polimorficzne metody i konieczną infrastrukturę.
 
 Proszę dopisać potrzebne klasy o odpowiedniej hierarchii
 oraz funkcje tak, aby program kompilował się i dawał oczekiwany wynik.
 Wykorzystanie dziedziczenia to uniknięcie kopiuj-wklej, 
 kod klasy nadrzędnej ma realizować maksimmum pozliwej funkcjonalności.
 */

#include "Div.h"
#include "Exp.h"
#include "Add.h"
#include <iostream>

int main() {
  Division div1(4.,2.);
  Division div2(2.5,0.5);
  Exponentiation pow(5,0.5);
  const double n = 4.;
  const Addition suma(n,3.2);

  std::cout << "Dzielenie:\t";
  div1.print();
  std::cout <<std::endl;
  "Dzielenie:" >>= div2;
  "Potegowanie:" >>= pow;
  "Sumowanie:" >>= suma;

Operation* d1 = new Division(7,2);
  "Dzielenie:" >>= *d1;
const Operation* d2(new Addition(n/5., 3.2));
  "Sumowanie:" >>= *d2;

  std::cout << "=====================================" << std::endl;
    
  const Operation* all[] = {&div1, &div2, &pow, &suma, d1, d2}; 
  for ( unsigned idx = 0; idx < sizeof(all)/sizeof(Operation*); ++idx ) {
    const Operation* d = all[idx];
    d->print(); 
    std::cout << " = " << d->eval() << std::endl;
  } 
  delete d1;
  delete d2; 
}
/* wynik ./main
Dzielenie:      4 / 2 
Dzielenie:      2.5 / 0.5
Potegowanie:    5 ^ 0.5
Sumowanie:      4 + 3.2
Dzielenie:      7 / 2
Sumowanie:      0.8 + 3.2
=====================================
4 / 2  = 2
2.5 / 0.5  = 5
5 ^ 0.5  = 2.23607
4 + 3.2  = 7.2
7 / 2  = 3.5
0.8 + 3.2  = 4
 */
