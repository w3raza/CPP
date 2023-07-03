#include <iostream>

struct Test1
{
    Test1() { std::cout << "test1 "; }
};

struct Test2
{
    Test2() { std::cout << "test2 "; }
};

struct O
{
    O()
    {
        std::cout << "O ";
    }
};

struct A
{
    A() { std::cout << "A "; }
};
struct B
{
    B() { std::cout << "B "; }
};
struct X : public A, virtual B, virtual O
{
    X() { std::cout << "X "; }
    // Test2 t;
};
struct Y : virtual A, B
{
    Y() { std::cout << "Y "; }
    // Test1 t;
};
struct Z : public Y, public X
{
    Z() { std::cout << "Z "; }
};
;

int main()
{
    Z z;
}
// A B O B Y A X Z