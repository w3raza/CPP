#pragma once
#include <iostream>
#include "Faculty.h"

class Grade : public Student, public Faculty{
public:
    Grade(const std::string& name, long id, const std::string& spec) : Person(name), Student(name, id), Faculty(name, spec){}
    virtual ~Grade(){std::cout << "~Grade" << std::endl;}

    virtual std::ostream& print(std::ostream& os) const{
        os << "jako "; Person::print(os) << std::endl;
        os << "jako "; Student::print(os) << std::endl;
        os << "jako "; Faculty::print(os);
        return os ;
    }
};

std::ostream& operator<<(std::ostream& os, const Grade& grade){
    return os;
}