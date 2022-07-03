
//
// To jest przyk�adowy kod z podrozdzia�u 19.2.5 �Przypisywanie� ksi��ki
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
    void push_back(double d);
    vector& operator=(const vector& a);
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

void vector::push_back(double d)
 // Zwi�ksza rozmiar wektora o jeden i inicjuje nowy element warto�ci� d.
{
    // Rezerwuje wi�cej przestrzeni.
    if (space==0)
        reserve(8);
    else 
    if (space==sz)
        reserve(2*space);

    elem[sz] = d;    // Dodaje d na ko�cu.
    ++sz;            // Zwi�ksza rozmiar (sz okre�la liczb� element�w).
}

//------------------------------------------------------------------------------

vector& vector::operator=(const vector& a)
{
    if (this==&a) return *this;    // samoprzypisanie

    if (a.sz<=space) {             // wystarczaj�ca ilo�� przestrzeni, nie trzeba nic dodatkowo alokowa�
        for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i]; // Kopiuje elementy.
        sz = a.sz;
        return *this;
    }

    double* p = new double[a.sz];  // Alokuje now� przestrze�.
    for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];    // Kopiuje elementy.
    delete[ ] elem;                // Dealokuje star� przestrze�.
    space = sz = a.sz;             // Ustawia nowy rozmiar.
    elem = p;                      // Ustawia nowe elementy.
    return *this;                  // zwraca referencj� do samego siebie
}

//------------------------------------------------------------------------------

int main()
{
    vector v;
    v.reserve(10);
    v.resize(4);
    v.push_back(7);

    vector a;
    a = v;
    return a.capacity();
}

//------------------------------------------------------------------------------
