#pragma once
#include <iostream>
#include "Data.h"

struct Node
{
    Data* _data;
    Node* _next;
};

class List{
private:
    Node* _list;
public:
    enum Position {Begin, End};

    void insert(Fraction f, const Position& p){
        _list->_data = f;
    }
    
};