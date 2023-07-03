#include "school.h"
#include "student.h"
#include <iostream>
#include <algorithm>

SchoolClass::SchoolClass(const std::string& name, const int& number): _name(name), _number_of_seats(number){}

std::string SchoolClass::getclass() const{
    return _name;
}

int SchoolClass::getlimit() const{
    return _number_of_seats;
}

int SchoolClass::getfree() const{
    return _number_of_seats - _students.size();
}

void SchoolClass::addStudent(std::shared_ptr<Student> student){
    if(getfree()){
        _students.push_back(student);
    }
}

void SchoolClass::removeStudent(std::shared_ptr<Student> student){
    // Znajdź studenta w wektorze
    auto iterator = std::find(_students.begin(), _students.end(), student);

    // Jeśli student zostanie znaleziony, usuń go
    if (iterator != _students.end()) 
    {
        _students.erase(iterator);
    }else{
        _students.pop_back();
    }
}

void SchoolClass::printBasic() const{
    std::cout << _name << " - " << getfree() << std::endl;
}

void SchoolClass::print() const{
    size_t students = _students.size();
    std::cout << _name << " - " << students << "/" << _number_of_seats << ": ";
    if(_students.empty()){
        std::cout << "brak przyjetych";
    }else{
        std::cout << std::endl;
        for(auto& s : _students){
            s->print();
        }
    }
    std::cout << std::endl;
}

//-------------------- EXTENDED --------------------//
void SchoolClass::setlimit(int limit){
    _number_of_seats = limit;
}