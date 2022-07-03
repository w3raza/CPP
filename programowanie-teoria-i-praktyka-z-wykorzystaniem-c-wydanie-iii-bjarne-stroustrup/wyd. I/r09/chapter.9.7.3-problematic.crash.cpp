
//
// To jest przyk�adowy kod z podrozdzia�u 9.7.3 �Konstruktory domy�lne� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

// Prosta klasa Date (z u�yciem typu Month).
class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) // Sprawdza poprawno�� daty i wykonuje inicjacj�.
    {
        // ...
    }

private:
    int   y;                    // Rok
    Month m;
    int   d;                    // dzie�
};

//------------------------------------------------------------------------------


int main()
{
    //Date d1;                  // B��d: brak inicjatora.
    //Date d2(1998);            // B��d: za ma�o argument�w.
    //Date d3(1,2,3,4);         // B��d: za du�o argument�w.
    //Date d4(1,"jan",2);       // B��d: nieprawid�owy typ argumentu.
    Date d5(1,Date::jan,2);     // Dobrze: u�ycie trzyargumentowego konstruktora.
    Date d6 = d5;               // Dobrze: u�ycie konstruktora kopiuj�cego.

    {
        string s1;              // Warto�� domy�lna: pusty �a�cuch "".
        vector<string> v1;      // Warto�� domy�lna: pusty wektor � zero element�w.
        vector<string> v2(10);  // Wektor dziesi�ciu domy�lnych �a�cuch�w.
    }

    {
        string s1 = string();   // Warto�� domy�lna: pusty �a�cuch "".
        vector<string> v1 = vector<string>(); // Warto�� domy�lna:
        // pusty wektor � zero element�w.
        vector<string> v2(10,string());       // Wektor dziesi�ciu domy�lnych �a�cuch�w.
    }

    {
        // Wolimy r�wnowa�n� i potoczn� wersj�:
        string s1;              // Warto�� domy�lna: pusty �a�cuch "".
        vector<string> v1;      // Warto�� domy�lna: pusty wektor � zero element�w.
        vector<string> v2(10);  // Wektor dziesi�ciu domy�lnych �a�cuch�w.
    }

    string s;
    s[2] = 'a';                 // Zapisywanie pod losowym adresem.
    s = "hello";

    vector<string> v;
    cout << v[3];               // Odczyt z losowego adresu.

    //Date d;
    //Date::Month m = d.month();// Kopiowanie losowej warto�ci.

    string s1 = "";
    vector<string> v1(0);
    vector<string> v2(10,"");   // Wektor dziesi�ciu pustych �a�cuch�w.
}

//------------------------------------------------------------------------------
