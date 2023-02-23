
//
// To jest przyk�adowy kod z podrozdzia�u 25.5.2 �Klasa bitset� ksi��ki
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
    bitset<12345> my_bits(s);    // Mo�e spowodowa� wyj�tek std::invalid_argument.
    bitset<32> b1, b2, b3;

    b1 = b2&b3; // i
b1 = b2|b3; // lub
b1 = b2^b3; // xor
b1 = ~b2;   // dope�nienie
b1 = b2<<2; // przesuni�cie w lewo
b1 = b2>>3; // przesuni�cie w prawo


    bitset<32> b;

    cin>>b;               // Wczytuje na wej�ciu obiekt typu bitset.
cout<<bitset<8>('c'); // Wysy�a na wyj�cie wzorzec bitowy litery 'c'.
}

//------------------------------------------------------------------------------

int main()
try
{
    const int max = 10;
    bitset<max> b;
    while (cin>>b) {
        cout << b << '\n';
        for (int i =0; i<max; ++i) cout << b[i];    // odwr�cona kolejno��
        cout << '\n';
    }
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
