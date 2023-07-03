#include "edusys.h"
#include "student.h"
#include "school.h"
#include <iostream>

EduSys::EduSys(std::vector<std::shared_ptr<SchoolClass>> school, std::vector<std::shared_ptr<Student>> students) : _school(school), _students(students) {}

void EduSys::operator+=(std::shared_ptr<Student> student){
    _students.push_back(student);
}

void EduSys::sortpoints(){
    std::sort(_students.begin(), _students.end(), [](const std::shared_ptr<Student>& a, const std::shared_ptr<Student>& b){
        return a->getPoints() > b->getPoints();
    });
}

void EduSys::recruit(){
    sortpoints();
    for(auto& student: _students){
        if(student->getRecruited()){
            std::vector<std::shared_ptr<SchoolClass>> preferences = student->getPreferences();

            for(auto& preference : preferences){
                if(preference->getfree()){
                    preference->addStudent(student);
                    student->addAssignedSchool(preference);
                    student->setRecruited(false);
                    break;
                }
            }
            student->clearPreferences();
        }
    }
}

void EduSys::printStud() const{
    for(auto& s : _students){
        s->print();
    }
    std::cout << std::endl;
}

void EduSys::printRecruit() const{
    for(auto& s : _school){
        s->print();
    }
    std::cout << std::endl;
}

//-------------------- EXTENDED --------------------//
double EduSys::getAverageStudScore() const{
    double sum = 0.0;
    for(auto& student : _students){
        sum += student->getPoints();
    }

    return sum/_students.size();
}

void EduSys::printPlaces() const{
    std::vector<std::shared_ptr<SchoolClass>> _vec;

    for(auto& school : _school){
        if(school->getfree()){
            _vec.push_back(school);
        }
    }

    if(_vec.empty()){
        std::cout << "brak miejsc" << std::endl;
    }else{
        for(auto& school : _vec){
            school -> printBasic();
        }
    }
}

void EduSys::operator+=(std::shared_ptr<SchoolClass> school){
    _school.push_back(school);
}

void EduSys::printApplicants() const{
    std::vector<std::shared_ptr<Student>> _vec;
    for(auto& studnet: _students){
        if(studnet->getRecruited()){
            _vec.push_back(studnet);
        }
    }

    for(auto& student : _vec){
        student->print();
    }
}

std::shared_ptr<Student> EduSys::findStudent(const std::string& name){
    for(auto& studnet: _students){
        if(studnet->getName() == name){
            return studnet;
        }
    }

    return nullptr;
}
