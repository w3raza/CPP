#include"Wymierne.h"

int nwd(int m, int n){
    int oldm, oldn;
        while( m % n != 0 ){
            oldm = m;
            oldn = n;
        m = oldn;
        n = oldm % oldn;
    }
    return n;
} 

void Wymierne::print(const char* name) const{
    std::cout << name;
    if(_mianownik != 1 && _mianownik != 0){
        int n = nwd(_licznik, _mianownik);
        std::cout << _licznik/n  << "/" << _mianownik/n;
    }else{
        std::cout << _licznik;
    }
    std::cout << std::endl;
}

Wymierne::operator double(){
    return (double)_licznik/(double)_mianownik;
}

Wymierne& pomnoz(const Wymierne& obj1, const Wymierne& obj2){
    return obj1.pomnoz(obj1, obj2);
}

Wymierne& Wymierne::pomnoz(const Wymierne& obj1, const Wymierne& obj2){
    int licznik = obj1._licznik * obj2._licznik;
    int mianownik = obj1._mianownik * obj2._mianownik;
    Wymierne w(licznik, mianownik);
    
    return w;
}

int Wymierne::getLicznik()const{
    return _licznik;
}

int Wymierne::getMianownik()const{
    return _mianownik;
}

void Wymierne::setM(int m){
    this->_mianownik = m;
}