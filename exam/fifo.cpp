#include <deque>
#include <typeinfo>
#include <iostream>

template <class T = int, template <class P = T, class Alloc = std::allocator<T>>
                         class U = std::deque> // template ma przyjmować, typ (T) i kontener (U<T, Alloc>). wiemy z treści ze kontenerem jest deque, więc odtwarzamy jego argumenty szablonowe czyli P - typ i allocator, który też jest template’em dla typu P ktory ma byc T. Dopiero jak argumenty szablonowe kontenera pokryja sie z deklaracja deque można go przypisać jako parametr domyślny, inaczej rzuci jakimś invalid use of std::deque.

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

    typedef U<T> storage_type; // tworzy typ strage_type

    typename storage_type::const_iterator begin() // ktos cos? po co ten typename
    {                                             // w sensie czemu bez niego nie kompiluje?
                                                  // poniewaz kompilator nie wie czy sie odwolujemy do zmiennej statycznej czy typu, a typeamem mu mowimy ze odwolujemy sie do typu
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
// Wynik : fifo<T, StorageType>::fifo()[with T = int, StorageType = std::deque] 0 4 1, 2, 3, 4,
