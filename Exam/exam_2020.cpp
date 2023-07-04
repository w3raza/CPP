// ---------------------------- Zadanie 1. ----------------------------
#include <iostream>

struct Int_t{
    Int_t(int v): _v(v){
        std::cout << "K_" << _v << ";";
    }

    ~Int_t(){
        std::cout << "D_" << _v << ";";
    }
private:
    int _v = 1;
};

class ptr{
public:
    ptr(Int_t* p = nullptr){
        _p = p;
    }
    ~ptr(){
        delete _p;
    }
private:
    Int_t* _p;
};

int main(){
    { ptr p{new Int_t{1}}; }
      ptr p{new Int_t{2}};
}
/*
K_1;D_1;K_2;D_2;
*/

/* ---------------------------- Zadanie 2. ----------------------------
Zaznacz wszystkie prawdziwe stwierdzenia:
a. W języku C++ wymagane jest obsłużenie każdego wyjątku 
b. Wyrzucanie wyjątków z destruktorów jest zabronione, bo mogłoby zakłócać procedurę obsługi wyjątków 
c. W języku C++ funkcja (metoda) może obiecywać, że jest bezpieczna i nie wyrzuca wyjątków // noexcept
d. Wyrzucanie wyjątków z destruktorów jest dozwolone, bo wyjątki można wyrzucać w dowolnym miejscu i powinny być zawsze poprawnie obsłużone 
e. Żadne z pozostałych stwierdzeń nie jest prawdziwe 
f. Wyrzucanie wyjątków z destruktorów jest dozwolone, choć zdecydowanie nie należy tego robić 

Prawdziwe stwierdzenia to:
c. W języku C++ funkcja (metoda) może obiecywać, że jest bezpieczna i nie wyrzuca wyjątków.
f. Wyrzucanie wyjątków z destruktorów jest dozwolone, choć zdecydowanie nie należy tego robić.

Wyjaśnienie:
a. Nie jest wymagane obsłużenie każdego wyjątku w języku C++. Obsługa wyjątków jest opcjonalna, a programista może decydować, czy chce obsłużyć konkretne wyjątki czy też przekazać je dalej.
b. Wyrzucanie wyjątków z destruktorów jest zazwyczaj niezalecane, ponieważ może prowadzić do nieprzewidywalnego zachowania programu i trudności w obsłudze wyjątków.
d. Wyrzucanie wyjątków z destruktorów jest zazwyczaj niezalecane. Wyjątki powinny być obsługiwane w sposób kontrolowany i przewidywalny, a wyrzucanie ich z destruktorów może utrudnić taką obsługę.
e. Nie można stwierdzić, że żadne z pozostałych stwierdzeń nie jest prawdziwe, ponieważ istnieją prawdziwe stwierdzenia (c i f).
*/

// ---------------------------- Zadanie 3. ----------------------------
#include <iostream>
#include <stdexcept> //std::runtime_error

class Fraction {
public:
    Fraction(int l = 0, int m = 1) noexcept: _l(l), _m(m) {
        if(_m == 0){
            throw std::runtime_error("Invalid denominator");
        }
    }
private:
    int _l = 0;
    int _m = 1;
};

int main() {
    try {
       Fraction f(1, 0); 
    }catch (std::runtime_error &e){
        std::cout << e.what() << '\n';
    }
}
/*
terminate called after throwing an instance of 'std::runtime_error'
what():  Invalid denominator
Aborted
*/

// ---------------------------- Zadanie 4. ----------------------------
#include <iostream>

template <typename T>
struct box{
    T a_ = {};
};

template <typename T>
std::ostream& operator<<(std::ostream& o, const box<T>& val){
    return o << "T(" << val.a_ << ");";
}

int main(){
    std::cout << box< box<int> >() << std::endl;
}
/*
T(T(0););
*/

// ---------------------------- Zadanie 5. ----------------------------
#include <iostream>
#include <array>

template <typename T, typename V>
void set_for_each(T& cnt, V val){
    for(auto v: cnt)
        v = val;
}

template <typename T>
void printer(const T& cnt, std::ostream& o = std::cout){
    for(auto v: cnt)
        o << v << ";";
}

int main(){
    std::array<int, 5> t = {1, 2, 3};
    set_for_each(t, 7);
    printer(t);
}
/*
1;2;3;0;0;

Jeśli byśmy chcieli uzysakć same 7 na wyjściu to trzeba dodać &:  for(auto& v: cnt)
*/

// ----------------------------Zadanie 6.  ----------------------------
/* Zaznacz wszystkie prawdziwe stwierdzenia:
a. Programowanie zorientowane obiektowo charakteryzuje się m.in.: uogólnieniem i abstrakcją 
b. Żadne z pozostałych stwierdzeń nie jest prawdziwe 
c. Programowanie zorientowane obiektowo charakteryzuje się m.in.: polimorfizmem 
d. Programowanie zorientowane obiektowo charakteryzuje się m.in.: wykorzystaniem funkcji wirtualnych
e. Programowanie zorientowane obiektowo charakteryzuje się m.in.: wykorzystaniem obiektów i relacji między nimi
f. Programowanie zorientowane obiektowo charakteryzuje się m.in: wykorzystaniem dziedziczenia 

Stwierdzenia a, c, d, e i f są prawdziwe.

a. Programowanie zorientowane obiektowo charakteryzuje się m.in. uogólnieniem i abstrakcją. OOP (Object-Oriented Programming) opiera się na tworzeniu klas, które są uogólnieniem obiektów, a także na abstrakcji, czyli tworzeniu abstrakcyjnych modeli, które reprezentują rzeczywistość.
c. Programowanie zorientowane obiektowo charakteryzuje się m.in. polimorfizmem. Polimorfizm pozwala na korzystanie z różnych implementacji danego interfejsu przez różne obiekty. Oznacza to, że obiekty mogą zachowywać się różnie w zależności od swojego typu.
d. Programowanie zorientowane obiektowo charakteryzuje się m.in. wykorzystaniem funkcji wirtualnych. Funkcje wirtualne pozwalają na przesłanianie metod w klasach pochodnych, co umożliwia polimorficzne zachowanie obiektów.
e. Programowanie zorientowane obiektowo charakteryzuje się m.in. wykorzystaniem obiektów i relacji między nimi. OOP skupia się na tworzeniu obiektów, które są instancjami klas, oraz na definiowaniu relacji między nimi, takich jak dziedziczenie, agregacja i kompozycja.
f. Programowanie zorientowane obiektowo charakteryzuje się m.in. wykorzystaniem dziedziczenia. Dziedziczenie pozwala na tworzenie klas pochodnych, które dziedziczą cechy i zachowanie po klasach bazowych, co umożliwia ponowne wykorzystanie kodu i tworzenie hierarchii klas.
*/

// ---------------------------- Zadanie 7. ----------------------------
/* Zaznacz wszystkie prawdziwe stwierdzenia:
a. Rzutowanie w dół hierarchii dziedziczenie może odbyć się niejawnie, ponieważ uwidacznia się w ten sposób polimorfizm
b. Rzutowanie w dół hierarchii dziedziczenie może odbyć się niejawnie, ponieważ korzysta z wczesnego wiązania 
c. Rzutowanie w dół hierarchii dziedziczenie może odbyć się niejawnie, ponieważ jest to część mechanizmu dziedziczenia
d. Rzutowanie w dół hierarchii dziedziczenie może odbyć się niejawnie, ponieważ wykorzystuje obiekty
e. Żadne z pozostałych stwierdzeń nie jest prawdziwe
f. Rzutowanie w dół hierarchii dziedziczenie może odbyć się niejawnie, bo jest to rodzaj abstrakcji wykorzystywanej w programowaniu obiektowym

// e ?
*/

// ---------------------------- Zadanie 8. ----------------------------
/*Zaznacz wszystkie prawdziwe stwierdzenia:
a. Żadne z pozostałych stwierdzeń nie jest prawdziwe 
b. W języku C++ np. typ zdefiniowany jako struct A{}; ma rozmiar 0
c. Klasa (class) i struktura (struct) w języku C++ są na tyle różne, że nie da się ich zawsze wzajemnie zastępować 
d. Zawsze poprawne jest zdefiniowanie funkcji w pliku nagłówkowym 
e. Linkowanie nie zawsze jest konieczne, aby zbudować program (np. kiedy mamy tylko plik main.cpp) 
f. Kompilacja jest pierwszym etapem przetwarzania kodu źródłowego na program 

Prawdziwe stwierdzenia to:
b. W języku C++ np. typ zdefiniowany jako struct A{}; ma rozmiar 0
c. Klasa (class) i struktura (struct) w języku C++ są na tyle różne, że nie da się ich zawsze wzajemnie zastępować
e. Linkowanie nie zawsze jest konieczne, aby zbudować program (np. kiedy mamy tylko plik main.cpp)
f. Kompilacja jest pierwszym etapem przetwarzania kodu źródłowego na program
*/

// ---------------------------- Zadanie 9. ----------------------------
#include <iostream>

struct A{
    A() : A{0}{
        std::cout << "A();";
    }

    A(const A& a) : A(a._a){
        std::cout << "A(const A&);";
    }

    A(int a) : _a(a){
        std::cout << "A(int a);";
    }
private:
    int _a = 0;
};

int main(){
    A a; a = A{};
}
/*
A(int a);A();A(int a);A();
*/

// ---------------------------- Zadanie 10. ---------------------------- 
/* Zaznacz wszystkie prawdziwe stwierdzenia:
a. Żadne z pozostałych stwierdzeń nie jest prawdziwe 
b. Kompilacji może podlegać dowolny plik obiektowy (o) 
c. Jednostką kompilacji w języku C++ nazywamy dowolny plik źródłowy (.cpp) 
d. Kompilacji może podlegać dowolny plik nagłówkowy (.hpp) 
e. Kompilacji może podlegać dowolny plik źródłowy (.cpp) 
f. Kompilacji mogą podlegać tylko pliki przekazane do kompilatora (np. g++) 

c. Jednostką kompilacji w języku C++ nazywamy dowolny plik źródłowy (.cpp)
e. Kompilacji może podlegać dowolny plik źródłowy (.cpp)
*/