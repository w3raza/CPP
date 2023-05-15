#ifndef MYLIST_H
#define MYLIST_H

#include "Element.h"

class MyList {
public:
    MyList() : first(nullptr), last(nullptr) {}
    MyList(const MyList& other) : first(nullptr), last(nullptr) {
        Element* ptr = other.first;
        while (ptr != nullptr) {
            addLast(new Element(*ptr));
            ptr = ptr->getNext();
        }
    }
    ~MyList() {
        while (first != nullptr) {
            Element* next = first->getNext();
            delete first;
            first = next;
        }
    }
    void addFirst(Element* el) {
        el->setNext(first);
        first = el;
        if (last == nullptr) {
            last = el;
        }
    }
    void addLast(Element* el) {
        if (last != nullptr) {
            last->setNext(el);
        } else {
            first = el;
        }
        last = el;
    }
    void printList() const {
        Element* ptr = first;
        std::cout << "Lista1 = <";
        while (ptr != nullptr) {
            ptr->printElem();
            ptr = ptr->getNext();
            if (ptr != nullptr) {
                std::cout << " ";
            }
        }
        std::cout << ">" << std::endl;
    }
private:
    Element* first;
    Element* last;
};

#endif // MYLIST_H
