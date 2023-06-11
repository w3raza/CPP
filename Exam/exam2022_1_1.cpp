// 1 z public
#include <iostream>

struct B
{
protected:
    friend std::ostream &operator<<(std::ostream &o, const B &b);

    virtual std::ostream &printOn(std::ostream &o) const = 0;
};

std::ostream &operator<<(std::ostream &o, const B &b)
{
    return b.printOn(o);
}

std::ostream &B::printOn(std::ostream &o) const
{
    return o << __PRETTY_FUNCTION__ << "\n";
}

class D1 : public B
{
protected:
    std::ostream &printOn(std::ostream &o) const
    {
        return o << __PRETTY_FUNCTION__ << "\n";
    }
};

struct D2 : public D1
{
};

class D3 : public D1
{
protected:
    std::ostream &printOn(std::ostream &o) const
    {
        return o << __PRETTY_FUNCTION__ << "\n";
    }
};

struct D4 : public D3
{
protected:
    std::ostream &printOn(std::ostream &o) const
    {
        B::printOn(o);
        D1::printOn(o);
        D3::printOn(o);
        return o << __PRETTY_FUNCTION__ << "\n";
    }
};

int main()
{
    // B b
    D1 d1;
    D2 d2;
    D3 d3;
    const D4 d4;
    std::cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << "d4: " << d4;
}
/*
d1: virtual std::ostream& D1::printOn(std::ostream&) const
d2: virtual std::ostream& D1::printOn(std::ostream&) const
d3: virtual std::ostream& D3::printOn(std::ostream&) const
d4: virtual std::ostream& B::printOn(std::ostream&) const
virtual std::ostream& D1::printOn(std::ostream&) const
virtual std::ostream& D3::printOn(std::ostream&) const
virtual std::ostream& D4::printOn(std::ostream&) const
*/