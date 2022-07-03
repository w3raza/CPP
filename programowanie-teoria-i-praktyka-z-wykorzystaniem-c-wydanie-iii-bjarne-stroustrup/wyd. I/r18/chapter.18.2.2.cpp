
//
// To jest przyk³adowy kod z podrozdzia³u 18.2.2 „Przypisywanie z kopiowaniem” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class vector {
    int sz;
    double* elem;
    void copy(const vector& arg);     // Kopiuje elementy z arg do *elem.
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    ~vector() { delete[] elem; }                  // destruktor

    int size() const { return sz; }               // aktualny rozmiar

    double get(int n) { return elem[n]; }         // dostêp: odczyt
    void set(int n, double v) { elem[n]=v; }      // dostêp: zapis
    vector& operator=(const vector&);             // przypisanie kopiuj¹ce
};

//------------------------------------------------------------------------------

void vector::copy(const vector& arg)
// Kopiuje elementy <0,arg.sz–1>.
{
    for (int i = 0; i<arg.sz; ++i) elem[i] = arg.elem[i];
}

//------------------------------------------------------------------------------

vector& vector::operator=(const vector& a)
// Czyni ten wektor kopi¹ wektora a.
{
    double* p = new double[a.sz];     // alokuje pamiêæ
    copy(a);                          // kopiuje elementy
    delete[ ] elem;                   // dealokuje pamiêæ
    elem = p;                         // Teraz mo¿na zresetowaæ elem.
    sz = a.sz;
    return *this;                     // Zwraca referencjê do samego siebie (podrozdzia³ 17.10).
}

//------------------------------------------------------------------------------

void f2(int n)
{
    vector v(3);                      // definicja wektora
    v.set(2,2.2);
    vector v2(4);
    v2 = v;                           // Przypisanie: co tu siê dzieje?
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    vector v(10);
    v=v;    // samoprzypisanie
}

//------------------------------------------------------------------------------
