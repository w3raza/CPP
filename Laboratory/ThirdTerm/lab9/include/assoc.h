#pragma once
#include <iostream>
#include <cstring>
#include <stdexcept>

class Assoc{
public:
    Assoc();
    void insert(std::string przedmiot, double ocena);
    void print(std::string str) const;
    double& operator[](std::string przedmiot);
    double operator[](std::string przedmiot)const;
    Assoc& operator=(const Assoc&);
    bool contains(std::string str)const;

private:
    std::string* _przedmiot; //key
    double* _ocena; //value
    size_t _size;
    int _capacity;
};

std::string print(bool);