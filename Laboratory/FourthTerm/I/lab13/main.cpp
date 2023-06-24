// ZADANIE WYKONYWANE W TRYBIE ZDALNYM, NIE NA OCENE
// zachęcam do samodzielnego wykonywania! 
//
// Prosze dopisać kod, dodac nowe pliki, tak aby program wykonywal się, 
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest zdefiniowanie odpowiednich funktorów, klas szablonowych,
// funkcji nienazwanych lambda, odpowiednio wykorzystanach w poniższmym main.
// UWAGA: część zadania wykonujemy modyfikując plik main.cpp
//
// Ostateczny program powinien byc przyjazny dla programisty (miec czytelny 
// i dobrze napisany kod), oraz powinna być spełniona zasada D.R.Y. 
// - Don't Repeat Yourself.
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu. Rozwiazanie (czyli dodane pliki i main.cpp) 
// należy wgrać do UPEL jako archiwum tar.gz, 
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab14/
// * archiwum nie powinno zawierać katalogu build/

#include <iostream>
#include "FunLambdas.hh"

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

  // _________  
  // ZADANIE 1
  // Zaimplementuj funkcję flcpp::approximateDerivative która zwraca przybliżoną wartość
  // pochodnej funkcji, metodą różnic, def.:
  // wart_pochodnej = (fun (x+h) - fun(x-h)) / (2 * h)
  // UWAGA: w definicji wykorzystaj: std::function
  double derivative = flcpp::approximateDerivative(myFunction, x, h); 
  std::cout << "FUNCTION: Approximate derivative  (x = " << x << ") = " << derivative << std::endl;
  
  // ZMODYFIKUJ DEFINICJĘ tak aby lambda była odpowiednikiem flcpp::approximateDerivative
  // - zwróć uwagę na typ przechwytywania zmiannych lokalnych (nie wykonuj kopii)
  auto approximateDerivativeLambda = []() -> double { return 0; }; 
                                                                   
  std::cout << "LAMBDA:   Approximate derivative ( x = " << x << ") = " << approximateDerivativeLambda() << std::endl;

  // _________  
  // ZADANIE 2
  // Zdefiniuj szablon funktora opowiadającego za sumowanie kolejo
  // przekazanych argumentów:
  flcpp::Sum<int> sum{s};
  std::for_each(a.begin(), a.end(), sum);
  std::cout << "FUNCTOR: Sum = " << s << std::endl;

  s = 0;
  // ZMODYFIKUJ DEFINICJĘ tak aby lambda była odpowiednikiem flcpp::sum
  // std::for_each(a.begin(), a.end(), [](int x) {} );
  // std::cout << "LAMBDA:  Sum = " << s << std::endl;

  // _________ 
  // ZADANIE 3
  // Zdefiniuj szablon funktora flcpp::filter który przyjmujac jako parametr obiekt 
  // zawierajacy iterator, na podstawie przekazanej jako drugi parametr funkcji (szablonowej lub nie)
  // albo funktora będzie odpowiednie wartości drukował na ekran:
  flcpp::filter(a,flcpp::even<int>);  // Zdefiniuj odpowieni szablon funkcji even
  flcpp::filter(a,flcpp::odd<int>);   // Zdefiniuj odpowieni szablon funkcji odd
  int value=9;
  flcpp::filter(a,flcpp::GreaterThan<int>(value)); // Zdefiniuj odpowieni szablon funktora GreaterThan
  
  // ZMODYFIKUJ DEFINICJĘ tak aby lambda była odpowiednikiem flcpp::GreaterThan dla typu int
  // flcpp::filter(a, []() {} );
  return 0;

}
/* wynik
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