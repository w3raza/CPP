#include <deque>
#include <iostream>

// template ma przyjmować, typ (T) i kontener (U<T, Alloc>). wiemy z treści ze kontenerem jest deque, więc odtwarzamy jego argumenty szablonowe czyli P - typ i allocator, który też jest template’em dla typu P ktory ma byc T. 
// Dopiero jak argumenty szablonowe kontenera pokryja sie z deklaracja deque można go przypisać jako parametr domyślny, inaczej rzuci jakimś invalid use of std::deque.
template <class T = int, template <class P = T, class Alloc = std::allocator<T>>
                         class U = std::deque> 
class fifo
{
public:
    void push(T &in) { m_Container.push_back(in); } // wrzuca kolejny elemnet na koniec

    fifo() // glośny konaltruktor
    {
        std::cout << __PRETTY_FUNCTION__ << " ";
    }

    T get() // zwraca pierwszy element (first in -> first out)
    {
        T tmp = m_Container.front(); // przypisuje wartosc
        m_Container.pop_front();     // usuwa pierwszy element
        return tmp;                  // zwraca wartosc usunietego elementu
    }

    typedef U<T> storage_type; // tworzy typ strage_type using storage_type = u<T>

    //W C++, słowo kluczowe typename wskazuje, że dany symbol powinien być traktowany jako typ
    // W kontekście naszego kodu, typename jest używane w metodach begin() i end(), aby poinformować kompilator, że storage_type::const_iterator jest typem. 
    // Słowo kluczowe typename jest wymagane, ponieważ kompilator C++ musi wiedzieć, czy odwolujemy do zmiennej statycznej czy typu
    typename storage_type::const_iterator begin() 
    {                                             
        return m_Container.begin();
    }
    typename storage_type::const_iterator end() { return m_Container.end(); }
    int size()
    {
        std::cout << " ";
        return m_Container.size();
    }

private:
    U<T> m_Container;
};

int main()
{
    fifo<> ft;
    for (int i : {0, 1, 2, 3, 4})
        ft.push(i);

    fifo<int, std::deque> f = ft;

    std::cout << f.get();
    std::cout << f.size();

    for (fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
        std::cout << *i << ",";
}
// Wynik : fifo<T, StorageType>::fifo()[with T = int, StorageType = std::deque] 0 41, 2, 3, 4,

//#include <deque>
// #include <iostream>

// // Deklaracja klasy fifo
// template <typename T = int, typename StorageType = std::deque<T>>
// class fifo
// {
// public:
//     typedef StorageType storage_type;

//     // konstruktor domyślny
//     fifo() { std::cout << "fifo<T, StorageType>::fifo()[with T = int, StorageType = std::deque]" << std::endl; }

//     // konstruktor kopiujący fifo<int, std::deque> f = ft; 
       // W C++ domyślny konstruktor kopiujący wykonuje kopiowanie "płytkie" (shallow copy)
       // Domyślny konstruktor kopiujący wystarczz, ponieważ std::deque (czy inna kolekcja wykorzystywana jako StorageType) już prawidłowo obsługuje kopiowanie.
////     fifo(const fifo &other) : data(other.data) {}

//     // dodanie elementu do kolejki
//     void push(const T &value) { data.push_back(value); }

//     // usunięcie i zwrócenie pierwszego elementu z kolejki
//     T get()
//     {
//         T value = data.front();
//         data.pop_front();
//         return value;
//     }

//     // zwraca rozmiar kolejki
//     size_t size() const { return data.size(); }

//     // zwraca iterator do pierwszego elementu
//     typename storage_type::const_iterator begin() const { return data.begin(); }

//     // zwraca iterator za ostatnim elementem
//     typename storage_type::const_iterator end() const { return data.end(); }

// private:
//     storage_type data;
// };

// int main()
// {
//     fifo<> ft;
//     for (int i : {0, 1, 2, 3, 4})
//         ft.push(i);

//     fifo<int, std::deque> f = ft;

//     std::cout << f.get();
//     std::cout << f.size();

//     for (fifo<>::storage_type::const_iterator i = f.begin(); i != f.end(); ++i)
//         std::cout << *i << ",";
// }
