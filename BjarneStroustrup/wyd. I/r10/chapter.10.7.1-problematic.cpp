
//
// To jest przyk�adowy kod z podrozdzia�u 10.7.1 �Roz�o�enie problemu na mniejsze cz�ci� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Podaj liczb� ca�kowit� z zakresu od 1 do 10 (w��cznie):\n";
    int n = 0;
    while (true)    {
        cin >> n;
        if (cin) {    // Mamy liczb� ca�kowit�; sprawdzamy j�.
            if (1<=n && n<=10) break;
            cout << "Niestety "
                 << n << " nie nale�y do zakresu <1,10>. Spr�buj jeszcze raz.\n";
        }
        else if (cin.fail()) {    // Znaleziono co�, co nie jest liczb� ca�kowit�.
            cin.clear();          // Ustawia stan z powrotem na good().
                                  // Chcemy przyjrze� si� znakom.
            cout << "Niestety, to nie by�a liczba. Spr�buj jeszcze raz.\n";
            char ch;
            while (cin>>ch && !isdigit(ch)); // Odrzuca niecyfry.
            if (!cin) error("Brak danych.");     // Nie znaleziono cyfry � poddajemy si�.
            cin.unget();    // Oddaje cyfr� z powrotem, dzi�ki czemu mo�na odczyta� liczb�.
        }
        else {
            error("Brak danych.");    // Stan eof lub bad � poddajemy si�.
        }
    }
    // Je�li dotrzemy do tego miejsca, oznacza to, �e n nale�y do zakresu <1,10>.
    return n;
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
