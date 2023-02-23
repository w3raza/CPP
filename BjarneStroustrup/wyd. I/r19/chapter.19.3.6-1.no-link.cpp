
//
// To jest przyk³adowy kod z podrozdzia³u 19.3.6 „Uogólnianie wektora” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
// Prawie prawdziwy wektor elementów typu T:
template<class T> class vector {      // Czytaj: „dla wszystkich typów T” (tak jak w matematyce).
    int sz;                           // rozmiar
    T* elem;                          // wskaŸnik na elementy
    int space;                        // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // konstruktor kopiuj¹cy
    vector& operator=(const vector&); // przypisanie kopiuj¹ce

    ~vector() { delete[ ] elem; }     // destruktor

    T& operator[ ] (int n) { return elem[n]; } // dostêp: zwraca referencjê
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
    v1.resize(200, 0.0);           // Dodaje 100 kopii 0.0 — wpisanie 0.0 by³o zbêdne.
    v1.resize(300, 1.0);           // Dodaje 100 kopii 1.0.

    //vector<No_default> v2(10);   // B³¹d: próba utworzenia 10 obiektów No_default().

    vector<No_default> v3;
    v3.resize(100, No_default(2)); // Dodaje 100 kopii No_default(2).
    //v3.resize(200);              // B³¹d: próba utworzenia 100 obiektów No_default().
}

//------------------------------------------------------------------------------
