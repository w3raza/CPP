
//
// To jest przyk³adowy kod z podrozdzia³u 10.10 „Standardowa pêtla wejœciowa” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef int My_type;

//------------------------------------------------------------------------------

void input_loop_1(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // Wczytuje dane do koñca pliku.
        // Mo¿e jakiœ test poprawnoœci var.
        // Jakieœ operacje przy u¿yciu var.
    }
    // Rzadko da siê odzyskaæ sprawnoœæ po wyst¹pieniu stanu bad. Nie nale¿y tego próbowaæ, jeœli nie jest to konieczne:
    if (ist.bad()) error("Nieprawid³owy strumieñ wejœciowy.");
    if (ist.fail()) {
        // Czy to by³ akceptowalny znak koñcowy?
    }
    // Kontynuacja: znaleziono koniec pliku.
}

//------------------------------------------------------------------------------

void input_loop_2(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // Wczytuje dane do koñca pliku.
        // Mo¿e jakiœ test poprawnoœci var.
        // Jakieœ operacje przy u¿yciu var.
    }
    if (ist.fail()) { // Znak '|' pe³ni rolê symbolu koñca i/lub separatora.
        ist.clear();
        char ch;
        if (!(ist>>ch && ch=='|')) error("Niepoprawny znak koñca danych.");
    }
    // Kontynuacja: znaleziono koniec pliku lub znak koñcowy.
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail()) { // U¿ycie term jako znaku koñca i/lub znaku oddzielaj¹cego.
        ist.clear();
        char ch;
        if (ist>>ch && ch==term) return;    // Wszystko jest w porz¹dku.
        error(message);
    }
}

//------------------------------------------------------------------------------

void input_loop_3(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // Wczytuje dane do koñca pliku.
        // Mo¿e jakiœ test poprawnoœci var.
        // Jakieœ operacje przy u¿yciu var.
    }
    end_of_loop(ist,'|',"Niepoprawne zakoñczenie pliku");    // Test okreœlaj¹cy, czy mo¿na kontynuowaæ.
    // Kontynuacja: znaleziono koniec pliku lub znak koñcowy.
}

//------------------------------------------------------------------------------

int main()
try
{
    input_loop_3(cin);
    input_loop_2(cin);
    input_loop_1(cin);
    // Gdzieœ w kodzie: ist zg³asza wyj¹tek, jeœli coœ siê nie uda:
    cin.exceptions(cin.exceptions()|ios_base::badbit);
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
