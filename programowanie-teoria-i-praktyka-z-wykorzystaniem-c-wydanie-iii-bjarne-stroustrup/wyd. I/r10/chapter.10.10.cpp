
//
// To jest przyk�adowy kod z podrozdzia�u 10.10 �Standardowa p�tla wej�ciowa� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef int My_type;

//------------------------------------------------------------------------------

void input_loop_1(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // Wczytuje dane do ko�ca pliku.
        // Mo�e jaki� test poprawno�ci var.
        // Jakie� operacje przy u�yciu var.
    }
    // Rzadko da si� odzyska� sprawno�� po wyst�pieniu stanu bad. Nie nale�y tego pr�bowa�, je�li nie jest to konieczne:
    if (ist.bad()) error("Nieprawid�owy strumie� wej�ciowy.");
    if (ist.fail()) {
        // Czy to by� akceptowalny znak ko�cowy?
    }
    // Kontynuacja: znaleziono koniec pliku.
}

//------------------------------------------------------------------------------

void input_loop_2(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // Wczytuje dane do ko�ca pliku.
        // Mo�e jaki� test poprawno�ci var.
        // Jakie� operacje przy u�yciu var.
    }
    if (ist.fail()) { // Znak '|' pe�ni rol� symbolu ko�ca i/lub separatora.
        ist.clear();
        char ch;
        if (!(ist>>ch && ch=='|')) error("Niepoprawny znak ko�ca danych.");
    }
    // Kontynuacja: znaleziono koniec pliku lub znak ko�cowy.
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail()) { // U�ycie term jako znaku ko�ca i/lub znaku oddzielaj�cego.
        ist.clear();
        char ch;
        if (ist>>ch && ch==term) return;    // Wszystko jest w porz�dku.
        error(message);
    }
}

//------------------------------------------------------------------------------

void input_loop_3(istream& ist)
{  
    My_type var;
    while (ist>>var) {    // Wczytuje dane do ko�ca pliku.
        // Mo�e jaki� test poprawno�ci var.
        // Jakie� operacje przy u�yciu var.
    }
    end_of_loop(ist,'|',"Niepoprawne zako�czenie pliku");    // Test okre�laj�cy, czy mo�na kontynuowa�.
    // Kontynuacja: znaleziono koniec pliku lub znak ko�cowy.
}

//------------------------------------------------------------------------------

int main()
try
{
    input_loop_3(cin);
    input_loop_2(cin);
    input_loop_1(cin);
    // Gdzie� w kodzie: ist zg�asza wyj�tek, je�li co� si� nie uda:
    cin.exceptions(cin.exceptions()|ios_base::badbit);
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
