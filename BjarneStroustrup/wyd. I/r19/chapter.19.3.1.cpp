
//
// To jest przyk³adowy kod z podrozdzia³u 19.3.1 „Typy jako parametry szablonów” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <string>

using std::string;

//------------------------------------------------------------------------------

// Prawie prawdziwy wektor elementów typu T:
template<class T> class vector {      // Czytaj: „dla wszystkich typów T” (tak jak w matematyce).
    int sz;                           // rozmiar
    T* elem;                          // wskaŸnik na elementy
    int space;                        // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // konstrruktor kopiuj¹cy
    vector& operator=(const vector&); // przypisanie kopiuj¹ce

    ~vector() { delete[ ] elem; }     // destruktor

    T& operator[ ] (int n) { return elem[n]; } // dostêp: zwraca referencjê
    const T& operator[ ] (int n) const { return elem[n]; }  

    int size() const { return sz; }   // aktualny rozmiar
    int capacity() const { return space; }

    void resize(int newsize);         // wzrost
    void push_back(const T& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------


int main()
{
    vector<double> vd;                // T jest double.
    vector<int> vi;                   // T jest int.
    vector<double*> vpd;              // T jest double*.
    vector< vector<int> > vvi;        // T jest vector<int>, w którym T jest int.
}

//------------------------------------------------------------------------------

class vector_char {
    int sz;        // rozmiar
    char* elem;    // wskaŸnik na elementy
    int space;     // size+free_space
public:
    vector_char();
    vector_char(int s);

    vector_char(const vector_char&);             // konstruktor kopiuj¹cy
    vector_char& operator=(const vector_char &); // przypisanie kopiuj¹ce

    ~vector_char ();                             // destruktor

    char& operator[ ] (int n);                   // dostêp: zwraca referencjê
    const char& operator[ ] (int n) const;  

    int size() const ;                           // aktualny rozmiar
    int capacity() const;

    void resize(int newsize);                    // wzrost
    void push_back(const char& d);
    void reserve(int newalloc);
};

//------------------------------------------------------------------------------

void fct(vector<string>& v)
{
    int n = v.size();
    v.push_back("Nora");
    // ...
}

//------------------------------------------------------------------------------

template<class T> void vector<T>::push_back(const T& d) { /* ... */ };

//------------------------------------------------------------------------------
