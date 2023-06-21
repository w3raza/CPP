#include "Data.h"

// ----------------- Fraction -----------------
Data* Fraction::clone() const {
        return new Fraction(*this);
    }

void Fraction::print()const {
    if(_denominator == 1){
        std::cout << _numerator;
    }else{
        std::cout << _numerator << "/" << _denominator;
    }
}

// ----------------- StringData -----------------
Data* StringData::clone() const {
    return new StringData(*this);
}

void StringData::print()const {
    std::cout << _value;
}