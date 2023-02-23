
//
// To jest przyk�adowy kod z podrozdzia�u 18.5.3 �Inicjowanie tablic� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int strlen(const char* p)     // Podobna do standardowej funkcji strlen().
{
    int n = 0;
    while (p[n]) ++n;
    return n;
}

//------------------------------------------------------------------------------

int main()
{
    char ac[ ] = "Beorn";                   // Tablica 6 znak�w.
    char* pc = "Howdy";                     // pc wskazuje tablic� sze�ciu znak�w.
    int ai[ ] = { 1, 2, 3, 4, 5, 6 };       // Tablica 6 liczb typu int.
    int ai2[100] = { 0,1,2,3,4,5,6,7,8,9 }; // 90 ostatnich element�w zostanie zainicjowanych warto�ciami 0.
    double ad[100] = { };                   // Wszystkie elementy zostan� zainicjowane warto�ciami 0.0.
    char chars[ ] = { 'a', 'b', 'c' };      // Brak ko�cowego 0!
}

//------------------------------------------------------------------------------
