
//
// To jest przyk�adowy kod z podrozdzia�u 9.4.6 �Raportowanie b��d�w� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

// Prosta klasa Date (uniemo�liwia tworzenie obiekt�w o nieprawid�owym stanie).
class Date {
public:
    class Invalid { };         // B�dzie s�u�y� jako typ wyj�tku.
    Date(int y, int m, int d); // Sprawdza poprawno�� daty i wykonuje inicjacj�.
    int month() { return m; }
    int day()   { return d; }
    int year()  { return y; }
    void add_day(int n) { /*...*/ }

private:
    int y, m, d;               // Rok, miesi�c, dzie�
    bool check();              // Zwraca true, je�li data jest poprawna.
};

//------------------------------------------------------------------------------

Date::Date(int yy, int mm, int dd)
: y(yy), m(mm), d(dd)              // Inicjacja danych sk�adowych.
{
    if (!check()) throw Invalid(); // Sprawdzanie poprawno�ci.
}

//------------------------------------------------------------------------------

bool Date::check()  // Zwraca true, je�li data jest poprawna.
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
    cout << dxy << '\n';       // Deklaracja operatora << znajduje si� w podrozdziale 9.8.
    dxy.add_day(2);
}
catch(Date::Invalid) {
    error("Nieprawid�owa data");
}

//------------------------------------------------------------------------------

int main()
try
{
    f(8,29);
    f(15,29);                  // B��d czasu wykonywania: nieprawid�owa data.
    return 0;
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
