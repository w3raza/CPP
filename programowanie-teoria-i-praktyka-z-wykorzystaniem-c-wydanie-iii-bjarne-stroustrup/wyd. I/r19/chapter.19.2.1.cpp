
//
// To jest przyk³adowy kod z podrozdzia³u 19.2.1 „Reprezentacja” ksi¹¿ki
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
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) { }

int main()
{
    vector v;
}

//------------------------------------------------------------------------------
