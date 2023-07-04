#include <cstdlib>
#include <iostream>

namespace oop
{
    template <typename T>
    struct Array
    {
        Array(T rozmiar) : _max_size(rozmiar), _t(new T[rozmiar]) {}
        using value_type = T;
        Array &insert(const T &znak)
        {
            _t[_size++] = znak;
            return *this;
        }

        Array &operator+(T &&znak)
        {
            insert(znak);
        }
        T operator~()
        {
            return _size;
        }

        T &operator[](const T &index)
        {
            return _t[index];
        }

    private:
        T *_t;
        unsigned _max_size, _size = 0;
    };
}

int main()
{
    typedef oop::Array<char> type;
    type a(rand() % 10 + 6);

    a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3);

    for (unsigned i = 0; i != ~a; ++i)
    {
        std::cout << a[i] << (i + 1 != ~a ? "" : "\n");
    }
}
/*Wyjście: #C++003 */

// // Proszę dokończyć program wg. std. C++11, tak aby działał w podany w komentarzu sposob.
// // Prosze dokładnie uzasaednić odpowiedź.

// /* Uzupełnij 1 */

// #include <cstdlib>

// int main()
// {
//     typedef oop::Array<char> type;
//     type a(rand() % 10 + 6);

//     a.insert('#').insert('C') + type::value_type('+') + '+' + '0' + ('0' + 3);

//     for (unsigned i = 0; i != ~a; ++i)
//     {
//         std::cout << a[i] << (i + 1 != ~a ? "" : "\n");
//     }
// }
// /* Wyjście: #C++003 */