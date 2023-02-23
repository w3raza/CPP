
//
// To jest przyk�adowy kod z podrozdzia�u 10.4 �Otwieranie pliku� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <fstream>
#include <string>
#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

struct Point
{
    int x;
    int y;

    friend istream& operator>>(istream& ist, Point& p)
    {
        char a,b,c;

        if ((ist >> a >> p.x >> b >> p.y >> c) && !(a == '(' && b == ',' && c == ')'))
            throw runtime_error("Nieprawid�owy format");

        return ist;
    }

    friend ostream& operator<<(ostream& ost, const Point& p)
    {
        return ost << '(' << p.x << ',' << p.y << ')' << endl;
    }
};

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Podaj nazw� pliku wej�ciowego: ";
    string name;
    cin >> name;
    ifstream ist(name.c_str());    // ist jest strumieniem wej�ciowym dla pliku o nazwie name.
    if (!ist) error("Nie mo�na otworzy� pliku wej�ciowego ",name);

    vector<Point> points;
    Point p;
    while (ist>>p) points.push_back(p);
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
