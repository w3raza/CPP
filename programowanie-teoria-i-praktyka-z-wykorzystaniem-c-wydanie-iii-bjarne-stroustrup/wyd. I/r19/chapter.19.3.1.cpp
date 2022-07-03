
//
// To jest przyk�adowy kod z podrozdzia�u 19.3.1 �Typy jako parametry szablon�w� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <string>

using std::string;

//------------------------------------------------------------------------------

// Prawie prawdziwy wektor element�w typu T:
template<class T> class vector {      // Czytaj: �dla wszystkich typ�w T� (tak jak w matematyce).
    int sz;                           // rozmiar
    T* elem;                          // wska�nik na elementy
    int space;                        // size+free_space
public:
    vector() : sz(0), elem(0), space(0) { }    
    vector(int s);

    vector(const vector&);            // konstrruktor kopiuj�cy
    vector& operator=(const vector&); // przypisanie kopiuj�ce

    ~vector() { delete[ ] elem; }     // destruktor

    T& operator[ ] (int n) { return elem[n]; } // dost�p: zwraca referencj�
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
    vector< vector<int> > vvi;        // T jest vector<int>, w kt�rym T jest int.
}

//------------------------------------------------------------------------------

class vector_char {
    int sz;        // rozmiar
    char* elem;    // wska�nik na elementy
    int space;     // size+free_space
public:
    vector_char();
    vector_char(int s);

    vector_char(const vector_char&);             // konstruktor kopiuj�cy
    vector_char& operator=(const vector_char &); // przypisanie kopiuj�ce

    ~vector_char ();                             // destruktor

    char& operator[ ] (int n);                   // dost�p: zwraca referencj�
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
