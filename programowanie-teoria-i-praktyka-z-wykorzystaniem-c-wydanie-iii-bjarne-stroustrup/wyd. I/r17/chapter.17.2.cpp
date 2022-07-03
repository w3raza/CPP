
//
// To jest przyk�adowy kod z podrozdzia�u 17.2 �Podstawowe wiadomo�ci na temat typu Vector� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

//------------------------------------------------------------------------------

int main()
{
    using std::vector;        // U�ycie wektora z biblioteki STL.
    vector<double> age(4);    // Wektor czterech element�w typu double.
    age[0]=0.33;
    age[1]=22.0;
    age[2]=27.2;
    age[3]=54.2;
}

//------------------------------------------------------------------------------

// Bardzo uproszczony wektor obiekt�w typu double (jak vector<double>).
class vector {
    int sz;                   // rozmiar
    double* elem;             // Wska�nik pierwszego elementu (typu double).
public:
    vector(int s);            // Konstruktor: alokuje s obiekt�w tyupu double i
                              // sprawia, �e wska�nik elem wskazuje je.
                              // Zapisuje warto�� s w sz.
    int size() const { return sz; } // bie��cy rozmiar wektora
};

//------------------------------------------------------------------------------
