#include <iostream> // cout
                    //#include <cstdlib> // rand (nevermind działa i bez tego)

namespace OOP
{ // tworzymy namespace bo potem wyciągamy z niego ten szablon
    template <typename T>
    class Array
    {
        unsigned _size = 0, _max_size;
        T *_t;

    public: // ups zapomniałem tego :(
        Array(int max_size) : _max_size(max_size), _t(new T[max_size]) {}
        ~Array() { delete[] _t; } // nie wiem czy wymagał
        Array &insert(const T &added)
        {
            _t[_size++] = added;
            return *this;
        }                                                          // Musi być const, nie musi być referencja. dlaczego? tylko bóg wie
        Array &operator%(const T &added) { return insert(added); } // jak wyżej
        int operator~() { return _size; }
        T &operator[](int index) { return _t[index]; }
        using value_type = T; // żeby działało type::value_type. można też zrobić funkcję statyczną
    };
}

int main()
{
    typedef ::OOP::Array<int> type;
    type a(rand() % 100 + 10); // nie trzeba seedować żeby program się wykonał

    a.insert('#' - 1).insert('P') % type::value_type('O') % ('-') % ('E') % ('G') % ('Z') % ('1');

    ++a[0];
    for (unsigned i = 0; i != ~a; i++)
    {
        std::cout << static_cast<char>(a[i]) << (i + 1 != ~a ? '_' : '\n');
    }
}
//#_P_O_-_E_G_Z_1