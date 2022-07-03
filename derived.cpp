#include <vector>
#include <iostream>

struct Base
{
    virtual std::ostream &print(std::ostream &) const = 0;
};

struct Derived1 : Base
{
    std::ostream &print(std::ostream &out) const
    {
        return out << "virtual std::ostream &Derived1::print(std::ostream &) const,";
    }
};

struct Derived2 : Base
{
    std::ostream &print(std::ostream &out) const
    {
        return out << "\nvirtual std::ostream &Derived2::print(std::ostream &) const,\n";
    }
};

struct Derived3 : Derived2
{
    std::ostream &print(std::ostream &out) const { return out << "virtual std::ostream &Derived3::print(std::ostream &) const\n"; }
};

std::ostream &operator<<(std::ostream &out, const Base &base)
{
    return base.print(out);
}

std::ostream &operator<<(std::ostream &out, std::vector<Base *> v)
{
    out << "[";
    for (unsigned i = 0; i < v.size(); ++i)
        out << *v[i];
    out << "]\n";

    return out;
}

int main()
{
    Derived1 d1;
    Derived3 d3;
    Derived2 d2 = d3;
    // Derived1 d1_make_err = d2;

    // std::vector<Base> v_make_err = {d1, d2, d3};
    std::vector<Base *> v = {&d1, &d2, &d3};

    std::cout << *v.front() << std::endl;
    std::cout << v;
}
// Wynik : virtual std::ostream &Derived1::print(std::ostream &) const
//             [virtual std::ostream & Derived1::print(std::ostream &) const,
//              virtual std::ostream &Derived2::print(std::ostream &) const,
//              virtual std::ostream &Derived3::print(std::ostream &) const]
