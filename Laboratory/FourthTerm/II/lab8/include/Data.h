#ifndef DATA_H
#define DATA_H

#pragma once
#include <iostream>
#include <cstring>

class Data{
private:
    std::string _day;
    std::vector<double> _vec;
public:
    Data(std::string day, std::vector<double> vec): _day(day), _vec(vec){}
    void print() const{
        std::cout << _day << "    ";
    }
};

#endif