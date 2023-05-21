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
        std::cout << "--- NEW[] --- rozmiar = " << size << "  sizeof = " << sizeof(MyInt) << std::endl;
        return ::operator new[](size);
    }

    void operator delete[](void* ptr, std::size_t size){
        std::cout << "--- DELETE[] --- rozmiar = " << size << std::endl;
        ::operator delete[](ptr);
    }

    MyInt operator++(int){
        MyInt tmp = *this;
        tmp._value++;

        return tmp;
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