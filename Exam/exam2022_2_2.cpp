#include <iostream>

// Deklarujemy generyczny szablon klasy B.
template<typename T>
struct B;

// Specjalizujemy B dla typów niebędących wskaźnikami. U1 oznacza specjalizację dla typów niebędących wskaźnikami.
template<typename T>
struct B
{
    // Definiujemy typ T jako value_type dla tej klasy. U2 to deklaracja aliasu typu.
    using value_type = T;

    // Konstruktor, który inicjalizuje _v przekazaną wartością.
    B(T val) :_v{val} {}

    // Metoda zwracająca przechowywaną wartość.
    T& get() { return _v; }

private:
    // Przechowujemy wartość typu T.
    value_type _v = value_type();
};

// Specjalizujemy B dla typów będących wskaźnikami. U3 oznacza specjalizację dla typów będących wskaźnikami.
template<typename T>
struct B<T*>
{
    // Definiujemy typ T jako value_type dla tej klasy. U4 to deklaracja aliasu typu.
    using value_type = T;

    // Konstruktor, który inicjalizuje _p przekazanym wskaźnikiem.
    B(T* ptr) : _p{ptr} {}

    // Wyłączamy konstruktor kopiujący, aby uniknąć przypadkowego skopiowania i potencjalnych problemów z pamięcią.
    B(const T&) = delete;

    // Destruktor, który zwalnia dynamicznie zaalokowaną pamięć.
    ~B() { delete[] _p; }

    // Metoda zwracająca wartość przechowywaną pod wskaźnikiem.
    T& get() const { return *_p; }

private:
    // Przechowujemy wskaźnik na wartość typu T.
    value_type* _p; //U5
};

int main()
{
    // Definiujemy typy dla wygody.
    typedef B<int> int_b;
    typedef B<int*> int_p_b;    

    // Tworzymy obiekty typu B.
    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    
    // Linie poniżej są wykomentowane, ponieważ wywołują błędy. Konstruktor kopiujący jest wyłączony dla typu B<int*>.
    //int_p_b e = b; //error
    //b = b; //error
    
    // Wyświetlamy przechowywane wartości.
    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout << "b=" << b.get()+1 << std::endl;
}
/*
a=1
a_copy=2
b=3
*/

// /*
// Proszę uzupełnić program, stosując standard nie niszy ni C++14, tylko w podanych miejsach 
// i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
// komentarzu na koncu kodu. Proszę podać najprostszą moliwą poprawnie działającą 
// implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi uzycie 
// konstrukcje. Brak poprawnego uzasadnenia lub niespełnienie warunkow jest roznoznaczne z 
// brakiem odpowiedzi.
// */
// #include <iostream>

// template<typename T>
// struct B;

// template<typename T>
// struct // U1
// {
//     //U2
// private:
//     value_type _v = value_type();
// };

// template<typename T>
// struct // U3
// {
//     //U4
// private:
//     value_type //U5
// };

// int main()
// {
//     typedef B<int> int_b
//     typedef B<int> int_p_b    

//     int_b a(1);
//     int_b a_copy(a);
//     int_p_b b(new int_p_b::value_type{2});
//     // int_p_b e = b; //error
//     // b=b //error
    
//     std::cout << "a=" << a.get() << std::endl;
//     std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
//     std::cout <<" c=" << c.get()+1 << std::endl;
// }
// /*
// a=1
// a_copy=2
// b=3
// */