#include <iostream> // std::cout

namespace OOP
{
    template <class T>
    class Array
    {
    private:
        T *_ptr;
        int _max_size;
        int _size = 0;

    public:
        Array(T max_size) : _max_size(max_size), _ptr(new T[max_size]) {}
        ~Array() { delete[] _ptr; }

        using value_type = T;

        Array &insert(const T &added)
        {
            _ptr[_size++] = added;
            return *this;
        }

        Array &operator%(const T &added)
        {
            return insert(added);
        }

        T& operator[](int size)
        {
            return _ptr[size];
        }

        int &operator~()
        {
            return _size;
        }
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