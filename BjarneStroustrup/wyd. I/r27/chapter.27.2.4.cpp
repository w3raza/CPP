
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.2.4 "Wywo³ywanie C z poziomu C++ i C++ z poziomu C" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

// Wywo³anie funkcji C z poziomu C++.

extern "C" double sqrt(double);    // £¹czy jako funkcjê C.

//------------------------------------------------------------------------------

void my_c_plus_plus_fct()
{
    double sr = sqrt(2);
}

//------------------------------------------------------------------------------

struct S
{
    int f(int n) const { return n*n; }
};

//------------------------------------------------------------------------------

// Funkcja C++ daj¹ca siê wywo³ywaæ z poziomu C.

extern "C" int call_f(S* p, int i)
{
    return p->f(i);
}

//------------------------------------------------------------------------------

/* Wywo³anie funkcji C++ z poziomu C.

int call_f(S* p, int i);
struct S* make_S(int,const char*); 

void my_c_fct(int i)
{
    /* ... */
    struct S* p = make_S(i, "foo");
    int x = call_f(p,i);
    /* ... */
}

//------------------------------------------------------------------------------

#ifdef __cplusplus

// W C++:
class complex {
    double re, im;
public:
    // Wszystkie typowe operacje.
};

#else

/* W C: */
struct complex {
    double re, im;
    /* brak operacji */
};

#endif 

//------------------------------------------------------------------------------

int main()
{
    my_c_fct(42);
}

//------------------------------------------------------------------------------

struct S* make_S(int,const char*)
{
    return new S;
}

//------------------------------------------------------------------------------
