
//
// To jest przyk³adowy kod z podrozdzia³u 25.5.6 „Przyk³ad — proste szyfrowanie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void encipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long * const k)
{
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0;
    unsigned long delta = 0x9E3779B9;
    unsigned long n = 32;
    while(n-->0) {
        y += (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
        sum += delta;
        z += (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
    }
    w[0]=y; w[1]=z;
}

//------------------------------------------------------------------------------

// Odpowiednia funkcja deszyfruj¹ca
void decipher(
    const unsigned long *const v,
    unsigned long *const w,
    const unsigned long * const k)
{ 
    unsigned long y = v[0];
    unsigned long z = v[1];
    unsigned long sum = 0xC6EF3720;
    unsigned long delta = 0x9E3779B9;
    unsigned long n = 32;
    // sum = delta<<5, ogólnie sum = delta * n
    while(n-->0) {
        z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
        sum -= delta;
        y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
    }
    w[0]=y; w[1]=z;
}

//------------------------------------------------------------------------------

int main()    // odbiorca
try
{
    const int nchar = 2*sizeof(long);    // 64 bity
    const int kchar = 2*nchar;           // 128 bitów

    string op;
    string key;
    string infile;
    string outfile;
    cout << "Podaj nazwê pliku wejœciowego i wyjœciowego oraz klucz:\n";
    cin >> infile >> outfile >> key;
    while (key.size()<kchar) key += '0'; // klawisz dope³nienia
    ifstream inf(infile.c_str());
    ofstream outf(outfile.c_str());
    if (!inf || !outf) error("Nieprawid³owa nazwa pliku.");

    const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long inptr[2];    
    char outbuf[nchar+1];
    outbuf[nchar]=0; // znak koñca
    unsigned long* outptr = reinterpret_cast<unsigned long*>(outbuf);
    inf.setf(ios_base::hex ,ios_base::basefield); // Szesnastkowy format danych wejœciowych.

    while (inf>>inptr[0]>>inptr[1]) {
        decipher(inptr,outptr,k);
        outf<<outbuf;
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
