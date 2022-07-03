
//
// To jest przyk�adowy kod z podrozdzia�u 26.3.3.3 �P�tle� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

//------------------------------------------------------------------------------

int do_loop(vector<int>& vec) // marna funkcja
// niezdyscyplinowana p�tla
{
    int i;
    int sum;
    while(i<=vec.size()) sum+=vec[i];
    return sum;
}

//------------------------------------------------------------------------------

const int MAX=256;
char buf[MAX];         // bufor o sta�ym rozmiarze

//------------------------------------------------------------------------------

char* read_line()      // niebezpieczne niedbalstwo
{
    int i = 0;
    char ch;
    while(cin.get(ch) && ch!='\n') buf[i++] = ch;
    buf[i+1] = 0;
    return  buf;
}

//------------------------------------------------------------------------------

int main()
{
    // niebezpieczne niedbalstwo:
    gets(buf);         // Wczytuje wiersz danych do buf.
    sprintf("%s",buf); // Wczytuje wiersz danych do buf.
}

//------------------------------------------------------------------------------
