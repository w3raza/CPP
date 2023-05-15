#pragma once
#include "MyString.h"
#include <memory>
#include <algorithm>
#include <vector>
#include <functional>

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

class MyStringContainer{
    public:
    MyStringContainer() = default;
    MyStringContainer(const MyStringContainer& other);
    ~MyStringContainer();
    void AddMStr(MyString* s); 
    std::vector<MyString> GetSorted(std::string s)const;
    static const std::vector<std::function<bool(const MyString&, const MyString&)>>& SortFunc();

    private:
    std::vector<MyString*> _container;
    static const std::vector<std::function<bool(const MyString&, const MyString&)>>& m_sortFuncs;
};

void PrintNames(const std::vector<MyString>& names);