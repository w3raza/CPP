
//
// To jest przyk�adowy kod z podrozdzia�u 19.2.3 �Zmienianie rozmiaru� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class vector {
    int sz;       // liczba element�w
    double* elem; // adres pierwszego elementu
    int space;    // liczba element�w plus �wolna przestrze�
                  // dla nowych element�w (�bie��cy rozmiar alokacji�)
public:
    vector();
    void reserve(int newalloc);
    int  capacity() const;
    void resize(int newsize);
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) {}

//------------------------------------------------------------------------------

void vector::reserve(int newalloc)
{
    if (newalloc<=space) return;             // Nigdy nie zmniejszaj obszaru alokacji.
    double* p = new double[newalloc];        // Alokuje now� przestrze�.
    for (int i=0; i<sz; ++i) p[i] = elem[i]; // Kopiuje stare elementy.
    delete[ ] elem;                          // Dealokuje star� przestrze�.
    elem = p;
    space = newalloc;        
}

//------------------------------------------------------------------------------

int vector::capacity() const { return space; }

//------------------------------------------------------------------------------

void vector::resize(int newsize)
// Zmienia rozmiar wektora na newsize.
// Ka�dy nowy element inicjuje domy�ln� warto�ci� 0.0.
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) elem[i] = 0;    // Inicjuje nowe elementy.
    sz = newsize;    
}

//------------------------------------------------------------------------------

int main()
{
    vector v;
    v.reserve(10);
    v.resize(4);
    return v.capacity();
}

//------------------------------------------------------------------------------
