
//
// To jest przyk�adowy kod z podrozdzia�u 10.7.1 �Roz�o�enie problemu na mniejsze cz�ci� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void skip_to_int()
{
    if (cin.fail()) {          // Znaleziono co�, co nie jest liczb� ca�kowit�.
        cin.clear();           // Chcemy przyjrze� si� znakom.
        char ch;
        while (cin>>ch){       // Odrzuca niecyfry.
            if (isdigit(ch)) {
                cin.unget();   // Oddaje cyfr� z powrotem, dzi�ki czemu mo�na odczyta� liczb�.
                               
                return;
            }
        }
    }
    error("Brak danych.");         // Stan eof lub bad � poddajemy si�.
}

//------------------------------------------------------------------------------

int get_int();                 // Wczytuje liczb� typu int ze strumienia cin.
int get_int(int low, int high);// Wczytuje liczb� typu int nale��c� do zakresu <low,high> ze strumienia cin.

//------------------------------------------------------------------------------

int get_int()
{
    int n = 0;
    while (true) {
        if (cin >> n) return n;
        cout << "Niestety, to nie by�a liczba. Spr�buj jeszcze raz.\n";
        skip_to_int();
    }
}

//------------------------------------------------------------------------------

int get_int(int low, int high)
{
    cout << "Podaj liczb� ca�kowit� z zakresu od "
         << low << " dto " << high << " (w��cznie):\n";

    while (true) {
        int n = get_int();
        if (low<=n && n<=high) return n;
        cout << "Niestety "
             << n << " nie nale�y do zakresu [" << low << ':' << high
             << ">. Spr�buj jeszcze raz.\n";
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    int n = get_int(1,10);
    cout << "n: " << n << endl;

    int m = get_int(2,300);
    cout << "m: " << m << endl;
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
