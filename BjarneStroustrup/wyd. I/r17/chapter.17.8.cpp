
//
// To jest przyk�adowy kod z podrozdzia�u 17.8 �Babranie si� w typach � void* i rzutowanie� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------
//void v;      // B��d: nie ma obiekt�w typu void.
void f();    // Funkcja f() nie zwraca warto�ci � f() nie zwraca obiektu typu void.

//------------------------------------------------------------------------------

int main()
{
    void* pv1 = new int;        // Dobrze: int* konwertuje si� na void*.
    void* pv2 = new double[10];  // Dobrze: double* konwertuje si� na void*.
}

//------------------------------------------------------------------------------

void f(void* pv)
{
    void* pv2 = pv;   // Kopiowanie jest dozwolone (do tego w�a�nie s�u�y typ void*).
    //double* pd = pv;  // B��d: nie mo�na przekonwertowa� void* na double*.
    //*pv = 7;          // B��d: nie mo�na wykona� dereferencji typu void*
                      // (nie wiadomo jakiego typu obiekt wskazuje).
    //pv[2] = 9;        // B��d: nie mozna indeksowa� typu void*.
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
