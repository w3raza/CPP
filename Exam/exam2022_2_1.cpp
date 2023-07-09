#include<iostream>

using namespace std;

struct A
{
    A(int a, int b) : _a(a), _b(b) {cout << __PRETTY_FUNCTION__ << " _a=" << _a << " _b=" << _b << "\n";}
    explicit A(int a) : A(a,0) {cout << __PRETTY_FUNCTION__ << " _a=" << _a << " _b=" << _b << "\n";} //explicit bo A f = 1;
    A() : A(0,0) {cout << __PRETTY_FUNCTION__ << " _a=" << _a << " _b=" << _b << "\n";}
    //'constexpr A::A(const A&)' is implicitly declared as deleted because 'A' declares a move constructor or move assignment operator
    A(A&& obj) : _a(obj._a),_b(obj._b) {cout << __PRETTY_FUNCTION__ << " _a=" << _a << " _b=" << _b << "\n";} //bo A d = std::move(c);
private:
    int _a=0, _b=0;
};

int main()
{
    cout << "a->"; A a;
    cout << "b->"; A b(1);
    cout << "c->"; A c(1,2);

    cout << "d->"; A d = std::move(c);

    //A e = c;
    //A f = 1;
}
/*
a-> A::A(int,int): _a=0,_b=0
A::A(): _a=0,_b=0
b-> A::A(int,int): _a=1,_b=0
A::A(int): _a=1,_b=0
c-> A::A(int,int): _a=1,_b=2
d-> A::[...]: _a=1,_b=2
*/

// #include<iostream>

// //U1 tylko jedna linijka i jeden średnik

// struct A
// {
// //U2
// //tylko konstruktory, zakaz użycia delete, w {} tylko printowanie __PRETTY_FUNCTION__ (oraz _a,_b)
// private:
//     int _a=0, _b=0;
// };

// int main()
// {
//     cout << "a->"; A a;
//     cout << "b->"; A b(1);
//     cout << "c->"; A c(1,2);

//     cout << "d->"; A d = std::move(c);

//     //A e = c;
//     //A f = 1;
// }
// /*
// a-> A::A(int,int): _a=0,_b=0
// A::A(): _a=0,_b=0
// b-> A::A(int,int): _a=1,_b=0
// A::A(int): _a=1,_b=0
// c-> A::A(int,int): _a=1,_b=2
// d-> A::[...]: _a=1,_b=2
// */