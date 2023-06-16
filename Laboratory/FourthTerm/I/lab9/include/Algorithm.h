#pragma once
#include <iostream>

template<typename T>
void swap(T& a, T& b){
    if(a != b){
        T* tmp = new T(a);
        a = b;
        b = *tmp;
    }   
}

template<typename Base, typename T>
bool instanceof(const T* t){
    return dynamic_cast<const Base*>(t) != nullptr;
}