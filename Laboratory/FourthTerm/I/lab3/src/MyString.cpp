#include "MyString.h"

std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.str();
    return os;
}

std::string MyString::str()const{
    return _string;
}

bool MyString::operator<(const MyString& other) const{
    return _string < other._string;
}

bool MyString::operator>(const MyString& other) const{
    return _string > other._string;
}