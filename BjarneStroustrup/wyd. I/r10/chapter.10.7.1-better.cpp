
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

int main()
try
{
    cout << "Podaj liczb� ca�kowit� z zakresu od 1 do 10 (w��cznie):\n";
    int n = 0;
    while (true) {
        if (cin>>n) {          // Mamy liczb� ca�kowit�; sprawdzamy j�.
            if (1<=n && n<=10) break;
            cout << "Niestety " << n
                << " nie nale�y do zakresu <1,10>. Spr�buj jeszcze raz.\n";
        }
        else {
            cout << "Niestety, to nie by�a liczba. Spr�buj jeszcze raz.\n";
            skip_to_int();
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
