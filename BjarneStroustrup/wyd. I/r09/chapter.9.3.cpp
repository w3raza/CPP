
//
// To jest przyk�adowy kod z podrozdzia�u 9.3 �Interfejs i implementacja� ksi��ki 
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
    //int y = x.mf(); // B��d: funkcja mf() jest prywatna (tzn. niedost�pna).
    int y = x.f(2);
    return y;
}

//------------------------------------------------------------------------------
