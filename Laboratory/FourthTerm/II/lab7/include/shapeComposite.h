#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#pragma once
#include "shapes.h"
#include "circle.h"
#include "rectangle.h"

class ShapeComposite : public Shape{
private:
    
public:
    ShapeComposite(std::shared_ptr<Shape> rec, std::shared_ptr<const Shape> cir, ShapeOperation operation){}
    virtual bool isIn(unsigned x, unsigned y) const override{ return false;}
};

#endif