
//
// To jest przyk³adowy kod z podrozdzia³u 19.3.5 „Dedukcja argumentów szablonu” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class T, int N> struct array {
    T elem[N];                  // Przechowuje elementy w tablicy sk³adowej.

    // Polega na domyœlnych konstruktorach, destruktorze i przypisaniu.

    T& operator[ ] (int n) { return elem[n]; } // dostêp: zwraca referencjê
    const T& operator[ ] (int n) const { return elem[n]; }

    T* data() { return elem; }  // konwersja na T*
    const T* data() const { return elem; }

    int size() const  { return N; }    
};

//------------------------------------------------------------------------------

array<char,1024> buf;    // Dla buf T jest char, a N wynosi 1024.
array<double, 10> b2;    // Dla b2 T jest double, a N wynosi 10.

template<class T, int N> void fill(array<T,N>& b, const T& val)
{
    for (int i = 0; i<N; ++i) b[i] = val;
}

//------------------------------------------------------------------------------

void f()
{
    fill(buf, 'x');      // Dla fill() T jest char, a N wynosi 1024,
                         // poniewa¿ to zawiera buf.
    fill(b2,0.0);        // Dla fill() T jest double, a N wynosi 10,
                         // poniewa¿ to zawiera b2.
}

//------------------------------------------------------------------------------

int main()
{
    f();
}

//------------------------------------------------------------------------------
