#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>

class Element {
public:
    Element(int* p, int n) : coords(new int[n]), size(n), next(nullptr) {
        for (int i = 0; i < n; ++i) {
            coords[i] = p[i];
        }
        ++objectsCount;
        id = objectsCount;
        std::cout << "Id_" << id << "(";
        printCoords();
        std::cout << ")" << std::endl;
    }
    Element(const Element& other) : coords(new int[other.size]), size(other.size), next(nullptr) {
        for (int i = 0; i < size; ++i) {
            coords[i] = other.coords[i];
        }
        ++objectsCount;
        id = objectsCount;
        std::cout << "Konstruktor kopiujacy " << id << std::endl;
    }
    Element(Element&& other) : coords(other.coords), size(other.size), next(other.next) {
        other.coords = nullptr;
        other.size = 0;
        other.next = nullptr;
        ++objectsCount;
        id = objectsCount;
        std::cout << "Konstruktor przenoszacy " << id << std::endl;
    }
    ~Element() {
        delete[] coords;
        if (next != nullptr) {
            delete next;
        }
        std::cout << "Id_" << id << "()" << std::endl;
    }
    Element& operator=(const Element& other) {
        if (this != &other) {
            delete[] coords;
            coords = new int[other.size];
            size = other.size;
            for (int i = 0; i < size; ++i) {
                coords[i] = other.coords[i];
            }
        }
        return *this;
    }
    static int getObjects() {
        return objectsCount;
    }
    Element* getNext() const {
        return next;
    }
    void setNext(Element* el) {
        next = el;
    }
    void printElem() const {
    }

    private:
    static int objectsCount;  // Licznik liczby utworzonych obiektów
    int id;                  // Numer identyfikacyjny obiektu
    int* coords;             // Współrzędne elementu
    int size;                 // Wymiar elementu
    Element* next;
};