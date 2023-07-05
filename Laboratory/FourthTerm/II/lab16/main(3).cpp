/* Celem zadania jest przećwiczenie szablonów klas z paraMeterami szablonu innymi niż typ (operatory arytmetyczne) oraz częściowej specjalizacji.
Należy zaimplementowac taki kod, ktory pozwoli realizować dzialania zgodnie z zasadami obowiazującymi w fizyce, to znaczy mnożyć i dzielić przez siebie można dowolne liczby, ale dodawać i odejmować jedynie liczby o tej samej jednostce.

UWAGA!!!
Rozwiązanie powinno działać dla dowolnych potęg Metera, również tych, które nie są wypisane w tym programie.
*/

#include "units.h"
#include <iostream>

// #define ERROR1
// #define ERROR2

int main()
{
  using namespace std;

  Meter len(4);
  Meter width(5);
  Meter height(2.5);
  Meter2 area = len * width;
  Meter3 volume = len * width * height;
  Meter perimeter = len + len + width + width;
  Meter2 doubleArea = area + area;
  Meter2 area2 = volume / height;
  Meter2 area3 = doubleArea - area;
  Meter calcheight = volume / area;

#ifdef ERROR1
  len + area;
  len + volume;
  volume + area;

  len - area;
  len - volume;
  volume - area;
#endif

  std::cout << "--- Wymiary pokoju ---\n";
  std::cout << "Dlugosc: " << len << "\n";
  std::cout << "Szerokosc: " << width << "\n";
  std::cout << "Wysokość: " << height << "\n";
  std::cout << "Powierzchnia: " << area << "\n";
  std::cout << "Objetosc: " << volume << "\n";
  std::cout << "Obwod: " << perimeter << "\n";
  std::cout << "Podwojona powierzchnia: " << doubleArea << "\n";
  std::cout << "Nowa powierzchnia: " << area2 << "\n";
  std::cout << "Nowa powierzchnia: " << area3 << "\n";
  std::cout << "Nowa wysokosc: " << calcheight << "\n";

  std::cout << "\nPotegi dlugosci:\n";
  std::cout << len * len << "\n";
  std::cout << len * len * len << "\n";
  std::cout << len * len * len * len << "\n";
  std::cout << len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len * len * len << "\n";

  std::cout << "\nPodwojone potegi dlugosci:\n";
  std::cout << len * len + len * len << "\n";
  std::cout << len * len * len + len * len * len << "\n";
  std::cout << len * len * len * len + len * len * len * len << "\n";
  std::cout << len * len * len * len * len + len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len + len * len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len * len + len * len * len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len * len * len + len * len * len * len * len * len * len * len << "\n";

#ifdef ERROR2
  std::cout << len + len * len << "\n";
  std::cout << len * len + len * len * len << "\n";
  std::cout << len * len * len + len * len * len * len << "\n";
  std::cout << len * len * len * len + len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len + len * len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len + len * len * len * len * len * len * len << "\n";
  std::cout << len * len * len * len * len * len * len + len * len * len * len * len * len * len * len << "\n";
#endif
}

/*
--- Wymiary pokoju ---
Dlugosc: 4 m
Szerokosc: 5 m
Wysokość: 2.5 m
Powierzchnia: 20 m^2
Objetosc: 50 m^3
Obwod: 18 m
Podwojona powierzchnia: 40 m^2
Nowa powierzchnia: 20 m^2
Nowa powierzchnia: 20 m^2
Nowa wysokosc: 2.5 m

Potegi dlugosci:
16 m^2
64 m^3
256 m^4
1024 m^5
4096 m^6
16384 m^7
65536 m^8

Podwojone potegi dlugosci:
32 m^2
128 m^3
512 m^4
2048 m^5
8192 m^6
32768 m^7
131072 m^8
*/
