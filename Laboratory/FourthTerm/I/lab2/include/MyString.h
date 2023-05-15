#pragma once
#include <cstring>
#include <iostream>
#include <vector>

class MyString{
    public:
    MyString() = default;
    MyString(const std::string& s): _string(s){}
    MyString(const char* s): _string(s){}

    std::string str()const;

    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;

    size_t length() const;

    private:
    std::string _string;
};
inline std::ostream& operator<<(std::ostream& os, const MyString& str) {
    os << str.str();
    return os;
}

inline std::string MyString::str()const{
    return _string;
}

inline bool MyString::operator<(const MyString& other) const{
    return _string < other._string;
}

inline bool MyString::operator>(const MyString& other) const{
    return _string > other._string;
}

inline size_t MyString::length() const{
    return _string.length();
}