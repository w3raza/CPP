
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.6.3 �Pliki� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(const char* fn)
{
    FILE* fi = fopen(fn, "r");    /* Otwiera fn do odczytu. */
    FILE* fo = fopen(fn, "w");    /* Otwiera fn2 do zapisu. */

    if (fi == 0) error("Nie uda�o si� otworzy� pliku wej�ciowego.");
    if (fo == 0) error("Nie uda�o si� otworzy� pliku wyj�ciowego.");

    /* Wczytuje dane z pliku przy u�yciu funkcji wej�ciowych biblioteki stdio, np. getc(). */
    /* Zapisuje dane w pliku przy u�yciu funkcji wyj�ciowych biblioteki stdio, np. fprintf(). */

    fclose(fo); 
    fclose(fi);

}

//------------------------------------------------------------------------------

int main()
try
{
    f("My_file");
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
