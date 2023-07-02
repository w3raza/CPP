#pragma once
#include <iostream>
#include <list>

#include "customList.h"

template<class T, bool U>
class UniqList : public CustomList<T>{
public:
    UniqList& push_back(const T& el){
        if constexpr(U){
            if(!this->contains(el))
            CustomList<T>::push_back(el);
        }else{
            CustomList<T>::push_back(el);
        }

        return *this;
    }

    UniqList& push_front(const T& el){
        if constexpr(U){
            if(!this->contains(el))
            CustomList<T>::push_front(el);
        }else{
            CustomList<T>::push_front(el);
        }

        return *this;
    }

    typename std::list<T>::iterator head(){
        return this->begin();
    }

    typename std::list<T>::iterator tail(){
        auto it = this->end();
        --it; // przesunięcie iteratora do tyłu o jedno miejsce, żeby wskazywał na ostatni element
        return it;
    }
};