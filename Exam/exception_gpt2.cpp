#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cmath>

class NegativeSquareRootException: public std::runtime_error {
public:
    NegativeSquareRootException(double value)
        : std::runtime_error("Error"), value(value) {}

    double getValue() const { return value; }

    const char* what() const noexcept override{
        return (std::string("Attempted to calculate the square root of ") + std::to_string(value)).c_str();
    }
private:
    double value;
};

double safeSqrt(double value) {
    if(value < 0){
        throw NegativeSquareRootException(value);
    }else{
        return std::sqrt(value);
    }
}

int main() {
    double x = -9;

    try {
        std::cout << "sqrt(x) = " << safeSqrt(x) << std::endl;
    }
    catch (const NegativeSquareRootException& ex) {
        std::cout << ex.what() << std::endl;
    }
    catch (...) {
        std::cout << "An unexpected error has occurred." << std::endl;
    }

    return 0;
}

/*
Output:
sqrt(x) = Error: Attempted to calculate the square root of -9.
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
// #include <string>

// class NegativeSquareRootException: public std::runtime_error {
// public:
//     NegativeSquareRootException(double value)
//         : std::runtime_error("Error"), value(value) {}

//     double getValue() const { return value; }

//     // U1
// private:
//     double value;
// };

// double safeSqrt(double value) {
//     //U2
// }

// int main() {
//     double x = -9;

//     try {
//         std::cout << "sqrt(x) = " << safeSqrt(x) << std::endl;
//     }
//     catch (const NegativeSquareRootException& ex) {
//         std::cout << ex.what() << std::endl;
//     }
//     catch (...) {
//         std::cout << "An unexpected error has occurred." << std::endl;
//     }

//     return 0;
// }

// /*
// Output:
// Error: Attempted to calculate the square root of -9.
// */
