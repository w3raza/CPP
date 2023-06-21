#ifndef LIST_H
#define LIST_H

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Data.h"

class List{
private:
    std::vector<Data*> elements;
public:
    enum Position {Begin, End};
    ~List();
    List& insert(const Data& data, const Position& p = End);
    void print()const;
    List reverse() const;
    Data* find(const Data& data) const;
    List copy_if(bool _is = true) const;
    std::vector<double> eval() const;

    friend std::ostream& operator<<(std::ostream& os, const List& l);
};
#endif