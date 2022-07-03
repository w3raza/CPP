
//
// To jest przyk�adowy kod z podrozdzia�u 10.7.2 �Oddzielenie warstwy komunikacyjnej od funkcji� ksi��ki 
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

int get_int(int low, int high, const string& greeting, const string& sorry)
{
    cout << greeting << ": [" << low << ':' << high << "]\n";

    while (true) {
        int n = get_int();
        if (low<=n && n<=high) return n;
        cout << sorry  << ": [" << low << ':' << high << "]\n";
    }
}

//------------------------------------------------------------------------------

int main()
try
{
    int strength = get_int(1,10, "Okre�l si��.", "Liczba spoza zakresu. Spr�buj ponownie.");
    cout << "Si�a: " << strength << endl;

    int altitude = get_int(0,50000,
                           "Podaj wysoko�� nad poziomem morza w metrach.",
                           "Liczba spoza zakresu. Spr�buj ponownie.");
    cout << "Wysoko��: " << altitude << "f nad poziomem morza.\n";
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
