#include "Named.h"
#include <iostream>

class Point : public Named{
    public:
    Point(int x = 0, int y = 0): _x(x), _y(y){}
    Point(int x, int y, std::string name): _x(x), _y(y), Named(name){}
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    Point operator ++(int);

    protected:
    int _x;
    int _y;
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    return os << p.Name() << " [" << p._x << "," << p._y << "]";
}

Point Point::operator ++(int){
    Point tmp = *this;  
	_x++; _y++; 

   return tmp;
}