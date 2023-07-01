#include <iostream>
#include <list>

// Używamy szablonu, ponieważ chcemy umożliwić operacje na różnych typach kolekcji (np. list, vector).
/*
*Jeżeli chodzi o F fun, to w kontekście tego kodu mogłoby to być const F& fun, ponieważ funkcja fun jest tylko wywoływana, ale nie jest modyfikowana. Ale zazwyczaj funktory i funkcje przekazuje się przez wartość, nie przez referencję, szczególnie gdy są małe i lekkie.
*/
template <typename T, typename F>
void print_to_if(std::ostream &o, T b, T e, F fun)
{
    for(; b != e; b++) //for(auto el = b; el != e; ++el){
    {
        // Wywołujemy funkcję 'fun' na elemencie. Funkcję 'fun' przekazujemy jako argument, co pozwala na różne operacje na elementach.
        if(fun(*b))
        {
            // Jeżeli funkcja 'fun' zwraca prawdę, wypisujemy element.
            o << *b << ", ";
        }
    }
    o << "\n";
}

/*
* Iteratory są specjalnymi obiektami w C++, które działają jak wskaźniki do elementów w kolekcji. Kiedy przekazujesz iterator przez wartość, tworzysz kopię iteratora, ale ta kopia nadal wskazuje na ten sam element w kolekcji. Zatem, modyfikując *b (wartość, na którą wskazuje iterator), modyfikujesz rzeczywisty element w kolekcji, a nie jego kopię.
*/
template <typename T, typename F>
void change(T b, T e, F fun)
{
    for(; b != e; b++) //for(auto el = b; el != e; ++el)
    {
        // Wywołujemy funkcję 'fun' na każdym elemencie. Tutaj funkcja 'fun' zmienia elementy.
        fun(*b);
    }
}

// Definiujemy te funkcje, ponieważ używamy ich jako argumenty w 'print_to_if'.
bool f1(int x) { return true; }
bool f2(int x) { return !(x % 2); } // Ta funkcja zwraca prawdę, jeżeli liczba jest parzysta.

// Definiujemy strukturę 'f3', ponieważ używamy jej jako funktora w funkcji 'change'.
//funkcje w C++ nie mogą przechowywać stanu, jak to robią funktory (struktury lub klasy z przeciążonym operatorem ()).
template<typename T = int>
struct f3
{
    T _value;
    // Konstruktor przyjmuje wartość, którą chcemy dodać do elementów.
    // Używamy listy inicjalizacyjnej (': _val(value)'), aby zainicjalizować '_val'.
    f3(const T& val): _value(val){}

    // Definiujemy operator(), aby umożliwić wywołanie struktury jak funkcji.
    // Operator() dodaje '_val' do 'x'.
    void operator()(T& x){
        x += _value;
    }
};

int main()
{
    const auto c1 = {1, 2, 3, 4, 5, 6, 7};
    std::list<int> c12 = {7, 6, 5, 4, 3, 2, 1};

    print_to_if(std::cout << "All: ", begin(c1), end(c1), f1);
    print_to_if(std::cout << "Even: ", begin(c1), end(c1), f2);
    int add_value{-1};
    change(begin(c12), end(c12), f3{add_value}); 

    print_to_if(std::cout << "All: ", begin(c12), end(c12), f1);
}

/*
All: 1,2,3,4,5,6,7,
Even: 2,4,6,
All: 6,5,4,3,2,1,0,
*/

// /* 
// Proszę dokończyć program tylko w podanych miejscach i zgodnie z podanymi warunkami, tak aby wyjście programi było takie jak podany na w komantarzu na końcu kodu. W rozwiązaniach proszę uywać C++ w standardzie przynajmniej C++11 lub 14, wszędzie tam gdzie jest to moliwe i uzasadnione. Prosze podać naprostszą mozliwa działającą implementację. Proszę dokładnie uzasadnić odpowiedź.
// */

// #include <iostream>
// #include <list>

// template</*U1*/>
// void print_to_if(/*U2*/){
//     /*U3*/
// }

// template</*U4*/>
// void change(/*U5*/){
//     /*U6*/
// }

// /* U7 - mogą być tylko definicję f1, f2, f3 */

// int main()
// {
//     const auto c1 = {1, 2, 3, 4, 5, 6, 7};

//     print_to_if(std::cout << "All: ", begin(c1), end(c1), f1);
//     print_to_if(std::cout << "Even: ", begin(c1), end(c1), f2);
//     int add_value{-1};
//     std::list<int> c12 = {7, 6, 5, 4, 3, 2, 1};
//     change(begin(c12), end(c12), f3{add_value});

//     print_to_if(std::cout << "All: ", begin(c12), end(c12), f1);
// }
// /*
// All: 1,2,3,4,5,6,7,
// Even: 2,4,6,
// All: 6,5,4,3,2,1,0,
// */