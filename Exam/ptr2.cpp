namespace std {class auto_ptr{}; class unique_ptr{}; class shared_ptr{} ; }
#include <iostream> 

struct A { int i = 1; };

template<typename T>
class ptr{
public:
    ptr(): _p(nullptr) {} //const ptr<A> b;
    explicit ptr(T* t): _p(t){} //explicit dla ptr<A>  _b_error = new A;
    ~ptr() {
        delete _p;
    }

    T& operator*() const{
        return *_p;
    }

    T* operator->()const{
        return _p;
    }

    bool operator==(const ptr<T>& other) const{
        return _p == other._p;
    }

    bool operator!=(const ptr<T>& other) const{
        return _p != other._p;
    }
   
private:
    //ptr<T>& operator=(const ptr<T>&) = delete; 
    ptr<T>& operator=(const ptr<T>&&) = delete; // const ptr<A> _c_error = a;     // Odkomentowanie powoduje błąd kompilacji 
    T* _p;
};

int main() {
const ptr<A>  a(new A);
const ptr<A> b;
ptr<A> c(new A);

// ptr<A>  _b_error = new A;      // Odkomentowanie powoduje błąd kompilacji 
// a = a; 			  // Odkomentowanie powoduje błąd kompilacji 
//const ptr<A> _c_error = a;     // Odkomentowanie powoduje błąd kompilacji 

std::cout << ((*a).i, a->i)        << " " << ++c->i << " ";
std::cout << (a == ptr<A>() ) << " " << (a != b) << "\n";
}
/* output/wyjście:
1 2 0 1
*/ 
