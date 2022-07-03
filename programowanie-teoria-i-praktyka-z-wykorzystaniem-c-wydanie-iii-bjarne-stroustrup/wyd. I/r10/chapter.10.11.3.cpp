
//
// To jest przyk�adowy kod z podrozdzia�u 10.11.3 �Zmienianie reprezentacji" ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<string> month_input_tbl;    // month_input_tbl[0]=="jan"

//------------------------------------------------------------------------------

void init_input_tbl(vector<string>& tbl)
// Inicjacja wektora reprezentacji danych wej�ciowych.
    tbl.push_back("jan");
    tbl.push_back("feb");
    tbl.push_back("mar");
    tbl.push_back("apr");
    tbl.push_back("may");
    tbl.push_back("jun");
    tbl.push_back("jul");
    tbl.push_back("aug");
    tbl.push_back("sep");
    tbl.push_back("oct");
    tbl.push_back("nov");
    tbl.push_back("dec");
}

//------------------------------------------------------------------------------

int month_to_int(string s)
// Czy s jest nazw� miesi�ca? Je�li tak, zwraca jej indeks z zakresu <0,11>, w przeciwnym przypadku zwraca �1.
{
    for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
    return -1;
}

//------------------------------------------------------------------------------

vector<string> month_print_tbl;    // month_print_tbl[0]=="January"

//------------------------------------------------------------------------------

void init_print_tbl(vector<string>& tbl)
// Inicjacja wektora reprezentacji wyj�ciowych.
{
    tbl.push_back("Stycze�");
    tbl.push_back("Luty");
    tbl.push_back("Marzec");
    tbl.push_back("Kwiecie�");
    tbl.push_back("Maj");
    tbl.push_back("Czerwiec");
    tbl.push_back("Lipiec");
    tbl.push_back("Sierpie�");
    tbl.push_back("Wrzesie�");
    tbl.push_back("Pa�dziernik");
    tbl.push_back("Listopad");
    tbl.push_back("Grudzie�");
}

//------------------------------------------------------------------------------

string int_to_month(int i)
// Zakres numer�w miesi�cy: [0:11].
{
    if (i<0 || 12<=i) error("Nieprawid�owy indeks miesi�ca.");
    return month_print_tbl[i];
}

//------------------------------------------------------------------------------

int main()
try
{
    // Inicjacja tablic reprezentacji:
    init_print_tbl(month_print_tbl);
    init_input_tbl(month_input_tbl);
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
