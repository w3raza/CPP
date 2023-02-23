
//
// To jest przyk³adowy kod z podrozdzia³u 25.3.4 „Przyk³ad u¿ycia stosu” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <stddef.h> 

//------------------------------------------------------------------------------

template<int N>class Stack { // Stos N bajtów.
public:
    Stack();                 // Tworzy stos N bajtów.
    void* get(int n);        // Alokuje n bajtów na stosie.
                             // Zwraca 0, jeœli nie ma wolnego miejsca.
    void free();             // Zwraca na stos ostatni¹ wartoœæ zwrócon¹ przez get().
    int available() const;   // Liczba dostêpnych bajtów.
private:
    // Przestrzeñ dla char[N] i danych do œledzenia, co zosta³o alokowane,
    // a co nie (np. wskaŸnik wskazuj¹cy wierzch stosu).
};

//------------------------------------------------------------------------------

class Port;
class Buffer;

//------------------------------------------------------------------------------

class Connection
{
public:
    Connection(Port* in, Port* out, int* buf);
    void* operator new(size_t size, void* place);
};

//------------------------------------------------------------------------------

extern Port* incoming;
extern Port* outgoing;

//------------------------------------------------------------------------------

int main()
{
    Stack<50*1024> my_free_store; // 50 KB pamiêci zosta³o zarezerwowanych dla stosu.

    void* pv1 = my_free_store.get(1024);
    int* buffer = static_cast<int*>(pv1);  

    void* pv2 = my_free_store.get(sizeof(Connection));
    Connection* pconn = new(pv2) Connection(incoming,outgoing,buffer);
}

//------------------------------------------------------------------------------
