#include <iostream> 

struct A { int i = 1; };

template<typename T>
class ptr{
public:
   //explicit bo ptr<A>  _b_error = new A;, 
    //A* a = nullptr bo ptr<A>() dlatego domyślna wartość = konstruktor bezargumentowy
    explicit ptr(A* a = nullptr): _p(a){} 

    ~ptr() {
        delete _p;
    }

    ptr<T>& operator=(const ptr<T>&&) = delete; //bo const ptr<A> _c_error = a; 

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
