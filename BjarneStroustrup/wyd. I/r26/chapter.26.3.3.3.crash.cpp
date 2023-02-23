
//
// To jest przyk³adowy kod z podrozdzia³u 26.3.3.3 „Pêtle” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

//------------------------------------------------------------------------------

int do_loop(vector<int>& vec) // marna funkcja
// niezdyscyplinowana pêtla
{
    int i;
    int sum;
    while(i<=vec.size()) sum+=vec[i];
    return sum;
}

//------------------------------------------------------------------------------

const int MAX=256;
char buf[MAX];         // bufor o sta³ym rozmiarze

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
