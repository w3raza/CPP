
//
// To jest przyk³adowy kod z podrozdzia³u 17.2 „Podstawowe wiadomoœci na temat typu Vector” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <vector>

//------------------------------------------------------------------------------

int main()
{
    using std::vector;        // U¿ycie wektora z biblioteki STL.
    vector<double> age(4);    // Wektor czterech elementów typu double.
    age[0]=0.33;
    age[1]=22.0;
    age[2]=27.2;
    age[3]=54.2;
}

//------------------------------------------------------------------------------

// Bardzo uproszczony wektor obiektów typu double (jak vector<double>).
class vector {
    int sz;                   // rozmiar
    double* elem;             // WskaŸnik pierwszego elementu (typu double).
public:
    vector(int s);            // Konstruktor: alokuje s obiektów tyupu double i
                              // sprawia, ¿e wskaŸnik elem wskazuje je.
                              // Zapisuje wartoœæ s w sz.
    int size() const { return sz; } // bie¿¹cy rozmiar wektora
};

//------------------------------------------------------------------------------
