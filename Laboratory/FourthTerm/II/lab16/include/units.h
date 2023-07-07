#include <iostream>

template<typename T, int m = 1>
class Unit{
private:
    T _val;
public:
    Unit(T val): _val(val){}

    T getVal() const{return _val;}

    template<typename T2, int m2>
    Unit<T, m+m2> operator*(const Unit<T2, m2>& other) const{
        return Unit<T, m+m2>(_val * other.getVal());
    }

    template<typename T2, int m2>
    typename std::enable_if<m==m2, Unit<T, m>>::type
    operator+(const Unit<T2, m2>& other) const{
        return Unit<T, m>(_val + other.getVal());
    }

    template<typename T2, int m2>
    Unit<T, m-m2> operator/(const Unit<T2, m2>& other) const{
        return Unit<T, m-m2>(_val / other.getVal());
    }

    template<typename T2, int m2>
    typename std::enable_if<m==m2, Unit<T, m>>::type
    operator-(const Unit<T2, m2>& other) const{
        return Unit<T, m>(_val - other.getVal());
    }
};

using Meter = Unit<double, 1>;
using Meter2 = Unit<double, 2>;
using Meter3 = Unit<double, 3>;

template<typename T, int m = 1>
std::ostream& operator<<(std::ostream& os, const Unit<T, m>& unit){
    os << unit.getVal();

    if(m != 0){
        os << " m";
    }

    if(m != 1){
        os << "^" << m;
    }

    return os;
}