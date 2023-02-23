
//
// To jest przyk�adowy kod z podrozdzia�u 17.7 �Wska�niki na obiekty klas� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

//------------------------------------------------------------------------------

// Bardzo uproszczony wektor liczb typu double.
class vector {
    int sz;            // rozmiar
    double* elem;      // wska�nik na elementy
public:
    vector(int s) :sz(s), elem(new double[s]) { } // konstruktor
    ~vector() { delete[] elem; }                  // destruktor

    int size() const { return sz; }               // bie��cy rozmiar wektora

    double get(int n) { return elem[n]; }         // dost�p: odczyt
    void set(int n, double v) { elem[n]=v; }      // dost�p: zapis
};

//------------------------------------------------------------------------------

vector* f(int s)
{
    vector v(s);
    vector* p = new vector(s); // Alokacja wektora w obszarze pami�ci wolnej.
    // ...
    *p = v;                    // Kopiowanie danych do wektora poprzez wska�nik.
    return p;
}

//------------------------------------------------------------------------------

void ff()
{
    vector* q = f(4);
    vector vv = *q;            // Kopiowanie danych z wektora poprzez wska�nik.
    // ...
    delete q;                  // Usuni�cie wektora z pami�ci wolnej.
}

//------------------------------------------------------------------------------

int main()
{
    int     s = 100;
    vector* p = new vector(s); // Alokacja wektora w obszarze pami�ci wolnej.
    delete p;                  // dealokacja

    // Przyk�ad z u�yciem standardowego wektora z biblioteki STL.
    {
        using std::vector;

        vector< vector<double> >* p
            = new vector<vector<double> > (10);
        delete p;

        vector< vector< vector<double> > >* q
            = new vector<vector<vector<double> > > (20);
        delete q;
    }

    // Wszystkie klasy obs�uguj� operator . (kropka) umo�liwiaj�cy uzyskanie dost�pu do sk�adowych.
    {
        vector v(4);
        int x = v.size();
        double d = v.get(3);
    }

    // Wszystkie klasy obs�uguj� operator -> (strza�ka) umo�liwiaj�cy uzyskanie dost�pu do sk�adowych.
    {
        vector* p = new vector(4);
        int x = p->size();
        double d = p->get(3);
    }
}

//------------------------------------------------------------------------------
