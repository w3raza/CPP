#include <iostream>

/*Uzupełnij*/
/*W klasie dozowlone jest tylko zdefiniowanie konstruktora i destruktora oraz może być tylko zdefiniowany
std::cout<<__PRETTY_FUNCTION__<<";"; lub
std::cout<<__PRETTY_FUNCTION__<<"\n";
*/

int main() { Z z; }

/*standardowe wyjście
A::A();B::B();Y::Y();B::B();X::X();Z::Z();
Z::~Z();X::~X();B::~B();Y::~Y();B::~B();A::~A();
*/