// #include <iostream>
// #include <string>

// class Point
// {
// public:
//     Point() : _x(0.0), _y(0.0), _Opis("")
//     {
//     }

//     Point(double x, double y, std::string Opis = "") : _x(x), _y(y), _Opis(Opis), _cxx_11{1010}
//     {
//     }

//     void print() const;

// private:
//     double _x;
//     double _y;
//     std::string _Opis;

//     int _cxx_11; //wg std c++11
// };
// /////////////////////////////////////////////////////////////////////////
// void Point::print() const
// {
//     if (_Opis.length() > 0)
//         std::cout << _Opis << "(x, y) = " << _x << ", " << _y << ", " << _cxx_11 << std::endl;
//     else
//         std::cout << "<bez_nazwy> "
//                   << "(x, y) = " << _x << ", " << _y << ", " << _cxx_11 << std::endl;
// }
// /////////////////////////////////////////////////////////////////////////

// int main()
// {
//     Point aPoint;
//     Point bPoint(1, 1, "bPoint");
//     Point cPoint = Point(2, 2, "cPoint");
//     Point dPoint(3, 3);

//     aPoint.print();
//     bPoint.print();
//     cPoint.print();
//     dPoint.print();
// }

#include <iostream>
#include <string>

using namespace std;

class Point
{
public:
    Point() : m_x(0.0), m_y(0.0), m_Opis("")
    {
        cout << "Konstruktor domniemany Point(" << m_Opis << ").\n";
    }

    Point(double x, double y, const string &Opis = "") : m_x(x), m_y(y), m_Opis(Opis)
    {
        cout << "Konstruktor Point(" << m_Opis << ").\n";
    }

    Point(Point &K)
    {
        m_Opis = K.m_Opis;
        m_x = K.m_x;
        m_y = K.m_y;
        cout << "Konstruktor kopiujący Point(" << K.m_Opis << ").\n";
    }

    ~Point()
    {
        cout << "Destruktor Point(" << m_Opis << ").\n";
    }

    void print();
    void SetOpis(string Opis)
    {
        m_Opis = Opis;
    }

private:
    double m_x;
    double m_y;
    string m_Opis;
};
/////////////////////////////////////////////////////////////////////////
void Point::print()
{
    if (m_Opis.length() > 0)
        cout << m_Opis << "(x, y) = " << m_x << ", " << m_y << endl;
    else
        cout << "<bez_nazwy> "
             << "(x, y) = " << m_x << ", " << m_y << endl;
}
/////////////////////////////////////////////////////////////////////////
int main()
{
    cout << "----------- Start ----------------\n";

    Point aPoint(1, 1, "pierwszy");
    Point bPoint = aPoint; //dzia³a konstruktor kopiuj¹cy, a nie operator =
    // Point bPoint(aPoint);

    Point cPoint;
    cPoint = bPoint;

    aPoint.print();
    bPoint.print();
    cPoint.print();

    bPoint.SetOpis("drugi");
    cPoint.SetOpis("trzeci");
}