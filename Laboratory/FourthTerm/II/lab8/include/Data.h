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

        for(auto& el : _vec){
            printf("%6g", el);
        }
        std::cout << std::endl;
    }
    
    double sum() const{
        double s = 0.0;
        std::for_each(_vec.begin(), _vec.end(), [&](double val){s += val;});
        return s;
    }

    double operator[](int i) const{
        if(i < _vec.size()){
            return _vec.at(i);
        }else{
            return 0.0;
        }
    }
};

#endif