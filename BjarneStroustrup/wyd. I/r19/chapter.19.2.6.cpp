
//
// To jest przyk�adowy kod z podrozdzia�u 19.2.6 �Podsumowanie dotychczasowej pracy nad typem vector� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Prawie prawdziwy wektor liczb typu double:
class vector {
    /*
    inwariant:
        for 0<=n<sz elem[n] jest elementem n
        sz<=space;
        Je�li sz<space, jest miejsce dla (space�sz) liczb za elem[sz�1].

    */
    int sz;           // rozmiar
    double* elem;     // wska�nik na elementy (lub 0)
    int space;         // Liczba element�w plus liczba wolnych miejsc.
public:
    vector() : sz(0), elem(0), space(0) { }
    vector(int s) :sz(s), elem(new double[s]), space(s)
    {
        for (int i=0; i<sz; ++i) elem[i]=0;    // inicjacja element�w
    }    

    vector(const vector&);            // konstruktor kopiuj�cy
    vector& operator=(const vector&); // przypisanie kopiuj�ce

    ~vector() { delete[ ] elem; }     // destruktor

    double& operator[ ](int n) { return elem[n]; } // dost�p
    const double& operator[ ](int n) const { return elem[n]; } 

    int size() const { return sz; }    
    int capacity() const { return space; }

    void resize(int newsize);         // wzrost
    void push_back(double d);
    void reserve(int newalloc);
};

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
    return *this;                  //  Zwraca referencj� do samego siebie.
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
