
//
// To jest przyk³adowy kod z podrozdzia³u 26.3.3.1 „Zale¿noœci” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

vector<int> vec(10);

//------------------------------------------------------------------------------

int do_dependent(int a, int& b) // marna funkcja
      // niezdyscyplinowane zale¿noœci
{
    int val ;
    cin>>val;
    vec[val] += 10;
    cout << a;
    b++;
    return b;
}

//------------------------------------------------------------------------------

int main()
{
    int b = 0;
    return do_dependent(b,b);
}

//------------------------------------------------------------------------------
