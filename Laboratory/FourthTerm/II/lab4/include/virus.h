#pragma once
#include <iostream>
#include <memory>
#include <cstring>
#include "dna.h"

class Virus{
    public:
        Virus(){};
        Virus(const std::string& name): _name(name), _rna(nullptr), _age(0) {}
        Virus(Virus& other): _name(other._name), _rna(nullptr), _age(other._age){
            if (this != &other){
                other._age++;
                if (other._rna != nullptr) {
                    _rna = std::make_unique<RNA>(*other._rna);
                }
            }
        }
        Virus(Virus&& other)noexcept : _name(std::move(other._name + "-1")), _rna(std::make_unique<RNA>(*other._rna)), _age(other._age) {
            _rna->mutate();
        }
        
        ~Virus(){}

        Virus& operator=(Virus& other){
            if (this != &other){
                this->_age = other.get_age();
                this->_name = other._name;

                if (other._rna != nullptr) {
                    _rna = std::make_unique<RNA>(*other._rna);
                } 
                other._age++;
            }
            
            return *this;
        }

        Virus& operator=(Virus&& other) noexcept{
            if (this != &other){
                this->_age = other.get_age();
                this->_name = std::move(other._name);
                _rna = std::make_unique<RNA>(*other._rna);
            }
            return *this;
        }

        int get_age() const { return _age;}

        std::string get_name()const {return _name;}

        std::unique_ptr<RNA>& get_RNA() {
            return _rna;
        }

        void set_RNA(const std::vector<Nukleotyp>& vec){
            _rna = std::make_unique<RNA>(vec);
        }

    private:
        int _age;
        std::string _name;
        std::unique_ptr<RNA> _rna;
};