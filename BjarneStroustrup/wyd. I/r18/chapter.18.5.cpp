
//
// To jest przyk�adowy kod z podrozdzia�u 18.5 �Tablice� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

const int max = 100;
int gai[max];            // Globalna tablica (100 liczb typu int); ��yje wiecznie�

int f(int n)
{
    char lac[20];        // Lokalna tablica; ��yje� do ko�ca swojego zakresu.
    int lai[60];
    //double lad[n];       // B��d: rozmiar tablicy nie jest sta�y.
    // ...
    return 0;
}

//------------------------------------------------------------------------------

int f2(int n)
{
    char lac[20];        // Lokalna tablica; ��yje� do ko�ca swojego zakresu.

    lac[7] = 'a';
    *lac = 'b';          // R�wnoznaczne z lac[0]='b'.

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
