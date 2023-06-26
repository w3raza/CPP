#ifndef GREATERCLASS_H
#define GREATERCLASS_H

#pragma once
#include <iostream>
#include <cstring>

class Int{
private:
    int _val;
public:
    Int() = default;
    Int(int v): _val(v){}

    bool operator<(const Int& other) const {
        return _val < other._val;
    }

    operator int() const{
        return _val;
    }

    operator char() const{
        return static_cast<char>(_val);
    }

    void print() const{
        std::cout << _val;
    }

    friend std::ostream& operator<<(std::ostream& os, const Int& i){
        i.print();
        return os;
    }
};

class String{
private:
    std::string _val;
public:
    String() = default;
    String(std::string v): _val(v){}

    bool operator<(const String& other) const {
        return _val.length() < other._val.length();
    }

    operator std::string() const{
        return _val;
    }

    const char* c_str() const {
        return _val.c_str();
    }

    operator char*() const{
        return const_cast<char*>(c_str());
    }

    void print() const{
        std::cout << _val;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s){
        s.print();
        return os;
    }
};

#endif