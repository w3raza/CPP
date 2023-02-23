
//
// To jest przyk³adowy kod z podrozdzia³u 18.5.2 „WskaŸniki i tablice” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Nazwa tablicy odnosi siê do wszystkich jej elementów.
char ch[100];
char* p = ch; // Zmienna p jest inicjowana wartoœci¹ &ch[0].

//------------------------------------------------------------------------------

int strlen(const char* p)    // Podobna do funkcji strlen() z biblioteki standardowej.
{
    int count = 0;
    while (*p) { ++count; ++p; }
    return count;
}

//------------------------------------------------------------------------------

char lots [100000];

void f()
{
    int nchar = strlen(lots);
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
