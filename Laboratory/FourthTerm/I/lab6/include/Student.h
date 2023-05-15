#pragma once
#include <iostream>
#include "Person.h"

class Student : public virtual Person{
public:
    Student(const std::string& name, long id) : Person(name), _id(id){}
    virtual ~Student(){std::cout << "~Student (" << getName() << ", id=" << _id << ")" << std::endl;}

    virtual long getId() const{
        return _id;
    }
    
    virtual std::ostream& print(std::ostream& os) const{
        os << "Student: ";
        Person::print(os);
        return os << " id: " << _id;
    }

private:
    long _id;
};

std::ostream& operator<<(std::ostream& os, const Student& student){
    return student.print(os);
}