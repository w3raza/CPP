#ifndef STUDENT_H
#define STUDENT_H

#pragma once

#include <vector>
#include <string>
#include <memory>

class SchoolClass; // Forward declaration

class Student{
private:
    int _points;
    bool _is_recruited = true;
    std::string _name;
    std::vector<std::shared_ptr<SchoolClass>> _preferences;
    std::shared_ptr<SchoolClass> _assigned_school;

public: 
    Student(const std::string& name, const int& points, std::vector<std::shared_ptr<SchoolClass>> preferences);
    int getPoints() const;
    bool getRecruited() const;
    void setRecruited(bool);
    std::string getName() const;
    void addAssignedSchool(std::shared_ptr<SchoolClass>);
    void clearPreferences();
    void print() const;
    std::vector<std::shared_ptr<SchoolClass>> getPreferences() const;

    //-------------------- EXTENDED --------------------//
    void dropout();
    void apply(std::shared_ptr<SchoolClass>);
    void apply(std::vector<std::shared_ptr<SchoolClass>>);
};
#endif