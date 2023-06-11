#include <iostream>

struct A {
    A() {
        A(0);
        std::cout << "A();";
    }

    A(const A& a) {
        A(a._a);
        std::cout << "A(const A&);";
    }

    A(int a) : _a(a) {
        std::cout << "A(int a);";
    }

private:
    int _a = 0;
};

int main() {
    A a;
    a = A();
}
