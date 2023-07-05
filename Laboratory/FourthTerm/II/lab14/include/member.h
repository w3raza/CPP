#ifndef MEMBER_H
#define MEMBER_H

#pragma once
#include <iostream>
#include <cstring>

class Member
{
private:
    int _power;
    int _magic;
    int _health;
    std::string _name;
public:
    Member(std::string name): _name(name) {}

    Member& power(const int& p){
        _power = p;

        return *this;
    }

    Member& health(const int& h){
        _health = h;

        return *this;
    }

    Member& magic(const int& m){
        _magic = m;

        return *this;
    }

    int magic() const{
        return _magic;
    }

    void print() const{
        std::cout << _name << " power:" << _power << " magic:" << _magic << " health:" << _health <<std::endl;
    }

    bool operator==(const Member& other) const{
        return _name == other._name;
    }

    bool operator<(const Member& other) const{
        return _name < other._name;
    }
};

#endif