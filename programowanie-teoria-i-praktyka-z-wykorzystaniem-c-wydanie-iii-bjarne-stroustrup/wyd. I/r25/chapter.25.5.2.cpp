
//
// To jest przyk³adowy kod z podrozdzia³u 25.5.2 „Klasa bitset” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <bitset>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

void test()
{
    bitset<4> flags = 0xb;
    bitset<128> dword_bits(string("1010101010101010"));
    bitset<12345> lots;

    string s;
    cin>>s;
    bitset<12345> my_bits(s);    // Mo¿e spowodowaæ wyj¹tek std::invalid_argument.
    bitset<32> b1, b2, b3;

    b1 = b2&b3; // i
b1 = b2|b3; // lub
b1 = b2^b3; // xor
b1 = ~b2;   // dope³nienie
b1 = b2<<2; // przesuniêcie w lewo
b1 = b2>>3; // przesuniêcie w prawo


    bitset<32> b;

    cin>>b;               // Wczytuje na wejœciu obiekt typu bitset.
cout<<bitset<8>('c'); // Wysy³a na wyjœcie wzorzec bitowy litery 'c'.
}

//------------------------------------------------------------------------------

int main()
try
{
    const int max = 10;
    bitset<max> b;
    while (cin>>b) {
        cout << b << '\n';
        for (int i =0; i<max; ++i) cout << b[i];    // odwrócona kolejnoœæ
        cout << '\n';
    }
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
