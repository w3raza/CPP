#pragma once
#include "MyString.h"

struct Less{
    bool operator()(const MyString& a, const MyString& b){
        return a < b;
    }
};

struct Greater{
    bool operator()(const MyString& a, const MyString& b){
        return a > b;
    }
};

struct Length{
    bool operator()(const MyString& a, const MyString& b){
        return a.length() < b.length();
    }
};

void PrintNames(const std::vector<MyString>& vec){
    for(auto &el: vec){
        std::cout << el.str() << " ";
    }
    std::cout << "\n" << std::endl;
}