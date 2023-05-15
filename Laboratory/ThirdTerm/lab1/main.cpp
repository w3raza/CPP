/*Proszę skompilować program manualnie (kompilator g++) - bez użycia programu make.
 Proszę uzupełnić kod o bibliotekę silnia (silnia.h, silnia.cpp)
 * z funkcjami silnia i silnia_rec
 * Proszę skompilować uzupełniony program
 * Rozwiązanie w formie wszystkich plików kodu źródłowego proszę umieścić w katalogu o nazwie
 * nr_grupy_lab1_nazwisko, z którego należy utworzyć archiwum nr_grupy_lab1_nazwisko.tar.gz
 * i przesłać na platformę UPEL
 * 
 */

#include <iostream> 
#include <cmath>
#include "silnia.h"

// Dodać bibliotekę silnia
// Aby uniknąć podwójnego ładowania jednej biblioteki,
// w odpowiednim miejscu zastosuj dyrektywę pragma
// https://en.wikipedia.org/wiki/Pragma_once

using namespace std;

int main ()
{
  int i,abs_i;
  cout << "Podaj liczbę całkowitą: ";
  cin >> i;
  cout << "Podano liczbę " << i;
  abs_i=abs(i);
  cout << " a jej wartość bezwzględna wynosi " << abs_i << ".\n";

//Odkomentuj po napisaniu funkcji silnia i silnia_rec w osobnej bibliotece silnia.h
  cout << "Silnia liczby " << i <<" wynosi "<< silnia(i) <<".\n";
  cout << "Silnia liczby " << abs_i <<" wynosi "<< silnia(abs_i) <<".\n";
  cout << "Silnia obliczona rekurencyjnie liczby " << abs_i <<" wynosi "<< silnia_rec(abs_i) <<".\n";

  return 0;
}

/* 
Przykładowy oczekiwany wynik dla -3:
Podaj liczbę całkowitą: -3
Podano liczbę -3 a jej wartość bezwzględna wynosi 3.
Silnia liczby -3 = brak rozwiązania .
Silnia liczby 3 = 6.
Silnia obliczona rekurencyjnie liczby 3 wynosi 6.
*/  

