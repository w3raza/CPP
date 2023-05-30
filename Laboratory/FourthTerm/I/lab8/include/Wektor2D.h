#pragma once
#include <iostream>
#include <cstring>
#include <set>

class Wektor2D{
public:
    Wektor2D(const std::string& name, int x, int y) : _name(name), _x(x), _y(y){}
    int getX()const;
    int getY()const;
    std::string getName()const;
    void print()const;
    bool operator<(const Wektor2D& vec)const;
    
private:
    std::string _name;
    int _x;
    int _y;
};

std::ostream& operator<<(std::ostream& os, Wektor2D* vec);