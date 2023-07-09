#include <vector>
#include <iostream>

struct Base
{
    virtual std::ostream &print(std::ostream &) const = 0; // = 0 aby klasa Base była abstrakcyjna bo std::vector<Base> v_make_err = {d1, d2, d3};
};

//Ta definicja nic nie zmieni nadal klasa Base jest abstrakcyjna
// std::ostream & Base::print(std::ostream & os) const{
//     return os;
// }

struct Derived1 : Base
{
    std::ostream &print(std::ostream &out) const override
    {
        return out << __PRETTY_FUNCTION__;
    }
};

struct Derived2 : Base //po Base bo // Derived1 d1_make_err = d2;
{
    virtual std::ostream &print(std::ostream &out) const override
    {
        return out << __PRETTY_FUNCTION__;
    }
};

struct Derived3 : Derived2
{
    std::ostream &print(std::ostream &out) const override
    { 
        return out << __PRETTY_FUNCTION__; 
    }
};

std::ostream &operator<<(std::ostream &out, const Base &base)
{
    return base.print(out);
}

std::ostream &operator<<(std::ostream &out, std::vector<Base *> v)
{
    out << "[";
    for (unsigned i = 0; i < v.size() -1; ++i){
        v[i]->print(out);
        std::cout << "," <<std::endl;
    }
    v.back()->print(out);
    out << "]\n";

    return out;
}

int main()
{
    Derived1 d1;
    Derived3 d3;
    Derived2 d2 = d3;
    // Derived1 d1_make_err = d2; //error: conversion from 'Derived2' to non-scalar type 'Derived1' requested

    // std::vector<Base> v_make_err = {d1, d2, d3}; // error: could not convert '{d1, d2, d3}' from '<brace-enclosed initializer list>' to 'std::vector<Base>'
    std::vector<Base *> v = {&d1, &d2, &d3};

    std::cout << *v.front() << std::endl;
    std::cout << v;
}
// Wynik : virtual std::ostream &Derived1::print(std::ostream &) const
//             [virtual std::ostream & Derived1::print(std::ostream &) const,
//              virtual std::ostream &Derived2::print(std::ostream &) const,
//              virtual std::ostream &Derived3::print(std::ostream &) const]