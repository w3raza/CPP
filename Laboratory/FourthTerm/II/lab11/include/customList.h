#pragma once
#include <algorithm>
#include <iostream>
#include <list>

template<class T>
class CustomList : public std::list<T>{
public:
    CustomList& push_back(const T& value){
        std::list<T>::push_back(value);

        return *this;
    }

    CustomList& push_front(const T& value){
        std::list<T>::push_front(value);
        
        return *this;
    }

    bool contains(const T& value) const{
        return std::find(this->begin(), this->end(), value) != this->end();
    }

    typename std::list<T>::iterator find(const T& value){
        return std::find(this->begin(), this->end(), value);
    }

    void erase(typename std::list<T>::iterator it){
        if(it != this->end())
            std::list<T>::erase(it);
    }

    CustomList reverse(){
         CustomList reversed = *this;
        std::reverse(reversed.begin(), reversed.end());
        return reversed;
    }

    CustomList copy_reversed() const{
    }

    void removeDuplicates(){

    }

    T sumAll() const{

    }

    void print() const{
        std::for_each(this->begin(), this->end(), " ");
    }

    T& operator[](typename std::list<T>::iterator it){
        
    }
};

template<class T>
std::ostream& operator<<(std::ostream& os, const CustomList<T>& list){
    list.print();
    return os;
}