#include "student.h"
#include "school.h"
#include <iostream>

Student::Student(const std::string& name, const int& points, std::vector<std::shared_ptr<SchoolClass>> preferences): _name(name), _points(points), _preferences(preferences){}

int Student::getPoints() const{
    return _points;
}

bool Student::getRecruited() const
{
    return _is_recruited;
}

void Student::setRecruited(bool is){
    _is_recruited = is;
}

std::string Student::getName() const{
    return _name;
}

std::vector<std::shared_ptr<SchoolClass>> Student::getPreferences() const{
    return _preferences;
}

void Student::addAssignedSchool(std::shared_ptr<SchoolClass> school){
    _assigned_school = school;
}

void Student::clearPreferences(){
    _preferences.clear();
}

void Student::print() const{
    std::cout << _name << ": " << _points << " [ ";
    for(auto& el : _preferences){
        std::cout << el->getclass() << " ";
    }
    std::cout << "] --> ";
    if(_assigned_school == nullptr){
        std::cout << "kandydat" << std::endl;
    }else{
        std::cout << _assigned_school->getclass() << std::endl;
    }
}

//-------------------- EXTENDED --------------------//
void Student::dropout(){
    std::cout << _name << " wypisuje sie ze szkoly " << _assigned_school->getclass() << std::endl;
    _is_recruited = true;
    _assigned_school->removeStudent(std::make_shared<Student>(*this));
    _assigned_school = nullptr;
}

void Student::apply(std::shared_ptr<SchoolClass> school){
    if(_is_recruited){
        _is_recruited = false;
        _assigned_school = school;
        _assigned_school->addStudent(std::make_shared<Student>(*this));
    }
}

void Student::apply(std::vector<std::shared_ptr<SchoolClass>> _vec){
    if(_is_recruited){
        _preferences = _vec;
    }
}