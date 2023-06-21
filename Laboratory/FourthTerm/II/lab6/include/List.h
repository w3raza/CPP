#ifndef LIST_H
#define LIST_H

#pragma once
#include <iostream>
#include <vector>
#include "Data.h"

class List{
private:
    std::vector<Data*> elements;
public:
    enum Position {Begin, End};

    List& insert(const Data& data, const Position& p = End);
    void print()const;
    friend std::ostream& operator<<(std::ostream& os, const List& l);
};
#endif