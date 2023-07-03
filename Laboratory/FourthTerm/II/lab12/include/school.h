#ifndef SCHOOL_H
#define SCHOOL_H

#pragma once

#include <vector>
#include <string>
#include <memory>

class Student; // Forward declaration

class SchoolClass{
private:
    std::string _name;
    int _number_of_seats;
    std::vector<std::shared_ptr<Student>> _students;

public: 
    SchoolClass(const std::string& name, const int& number);
    std::string getclass() const;
    int getlimit() const;
    int getfree() const;
    void addStudent(std::shared_ptr<Student>);
    void removeStudent(std::shared_ptr<Student>);
    void printBasic() const;
    void print() const;

    //-------------------- EXTENDED --------------------//
    void setlimit(int);
};
#endif