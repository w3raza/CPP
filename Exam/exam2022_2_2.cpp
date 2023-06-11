#include <iostream>

template<typename T>
struct B;

template<typename T>
struct B// U1
{
    //U2
    using value_type = T;
    B(T val) :_v{val} {}
    value_type get() const { return _v; }

private:
    value_type _v = value_type();
};

template<typename T>
struct B<T*>// U3
{
    //U4
    using value_type = T;
    B(T* ptr) : _p{ptr} {}
    B(const T&) = delete;
    value_type get() const { return *_p; }

private:
    value_type* _p;//U5
};

int main()
{
    //using int_b = B<int>;       //
    //using int_p_b = B<int*>;    //nie pamiętam czy using czy typedef
    typedef B<int> int_b;
    typedef B<int*> int_p_b;        //jednak typedef

    int_b a(1);
    int_b a_copy(a);
    int_p_b b(new int_p_b::value_type{2});
    // int_p_b e = b; //error
    // b=b //error
    
    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
    std::cout << "b=" << b.get()+1 << std::endl;
}
/*
a=1
a_copy=2
b=3
*/

// #include <iostream>

// template<typename T>
// struct B;

// template<typename T>
// struct // U1
// {
//     //U2
// private:
//     value_type _v = value_type();
// };

// template<typename T>
// struct // U3
// {
//     //U4
// private:
//     value_type //U5
// };

// int main()
// {
//     //using int_b = B<int>;       //
//     //using int_p_b = B<int*>;    //nie pamiętam czy using czy typedef
//     typedef B<int> int_b
//     typedef B<int> int_p_b        //jednak typedef

//     int_b a(2);
//     int_b a_copy(a);
//     int_p_b b(new int_p_b::value_type{2});
//     // int_p_b e = b; //error
//     // b=b //error
    
//     std::cout << "a=" << a.get() << std::endl;
//     std::cout << "a_copy=" << a_copy.get()+1 << std::endl;
//     std::cout <<" c=" << c.get()+1 << std::endl;
// }
// /*
// a=1
// a_copy=2
// b=3
// */