/*Uzupełnij*/
/*W klasie dozowlone jest tylko zdefiniowanie konstruktora i destruktora oraz może być tylko zdefiniowany
std::cout<<__PRETTY_FUNCTION__<<";"; lub
std::cout<<__PRETTY_FUNCTION__<<"\n";
*/

/**
* Mozna by było przeniesc __PRETTY_FUNCTION__ do macro: #define PRINT_FUNC std::cout<<__PRETTY_FUNCTION__<<";"; 
ale ze względu na treść zadania to w sumie nie mozna
*/
#include <iostream>

class A{
// Musi być public lub protected
public:
    A(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }   
    
    ~A(){
        std::cout<<__PRETTY_FUNCTION__<<"\n";
    }
};

class B{
// Musi być public lub protected
public:
    B(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }   
    
    ~B(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }
};

class X: public B{ 
// Musi być public lub protected
public:
    X(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }   
    
    ~X(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }
};

class Y: public A, public B{
// Musi być public lub protected
public:
    Y(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }   
    
    ~Y(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }
};
/**
 * Bez słowa kluczowego public i tak się skompiluje i będzie poprawne wyjście pomimo, ze wtedy dziedziczenie jest prywatne
 * class Z: Y, X, to jest to równoznaczne z napisaniem class Z: private Y, private X.
 * Klasy pochodne zawsze mają dostęp do publicznych i chronionych konstruktorów swojej klasy bazowej, niezależnie od modyfikatora dostępu użytego w dziedziczeniu. 
   W tym przypadku, klasa Z ma dostęp do konstruktorów klas Y i X, dlatego program wykonuje się poprawnie.
*/
class Z: public Y, public X{
//Tu musi być public aby funkcja main miała dostęp do konstruktora Z
public:
    Z(){
        std::cout<<__PRETTY_FUNCTION__<<"\n";
    }   
    
    ~Z(){
        std::cout<<__PRETTY_FUNCTION__<<";";
    }
};

int main() { Z z; }

/*standardowe wyjście
A::A();B::B();Y::Y();B::B();X::X();Z::Z();
Z::~Z();X::~X();B::~B();Y::~Y();B::~B();A::~A();
*/