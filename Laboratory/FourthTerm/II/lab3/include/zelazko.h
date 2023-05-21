#pragma once

#include <iostream>
#include <cstring>

class Zelazko{
    public:
    void setPrice(const double price){
        _price = price;
    }

    void setRange(const int range){
        _range = range;
    }

    void setName(std::string name){
        _name = name;
    }

    void UstawTemperature(const int temperature){
        if(0 <= temperature && temperature <= _range){
            _temperature =temperature;
        }else{
            WypiszPozaZakresem();
        }
    }

    int getTemperature() const{
        return _temperature;
    }

    void Wypisz() const{
        std::cout << _name << " cena: " << _price << ". Temperatura: " << _temperature << " Zakres: " << _range << std::endl;
    }

    void WypiszPozaZakresem() const{
        std::cout << "Ten model nie obsluguje takiego zakresu temperatur." << std::endl;
    }

    private:
    double _price = 0;
    int _temperature = 0;
    int _range = 0;
    std::string _name;
};

class ZelazkoPhilips : public Zelazko{
    public:
    ZelazkoPhilips(const double cenaZelazka){
        setPrice(cenaZelazka); 
        setRange(5);
        setName("Philips");
    }
};

class ZelazkoTefal : public Zelazko{
    public:
    ZelazkoTefal(const double cenaZelazka){
        setPrice(cenaZelazka); 
        setRange(7);
        setName("Tefal");
    }
};