/*
  Zadanie jest rozszerzeniem poprzedniego o różne jednostki i typy.

  Celem zadanie jest stworzenie szablonu klasy symbolizującej wielkość fizyczną w jednostkach SI (czyli kombinacje różnych potęg kg, m oraz s). 
  Wielkości te można dodawać tylko jeśli ich jednostki są zgodne, czyli np. można dodać dwie liczby w m^2, ale nie można dodać np. m/s do m^2.
  Można mnożyć je bez ograniczeń, czyli np. wielkość w m pomnożyć przez wielkość w s.
  Dodatkowo można do siebie dodawać wielkości różnych typów (np. double i int).
  Wskazówka: można wykorzystać std::common_type do zdefiniowania wielu typów

  Uwaga: warunki muszą być spełnione dla dowolnych kombinacji jednostek, nie tylko dla tych podanych w programie.

  Uwaga: kompilacja z flagami error musi skutkować błędem: 
  "no match for ‘operator+’ (operand types are (...)"
*/

// #define ERROR1
// #define ERROR2
// #define ERROR3

#include <iostream>
#include "units.h"

int main(){
  Length<double> l1(3.2);
  Length<float> l2(4.0);
  std::cout << "lengths:\t" << l1 + l2 << std::endl;

  Area<int> S(4);
  static_assert(sizeof(S) == sizeof(int), "size wrong");
  static_assert(sizeof(Area<int>(2) + S) == sizeof(int), "summation wrong");
  std::cout << S + l1 * l2 << std::endl;
  std::cout <<  l2 * l2 * l2 << std::endl;

  Time<double> t(10);
  Velocity<double> v1 = l1 / t;
  Velocity<double> v2(20.5);
  std::cout << "velocity:\t" << v1 + v2 << std::endl;

  Acceleration<double> a = v2 / t;
  const Acceleration<float> g(9.80665);
  Weight<int> m(10);
  std::cout << "momentum:\t" << a + g << std::endl;
  std::cout << "gravity:\t" << m * g << std::endl;
  std::cout << "gravity:\t" << g * m << std::endl;
  
  // operacje na dowolnych jednostkach
  std::cout << "mass per area:\t" << m / l1 / l2 + m / S << std::endl;
  std::cout << "pressure:\t" << m * g / S + m * a / S << std::endl;

  // nie mogą się kompilować m.in.:
  #ifdef ERROR1
  l1 * l2 * l1 + a;
  #endif
  #ifdef ERROR2
  l1 + l1 * l2;
  #endif
  #ifdef ERROR3
  m + m / t;
  #endif
}

/* wynik

lengths:	7.2 m
16.8 m^2
64 m^3
velocity:	20.82 m s^-1
momentum:	11.8567 m s^-2
gravity:	98.0665 kg m s^-2
gravity:	98.0665 kg m s^-2
mass per area:	2.78125 kg m^-2
pressure:	29.6416 kg m^-1 s^-2
 */
