
//
// To jest przyk�adowy kod z podrozdzia�u 25.3.3 �Przyk�ad zastosowania puli" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class T, int N> 
class Pool                 // Pula N obiekt�w typu T.
{
public:
    Pool();                // Tworzy pul� n obiekt�w typu T.
    T* get();              // Pobiera element T z puli. Zwraca warto�� 0, je�li nie ma wolnych T.
    void free(T*);         // Zwraca do puli T wydany przez funkcj� get().
    int available() const; // Liczba wolnych T.
private:
    // Przestrze� dla T[N] i danych do �ledzenia, kt�re T s� alokowane,
    // a kt�re nie (np. lista wolnych obiekt�w).
};

//------------------------------------------------------------------------------

class Small_buffer;
class Status_indicator;

//------------------------------------------------------------------------------

int main()
{
    Pool<Small_buffer,10> sb_pool;
    Pool<Status_indicator,200> indicator_pool;

    Small_buffer* p = sb_pool.get();
    // ...
    sb_pool.free(p);
}

//------------------------------------------------------------------------------
