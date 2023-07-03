#ifndef EDUSYS_H
#define EDUSYS_H

#pragma once

#include <vector>
#include <memory>

class Student;
class SchoolClass; 

class EduSys{
private:
    std::vector<std::shared_ptr<SchoolClass>> _school;
    std::vector<std::shared_ptr<Student>> _students;

public: 
    EduSys(std::vector<std::shared_ptr<SchoolClass>>, std::vector<std::shared_ptr<Student>>);
    void operator+=(std::shared_ptr<Student>);
    void sortpoints();
    void recruit();
    void printStud() const;
    void printRecruit() const;

    //-------------------- EXTENDED --------------------//
    double getAverageStudScore() const;
    void printPlaces() const;
    void operator+=(std::shared_ptr<SchoolClass>);
    void printApplicants() const;
    std::shared_ptr<Student> findStudent(const std::string&);
};
#endif