
//
// To jest przyk³adowy kod z podrozdzia³u 19.2.2 „Rezerwacja pamiêci i pojemnoœæ kontenera” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class vector {
    int sz;       // liczba elementów
    double* elem; // adres pierwszego elementu
    int space;    // liczba elementów plus „wolna przestrzeñ”
                  // dla nowych elementów („bie¿¹cy rozmiar alokacji”)
public:
    vector();
    void reserve(int newalloc);
    int  capacity() const;
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) {}

//------------------------------------------------------------------------------

void vector::reserve(int newalloc)
{
    if (newalloc<=space) return;             // Nigdy nie zmniejszaj obszaru alokacji.
    double* p = new double[newalloc];        // Alokuje now¹ przestrzeñ.
    for (int i=0; i<sz; ++i) p[i] = elem[i]; // Kopiuje stare elementy.
    delete[ ] elem;                          // Dealokuje star¹ przestrzeñ.
    elem = p;
    space = newalloc;        
}

//------------------------------------------------------------------------------

int vector::capacity() const { return space; }

//------------------------------------------------------------------------------

int main()
{
    vector v;
    v.reserve(10);
    return v.capacity();
}

//------------------------------------------------------------------------------
