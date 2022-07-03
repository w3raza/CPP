
//
// To jest przyk³adowy kod z podrozdzia³u 10.7.2 „Oddzielenie warstwy komunikacyjnej od funkcji” ksi¹¿ki 
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
    int strength = get_int(1,10, "Okreœl si³ê.", "Liczba spoza zakresu. Spróbuj ponownie.");
    cout << "Si³a: " << strength << endl;

    int altitude = get_int(0,50000,
                           "Podaj wysokoœæ nad poziomem morza w metrach.",
                           "Liczba spoza zakresu. Spróbuj ponownie.");
    cout << "Wysokoœæ: " << altitude << "f nad poziomem morza.\n";
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
