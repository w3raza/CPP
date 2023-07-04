//Proszę omówić poprawność poniższego kodu:
#include <iostream>
#include <typeinfo>

struct A { 
	virtual ~A() {std::cout << "~A()\n"; }
};

template <typename T>
struct B: A {
	T v = T();
	B() = default;
	B(const B&) { std::cout << "Copy " << typeid(B<T>).name() << "()\n";}
	~B() { std::cout << "~" << typeid(B<T>).name() << "()\n"; }
};


int main() {
	typedef B<A> B_A;
	using TypeName = B<B_A>;
	TypeName a = TypeName(TypeName());
	TypeName b {a};
}
/*Wyjście programu
Copy 1BIS_I1AEE()
~1BIS_I1AEE()
~1BI1AE()
~A()
~A()
~A()
~1BIS_I1AEE()
~1BI1AE()
~A()
~A()
~A()
*/
/*
Ten kod C++ jest poprawny i powinien skompilować się bez problemów. 
Struktura A to prosty typ z destruktorem wirtualnym, który wyświetla komunikat przy niszczeniu obiektu. 
Struktura B to szablon struktury, która dziedziczy po A i posiada jedno pole o typie określanym przez parametr szablonu. 
Wartość tego pola jest inicjalizowana do domyślnej wartości dla tego typu (T()).

Klasa B ma dwa konstruktory: domyślny i kopiujący. 
Konstruktor kopiujący wyświetla komunikat podczas wywołania. Jest to bardzo przydatne do śledzenia tego, kiedy i jakie obiekty są kopiowane. 
Konstruktor domyślny jest jawnie wywoływany poprzez B() = default; co jest równoznaczne z brakiem jakiejkolwiek implementacji.

Główna funkcja (main) używa struktury B do zdefiniowania dwóch typów: B_A, który jest B<A>, i TypeName, który jest B<B_A>. 
Następnie tworzy dwa obiekty tych typów: a i b. 
Obiekt a jest inicjalizowany przy użyciu tymczasowego obiektu TypeName, który jest niszczony natychmiast po zainicjowaniu a. 
Obiekt b jest inicjalizowany poprzez kopię a.

Podczas wykonania programu, zauważysz, że tworzone są różne obiekty (oraz ich kopie), a następnie są one niszczone, gdy wyjdą poza zakres (na końcu funkcji main). 
Wiadomości wyświetlane w konsoli pomogą Ci zrozumieć, jakie obiekty są kopiowane i niszczone oraz w jakiej kolejności.

Jednak, warto dodać, że metoda typeid().name() zwraca nazwę typu w formie ciągu znaków, ale dokładna postać tego ciągu znaków jest zależna od implementacji. 
W praktyce może to oznaczać, że ciągi znaków, które otrzymasz, mogą nie być czytelne. 
Na przykład, dla niektórych kompilatorów, typeid(B<T>).name() może zwrócić ciąg znaków typu 1B1A zamiast oczekiwanego B<A>.
*/