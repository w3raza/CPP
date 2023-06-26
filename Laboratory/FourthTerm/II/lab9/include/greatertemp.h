#ifndef GREATERTEMP_H
#define GREATERTEMP_H

#pragma once
#include "greaterclass.h"
#include <iostream>

template<typename T = Int>
const T& max(const T& c1, const T& c2){
    return c1 < c2 ? c2 : c1;
}

template<typename T>
T Tmax(const T& c1, const T& c2){
    return max(c1,c2);
}

template <typename T>
const T Tmax(const std::initializer_list<T>& list) {
    return *std::max_element(list.begin(), list.end());
}

template<typename T = Int>
void Tswap(T& a, T& b){
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
T convert(const T& t){
    return static_cast<T>(t);
}

template<typename T, typename K>
T convert(const K& t){
    return static_cast<T>(t);
}

#endif