
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.6.3 „Pliki” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void f(const char* fn)
{
    FILE* fi = fopen(fn, "r");    /* Otwiera fn do odczytu. */
    FILE* fo = fopen(fn, "w");    /* Otwiera fn2 do zapisu. */

    if (fi == 0) error("Nie uda³o siê otworzyæ pliku wejœciowego.");
    if (fo == 0) error("Nie uda³o siê otworzyæ pliku wyjœciowego.");

    /* Wczytuje dane z pliku przy u¿yciu funkcji wejœciowych biblioteki stdio, np. getc(). */
    /* Zapisuje dane w pliku przy u¿yciu funkcji wyjœciowych biblioteki stdio, np. fprintf(). */

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
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
