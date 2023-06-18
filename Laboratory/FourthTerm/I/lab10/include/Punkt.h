#pragma once
#include <iostream>
#include <cstring>

class Punkt{
private:
    int _x;
    int _y;
    std::string _name;
public:
    Punkt(std::string name, int x, int y): _name(name), _x(x), _y(y){}

    bool operator<(const Punkt& other) const{
        return this->_x == other._x ? this->_y < other._y : this->_x < other._x;
    }

    friend std::ostream& operator<<(std::ostream& os, const Punkt& p);

    template<char c>
    int wsp() const{
    if (c == 'x') {
        return _x;
    } else if (c == 'y') {
        return _y;
    }
        return 0; // Dodany domyślny return dla innych wartości szablonu.
    }

    template<typename T>
    static T max(T a, T b){
        return a < b ? b : a;
    }
};

template<typename T>
void swap(T& a, T& b){
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

std::ostream& operator<<(std::ostream& os, const Punkt& p){
    return os << p._name << "(" << p._x << "," << p._y << ")";
}