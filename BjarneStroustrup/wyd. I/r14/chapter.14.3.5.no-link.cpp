
//
// To jest przyk�adowy kod z podrozdzia�u 14.3.5 �Czyste funkcje wirtualne� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class B {    // Abstrakcyjna klasa bazowa.
public:
    virtual void f() = 0;    // Funkcja czysto wirtualna
    virtual void g() = 0;
};

//B b;    // B��d: B jest klas� abstrakcyjn�.

//------------------------------------------------------------------------------

class D1 : public B { 
public:

    void f();
    void g();
};

D1 d1;        // ok

//------------------------------------------------------------------------------

class D2 : public B { 
public:

    void f();
    // no  g() 
};

//D2 d2;        // B��d: D2 jest (nadal) klas� abstrakcyjn�.

//------------------------------------------------------------------------------

class D3 : public D2 { 
public:

    void g();
};

D3 d3;     // ok

//------------------------------------------------------------------------------
