
//
// To jest przyk³adowy kod z podrozdzia³u 17.8 „Babranie siê w typach — void* i rzutowanie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
//void v;      // B³¹d: nie ma obiektów typu void.
void f();    // Funkcja f() nie zwraca wartoœci — f() nie zwraca obiektu typu void.

//------------------------------------------------------------------------------

int main()
{
    void* pv1 = new int;        // Dobrze: int* konwertuje siê na void*.
    void* pv2 = new double[10];  // Dobrze: double* konwertuje siê na void*.
}

//------------------------------------------------------------------------------

void f(void* pv)
{
    void* pv2 = pv;   // Kopiowanie jest dozwolone (do tego w³aœnie s³u¿y typ void*).
    //double* pd = pv;  // B³¹d: nie mo¿na przekonwertowaæ void* na double*.
    //*pv = 7;          // B³¹d: nie mo¿na wykonaæ dereferencji typu void*
                      // (nie wiadomo jakiego typu obiekt wskazuje).
    //pv[2] = 9;        // B³¹d: nie mozna indeksowaæ typu void*.
    int* pi = static_cast<int*>(pv);    // Dobrze: jawna konwersja.
                      // ...
}

//------------------------------------------------------------------------------

struct Register;
struct Buffer;

Register* in = reinterpret_cast<Register*>(0xff);

//------------------------------------------------------------------------------

void f(const Buffer* p)
{
    Buffer* b = const_cast<Buffer*>(p);
    // ...
}

//------------------------------------------------------------------------------
