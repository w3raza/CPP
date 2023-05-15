#pragma once
#include <iostream>
#include <cstring>

class Person{
public:
    Person(const std::string& name): _name(name){}
    virtual ~Person(){std::cout << "~Person (" << _name << ")" << std::endl;}
    
    virtual std::string getName(){return _name;}

    virtual std::ostream& print(std::ostream& os) const{
        return os << "Person: name: " << _name;
    }

private:
    std::string _name;
};

std::ostream& operator<<(std::ostream& os, const Person& person){
    return person.print(os);
}