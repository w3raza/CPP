#pragma once
#include <iostream>

class MyArray{
public:
    MyArray(size_t size): _size(size), _ptr(new int[size]){initialize();}
    ~MyArray(){}

    void initialize(){
        for(int i = 0; i < _size; i++){
            _ptr[i] = 7;
        }
    }

    size_t size(){return _size;}

    int& operator[](int i){return _ptr[i];}

private:
    size_t _size;
    int* _ptr;
};

std::ostream& operator<<(std::ostream& os, const MyArray& arr){
    return os << arr.print();
}
