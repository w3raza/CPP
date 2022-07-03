
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.3.3 „Definicje” ksi¹¿ki
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

    // Jêzyk C++ pozwala na umieszczanie definicji w wiêkszej liczbie ró¿nych miejsc ni¿ C.
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
    if (i< 0 || max<=i) error("B³¹d zakresu");
    int a[max];    // B³¹d: w jêzyku C za instrukcj¹ nie mo¿e znajdowaæ siê deklaracja.
    /* ... */
}

#else

void f(int i)
{
    if (i< 0 || max<=i) error("B³¹d zakresu");
    {
        int a[max];
        /* ... */
    }
}

int x;
int x;  /* W jêzyku C definiuje lub deklaruje liczbê ca³kowit¹ o nazwie x. W jêzyku C++ to jest b³¹d. */

#endif

//------------------------------------------------------------------------------
