
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.3.3 �Definicje� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

struct S {};

//------------------------------------------------------------------------------

struct S* next(struct S* p) { return p; }

//------------------------------------------------------------------------------

int main()
{
    const int max = 10;
    int x[max];
    int y[max];
    struct S* q = 0;

    // J�zyk C++ pozwala na umieszczanie definicji w wi�kszej liczbie r�nych miejsc ni� C.
    for (int i = 0; i<max; ++i) x[i] = y[i];    // Definicja i nie dozwolona w C.

    while (struct S* p = next(q)) {        // Definicja p nie dozwolona w C.
        /* ... */
    }

    int i;
    for (i = 0; i<max; ++i) x[i] = y[i];

    struct S* p;
    while (p = next(q)) {
        /* ... */
    }
}

//------------------------------------------------------------------------------

extern void error(const char*) {}
const int max = 10;

//------------------------------------------------------------------------------

#ifdef __cplusplus

void f(int i)
{
    if (i< 0 || max<=i) error("B��d zakresu");
    int a[max];    // B��d: w j�zyku C za instrukcj� nie mo�e znajdowa� si� deklaracja.
    /* ... */
}

#else

void f(int i)
{
    if (i< 0 || max<=i) error("B��d zakresu");
    {
        int a[max];
        /* ... */
    }
}

int x;
int x;  /* W j�zyku C definiuje lub deklaruje liczb� ca�kowit� o nazwie x. W j�zyku C++ to jest b��d. */

#endif

//------------------------------------------------------------------------------
