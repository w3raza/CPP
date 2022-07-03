
//
// To jest przyk³adowy kod z podrozdzia³u 9.4.6 „Raportowanie b³êdów” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// Prosta klasa Date (uniemo¿liwia tworzenie obiektów o nieprawid³owym stanie).
class Date {
public:
    class Invalid { };         // Bêdzie s³u¿yæ jako typ wyj¹tku.
    Date(int y, int m, int d); // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    int month() { return m; }
    int day()   { return d; }
    int year()  { return y; }
    void add_day(int n) { /*...*/ }

private:
    int y, m, d;               // Rok, miesi¹c, dzieñ
    bool check();              // Zwraca true, jeœli data jest poprawna.
};

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd)
: y(yy), m(mm), d(dd)              // Inicjacja danych sk³adowych.
{
    if (!check()) throw Invalid(); // Sprawdzanie poprawnoœci.
}

//------------------------------------------------------------------------------

bool Date::check()  // Zwraca true, jeœli data jest poprawna.
{
    if (m<1 || 12<m) return false;
    // ...
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

//------------------------------------------------------------------------------

void error(const char* errmsg)
{
    cerr << errmsg << endl;
}

//------------------------------------------------------------------------------

void f(int x, int y)
try {
    Date dxy(2004,x,y);
    cout << dxy << '\n';       // Deklaracja operatora << znajduje siê w podrozdziale 9.8.
    dxy.add_day(2);
}
catch(Date::Invalid) {
    error("Nieprawid³owa data");
}

//------------------------------------------------------------------------------

int main()
try
{
    f(8,29);
    f(15,29);                  // B³¹d czasu wykonywania: nieprawid³owa data.
    return 0;
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
