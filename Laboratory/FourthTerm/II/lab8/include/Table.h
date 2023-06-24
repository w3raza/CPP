#ifndef TABLE_H
#define TABLE_H

#pragma once
#include <iostream>

class Table{
private:
public:
    void operator+=(const Data& d){}
    void print()const{}
    Table& sort(int column)const{}
    Table& sortBy(bool is_greater)const{}
};

#endif