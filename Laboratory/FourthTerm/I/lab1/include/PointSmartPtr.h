#include "Point.h"

class PointSmartPtr : public Point{
    public:
    PointSmartPtr(Point* ptr): _ptr(ptr) {_counter++;}
    Point& operator *() const;

    private:
    int _counter = 0;
    Point* _ptr;
};

Point& PointSmartPtr::operator*() const
{
    return *_ptr;
}