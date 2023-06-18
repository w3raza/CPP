#ifndef RATIONAL_H
#define RATIONAL_H

#include <Pair.h>

template<typename T>
struct Rational : Pair<T, T>{
    Rational(T a, T b): Pair<T,T>{a,b}{}

    operator double() const{
        return static_cast<double>(this->first)/static_cast<double>(this->second);
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        return os << r.first << '/' << r.second;
    }

    Rational Inverse() const{
        return Rational{this->second, this->first};
    }
};

template<class T, class U>
Rational(T, U) -> Rational<T>;

#endif //RATIONAL_H