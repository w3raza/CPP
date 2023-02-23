
//
// To jest przyk³adowy kod z podrozdzia³u 17.7 „WskaŸniki na obiekty klas” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

//------------------------------------------------------------------------------

// Bardzo uproszczony wektor liczb typu double.
class vector {
    int sz;            // rozmiar
    double* elem;      // wskaŸnik na elementy
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    ~vector() { delete[] elem; }                  // destruktor

    int size() const { return sz; }               // bie¿¹cy rozmiar wektora

    double get(int n) { return elem[n]; }         // dostêp: odczyt
    void set(int n, double v) { elem[n]=v; }      // dostêp: zapis
};

//------------------------------------------------------------------------------

vector* f(int s)
{
    vector v(s);
    vector* p = new vector(s); // Alokacja wektora w obszarze pamiêci wolnej.
    // ...
    *p = v;                    // Kopiowanie danych do wektora poprzez wskaŸnik.
    return p;
}

//------------------------------------------------------------------------------

void ff()
{
    vector* q = f(4);
    vector vv = *q;            // Kopiowanie danych z wektora poprzez wskaŸnik.
    // ...
    delete q;                  // Usuniêcie wektora z pamiêci wolnej.
}

//------------------------------------------------------------------------------

int main()
{
    int     s = 100;
    vector* p = new vector(s); // Alokacja wektora w obszarze pamiêci wolnej.
    delete p;                  // dealokacja

    // Przyk³ad z u¿yciem standardowego wektora z biblioteki STL.
    {
        using std::vector;

        vector< vector<double> >* p
            = new vector<vector<double> > (10);
        delete p;

        vector< vector< vector<double> > >* q
            = new vector<vector<vector<double> > > (20);
        delete q;
    }

    // Wszystkie klasy obs³uguj¹ operator . (kropka) umo¿liwiaj¹cy uzyskanie dostêpu do sk³adowych.
    {
        vector v(4);
        int x = v.size();
        double d = v.get(3);
    }

    // Wszystkie klasy obs³uguj¹ operator -> (strza³ka) umo¿liwiaj¹cy uzyskanie dostêpu do sk³adowych.
    {
        vector* p = new vector(4);
        int x = p->size();
        double d = p->get(3);
    }
}

//------------------------------------------------------------------------------
