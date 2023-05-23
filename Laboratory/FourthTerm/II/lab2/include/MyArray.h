#pragma once
#include "MyInt.h"
#include <iostream>

class MyArray{
public:
    MyArray(){}

    MyArray(size_t size): _size(size), _ptr(new MyInt[size]){}

    MyArray(const MyArray& arr): _size(arr._size), _ptr(new MyInt[arr._size]){
        for(int i = 0; i < arr._size; i++){
            _ptr[i] = arr._ptr[i];
        }
    }

    MyArray( MyArray&& arr): _size(arr._size), _ptr(std::move(arr._ptr)){
        arr._size = 0;
        arr._ptr = nullptr;
    }

    ~MyArray(){
        delete[] _ptr;
    }

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
        return _ptr[i % _size];
    }

    MyArray& operator++() {
    for (int i = 0; i < _size; ++i)
        ++_ptr[i];
        return *this;
    }

    MyArray operator++(int) {
        MyArray temp(*this);
        ++(*this);
        return temp;
    }


    MyArray& operator=(const MyArray& arr){
        if (this != &arr) {
            delete[] _ptr;
            _size = arr._size;
            _ptr = new MyInt[arr._size];
            for(int i = 0; i < arr._size; i++){
                _ptr[i] = arr._ptr[i];
            }
        }
        return *this;
    }

    MyArray& operator=(MyArray&& arr){
        if (this != &arr) {
            delete[] _ptr;
            _size = arr._size;
            _ptr = std::move(arr._ptr);
            arr._size = 0;
            arr._ptr = nullptr;
        }
    
        return *this;
    }

private:
    size_t _size;
    MyInt* _ptr;
};

std::ostream& operator<<(std::ostream& os, const MyArray& arr){
    return arr.print(os);
}
