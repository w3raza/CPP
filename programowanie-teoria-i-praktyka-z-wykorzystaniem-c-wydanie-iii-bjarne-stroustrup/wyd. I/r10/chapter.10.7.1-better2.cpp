
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

int get_int();                 // Wczytuje liczbê typu int ze strumienia cin.
int get_int(int low, int high);// Wczytuje liczbê typu int nale¿¹c¹ do zakresu <low,high> ze strumienia cin.

//------------------------------------------------------------------------------

int get_int()
{
    int n = 0;
    while (true) {
        if (cin >> n) return n;
        cout << "Niestety, to nie by³a liczba. Spróbuj jeszcze raz.\n";
        skip_to_int();
    }
}

//------------------------------------------------------------------------------

int get_int(int low, int high)
{
    cout << "Podaj liczbê ca³kowit¹ z zakresu od "
         << low << " dto " << high << " (w³¹cznie):\n";

    while (true) {
        int n = get_int();
        if (low<=n && n<=high) return n;
        cout << "Niestety "
             << n << " nie nale¿y do zakresu [" << low << ':' << high
             << ">. Spróbuj jeszcze raz.\n";
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
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
