// 2
#include <iostream>
#include <list>

template <typename T, typename F>
void print_to_if(std::ostream &o, T s, T e, F f)
{
    for (; s != e; s++)
    {
        if (f(*s))
        {
            o << *s;
            o << ", ";
        }
    }
    o << "\n";
}

template <typename T, typename F>
void change(T s, T e, F f)
{
    for (; s != e; s++)
    {
        f(*s);
    }
}

bool f1(int x) { return true; }
bool f2(int x) { return !(x % 2); }

struct f3
{
    f3(int value) : _val(value) {}

    void operator()(int &x)
    {
        x += _val;
    }

    int _val;
};

int main()
{
    const auto c1 = {1, 2, 3, 4, 5, 6, 7};

    print_to_if(std::cout << "All: ", begin(c1), end(c1), f1);
    print_to_if(std::cout << "Even: ", begin(c1), end(c1), f2);
    int add_value{-1};
    std::list<int> c12 = {7, 6, 5, 4, 3, 2, 1};
    change(begin(c12), end(c12), f3{add_value});

    print_to_if(std::cout << "All: ", begin(c12), end(c12), f1);
}
/*
All: 1,2,3,4,5,6,7,
Even: 2,4,6,
All: 6,5,4,3,2,1,0,
*/

// /* 
// Proszę dokończyć program tylko w podanych miejscach i zgodnie z podanymi warunkami, tak aby wyjście programi było takie jak podany na w komantarzu na końcu kodu. W rozwiązaniach proszę uywać C++ w standardzie przynajmniej C++11 lub 14, wszędzie tam gdzie jest to moliwe i uzasadnione. Prosze podać naprostszą mozliwa działającą implementację. Proszę dokładnie uzasadnić odpowiedź.
// */

// #include <iostream>
// #include <list>

// template</*U1*/>
// void print_to_if(/*U2*/){
//     /*U3*/
// }

// template</*U4*/>
// void change(/*U5*/){
//     /*U6*/
// }

// /* U7 - mogą być tylko definicję f1, f2, f3 */

// int main()
// {
//     const auto c1 = {1, 2, 3, 4, 5, 6, 7};

//     print_to_if(std::cout << "All: ", begin(c1), end(c1), f1);
//     print_to_if(std::cout << "Even: ", begin(c1), end(c1), f2);
//     int add_value{-1};
//     std::list<int> c12 = {7, 6, 5, 4, 3, 2, 1};
//     change(begin(c12), end(c12), f3{add_value});

//     print_to_if(std::cout << "All: ", begin(c12), end(c12), f1);
// }
// /*
// All: 1,2,3,4,5,6,7,
// Even: 2,4,6,
// All: 6,5,4,3,2,1,0,
// */