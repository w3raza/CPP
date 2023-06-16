#include <iostream>
#include <string>

class Number
{
public:
    explicit Number(int n = 0) : _n(n)
    {
    }
    int Get() const
    {
        return _n;
    }

    void print() const
    {
        std::cout << _n << std::endl;
    }

private:
    int _n;
};

/////////////////////////////////////////////////////////////////////////
class Frac
{
public:
    friend Frac multi(const Frac &a, const Frac &b);

    Frac(int l = 0, int m = 1) : _l(l), _m(m)
    {
    }

    Frac(int l) : _l(l), _m(1)
    {
        std::cout << "Dziala konstruktor konwertujacy (int)." << std::endl;
    }

    explicit Frac(Number n) : _l(n.Get()), _m(1)
    {
        std::cout << "Dziala konstruktor konwertujacy Frac(Number)." << std::endl;
    }

    //funkcja konwertująca do double
    explicit operator double() const
    {
        std::cout << "Dziala funkcja konwertujaca do double." << std::endl;
        return (double)_l / (double)_m;
    }

    //funkcja konwertująca do Number
    explicit operator Number() const
    {
        std::cout << "Dziala funkcja konwertujaca do Number." << std::endl;
        return Number((int)((double)_l / (double)_m + 0.5));
    }

    void print() const
    {
        std::cout << _l << "/" << _m << std::endl;
    }

private:
    int _l;
    int _m;
};

/////////////////////////////////////////////////////////////////////////
Frac multi(const Frac &a, const Frac &b)
{
    Frac tmp;
    tmp._l = a._l * b._l;
    tmp._m = a._m * b._m;
    return tmp;
}

/////////////////////////////////////////////////////////////////////////
int sum(const Number &a, const Number &b)
{
    return a.Get() + b.Get();
}

/////////////////////////////////////////////////////////////////////////
int main()
{
    using namespace std;

    Frac aFraction{4, 3};
    Number aNumber{1};

    //wykorzystujemy funkcje konwertującą przy wywołaniu funkcji której argumentami są dwa obiekty typu Number
    cout << "  --- Suma: "
         << sum(aNumber, (Number)(aFraction)) << endl;
    cout << "  --- Multi: "
         << (double)(multi(aFraction, (Frac)(aNumber))) << endl;
}

// #include <iostream>
// #include <string>

// class Number
// {
// public:
//     Number(int n = 0) : _n(n)
//     {
//     }
//     int Get() const
//     {
//         return _n;
//     }

//     void print() const
//     {
//         std::cout << _n << std::endl;
//     }

// private:
//     int _n;
// };

// /////////////////////////////////////////////////////////////////////////
// class Frac
// {
// public:
//     friend Frac multi(const Frac &a, const Frac &b);

//     Frac(int l = 0, int m = 1) : _l(l), _m(m)
//     {
//     }

//     Frac(int l) : _l(l), _m(1)
//     {
//         std::cout << "\nDziala konstruktor konwertujacy (int)." << std::endl;
//     }

//     Frac(const Number &n) : _l(n.Get()), _m(1)
//     {
//         std::cout << "\nDziala konstruktor konwertujacy (Number)." << std::endl;
//     }

//     //funkcja konwertująca do double
//     operator double() const
//     {
//         std::cout << "\nDziala funkcja konwertujaca do double." << std::endl;
//         return (double)_l / (double)_m;
//     }

//     //funkcja konwertująca do Number
//     operator Number() const
//     {
//         std::cout << "\nDziala funkcja konwertujaca do Number." << std::endl;
//         return Number((int)((double)_l / (double)_m + 0.5));
//     }

//     void print() const
//     {
//         std::cout << _l << "/" << _m << std::endl;
//     }

// private:
//     int _l;
//     int _m;
// };

// /////////////////////////////////////////////////////////////////////////
// Frac multi(const Frac &a, const Frac &b)
// {
//     Frac tmp;
//     tmp._l = a._l * b._l;
//     tmp._m = a._m * b._m;
//     return tmp;
// }

// /////////////////////////////////////////////////////////////////////////
// int sum(const Number &a, const Number &b)
// {
//     return a.Get() + b.Get();
// }

// /////////////////////////////////////////////////////////////////////////
// int main()
// {
//     using namespace std;

//     Frac aFraction(4, 3);
//     Number aNumber(1);

//     //wykorzystujemy funkcje konwertującą przy wywołaniu funkcji której argumentami są dwa obiekty typu Number
//     cout << sum(aNumber, aFraction) << endl;
//     cout << multi(aFraction, aNumber) << endl;
// }
// #include <iostream>
// #include <string>

// class Frac
// {
// public:
//     friend Frac multi(const Frac &a, const Frac &b);

//     Frac(int l = 0, int m = 1) : _l(l), _m(m) {}

//     //konstruktor służący jako konwerter z liczby typu int
//     Frac(int l) : _l(l), _m(1)
//     {
//         std::cout << "\nDziala konstruktor konwertujacy (int)." << std::endl;
//     }

//     //funkcja konwertująca do double
//     operator double() const
//     {
//         std::cout << "\nDziala funkcja konwertujaca do double." << std::endl;
//         return (double)_l / (double)_m;
//     }

//     void print() const
//     {
//         std::cout << _l << "/" << _m << std::endl;
//     }

// private:
//     int _l;
//     int _m;
// };
// /////////////////////////////////////////////////////////////////////////
// Frac multi(const Frac &a, const Frac &b)
// {
//     Frac tmp;
//     tmp._l = a._l * b._l;
//     tmp._m = a._m * b._m;
//     return tmp;
// }
// /////////////////////////////////////////////////////////////////////////
// double sum(double a, double b)
// {
//     return a + b;
// }
// /////////////////////////////////////////////////////////////////////////
// int main()
// {
//     using namespace std;

//     Frac aFraction(1, 2);

//     //wykorzystujemy funkcje konwertującą przy wywołaniu funkcji której argumentami są dwie liczby typu double
//     cout << sum(1.0, aFraction) << endl;

//     cout << 1 - aFraction << endl;
// }
