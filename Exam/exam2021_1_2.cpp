#include <utility> // dla std::pair
#include <iostream>

/*Uzupełnij*/

template<typename T>
struct ptr
{
    private:
        T* _p;

    public:
        using value_type = T;

        explicit ptr(T* object) : _p(object) {}

        ptr(const ptr& object) = delete;

        ptr(ptr&& object)
        {
            _p = object._p;
            object._p = nullptr;
        }

        ~ptr() { delete _p; };

        ptr& operator=(const ptr& object) = delete;
        ptr& operator=(ptr&& object) = delete;

        T& operator*() const { return *_p; }
        T* operator->() const { return _p; }

};

template<typename T = float>
struct Type_t
{
        T _v;

        Type_t() = default;
        explicit Type_t(T x) : _v(x) {}

        friend std::ostream& operator<<(std::ostream& os, const Type_t& t) { return os << t._v; }

};



using Float_t = Type_t<>;

int main()
{
    using Type_t = ptr<std::pair<Float_t, Float_t>>; //

    Type_t t1{new Type_t::value_type{}};
    // Type_t t2 = t1;
    // Type_t t2; t2 = t1;
    // Type_t t2 = new Type_t::value_type();
    // Powyższe się mają nie kompilować
    (*t1).first = Type_t::value_type::first_type{1.};
    t1->second = Type_t::value_type::second_type{2.5};

    Type_t t2 = std::move(t1);

    // t3=std::move(t2); // wydaje mi się, że tej linijki nie było
    const Type_t t3 = std::move(t2);                                  // tutaj było chyba const t3, ale nie pamiętam, w jaki sposób było inicjalizowane
    //                                                    //(*t3).first= 13;
    //                                                    // t3->second = 13;
    //                                                    // Powyższe się mają nie kompilować
    (*t3).first = Type_t::value_type::first_type{1};   //?
    t3->second = Type_t::value_type::second_type{2.5}; //?

    // // std::cout<< /*?Ktos pamięta?*/
    std::cout << (*t3).first._v << ", " << t3->second << std::endl;
}
/* output:
1, 2.5
1, 2.5
*/

// #include <utility> // dla std::pair
// /*Uzupełnij*/
// #include <iostream>
// using Float_t = type_t<>;

// int main()
// {
//     using Type_t = ptr<std::pair<Float_t, Float_t>>; //

//     Type_t t1{new Type_t::value_type{}};
//     // Type_t t2 = t1;
//     // Type_t t2; t2 = t1;
//     // Type_t t2 = new Type_t::value_type();
//     // Powyższe się mają nie kompilować
//     (*t1).first = Type_t::value_type::type_first{1.};
//     t1->second = Type_t::value_type::type_second{2.5};

//     Type_t t2 = std::move(t1);

//     // t3=std::move(t2); // wydaje mi się, że tej linijki nie było
//     const Type_t t3;                                   // tutaj było chyba const t3, ale nie pamiętam, w jaki sposób było inicjalizowane
//                                                        //(*t3).first= 13;
//                                                        // t3->second = 13;
//                                                        // Powyższe się mają nie kompilować
//     (*t3).first = Type_t::value_type::first_type{1};   //?
//     t3->second = Type_t::value_type::second_type{2.5}; //?

//     // std::cout<< /*?Ktos pamięta?*/
//     std::cout << (*t3).first._v << ", " << t3->second << std::endl;
// }
// /* output:
// 1, 2.5
// 1, 2.5
// */

