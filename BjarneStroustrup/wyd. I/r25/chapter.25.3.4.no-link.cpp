
//
// To jest przyk�adowy kod z podrozdzia�u 25.3.4 �Przyk�ad u�ycia stosu� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <stddef.h> 

//------------------------------------------------------------------------------

template<int N>class Stack { // Stos N bajt�w.
public:
    Stack();                 // Tworzy stos N bajt�w.
    void* get(int n);        // Alokuje n bajt�w na stosie.
                             // Zwraca 0, je�li nie ma wolnego miejsca.
    void free();             // Zwraca na stos ostatni� warto�� zwr�con� przez get().
    int available() const;   // Liczba dost�pnych bajt�w.
private:
    // Przestrze� dla char[N] i danych do �ledzenia, co zosta�o alokowane,
    // a co nie (np. wska�nik wskazuj�cy wierzch stosu).
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
    Stack<50*1024> my_free_store; // 50 KB pami�ci zosta�o zarezerwowanych dla stosu.

    void* pv1 = my_free_store.get(1024);
    int* buffer = static_cast<int*>(pv1);  

    void* pv2 = my_free_store.get(sizeof(Connection));
    Connection* pconn = new(pv2) Connection(incoming,outgoing,buffer);
}

//------------------------------------------------------------------------------
