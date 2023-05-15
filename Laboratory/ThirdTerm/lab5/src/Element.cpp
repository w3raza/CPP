#include "Element.h"

Element::~Element(){ 
    std::cout << "Destruktor Element: "; this->printElem(); std::cout << std::endl;
    delete[] _arr; 
}

void Element::printElem(){
    std::cout << "(";
    for(int i = 0; i < (_size - 1); i++){
        std::cout << _arr[i] << ",";
    }
    std::cout << _arr[_size - 1];
    std::cout << ")";
}