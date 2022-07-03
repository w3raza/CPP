
//
// To jest przyk³adowy kod z podrozdzia³u 18.5 „Tablice” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

const int max = 100;
int gai[max];            // Globalna tablica (100 liczb typu int); „¿yje wiecznie”

int f(int n)
{
    char lac[20];        // Lokalna tablica; „¿yje” do koñca swojego zakresu.
    int lai[60];
    //double lad[n];       // B³¹d: rozmiar tablicy nie jest sta³y.
    // ...
    return 0;
}

//------------------------------------------------------------------------------

int f2(int n)
{
    char lac[20];        // Lokalna tablica; „¿yje” do koñca swojego zakresu.

    lac[7] = 'a';
    *lac = 'b';          // Równoznaczne z lac[0]='b'.

    lac[-2] = 'b';       // Co?
    lac[200] = 'c';      // Co?
    return 0;
}

//------------------------------------------------------------------------------

int main()
{
    f(10);
    f2(10);
}

//------------------------------------------------------------------------------
