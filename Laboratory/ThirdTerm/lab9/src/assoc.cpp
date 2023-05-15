#ifndef ASSOC_H
#define ASSOC_H

#include "assoc.h"

Assoc::Assoc(){
    this->_size = 0;
    this->_capacity = 2;
    this->_przedmiot = new std::string[2];
    this->_ocena = new double[2];   
}

void Assoc::insert(std::string przedmiot, double ocena){
    (*this)[przedmiot] = ocena;
}

void Assoc::print(std::string str) const{
    for(int i =0; i < _size; ++i){
        std::cout << str 
        << " klucz: "
        << _przedmiot[i] 
        << " wartosc: "
        << _ocena[i]
        << std::endl;
    }
    
}

double& Assoc::operator[](std::string przedmiot){
    for(int i =0; i < _size; ++i){
        if(_przedmiot[i] == przedmiot){
            return _ocena[i];
        }
        if (_size == _capacity) {
            _capacity *= 2;
            std::string* newKeys = new std::string[_capacity];
            double* newValues = new double[_capacity];
            for (int i = 0; i < _size; ++i) {
                newKeys[i] = _przedmiot[i];
                newValues[i] = _ocena[i];
            }
            delete[] _przedmiot;
            delete[] _ocena;
            _przedmiot = newKeys;
            _ocena = newValues;
        }
    }
    _przedmiot[_size] = przedmiot;
    this->_size++;
    return _ocena[_size-1];
}

double Assoc::operator[](std::string przedmiot)const{
    for(int i =0; i < _size; ++i){
        if(_przedmiot[i] == przedmiot){
            return _ocena[i];
        }
    }
    throw std::out_of_range("Nie znaleziono klucza");
}

Assoc& Assoc::operator=(const Assoc& other){
    if (this != &other) {
        delete[] _przedmiot;
        delete[] _ocena;
        _capacity = other._capacity;
        _size = other._size;
        _przedmiot = new std::string[_capacity];
        _ocena = new double[_capacity];   

        for(int i = 0; i < _size; ++i){
            _przedmiot[i] = other._przedmiot[i];
            _ocena[i] = other._ocena[i];
        }
    }

    return *this;
}

bool Assoc::contains(std::string str)const{
    for (int i = 0; i < _size; ++i) {
            if (_przedmiot[i] == str) {
                return true;
            }
        }
        return false;
}

std::string print(bool is){
    if(is){
        return "Znaleziono";
    }else{
        return "Nie znaleziono";
    }
}

#endif // ASSOC_H