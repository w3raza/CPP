
//
// To jest przyk³adowy kod z podrozdzia³u 21.4.1 „Abstrakcyjne spojrzenie na obiekty funkcyjne” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

typedef int S;
typedef double T;

//------------------------------------------------------------------------------

class F { // Abstrakcyjny przyk³ad obiektu funkcyjnego.
    S s;  // stan
public:
    F(const S& ss) :s(ss) { /* ustala stan pocz¹tkowy */ }
    T operator() (const S& ss) const
    {
        // Operacje na ss przekazanym do s.
        // Zwraca wartoœæ typu T (T jest czêsto, bool lub S).
        return ss*ss;
    }

    const S& state() const { return s; } // ujawnia stan
    void reset(const S& ss) { s = ss; }  // resetuje stan
};

//------------------------------------------------------------------------------

int main()
{
    S s = 0;
    F f(s); // tworzy F
    f(s);   // stosuje f
}

//------------------------------------------------------------------------------
