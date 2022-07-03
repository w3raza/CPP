
//
// To jest przyk�adowy kod z podrozdzia�u 25.5.6 �Przyk�ad � proste szyfrowanie� ksi��ki
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

// Odpowiednia funkcja deszyfruj�ca:
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
    // sum = delta<<5, og�lnie sum = delta * n
    while(n-->0) {
        z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum>>11 & 3];
        sum -= delta;
        y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum&3];
    }
    w[0]=y; w[1]=z;
}

//------------------------------------------------------------------------------

int main()    // nadawca
try
{
    const int nchar = 2*sizeof(long);    // 64 bity
    const int kchar = 2*nchar;           // 128 bit�w

    string op;
    string key;
    string infile;
    string outfile;
    cout << "Podaj nazw� pliku wej�ciowego i wyj�ciowego oraz klucz:\n";
    cin >> infile >> outfile >> key;
    while (key.size()<kchar) key += '0'; // klawisz dope�nienia
    ifstream inf(infile.c_str());
    ofstream outf(outfile.c_str());
    if (!inf || !outf) error("Nieprawid�owa nazwa pliku.");

    const unsigned long* k =
        reinterpret_cast<const unsigned long*>(key.data());

    unsigned long outptr[2];
    char inbuf[nchar];
    unsigned long* inptr = reinterpret_cast<unsigned long*>(inbuf); 
    int count = 0;

    while (inf.get(inbuf[count])) {
        outf << hex;    // Szesnastkowy format danych wyj�ciowych.
        if (++count == nchar) {
            encipher(inptr,outptr,k);
            // Dope�nienie wiod�cymi zerami:
            outf << setw(8) << setfill('0') << outptr[0] << ' '
                << setw(8) << setfill('0') << outptr[1] << ' ';
            count = 0;
        }
    }

    if (count) { // pad
        while(count != nchar) inbuf[count++] = '0'; 
        encipher(inptr,outptr,k);
        outf << outptr[0] << ' ' << outptr[1] << ' ';
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
