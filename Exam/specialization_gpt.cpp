#include <iostream>

template<typename T>
struct A;

template<typename T>
struct A
{
    using value_type = T;
    A(const T& el): _v(el){}
    A(const A& a): _v(a._v){}
    
    T get()const{
        return _v;
    }
private:
    value_type _v = value_type();
};

template<typename T>
struct A<T*>
{
    using value_type = T;
    A(T* el): _v(el){}
    A(const A& a) = delete;
    A& operator=(const A& a) = delete;
    
    T* get()const{
        return _v;
    }
private:
    value_type* _v;
};

int main()
{
    typedef A<int> int_a;
    typedef A<int*> int_p_a;   

    int_a a(3);
    int_a a_copy(a);
    int_p_a b(new int_p_a::value_type{5});
    //int_p_a e = b; //error
    //b=b //error
    
    std::cout << "a=" << a.get() << std::endl;
    std::cout << "a_copy=" << a_copy.get() - 1 << std::endl;
    std::cout <<" b=" << *b.get() + 3 << std::endl;
}

/*
a=3
a_copy=5
b=8
*/

// /*
// Proszę uzupełnić program, stosując standard nie niższy niż C++14, tylko w podanych miejscach 
// i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
// komentarzu na końcu kodu. Proszę podać najprostszą możliwą poprawnie działającą 
// implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi użycie 
// konstrukcji. Brak poprawnego uzasadnienia lub niespełnienie warunków jest równoznaczne z 
// brakiem odpowiedzi.
// */

// #include <iostream>

// template<typename T>
// struct A;

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
//     //using int_a = A<int>;      
//     //using int_p_a = A<int*>;  
//     typedef A<int> int_a;
//     typedef A<int*> int_p_a;   

//     int_a a(3);
//     int_a a_copy(a);
//     int_p_a b(new int_p_a::value_type{5});
//     // int_p_a e = b; //error
//     // b=b //error
    
//     std::cout << "a=" << a.get() << std::endl;
//     std::cout << "a_copy=" << a_copy.get() - 1 << std::endl;
//     std::cout <<" b=" << *b.get() + 3 << std::endl;
// }

// /*
// a=3
// a_copy=5
// b=8
// */
