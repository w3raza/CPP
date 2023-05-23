#pragma once
#include <iostream>

class MyInt{
public:
    MyInt(){}
    ~MyInt(){}
    int getValue()const{return _value;}

    int& value(){
        return _value;
    }
    
    void* operator new[](std::size_t size){
        std::cout << "--- NEW[] --- rozmiar = " << size/sizeof(std::size_t) << "  sizeof = " << sizeof(MyInt) * size/sizeof(std::size_t) << std::endl;
        return ::operator new[](size);
    }

    void operator delete[](void* ptr, std::size_t size){
        std::cout << "--- DELETE[] --- rozmiar = " << size/sizeof(std::size_t) << std::endl;
        ::operator delete[](ptr);
    }

    MyInt& operator++() {
    ++_value;
    return *this;
    }

    MyInt operator++(int) {
        MyInt temp(*this);
        ++(*this);
        return temp;
    }

    void operator=(int value){
        _value = value;
    }

private:
    int _value = 7;
};

std::ostream& operator<<(std::ostream& os, const MyInt& i){
    return os << i.getValue();
}