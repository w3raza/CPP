#pragma once
#include<iostream>

class Element{
    public:
    Element(const int *arr, int size): _arr(arr), _size(size), _next(nullptr) {}
    Element(const Element&) = delete; // Nie chcemy kopiować elementu
    ~Element();
    void printElem();
    Element * getNext()const;
    const int *getArr()const;
    int getSize()const;
    void setNext(Element* next);
    
    private:
    int _size;
    const int *_arr;
    Element * _next;
};

inline Element* Element::getNext()const{
    return _next;
}

inline const int * Element::getArr()const{
    return _arr;
}

inline int Element::getSize()const{
    return _size;
}

inline void Element::setNext(Element* next){
    _next = next;
}