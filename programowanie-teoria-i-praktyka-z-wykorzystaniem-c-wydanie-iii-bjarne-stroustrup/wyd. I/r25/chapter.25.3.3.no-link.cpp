
//
// To jest przyk³adowy kod z podrozdzia³u 25.3.3 „Przyk³ad zastosowania puli" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

template<class T, int N> 
class Pool                 // Pula N obiektów typu T.
{
public:
    Pool();                // Tworzy pulê n obiektów typu T.
    T* get();              // Pobiera element T z puli. Zwraca wartoœæ 0, jeœli nie ma wolnych T.
    void free(T*);         // Zwraca do puli T wydany przez funkcjê get().
    int available() const; // Liczba wolnych T.
private:
    // Przestrzeñ dla T[N] i danych do œledzenia, które T s¹ alokowane,
    // a które nie (np. lista wolnych obiektów).
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
