#pragma once
#include <iostream>
#include <cstring>
#include <set>

class Wektor2D{
public:
    Wektor2D(const std::string& length, int x, int y) : _length(length), _x(x), _y(y){}
    int getX()const;
    int getY()const;
    void print()const;
    bool operator<(Wektor2D& vec);
    
private:
    std::string _length;
    int _x;
    int _y;
};

std::ostream& operator<<(std::ostream& os, Wektor2D* vec);