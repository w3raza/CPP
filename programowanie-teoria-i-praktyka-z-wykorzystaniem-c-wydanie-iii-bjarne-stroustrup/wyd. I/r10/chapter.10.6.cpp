
//
// To jest przyk�adowy kod z podrozdzia�u 10.6 �Obs�uga b��d�w wej�cia i wyj�cia� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

using namespace std;

//------------------------------------------------------------------------------

int main()
try
{
    int i = 0;
    cin >> i;
    if (!cin) {    // Ten kod b�dzie wykonywany, tylko gdy nie powiedzie si� operacja wej�ciowa.
        if (cin.bad()) error("Z�y stan strumienia cin."); // Uszkodzony strumie�: wynosimy si� st�d!
        if (cin.eof()) {
            // Nie ma wi�cej danych wej�ciowych.
            // W taki spos�b powinny ko�czy� si� serie operacji wej�ciowych.
        }
        if (cin.fail()) {   // Strumie� napotka� co�, czego si� nie spodziewa�.
            cin.clear();    // Przygotowanie na wi�cej danych.
            // Odzyskiwanie sprawno�ci.
        }
    }
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
