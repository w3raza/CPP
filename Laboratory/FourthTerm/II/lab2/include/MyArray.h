#pragma once
#include "MyInt.h"
#include <iostream>

class MyArray{
public:
    MyArray(size_t size): _size(size), _ptr(new MyInt[size]){}
    MyArray(const MyArray& arr): _size(arr._size), _ptr(arr._ptr){}
    ~MyArray(){}

    // void initialize(){
    //     for(int i = 0; i < _size; i++){
    //         _ptr[i] = 7;
    //     }
    // }

    std::ostream& print(std::ostream& os) const{
         os << "[";
        for(int i = 0; i < _size; i++){
            os << _ptr[i];
            if(i != _size-1){
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    size_t size(){return _size;}

    MyInt& operator[](int i)const{
        return _ptr[i];
    }

    MyArray operator++(int){
        MyArray tmp = *this;

        for(int i = 0; i < _size; i++){
            _ptr[i]++;
        }

        return tmp;
    }

private:
    size_t _size;
    MyInt* _ptr;
};

std::ostream& operator<<(std::ostream& os, const MyArray& arr){
    return arr.print(os);
}
