//1. Napisać słownik w oparciu o kontener vector i zastosować w nim algorytm sortujący i wstawiający

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

// Definicja typu dla pary klucz-wartość
typedef std::pair<std::string, std::string> KeyValuePair;

class Dictionary {
private:
    std::vector<KeyValuePair> entries;

public:
    // Funkcja do dodawania wpisu do słownika i następnie sortowania słownika
    void addEntry(const std::string& key, const std::string& value) {
        KeyValuePair newEntry(key, value);
        entries.push_back(newEntry);
        std::sort(entries.begin(), entries.end());
    }

    // Funkcja do wyszukiwania wartości na podstawie klucza
    std::string getValue(const std::string& key) {
        // Używamy algorytmu std::lower_bound do znalezienia wpisu o podanym kluczu
        auto it = std::lower_bound(entries.begin(), entries.end(), KeyValuePair(key, ""),
            [](const KeyValuePair &lhs, const KeyValuePair &rhs) {
                return lhs.first < rhs.first;
            });

        // Jeżeli klucz istnieje w słowniku, zwracamy powiązaną z nim wartość
        if (it != entries.end() && it->first == key) {
            return it->second;
        }

        // Jeżeli klucz nie istnieje w słowniku, zwracamy pusty string
        return "";
    }
};

int main() {
    Dictionary dict;

    dict.addEntry("klucz1", "wartość1");
    dict.addEntry("klucz2", "wartość2");
    dict.addEntry("klucz3", "wartość3");

    std::cout << "klucz1: " << dict.getValue("klucz1") << std::endl;
    std::cout << "klucz2: " << dict.getValue("klucz2") << std::endl;
    std::cout << "klucz3: " << dict.getValue("klucz3") << std::endl;
    std::cout << "klucz4: " << dict.getValue("klucz4") << std::endl;

    return 0;
}

//2. Omówić wszystkie rodzaje konwersji.
1. Konwersje jawne (explicit conversions): 
Są to konwersje typów, które są wyraźnie określone przez programistę. 
Można je przeprowadzić za pomocą operacji castowania, takich jak static_cast, dynamic_cast, const_cast, reinterpret_cast 
oraz tradycyjnego castowania w stylu C ( (type)value ).

2. Konwersje niejawne (implicit conversions): 
Są to konwersje typów, które są wykonywane przez kompilator bez wyraźnej interwencji programisty. 
Przykłady to konwersja int do double, konwersja wskaźnika na typ pochodny do wskaźnika na typ bazowy itd.

3. Konwersje standardowe (standard conversions): 
Są to predefiniowane konwersje, które są dostępne dla podstawowych typów danych, takich jak konwersje liczbowe, konwersje wskaźników, konwersje do bool, itd.

4. Konwersje zdefiniowane przez użytkownika (user-defined conversions): 
Są to konwersje, które są zdefiniowane przez użytkownika za pomocą konstruktorów konwertujących i operatorów konwersji.

5. Konwersje kwalifikatorów (qualification conversions): 
Są to konwersje, które dodają lub usuwają kwalifikatory cv (const i volatile).

Roznice między operatorami rzutowania static_cast, dynamic_cast, const_cast i reinterpret_cast:
static_cast: Jest to najbardziej ogólny operator rzutowania, który może konwertować między dowolnymi dwoma typami, o ile konwersja jest sensowna. static_cast sprawdza typy w czasie kompilacji, nie w czasie wykonania, co oznacza, że nie ma sprawdzania typów podczas działania programu.

dynamic_cast: Jest używany głównie z polimorfizmem, do bezpiecznego rzutowania w dół hierarchii dziedziczenia. dynamic_cast sprawdza typy zarówno w czasie kompilacji, jak i w czasie wykonania. Jeżeli rzutowanie nie jest poprawne, dynamic_cast zwróci wskaźnik null (dla wskaźników) lub rzuci wyjątek std::bad_cast (dla referencji).

const_cast: Jest używany do zmiany kwalifikatora const lub volatile obiektu. Jest to jedyny operator, który może to zrobić. Zauważ, że zmiana kwalifikatora const i modyfikowanie obiektu jest zazwyczaj niezdefiniowanym zachowaniem, chyba że oryginalny obiekt nie był const.

reinterpret_cast: Jest to najmniej bezpieczny operator rzutowania, który wykonuje bitową interpretację typów. Jest używany do konwersji między wskaźnikami i między wskaźnikami a liczbami całkowitymi. reinterpret_cast jest bardzo mocny i może prowadzić do niezdefiniowanego zachowania, jeżeli jest używany niepoprawnie.

//Przykład kodu z 2 klasami w którym niejawna konwersja nie zadziała, a konieczna będzie konwersja jawna
Konwersja z Derived* do Base* jest konwersją niejawną i zawsze zadziała, ale konwersja z Base* do Derived* wymaga konwersji jawnej, ponieważ nie wszystkie obiekty Base są obiektami Derived.

class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void ExtraMethod() {
        //...
    }
};

int main() {
    Base* b = new Derived();
    
    // Konwersja niejawna nie zadziała. Kompilator nie pozwoli na to.
    // Derived* d = b;
    
    // Musimy użyć konwersji jawnego (dynamic_cast)
    Derived* d = dynamic_cast<Derived*>(b);
    if(d != nullptr) {
        d->ExtraMethod(); // Teraz możemy wywołać
    }
    
    delete b;
    return 0;
}

// 3. Predykaty, co to, napisz fragemnt kodu ze zdefiniowanych swoim predykatem, i fragemnt kodu
// wykorzystujacy STL'owe. 
Predykat to funkcja lub obiekt funkcyjny, który zwraca wartość typu bool. 
Jest ona powszechnie używana w STL (Standard Template Library), zwłaszcza w algorytmach, które wymagają operacji porównania, 
takich jak std::sort, std::find_if czy std::remove_if.

//Definicja własnego predykatu:
#include <iostream>

//Definicja predykatu
bool isEven(int num) {
    return (num % 2) == 0;
}

int main() {
    int num = 4;
    
    //Użycie predykatu
    if(isEven(num)) {
        std::cout << num << " jest parzyste." << std::endl;
    } else {
        std::cout << num << " jest nieparzyste." << std::endl;
    }
    
    return 0;
}

//Użycie predykatu z STL:
#include <algorithm>
#include <vector>
#include <iostream>

//Definicja predykatu
struct IsEven {
    bool operator()(int num) {
        return num % 2 == 0;
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //Użycie predykatu
    auto it = std::find_if(vec.begin(), vec.end(), IsEven());
    
    if(it != vec.end()) {
        std::cout << "Pierwsza znaleziona liczba parzysta to: " << *it << std::endl;
    } else {
        std::cout << "Nie znaleziono liczby parzystej." << std::endl;
    }
    
    return 0;
}

//4. Alogrytmy z STL'a.
1. Sortowanie (std::sort): służy do sortowania elementów w kontenerze.

#include <algorithm> 
#include <vector>

int main() {
    std::vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    std::sort(v.begin(), v.end());
    return 0;
}

2. Szukanie (std::find): służy do wyszukiwania elementu w kontenerze.

#include <algorithm> 
#include <vector>

int main() {
    std::vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    auto it = std::find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        // Znaleziono element 5.
    }
    return 0;
}

3. Replace (std::replace): zastępuje wszystkie wystąpienia danego elementu innym elementem.

#include <algorithm> 
#include <vector>

int main() {
    std::vector<int> v = {4, 2, 5, 3, 5, 8, 3};
    std::replace(v.begin(), v.end(), 5, 10);
    // Wszystkie 5 zostały zastąpione przez 10.
    return 0;
}

4. Copy (std::copy): kopiuje elementy z jednego kontenera do drugiego.

#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2(5);
    std::copy(v1.begin(), v1.end(), v2.begin());
    // kopiuje elementy z v1 do v2
    return 0;
}

...

//5. Kontenery, rodzaje, właściwości poszczególnych kontenerów, bezpieczeństwo.

1. Vector: 
Jest to dynamiczna tablica, która może zmieniać swój rozmiar. 
Może dodawać lub usuwać elementy z końca w czasie O(1). 
Dostęp do elementów jest również bardzo szybki (O(1)).

2. List: 
Jest to dwukierunkowa lista powiązana, 
która umożliwia szybkie dodawanie i usuwanie elementów z dowolnej pozycji listy (O(1)), 
ale dostęp do elementów jest wolniejszy (O(n)) w porównaniu do vektora.

3. Deque: 
Jest to dwukierunkowa kolejka, 
która umożliwia szybkie dodawanie i usuwanie elementów z obu końców (O(1)), 
ale dostęp do elementów jest nieco wolniejszy (O(1)).

4. Stack: 
Jest to kontener typu LIFO (Last In, First Out), co oznacza, że ostatni dodany element jest pierwszym, który zostanie usunięty.

5. Queue: 
Jest to kontener typu FIFO (First In, First Out), co oznacza, że pierwszy dodany element jest pierwszym, który zostanie usunięty.

6. Priority_queue: 
Jest to kontener, który zawsze zwraca najwyższą wartość na górze. 
Używa się go zazwyczaj do algorytmów, które wymagają kolejności priorytetowej.

7. Set / Multiset: 
Jest to kontener, który przechowuje unikalne elementy w uporządkowany sposób. 
Multiset pozwala na przechowywanie duplikatów.

8. Map / Multimap: 
Jest to kontener, który przechowuje pary (klucz, wartość) w uporządkowany sposób. 
Multimap pozwala na przechowywanie wielu wartości dla jednego klucza.

Co do bezpieczeństwa, kontenery STL są ogólnie bezpieczne pod względem zarządzania pamięcią, 
ponieważ alokują i zwalniają pamięć automatycznie. 
Kontenery STL nie chronią również przed błędami takimi jak przekroczenie zakresu, 
które mogą prowadzić do niewłaściwego dostępu do pamięci. 

// Kontenery stl - podzial, struktura w pamieci, bezpieczenstwo, szybkosc, wykorzystanie, 
//iterator i pozniej opis wszystkich iteratorow
W STL, iteratory służą do nawigacji po elementach kontenera. Są one podobne do wskaźników, 
ale są bardziej abstrakcyjne i mogą być używane z różnymi rodzajami kontenerów.

Iteratory w STL można podzielić na pięć typów, zależnie od funkcjonalności:

1. Iterator Input: Może być używany do odczytu i przesuwania do przodu. 
Przykłady: strumienie wejściowe.

2. Iterator Output: Może być używany do zapisu i przesuwania do przodu. 
Przykłady: strumienie wyjściowe.

3. Iterator Forward: Może być używany do odczytu, zapisu, porównania i przesuwania do przodu. 
Przykłady: slist.

4. Iterator Bidirectional: Może być używany do odczytu, zapisu, porównania, przesuwania do przodu i do tyłu. 
Przykłady: list, set, multiset, map, multimap.

5. Iterator Random Access: Może być używany do odczytu, zapisu, porównania, przesuwania do przodu i do tyłu, 
a także skoków do dowolnego elementu. 
Przykłady: vector, deque, array, string.

// Obiekt jakiegos kontenera sekwencyjnego, ktory za pomoca odpowiedniego algorytmu STL doda do
// kazej wartosci, wartosc ostaniego elementu

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    if(!vec.empty()) {
        int last_element = vec.back();
        std::transform(vec.begin(), vec.end(), vec.begin(), [last_element](int x) { return x + last_element; });
    }

    for (int i : vec) {
        std::cout << i << ' ';
    }
    return 0;
}


//6. Po co nam szablony?
1. Generowanie kodu dla różnych typów danych: 
Szablony w C++ umożliwiają programistom tworzenie funkcji lub klas, które mogą obsługiwać różne typy danych bez powtarzania kodu. 
Na przykład, można utworzyć szablon funkcji, który porównuje dwie wartości - niezależnie od tego, czy są to liczby, znaki czy inne typy.

2. Wzrost wydajności: 
Szablony są przetwarzane podczas kompilacji, co sprawia, że są efektywne. 
Generowany kod jest zazwyczaj tak samo wydajny, jakbyśmy napisali funkcje lub klasy specyficzne dla danego typu danych.

3. Promowanie ponownego użycia kodu: 
Dzięki szablonom, można pisać kod, który jest łatwy do ponownego użycia i obsługi różnych typów danych. 
W rezultacie, zasada DRY (Don t Repeat Yourself) jest przestrzegana, co prowadzi do bardziej przejrzystego i zrozumiałego kodu.

4. Wsparcie dla programowania generycznego: 
Szablony są podstawą programowania generycznego w C++, które skupia się na tworzeniu kodu, który można łatwo dostosować do różnych typów danych lub operacji. 
Jest to szczególnie przydatne w kontekście kontenerów danych, takich jak listy, stosy, kolejki, drzewa, itp., które mogą być wykorzystane z dowolnym typem danych.

5. Abstrakcja typów danych: 
Szablony pozwalają na abstrakcję typów danych, co jest kluczowym elementem tworzenia bezpiecznego i łatwego do utrzymania kodu.

// Napisać program, w którym używamy specjalizacji klasy szablonowej.

template <typename T>
class MyContainer {
public:
    MyContainer(T val) : value(val) {}

    T increase() {
        return ++value;
    }

private:
    T value;
};

// Specjalizacja szablonu klasy dla typu int
template <>
class MyContainer<int> {
public:
    MyContainer(int val) : value(val) {}

    int increase() {
        return value += 10;
    }

private:
    int value;
};

int main() {
    MyContainer<double> myDouble(10.0);
    MyContainer<int> myInt(10);

    // Dla typu double, funkcja increase() zwiększa wartość o 1
    std::cout << "Double: " << myDouble.increase() << std::endl;  // Output: 11

    // Dla typu int, specjalizacja sprawia, że funkcja increase() zwiększa wartość o 10
    std::cout << "Int: " << myInt.increase() << std::endl;  // Output: 20

    return 0;
}

//7. Dziedziczenie->rodzaje(publiczne, chornione, prywatne, wielokrotne wirtualne)

1. Publiczne dziedziczenie (public): 
Jest to najczęściej używany rodzaj dziedziczenia. W publicznym dziedziczeniu publiczne i chronione członkowie klasy bazowej stają się odpowiednio publicznymi i chronionymi członkami klasy pochodnej. 

class Base {
public:
    int publicMember;
protected:
    int protectedMember;
};

class Derived : public Base {
// teraz publicMember jest dostępny jako publiczny członek Derived
// a protectedMember jako chroniony członek Derived
};

2. Chronione dziedziczenie (protected): 
W chronionym dziedziczeniu, publiczne i chronione członkowie klasy bazowej stają się chronionymi członkami klasy pochodnej.

class Base {
public:
    int publicMember;
protected:
    int protectedMember;
};

class Derived : protected Base {
// teraz publicMember i protectedMember są chronionymi członkami Derived
};

3. Prywatne dziedziczenie (private): 
W prywatnym dziedziczeniu, publiczne i chronione członkowie klasy bazowej stają się prywatnymi członkami klasy pochodnej.

class Base {
public:
    int publicMember;
protected:
    int protectedMember;
};

class Derived : private Base {
// teraz publicMember i protectedMember są prywatnymi członkami Derived
};

4. Wielokrotne dziedziczenie: 
Wielokrotne dziedziczenie pozwala na dziedziczenie po więcej niż jednej klasie bazowej.

class Base1 {
    // ...
};

class Base2 {
    // ...
};

class Derived : public Base1, public Base2 {
// Derived dziedziczy po Base1 i Base2
};

5. Wirtualne dziedziczenie: 
Jest to mechanizm, który pozwala na uniknięcie problemu diamentu (dwa egzemplarze jednej klasy w klasie pochodnej na skutek wielokrotnego dziedziczenia) poprzez tworzenie jednego wspólnego obiektu klasy bazowej dla klas pochodnych.

class Base {
    // ...
};

class Derived1 : virtual public Base {
    // ...
};

class Derived2 : virtual public Base {
    // ...
};

class MostDerived : public Derived1, public Derived2 {
// MostDerived dziedziczy po Derived1 i Derived2, ale dzięki wirtualnemu dziedziczeniu
// istnieje tylko jedna kopia Base
};


//8. Wczesne i pozne wiazanie - opis z przykladami

Wiązanie wczesne (Early Binding)
Wiązanie wczesne, czasami nazywane również wiązaniem statycznym, zachodzi w momencie kompilacji kodu. W tym przypadku kompilator decyduje, którą konkretną metodę lub funkcję wywołać, na podstawie deklaracji typu obiektu. Zazwyczaj szybsze i mniej podatne na błędy, ponieważ wszystkie decyzje są podejmowane podczas kompilacji.

#include<iostream>
using namespace std;

class KlasaA {
public:
   void funkcja() {
       cout << "Wywołanie metody z KlasyA" << endl;
   }
};

int main() {
    KlasaA obj;
    obj.funkcja();  // Wiązanie wczesne
    return 0;
}

Wiązanie późne (Late Binding)
Wiązanie późne, znane również jako wiązanie dynamiczne, odbywa się w czasie wykonywania programu. 
W przypadku wiązania późnego, decyzja o tym, którą metodę lub funkcję wywołać, jest podejmowana na podstawie rzeczywistego typu obiektu, a nie typu zadeklarowanego.
Wiązanie późne jest kluczowe dla takich funkcji programowania obiektowego jak dziedziczenie i polimorfizm. Pozwala to na większą elastyczność, ale jest nieco wolniejsze i może prowadzić do błędów, które są trudne do wykrycia podczas kompilacji.

#include<iostream>
using namespace std;

class KlasaA {
public:
    virtual void funkcja() {
        cout << "Wywołanie metody z KlasyA" << endl;
    }
};

class KlasaB: public KlasaA {
public:
    void funkcja() override {
        cout << "Wywołanie metody z KlasyB" << endl;
    }
};

int main() {
    KlasaA* obj = new KlasaB();
    obj->funkcja();  // Wiązanie późne
    delete obj;
    return 0;
}


//9. Po co, interfejs, rodzaje, charakterystyka, przyklad kodu z uzyciem jakiegos
1. Abstrakcja i enkapsulacja: Interfejsy pozwalają ukryć szczegóły implementacji, skupiając się tylko na wymaganych operacjach.
2. Polimorfizm: Interfejsy umożliwiają używanie różnych obiektów, które implementują ten sam interfejs, co sprawia, że kod staje się bardziej elastyczny.
3. Współpraca między modułami: Interfejsy ułatwiają komunikację i wymianę danych między różnymi częściami programu.
4. Testowanie i debugowanie: Interfejsy ułatwiają testowanie i debugowanie kodu, a także umożliwiają tworzenie mocków dla testów jednostkowych.
5. Rozszerzalność: Interfejsy umożliwiają dodawanie nowych funkcjonalności do istniejącego kodu bez modyfikacji istniejących komponentów.

Rodzaje interfejsów w C++:
- Interfejsy klas: Klasy w C++ mogą definiować publiczne metody jako interfejsy, które są dostępne dla innych części programu. Interfejsy klas określają, jakie metody można wywoływać na obiekcie danej klasy.
- Interfejsy struktur: Struktury w C++ mogą również posiadać interfejsy, które są definiowane przez publiczne metody. Interfejsy struktur działają podobnie jak interfejsy klas, ale mogą być używane, gdy nie potrzebujemy pełnej funkcjonalności klas.

// Definicja interfejsu
class IShape {
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

// Implementacja interfejsu przez klasę Circle
class Circle : public IShape {
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * 3.14159 * radius;
    }
};

// Implementacja interfejsu przez klasę Rectangle
class Rectangle : public IShape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }
};

// Użycie interfejsu w kodzie
#include <iostream>

void printShapeInfo(const IShape& shape) {
    std::cout << "Area: " << shape.getArea() << std::endl;
    std::cout << "Perimeter: " << shape.getPerimeter() << std::endl;
}

int main() {
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    printShapeInfo(circle);
    printShapeInfo(rectangle);

    return 0;
}

//10. Co to są wyjątki? Co czego służą? Co dzieje się kiedy wyjątek zostanie wyrzucony - bardzo wnikliwie?

Wyjątki są mechanizmem w języku programowania C++, który umożliwia wykrycie i obsługę błędów oraz nietypowych sytuacji w trakcie wykonywania programu. Głównym celem wyjątków jest umożliwienie programiście reagowania na te sytuacje i podjęcia odpowiednich działań, takich jak naprawa błędów, obsługa wyjątkowych warunków, czy zamknięcie zasobów.

Kiedy wyjątek zostaje "wyrzucony" (czyli rzucony), oznacza to, że program napotkał na pewną nietypową sytuację, która uniemożliwia kontynuowanie normalnego przepływu sterowania. Może to być spowodowane błędem logicznym, problemem zewnętrznym (np. brakujące pliki) lub innymi czynnikami.

Kiedy wyjątek zostaje rzucony, program przerywa bieżący blok instrukcji i rozpoczyna proces szukania obsługi tego wyjątku. W przypadku, gdy odpowiedni blok obsługi zostanie znaleziony, program przechodzi do tej części kodu i wykonuje określone w niej działania. Jeśli nie zostanie znaleziona żadna obsługa wyjątku, program zatrzymuje się, a nieobsłużony wyjątek powoduje zakończenie programu i może być zgłoszony użytkownikowi jako błąd.

Obsługa wyjątków w C++ odbywa się za pomocą bloków try-catch. Kod, który może rzucić wyjątek, jest umieszczany w bloku try, a następnie w bloku catch można zdefiniować obsługę konkretnych typów wyjątków. Jeśli wyjątek zostanie rzucony w bloku try, program będzie przeszukiwał kolejne bloki catch w poszukiwaniu obsługi. Jeśli odpowiedni blok catch zostanie znaleziony, zostanie wykonany, a program kontynuuje wykonanie po bloku catch.

Ogólnie rzecz biorąc, wyjątki pozwalają na kontrolowanie przepływu programu w sytuacjach wyjątkowych, umożliwiając programiście reagowanie na błędy i nietypowe warunki. W praktyce mogą być używane do obsługi błędów I/O, zarządzania pamięcią, komunikacji sieciowej i wielu innych sytuacji, w których wystąpienie błędu lub wyjątkowej sytuacji jest możliwe.

//Hierarchia wyrzucania. Specjalizacje. Omówić wyjątki w iostream.
W C++ hierarchia wyrzucania wyjątków odbywa się na podstawie relacji dziedziczenia pomiędzy typami wyjątków. Hierarchia ta pozwala na bardziej precyzyjne przechwytywanie i obsługę wyjątków, zaczynając od najbardziej szczegółowych typów, a kończąc na bardziej ogólnych.

W kontekście strumieni (iostream) w C++, hierarchia wyrzucania wyjątków jest dobrze zdefiniowana. Główne typy wyjątków związanych ze strumieniami to std::ios_base::failure oraz jej pochodne. 

Przykład użycia hierarchii wyrzucania wyjątków dla strumieni w C++:
#include <iostream>
#include <fstream>

int main() {
  try {
    std::ifstream file("nonexistent.txt");
    if (!file) {
      throw std::ios_base::failure("Failed to open file.");
    }
    // Operacje na pliku...
  } catch (const std::ios_base::failure& ex) {
    std::cout << "Exception caught: " << ex.what() << std::endl;
  }
  return 0;
}


// 11. Napisać przykład programu, w którym zademonstrujemy działanie mutable oraz const_cast (sytuacja,
// gdy jest on niezbędny).
#include <iostream>

class MyClass {
public:
    MyClass(int value) : m_value(value) {}

    // Metoda const, która modyfikuje mutable składową
    int getValue() const {
        // Używamy const_cast, aby usunąć const z mutable składowej
        // i umożliwić jej modyfikację w metodzie const
        return const_cast<int&>(m_mutableValue) += m_value;
    }

private:
    int m_value;
    mutable int m_mutableValue = 0;
};

int main() {
    const MyClass obj(5);

    std::cout << "Wartość: " << obj.getValue() << std::endl;

    return 0;
}
W powyższym programie definiujemy klasę MyClass, która ma dwie składowe: m_value i m_mutableValue. m_value jest zwykłą składową, natomiast m_mutableValue jest oznaczona jako mutable, co oznacza, że można ją modyfikować nawet w metodach const obiektu.

W metodzie getValue(), oznaczonej jako const, korzystamy z const_cast, aby usunąć const z m_mutableValue i umożliwić jej modyfikację. Następnie dodajemy wartość m_value do m_mutableValue i zwracamy wynik.

W funkcji main() tworzymy obiekt obj klasy MyClass o wartości 5. Następnie wywołujemy metodę getValue() na tym obiekcie i wyświetlamy wynik na ekranie.

Dzięki użyciu mutable i const_cast możemy modyfikować składową, która normalnie jest niedostępna w metodzie const, ale jest oznaczona jako mutable.

// Napisać program kopiujacy jeden plik do drugiego za pomoca iteratorow strumieniowych, tak zeby
// zmienial litery male na duze.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (inputFile.is_open() && outputFile.is_open()) {
        // Iterator strumienia wejściowego
        std::transform(std::istreambuf_iterator<char>(inputFile),
                       std::istreambuf_iterator<char>(),
                       std::ostreambuf_iterator<char>(outputFile),
                       [](char c) { return std::toupper(c); }); // Zamiana litery na dużą

        std::cout << "Kopiowanie zakończone." << std::endl;
    } else {
        std::cout << "Nie można otworzyć plików." << std::endl;
    }

    return 0;
}
W powyższym programie używamy strumienia std::ifstream do odczytu pliku wejściowego i strumienia std::ofstream do zapisu pliku wyjściowego. Wykorzystujemy iterator strumienia wejściowego std::istreambuf_iterator<char>(inputFile) oraz iterator strumienia wyjściowego std::ostreambuf_iterator<char>(outputFile). Następnie używamy funkcji std::transform, aby zamienić litery małe na duże za pomocą lambdy [](char c) { return std::toupper(c); }. Zmieniona zawartość jest zapisywana do pliku wyjściowego.