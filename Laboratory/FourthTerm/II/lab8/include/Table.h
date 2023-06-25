#ifndef TABLE_H
#define TABLE_H

#pragma once
#include "Data.h"
#include <iostream>
#include <vector>

class Table{
private:
    std::vector<Data> _vec;
public:
    Table() = default;

    void operator+=(const Data& d){
        _vec.push_back(d);
    }

    void print()const{
        for(auto& el : _vec){
            el.print();
        }
        std::cout << std::endl;
    }

    Table& sort(int column){
        if(column < 0){
            std::cout << "Illegal column number!" << std::endl;
        } else{
            std::sort(_vec.begin(), _vec.end(), [column](const Data& d1, const Data& d2){
                return d1[column] < d2[column];
            });
        }
        return *this;
    }

    Table& sortBy(std::function<bool(const Data& d1, const Data& d2)> fun){
        std::sort(_vec.begin(), _vec.end(), [&](const Data& d1, const Data& d2){
            return fun(d1,d2);
        });
        return *this;
    }
};

#endif