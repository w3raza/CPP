
//
// To jest przyk³adowy kod z podrozdzia³u 10.4 „Otwieranie pliku” ksi¹¿ki 
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
            throw runtime_error("Nieprawid³owy format");

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
    cout << "Podaj nazwê pliku wejœciowego: ";
    string name;
    cin >> name;
    ifstream ist(name.c_str());    // ist jest strumieniem wejœciowym dla pliku o nazwie name.
    if (!ist) error("Nie mo¿na otworzyæ pliku wejœciowego ",name);

    vector<Point> points;
    Point p;
    while (ist>>p) points.push_back(p);
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
