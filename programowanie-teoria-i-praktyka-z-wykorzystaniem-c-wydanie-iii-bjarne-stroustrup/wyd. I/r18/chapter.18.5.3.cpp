
//
// To jest przyk³adowy kod z podrozdzia³u 18.5.3 „Inicjowanie tablic” ksi¹¿ki
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
    char ac[ ] = "Beorn";                   // Tablica 6 znaków.
    char* pc = "Howdy";                     // pc wskazuje tablicê szeœciu znaków.
    int ai[ ] = { 1, 2, 3, 4, 5, 6 };       // Tablica 6 liczb typu int.
    int ai2[100] = { 0,1,2,3,4,5,6,7,8,9 }; // 90 ostatnich elementów zostanie zainicjowanych wartoœciami 0.
    double ad[100] = { };                   // Wszystkie elementy zostan¹ zainicjowane wartoœciami 0.0.
    char chars[ ] = { 'a', 'b', 'c' };      // Brak koñcowego 0!
}

//------------------------------------------------------------------------------
