#include <utility> // dla std::pair
/*Uzupełnij*/
#include <iostream>

template <class T = float>
struct Type_t
{
    T _v;
    operator float()
    {
        return static_cast<float>(_v);
    }
};

template <typename T>
struct ptr
{
private:
    T *_p;

public:
    using value_type = T;
    ptr(T *p) : _p(p) {}
    ptr(ptr &&new_obj) : _p(std::exchange(new_obj._p, nullptr)) {}
    T operator*() const
    {
        return *_p;
    }

    T *operator->() const
    {
        return _p;
    }

    // bez tego fisrt = 0
    T &operator*()
    {
        return *_p;
    }

    ~ptr() { delete[] _p; }
};

using Float_t = Type_t<>;

int main()
{
    using Test_t = ptr<std::pair<Float_t, Float_t>>; //

    Test_t t1{new Test_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t2; t2 = t1;
    // Type_t t2 = new Type_t::value_type{};
    //  Powyższe się mają nie kompilować
    (*t1).first = Test_t::value_type::first_type{1.};
    t1->second = Test_t::value_type::second_type{2.5};

    Test_t t2 = std::move(t1);
    std::cout << (*t2).first << ", " << t2->second._v << "\n";

    const Test_t t3 = std::move(t2);
    //(*t3).first= 13;
    // t3->second = 13;
    // Powyższe się mają nie kompilować
    //(*t3).first = Test_t::value_type::first_type{1};   //?
    // t3->second = Test_t::value_type::second_type{2.5}; //?

    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
1, 2.5
*/