#include <iostream>
#include <utility> //std::exchange

template<typename T>
struct C;

template<typename T>
struct C
{
    using value_type = T;
private:
    value_type _c;
public:
    C(const T& el) : _c(el){}
    C(const C& other) : _c(other._c){}
    
    T get() const{
        return _c;
    }
};

template<typename T>
struct C<T*>
{
    using value_type = T;
    C(T* el): _c(el){}
    //C(C&& other): _c(std::exchange(other._c, nullptr)){}
    C(C&& other): _c(std::move(other._c)){
        other._c = nullptr; //c3=0
    }
    C(const C& other) = delete;
    C& operator=(const C& other) = delete;
    
    T* get() const{
        return _c;
    }
private:
    value_type* _c;
};

int main()
{
    typedef C<int> int_c;
    typedef C<int*> int_p_c;  

    int_c c1(10);
    int_c c2(c1);

    int_p_c c3(new int(20));
    int_p_c c4(std::move(c3));

    // int_p_c c5 = c3; // error
    // c4 = c3; // error

    std::cout << "c1=" << c1.get() << std::endl;
    std::cout << "c2=" << c2.get() + 5 << std::endl;
    std::cout << "c3=" << (c3.get() ? *c3.get() : 0) << std::endl; // should print 0 because c3 has been moved
    std::cout << "c4=" << *c4.get() + 10 << std::endl;
}
/*
c1=10
c2=15
c3=0
c4=30
*/

/*
Proszę uzupełnić program, stosując standard nie niższy niż C++14, tylko w podanych miejscach 
i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
komentarzu na końcu kodu. Proszę podać najprostszą możliwą poprawnie działającą 
implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi użycie 
konstrukcji. Brak poprawnego uzasadnienia lub niespełnienie warunków jest równoznaczne z 
brakiem odpowiedzi.
*/

// #include <iostream>

// template<typename T>
// struct C;

// template<typename T>
// struct // U1
// {
//     //U2
// private:
//     value_type // U3
// public:
//     //U4
// };

// template<typename T>
// struct // U5
// {
//     //U6
// private:
//     value_type // U7
// };

// int main()
// {
//     typedef C<int> int_c;
//     typedef C<int*> int_p_c;  

//     int_c c1(10);
//     int_c c2(c1);

//     int_p_c c3(new int(20));
//     int_p_c c4(std::move(c3));

//     // int_p_c c5 = c3; // error
//     // c4 = c3; // error

//     std::cout << "c1=" << c1.get() << std::endl;
//     std::cout << "c2=" << c2.get() + 5 << std::endl;
//     std::cout << "c3=" << (c3.get() ? *c3.get() : 0) << std::endl; // should print 0 because c3 has been moved
//     std::cout << "c4=" << *c4.get() + 10 << std::endl;
// }
// /*
// c1=10
// c2=15
// c3=0
// c4=30
// */
