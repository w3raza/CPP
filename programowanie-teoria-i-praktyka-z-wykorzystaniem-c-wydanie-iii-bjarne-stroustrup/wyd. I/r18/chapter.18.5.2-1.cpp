
//
// To jest przyk�adowy kod z podrozdzia�u 18.5.2 �Wska�niki i tablice� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Nazwa tablicy odnosi si� do wszystkich jej element�w.
char ch[100];
char* p = ch; // Zmienna p jest inicjowana warto�ci� &ch[0].

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
