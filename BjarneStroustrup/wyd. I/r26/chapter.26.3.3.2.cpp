
//
// To jest przyk³adowy kod z podrozdzia³u 26.3.3.2 „Zarz¹dzanie zasobami” ksi¹¿ki
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
      // niezdyscyplinowane wykorzystanie zasobów
{
    FILE* f = fopen(s.c_str(),"r");    // Otwiera plik (styl jêzyka C).
    int* p = new int[a];               // Alokuje trochê pamiêci.
    if (b<=0) throw Bad_arg();         // Mo¿e zg³osiæ wyj¹tek.
    int* q = new int[b];       // Alokuje trochê wiêcej pamiêci.
    delete[] p;                // Dealokuje pamiêæ wskazywan¹ przez p.
}

//------------------------------------------------------------------------------

void do_resources2(int a, int b, const string& s) // trochê lepsza funkcja
{
    ifstream is(s.c_str(),ios_base::in); // Otwiera plik.
    vector<int>v1(a);          // Tworzy wektor (posiadaj¹cy pamiêæ).
    if (b<=0) throw Bad_arg(); // Mo¿e zg³osiæ wyj¹tek.
    vector<int> v2(b);         // Tworzy inny wektor (posiadaj¹cy pamiêæ).
}

//------------------------------------------------------------------------------

int* var = 0;

//------------------------------------------------------------------------------

FILE* do_resources3(int a, int* p, const string& s) // marna funkcja
      // niezdyscyplinowane przekazywanie zasobów
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
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
