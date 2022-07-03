
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
    cout << "Podaj nazw� pliku wyj�ciowego: ";
    string name;
    cin >> name;
    ofstream ost(name.c_str());    // ost jest strumieniem wyj�ciowym dla pliku o nazwie oname.
    if (!ost) error("Nie mo�na otworzy� pliku wyj�ciowego. ",name);

    vector<Point> points;

    for (int i = 0; i < 10; ++i)
    {
        Point p = {i, i*i};
        points.push_back(p);
    }

    for (int i=0; i<points.size(); ++i)
        ost << '(' << points[i].x << ',' << points[i].y << ")\n";
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
};

//------------------------------------------------------------------------------

void fill_from_file(vector<Point>& points, string& name)
{
    ifstream ist(name.c_str());    // Otwiera plik do odczytu.
    if (!ist) error("Nie mo�na otworzy� pliku wej�ciowego ",name);
    // � u�ycie ist �
    // Plik zostanie automatycznie zamkni�ty po zako�czeniu funkcji.
}

//------------------------------------------------------------------------------
