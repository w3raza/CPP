#pragma once
#include <iostream>
#include "Student.h"

class Faculty : public virtual Person{
public:
    Faculty(const std::string& name, const std::string& spec) : Person(name), _spec(spec){}
    virtual ~Faculty(){std::cout << "~Faculty"<< std::endl;}

    virtual std::string getSpec() const{
        return _spec;
    }

    virtual std::ostream& print(std::ostream& os) const{
        os << "Faculty: ";
        Person::print(os);
        return os << " spec: " << _spec;
    }

private:
    std::string _spec;
};

std::ostream& operator<<(std::ostream& os, const Faculty& faculty){
    return faculty.print(os);
}