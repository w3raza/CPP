#pragma once

#include "zelazko.h"
#include <iostream>
#include <cstring>

class Ubranie{
    public:
    Ubranie(const std::string& type_of_clothes, const std::string& type_of_fabric, double price, int range): _type_of_clothes(type_of_clothes), _type_of_fabric(type_of_fabric), _price(price), _range(range){}

    std::string getFabric()const{
        return _type_of_fabric;
    }

    void setPrice(const double price){
        _price = price;
    }

    double getPrice()const{
        return _price;
    }

    void setRange(const int range){
        _range = range;
    }

    int getIsIroned()const{
        return _is_ironed;
    }

    void Wypisz() const{
        std::cout << _type_of_clothes << " " << _type_of_fabric;
        std::cout << " cena: " << getPrice();
        if(getIsIroned()){
            std::cout << ". Wyprasowane.";
        }else{
            std::cout << ". Pogniecione.";
        }
    }

    void Prasuj(Zelazko zelazko){
        if(_is_ironed){
            std::cout << "Ubranie nie wymaga prasowania." << std::endl;
            return;
        }

        const int temperature = zelazko.getTemperature();
        if(_range >= temperature){
            std::cout << "---Prasuje " << _type_of_clothes  << " " << _type_of_fabric << " zelazkiem o temp. " << temperature << "." << std::endl;
            _is_ironed = true;
        }else{
            std::cout << "Zelazko za gorace." << std::endl;
        }
    }

    void Pogniec(){
        _is_ironed = false;
    }

    private:
        bool _is_ironed = false;
        int _range = 0;
        double _price = 0;
        std::string _type_of_clothes;
        std::string _type_of_fabric;
};

class Koszula : public Ubranie{
    public:
    Koszula(const std::string& type_of_fabric, const double price, const int range, const int length): Ubranie("Koszula", type_of_fabric, price, range), _is_long_sleeve(length){}

    void SkrocRekawy(){
        _is_long_sleeve = 0;
    }

    void Wypisz() const{
        Ubranie::Wypisz();
        if(_is_long_sleeve){
            std::cout << " Dlugi rekaw.";
        }else{
            std::cout << " Krotki rekaw.";
        }
        std::cout << std::endl;
    }

    private:
        bool _is_long_sleeve;
};

class KoszulaBawelniana : public Koszula{
    public:
    KoszulaBawelniana(const double price, const int length) : Koszula("bawelniana", price, 7, length){}
};

class KoszulaJedwabna : public Koszula{
    public:
    KoszulaJedwabna(const double price, const int length) : Koszula("jedwabna", price, 3, length){}
};

class Spodnie : public Ubranie{
    public:
    Spodnie(const std::string& type_of_fabric, const double price, const int range): Ubranie("Spodnie", type_of_fabric, price, range){}

    void PrasujKanty(Zelazko zelazko){
        if(_is_creased){
            std::cout << "Ubranie ma kanty." << std::endl;
            return;
        }
        std::cout << "---Prasuje nogawki Spodnie " << getFabric() << " zelazkiem o temp." << zelazko.getTemperature() << std::endl;
        _is_creased = true;
    }

    void Wypisz() const{
        Ubranie::Wypisz();
        if(_is_creased){
                std::cout << " Kanty.";
            }else{
                std::cout << " Brak kantow.";
            }
            std::cout << std::endl;
    }

    private:
    bool _is_creased;
};

class SpodnieBawelniane : public Spodnie{
    public:
    SpodnieBawelniane(const double price): Spodnie("bawelniana", price, 7){}
};

class SpodnieJedwabne : public Spodnie{
    public:
    SpodnieJedwabne(const double price): Spodnie("jedwabna", price, 3){}
};