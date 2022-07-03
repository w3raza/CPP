
//
// To jest przyk³adowy kod z podrozdzia³u 9.7.3 „Konstruktory domyœlne” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

// Prosta klasa Date (z u¿yciem typu Month).
class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    Date(int yy, Month mm, int dd) : y(yy), m(mm), d(dd) // Sprawdza poprawnoœæ daty i wykonuje inicjacjê.
    {
        // ...
    }

private:
    int   y;                    // Rok
    Month m;
    int   d;                    // dzieñ
};

//------------------------------------------------------------------------------


int main()
{
    //Date d1;                  // B³¹d: brak inicjatora.
    //Date d2(1998);            // B³¹d: za ma³o argumentów.
    //Date d3(1,2,3,4);         // B³¹d: za du¿o argumentów.
    //Date d4(1,"jan",2);       // B³¹d: nieprawid³owy typ argumentu.
    Date d5(1,Date::jan,2);     // Dobrze: u¿ycie trzyargumentowego konstruktora.
    Date d6 = d5;               // Dobrze: u¿ycie konstruktora kopiuj¹cego.

    {
        string s1;              // Wartoœæ domyœlna: pusty ³añcuch "".
        vector<string> v1;      // Wartoœæ domyœlna: pusty wektor — zero elementów.
        vector<string> v2(10);  // Wektor dziesiêciu domyœlnych ³añcuchów.
    }

    {
        string s1 = string();   // Wartoœæ domyœlna: pusty ³añcuch "".
        vector<string> v1 = vector<string>(); // Wartoœæ domyœlna:
        // pusty wektor — zero elementów.
        vector<string> v2(10,string());       // Wektor dziesiêciu domyœlnych ³añcuchów.
    }

    {
        // Wolimy równowa¿n¹ i potoczn¹ wersjê:
        string s1;              // Wartoœæ domyœlna: pusty ³añcuch "".
        vector<string> v1;      // Wartoœæ domyœlna: pusty wektor — zero elementów.
        vector<string> v2(10);  // Wektor dziesiêciu domyœlnych ³añcuchów.
    }

    string s;
    s[2] = 'a';                 // Zapisywanie pod losowym adresem.
    s = "hello";

    vector<string> v;
    cout << v[3];               // Odczyt z losowego adresu.

    //Date d;
    //Date::Month m = d.month();// Kopiowanie losowej wartoœci.

    string s1 = "";
    vector<string> v1(0);
    vector<string> v2(10,"");   // Wektor dziesiêciu pustych ³añcuchów.
}

//------------------------------------------------------------------------------
