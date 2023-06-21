#ifndef DATA_H
#define DATA_H

#pragma once
#include <iostream>
#include <cstring>

class Data{
public:
    virtual ~Data() = default;
    virtual Data* clone() const = 0;
    virtual void print()const = 0;
};

class Fraction : public Data{
private:
    int _numerator;
    int _denominator;
public:
    Fraction(int numerator, int denominator = 1): _numerator(numerator), _denominator(denominator){}
    Data* clone() const override;
    void print()const override;
};

class CharData : public Data{
private:
    char _value;
public:
    CharData(char val): _value(val){}
    Data* clone() const override;
    void print()const override;
};

class StringData : public Data{
private:
    std::string _value;
public:
    StringData(std::string val): _value(val){}
    Data* clone() const override;
    void print()const override;
};
#endif