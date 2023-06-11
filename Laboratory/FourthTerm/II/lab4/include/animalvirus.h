#pragma once
#include <iostream>
#include <cstring>
#include "virus.h"

class AnimalVirus: public Virus{
    public:
        AnimalVirus() = default;
        AnimalVirus(std::string virus,  std::string animal, RNA* rna): _virus(virus), _animal(animal), _rna(rna){}
        AnimalVirus(std::string virus,  std::string animal, std::vector<Nukleotyp> rna): _virus(virus), _animal(animal), _rna(new RNA(rna)){}
        AnimalVirus(AnimalVirus& other): _virus(other._virus), _animal(other._animal), _rna(nullptr){
            if (this != &other){
                if (other._rna != nullptr) {
                    _rna = other._rna;
                    other._age++;
                }
            }
        }
        AnimalVirus(AnimalVirus&& other)noexcept :  _virus(other._virus), _animal(other._animal), _rna(std::move(other._rna)) {}
        ~AnimalVirus(){}
        
        AnimalVirus& operator=(AnimalVirus& other){
            if (this != &other){
                this->_virus = other._virus;
                this->_animal = other._animal;

                if (other._rna != nullptr) {
                    _rna = other._rna;
                    other._age++;
                } 
            }
            
            return *this;
        }

        AnimalVirus& operator=(AnimalVirus&& other) noexcept{
            if (this != &other){
                this->_virus = other._virus;
                this->_animal = other._animal;
                if (other._rna != nullptr) {
                    _rna = std::move(other._rna);
                } 
            }
            return *this;
        }

        std::string get_name()const{
            return _virus;
        }

        std::string get_animal_host()const{
            return _animal;
        }

        RNA* get_RNA()const{
            return _rna;
        }

        int get_age() const { return _age;}

    private:
        int _age = 0;
        std::string _virus;
        std::string _animal;
        RNA* _rna;
};