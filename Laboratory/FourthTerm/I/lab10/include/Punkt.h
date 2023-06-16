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

    template<char c>
    int wsp() const {
    if (c == 'x') {
        return _x;
    } else if (c == 'y') {
        return _y;
    }
    return 0; // Dodany domyślny return dla innych wartości szablonu.
    }

};

