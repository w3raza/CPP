#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#pragma once
#include "shapes.h"
#include "circle.h"
#include "rectangle.h"

class ShapeComposite : public Shape{
private:
    std::shared_ptr<Shape> shape1_;
    std::shared_ptr<const Shape> shape2_;
    ShapeOperation operation_;
public:
    ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<const Shape> shape2, ShapeOperation operation) : shape1_{shape1}, shape2_{shape2}, operation_{operation} {} 
    virtual bool isIn(unsigned x, unsigned y) const override{ 
        switch(operation_) {
            case ShapeOperation::INTERSECTION:
                return shape1_->isIn(x,y) && shape2_->isIn(x,y);
            case ShapeOperation::SUM:
                return shape1_->isIn(x,y) || shape2_->isIn(x,y);
            case ShapeOperation::DIFFERENCE:
                return shape1_->isIn(x,y) && !shape2_->isIn(x,y);
        }
        return false; // should not happen
    }
    void print(std::ostream& os) const override{

    }
};

#endif