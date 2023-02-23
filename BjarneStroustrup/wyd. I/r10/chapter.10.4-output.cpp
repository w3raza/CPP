
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
    cout << "Podaj nazwê pliku wyjœciowego: ";
    string name;
    cin >> name;
    ofstream ost(name.c_str());    // ost jest strumieniem wyjœciowym dla pliku o nazwie oname.
    if (!ost) error("Nie mo¿na otworzyæ pliku wyjœciowego. ",name);

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
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
};

//------------------------------------------------------------------------------

void fill_from_file(vector<Point>& points, string& name)
{
    ifstream ist(name.c_str());    // Otwiera plik do odczytu.
    if (!ist) error("Nie mo¿na otworzyæ pliku wejœciowego ",name);
    // … u¿ycie ist …
    // Plik zostanie automatycznie zamkniêty po zakoñczeniu funkcji.
}

//------------------------------------------------------------------------------
