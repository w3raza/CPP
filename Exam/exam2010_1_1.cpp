#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

int liczba = -1;

struct A {
A() { }
    void operator()(int &element)
    {
        element = liczba;
        liczba--;
    }
};
int main() {
    list<int> coll(11);

    for_each(coll.begin(), coll.end(), A());
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, "; "));
    return 0;
}

// // uzupełnij

// struct A {
//  // uzupełnij
// };

// int main() {
//     list<int> coll(11);
//     for_each( /*uzupełnij*/ );
//     copy( /*uzupełnij*/ );
//     return 0;
// }
// //to ma się wyświetlić:
// // -1; -2; -3; -4; -5; -6; -7; -8; -9; -10; -11;