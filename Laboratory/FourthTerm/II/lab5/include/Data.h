#pragma once
#include <iostream>

class Data{
public:
    virtual void print()const = 0;
};

class Fraction : public Data{
private:
    int _numerator;
    int _denominator;

public:
    Fraction(int numerator, int denominator): _numerator(numerator), _denominator(denominator){}

    void print()const override{
        std::cout << _numerator << "/" << _denominator;
    }
};