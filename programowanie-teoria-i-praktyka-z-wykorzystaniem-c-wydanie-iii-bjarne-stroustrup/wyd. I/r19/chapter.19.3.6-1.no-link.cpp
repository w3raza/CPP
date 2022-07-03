
//
// To jest przyk�adowy kod z podrozdzia�u 19.3.6 �Uog�lnianie wektora� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
// Prawie prawdziwy wektor element�w typu T:
template<class T> class vector {      // Czytaj: �dla wszystkich typ�w T� (tak jak w matematyce).
    int sz;                           // rozmiar
    T* elem;                          // wska�nik na elementy
    int space;                        // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // konstruktor kopiuj�cy
    vector& operator=(const vector&); // przypisanie kopiuj�ce

    ~vector() { delete[ ] elem; }     // destruktor

    T& operator[ ] (int n) { return elem[n]; } // dost�p: zwraca referencj�
    const T& operator[ ] (int n) const { return elem[n]; }  

    int size() const { return sz; }   // aktualny rozmiar
    int capacity() const { return space; }

    void resize(int newsize, T def = T()); // wzrost
    void push_back(const T& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

struct No_default {
    No_default(int);               // Jedyny konstruktor struktury No_default.
    // ...
};

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    vector<double> v1;
    v1.resize(100);                // Dodaje 100 kopii double(), tzn. 0.0.
    v1.resize(200, 0.0);           // Dodaje 100 kopii 0.0 � wpisanie 0.0 by�o zb�dne.
    v1.resize(300, 1.0);           // Dodaje 100 kopii 1.0.

    //vector<No_default> v2(10);   // B��d: pr�ba utworzenia 10 obiekt�w No_default().

    vector<No_default> v3;
    v3.resize(100, No_default(2)); // Dodaje 100 kopii No_default(2).
    //v3.resize(200);              // B��d: pr�ba utworzenia 100 obiekt�w No_default().
}

//------------------------------------------------------------------------------
