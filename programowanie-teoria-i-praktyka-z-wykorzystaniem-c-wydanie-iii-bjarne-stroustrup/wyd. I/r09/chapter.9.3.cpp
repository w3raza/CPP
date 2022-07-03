
//
// To jest przyk³adowy kod z podrozdzia³u 9.3 „Interfejs i implementacja” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class X {
    int m;
    int mf() { return m; }
public:
    int f(int i) { m=i; return mf(); }
};

//------------------------------------------------------------------------------

int main()
{
    X x;
    //int y = x.mf(); // B³¹d: funkcja mf() jest prywatna (tzn. niedostêpna).
    int y = x.f(2);
    return y;
}

//------------------------------------------------------------------------------
