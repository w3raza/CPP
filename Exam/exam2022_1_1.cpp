#include <iostream>

struct B
{
    friend std::ostream &operator<<(std::ostream &o, const B &b);

    //bo // B b ERROR
    virtual std::ostream &printOn(std::ostream &o) const = 0;
};

std::ostream & B::printOn(std::ostream &o) const 
{
        return o << __PRETTY_FUNCTION__ << "\n";
}

std::ostream &operator<<(std::ostream &o, const B &b)
{
    return b.printOn(o);
}

class D1 : public B
{
protected:
    std::ostream &printOn(std::ostream &o) const override
    {
        return o << __PRETTY_FUNCTION__ << "\n";
    }
};

/*
* D2 dziedziczy swoją implementację printOn() od D1, ponieważ sama nie dostarcza implementacji.
*/
struct D2 : public D1
{
    //nic bo ma się wywołać printOn z D1, a nie moze byc klasa abstrakcyjna bo jest jej deklaracja w main
};

class D3 : public D1
{
protected:
    std::ostream &printOn(std::ostream &o) const override
    {
        return o << __PRETTY_FUNCTION__ << "\n";
    }
};

/*
* D4 dziedziczy po D3, ale dostarcza swoją własną implementację printOn(), która wywołuje printOn() z B, D1 i D3.
* D4 ma dostęp do składowych D3, D1 i B (ponieważ D3 dziedziczy po D1, a D1 dziedziczy po B). 
Innymi słowy, kiedy klasa A dziedziczy po klasie B, klasa A nie ma dostępu do składowych innej klasy C, 
nawet jeśli C również dziedziczy po B. Aby A miało dostęp do składowych C, A musiałoby dziedziczyć bezpośrednio po C.
*/
struct D4 : public D3
{
protected:
    std::ostream &printOn(std::ostream &o) const override
    {
        B::printOn(o);
        D1::printOn(o);
        D3::printOn(o);
        return o << __PRETTY_FUNCTION__ << "\n";
    }
};

int main()
{
    // B b; // Nie można utworzyć obiektu B, ponieważ B ma funkcję wirtualną
    D1 d1;
    D2 d2;
    D3 d3;
    const D4 d4;
    std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}


// // Uzupełnij. Nie wolno uzywać słowa kluczowego public (Tu jest błąd, mozna, inaczej się nie da)
// #include <iostream>

// struct B
// {
// //Uzupełnij tylko deklaracja jeden lub dwa
// };

// //Uzupełnij tylko definicja jeden lub dwa

// class D1 : //Uzupełnij
// {
// //Uzupełnij tylko deklaracja jeden
// };

// struct D2 : //Uzupełnij
// {
// //Uzupełnij tylko deklaracja jeden
// };

// class D3 : //Uzupełnij
// {
// //Uzupełnij tylko deklaracja jeden
// };

// struct D4 : //Uzupełnij
// {
// //Uzupełnij tylko deklaracja jeden
// };

// int main()
// {
//     // B b ERROR
//     D1 d1;
//     D2 d2;
//     D3 d3;
//     const D4 d4;
//     std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
// }
// /*
// d1: virtual std::ostream& D1::printOn(std::ostream&) const
// d2: virtual std::ostream& D1::printOn(std::ostream&) const
// d3: virtual std::ostream& D3::printOn(std::ostream&) const
// d4: virtual std::ostream& B::printOn(std::ostream&) const
// virtual std::ostream& D1::printOn(std::ostream&) const
// virtual std::ostream& D3::printOn(std::ostream&) const
// virtual std::ostream& D4::printOn(std::ostream&) const
// */