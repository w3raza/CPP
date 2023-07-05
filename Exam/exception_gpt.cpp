#include <iostream>
#include <stdexcept>

class DivisionByZeroException: public std::runtime_error {
public:
    DivisionByZeroException(): std::runtime_error("Error: Division by zero is not allowed.") {}
};

double safeDivide(int a, int b) {
    if(b == 0){
        throw DivisionByZeroException();
    }else{
        return (double)a/b;
    }
}

int main() {
    int x = 10;
    int y = 0;

    try {
        std::cout << "x/y = " << safeDivide(x, y) << std::endl;
    } 
    catch (const DivisionByZeroException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "An unexpected error has occurred." << std::endl;
    }

    return 0;
}

/*
Output:
x/y = Error: Division by zero is not allowed.
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
// #include <stdexcept>

// class DivisionByZeroException: public std::runtime_error {
// public:
//     //U1
// };

// double safeDivide(int a, int b) {
//     //U2
// }

// int main() {
//     int x = 10;
//     int y = 0;

//     try {
//         std::cout << "x/y = " << safeDivide(x, y) << std::endl;
//     } 
//     catch (const DivisionByZeroException& ex) {
//         std::cout << ex.what() << std::endl;
//     }
//     catch (...) {
//         std::cout << "An unexpected error has occurred." << std::endl;
//     }

//     return 0;
// }

// /*
// Output:
// x/y = Error: Division by zero is not allowed.
// */