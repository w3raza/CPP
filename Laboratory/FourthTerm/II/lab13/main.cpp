/* 
 Na zakończenie powtórka z algorytmów, funkcji lambda i funktorów.
 Celem zadania jest zdefiniowanie odpowiednich funktorów, klas szablonowych,
 funkcji nienazwanych lambda, odpowiednio wykorzystanach w poniższmym programie.
 UWAGA: kolejne części zadania wykonujemy odkomentowując odpowiednie #define
*/

#include <iostream>
#include "FunLambda.h"

#define ZADANIE1
#define ZADANIE2
#define ZADANIE3

// Example usage
double myFunction(double x) {
    return x * x;  // Example function: f(x) = x^2
}

int main() {

  double x = 2.0;
  double h = 0.001;
  std::vector<int> a {1,2,3,4,5,6,7,9,11,16,19};
  int s=0;

  std::cout << "Function value ( x = " << x << ") = " << myFunction(x) << std::endl;

#ifdef ZADANIE1
/* ZADANIE 1
   Zaimplementuj funkcję flmbd::approximateDerivative która zwraca przybliżoną wartość
   pochodnej funkcji, metodą różnic, def.:
   wart_pochodnej = (fun(x+h)-fun(x-h))/(2*h)
   UWAGA: w definicji wykorzystaj: std::function
*/
  double derivative = flmbd::approximateDerivative(myFunction, x, h); 
  std::cout << "FUNCTION: Approximate derivative  (x = " << x << ") = " << derivative << std::endl;
  
// ZMODYFIKUJ DEFINICJĘ tak aby lambda była odpowiednikiem flmbd::approximateDerivative
// - zwróć uwagę na typ przechwytywania zmiannych lokalnych (nie wykonuj kopii)
  auto approximateDerivativeLambda = [&x, &h]() -> double { return (myFunction(x+h)-myFunction(x-h))/(2*h); };                                                                   
  std::cout << "LAMBDA:   Approximate derivative ( x = " << x << ") = " << approximateDerivativeLambda() << std::endl;
#endif

#ifdef ZADANIE2
 /*  
   ZADANIE 2
   Zdefiniuj szablon funktora opowiadającego za sumowanie kolejo
   przekazanych argumentów:
*/
  flmbd::Sum<int> sum{s};
  std::for_each(a.begin(), a.end(), sum);
  std::cout << "FUNCTOR: Sum = " << s << std::endl;

  s = 0;
  // ZMODYFIKUJ DEFINICJĘ tak aby lambda była odpowiednikiem flmbd::sum
  std::for_each(a.begin(), a.end(), [&](int x) { s += x; } );
  std::cout << "LAMBDA:  Sum = " << s << std::endl;
#endif

#ifdef ZADANIE3
/*
  ZADANIE 3
  Zdefiniuj szablon funktora flmbd::filter który przyjmujac jako parametr obiekt 
  zawierajacy iterator, na podstawie przekazanej jako drugi parametr funkcji (szablonowej lub nie)
  albo funktora będzie odpowiednie wartości drukował na ekran:
*/
  flmbd::filter(a,flmbd::even<int>);  // Zdefiniuj odpowieni szablon funkcji even
  flmbd::filter(a,flmbd::odd<int>);   // Zdefiniuj odpowieni szablon funkcji odd
  int value=9;
  flmbd::filter(a,flmbd::GreaterThan<int>(value)); // Zdefiniuj odpowieni szablon funktora GreaterThan
  
  // ZMODYFIKUJ DEFINICJĘ tak, aby lambda była odpowiednikiem flmbd::GreaterThan dla typu int
  flmbd::filter(a, [&value](int x) { return x > value; } );
#endif

  return 0;
}


/* oczekiwany wynik
Function value ( x = 2) = 4
FUNCTION: Approximate derivative  (x = 2) = 4
LAMBDA:   Approximate derivative ( x = 2) = 0
FUNCTOR: Sum = 83
LAMBDA:  Sum = 83
2 4 6 16
1 3 5 7 9 11 19
11 16 19
11 16 19
*/