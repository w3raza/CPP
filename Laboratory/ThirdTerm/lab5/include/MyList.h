#pragma once
#include "Element.h"
#include <iostream>
#include <cstring>

class MyList{
    public:
    MyList() : head(nullptr), name("Unnamed") {}
    MyList(const MyList&) = delete;
    ~MyList();
    void add(const int* tab, int size);
    void add(Element* elem);
    void removeFirst();
    Element* getHead() const;
    bool isEmpty() const;
    void print(std::string listName) const;
    void copyRev(const MyList* src);
        
    private:
    Element* head;
    std::string name;
};

// class MyList{
//     public:
//     MyList();
//     MyList(const MyList& other);
//     ~MyList();
//     void add(Element *pp1);
//     void add(const int *tab, int size);
//     Element* getHead() const;
//     bool isEmpty() const;
//     void print(std::string _string) const;
//     void copyRev(const MyList* list);
//     void removeFirst();
    
//     private:
//     Element* _head;
// };