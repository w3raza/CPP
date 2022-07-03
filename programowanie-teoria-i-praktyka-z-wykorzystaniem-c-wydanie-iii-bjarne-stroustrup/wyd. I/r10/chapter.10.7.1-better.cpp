
//
// To jest przyk³adowy kod z podrozdzia³u 10.7.1 „Roz³o¿enie problemu na mniejsze czêœci” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void skip_to_int()
{
    if (cin.fail()) {          // Znaleziono coœ, co nie jest liczb¹ ca³kowit¹.
        cin.clear();           // Chcemy przyjrzeæ siê znakom.
        char ch;
        while (cin>>ch){       // Odrzuca niecyfry.
            if (isdigit(ch)) {
                cin.unget();   // Oddaje cyfrê z powrotem, dziêki czemu mo¿na odczytaæ liczbê.
                               
                return;
            }
        }
    }
    error("Brak danych.");         // Stan eof lub bad — poddajemy siê.
}

//------------------------------------------------------------------------------

int main()
try
{
    cout << "Podaj liczbê ca³kowit¹ z zakresu od 1 do 10 (w³¹cznie):\n";
    int n = 0;
    while (true) {
        if (cin>>n) {          // Mamy liczbê ca³kowit¹; sprawdzamy j¹.
            if (1<=n && n<=10) break;
            cout << "Niestety " << n
                << " nie nale¿y do zakresu <1,10>. Spróbuj jeszcze raz.\n";
        }
        else {
            cout << "Niestety, to nie by³a liczba. Spróbuj jeszcze raz.\n";
            skip_to_int();
        }
    }
    // Jeœli dotrzemy do tego miejsca, oznacza to, ¿e n nale¿y do zakresu <1,10>.
    return n;
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
