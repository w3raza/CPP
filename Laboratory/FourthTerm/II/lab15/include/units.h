#include <type_traits>
#include <iostream>

template<typename T, int m = 0, int kg = 0, int s = 0>
struct Unit {
    T val;
    explicit Unit(T val = 0) : val(val) {}
    
    template<typename T2, int m2, int kg2, int s2>
    Unit<std::common_type_t<T, T2>, m+m2, kg+kg2, s+s2>
    operator*(const Unit<T2, m2, kg2, s2>& rhs) const {
        return Unit<std::common_type_t<T, T2>, m+m2, kg+kg2, s+s2>(val * rhs.val);
    }

    template<typename T2, int m2, int kg2, int s2>
    Unit<std::common_type_t<T, T2>, m-m2, kg-kg2, s-s2>
    operator/(const Unit<T2, m2, kg2, s2>& rhs) const {
        return Unit<std::common_type_t<T, T2>, m-m2, kg-kg2, s-s2>(val / rhs.val);
    }

    template<typename T2, int m2 = m, int kg2 = kg, int s2 = s>
    typename std::enable_if<m==m2 && kg==kg2 && s==s2, Unit<std::common_type_t<T, T2>, m, kg, s>>::type
    operator+(const Unit<T2, m2, kg2, s2>& rhs) const {
        return Unit<std::common_type_t<T, T2>, m, kg, s>(val + rhs.val);
    }
};

template<typename T>
using Length = Unit<T, 1, 0, 0>;

template<typename T>
using Area = Unit<T, 2, 0, 0>;

template<typename T>
using Time = Unit<T, 0, 0, 1>;

template<typename T>
using Velocity = Unit<T, 1, 0, -1>;

template<typename T>
using Acceleration = Unit<T, 1, 0, -2>;

template<typename T>
using Weight = Unit<T, 0, 1, 0>;

template<typename T, int m = 0, int kg = 0, int s = 0>
std::ostream& operator<<(std::ostream& os, const Unit<T, m, kg, s> unit) {
    os << unit.val << " ";

    if(kg != 0){
        os << "kg";
        if(kg != 1){
            os << "^" << kg;
        }
        os << " ";
    }

    if(m != 0){
        os << "m";
        if(m != 1){
            os << "^" << m;
        }
        os << " ";
    }

    if(s != 0){
        os << "s";
        if(s != 1){
            os << "^" << s;
        }
    }

    return os;
}
