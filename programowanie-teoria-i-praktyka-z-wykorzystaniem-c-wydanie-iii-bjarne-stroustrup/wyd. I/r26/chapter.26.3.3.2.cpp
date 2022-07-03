
//
// To jest przyk�adowy kod z podrozdzia�u 26.3.3.2 �Zarz�dzanie zasobami� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

//------------------------------------------------------------------------------

struct Bad_arg {};

//------------------------------------------------------------------------------

void do_resources1(int a, int b, const string& s) // marna funkcja
      // niezdyscyplinowane wykorzystanie zasob�w
{
    FILE* f = fopen(s.c_str(),"r");    // Otwiera plik (styl j�zyka C).
    int* p = new int[a];               // Alokuje troch� pami�ci.
    if (b<=0) throw Bad_arg();         // Mo�e zg�osi� wyj�tek.
    int* q = new int[b];       // Alokuje troch� wi�cej pami�ci.
    delete[] p;                // Dealokuje pami�� wskazywan� przez p.
}

//------------------------------------------------------------------------------

void do_resources2(int a, int b, const string& s) // troch� lepsza funkcja
{
    ifstream is(s.c_str(),ios_base::in); // Otwiera plik.
    vector<int>v1(a);          // Tworzy wektor (posiadaj�cy pami��).
    if (b<=0) throw Bad_arg(); // Mo�e zg�osi� wyj�tek.
    vector<int> v2(b);         // Tworzy inny wektor (posiadaj�cy pami��).
}

//------------------------------------------------------------------------------

int* var = 0;

//------------------------------------------------------------------------------

FILE* do_resources3(int a, int* p, const string& s) // marna funkcja
      // niezdyscyplinowane przekazywanie zasob�w
{
    FILE* f = fopen(s.c_str(),"r");
    delete p;
    delete var;
    var = new int[27];
    return f;
}

//------------------------------------------------------------------------------

int main()
try
{
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
