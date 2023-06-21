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

double Fraction::eval() const{
    return _numerator/_denominator;
}

bool Fraction::isNumber() const {
    return true;
}

// ----------------- CharData -----------------

Data* CharData::clone()const {
    return new CharData(*this);
}
void CharData::print()const {
    std::cout << "\'" << _value << "\'";
}

double CharData::eval() const{
    return (double)_value;
}

bool CharData::isNumber() const {
    return false;
}

// ----------------- StringData -----------------
Data* StringData::clone() const {
    return new StringData(*this);
}

void StringData::print()const {
    std::cout << _value;
}

double StringData::eval() const{
    return (double)_value.length();
}

bool StringData::isNumber() const {
    return false;
}