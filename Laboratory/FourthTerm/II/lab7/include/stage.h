#ifndef STAGE_H
#define STAGE_H

#pragma once
#include "shapes.h"

class Stage{
private:
    size_t _width, _heigh;
public:
    Stage(size_t width, size_t heigh): _width(width), _heigh(heigh){}
    void drawShape(const Shape* shape, std::ostream& os) const{
        shape->print(os);
    }
};

#endif