#pragma once

#include <iostream>
#include "rna.h"

class DNA: public RNA{
    public:
        DNA(RNA first, RNA second): _first(first), _second(second){}
        RNA getFirst()const {return _first;}
        RNA getSecond()const {return _second;}

    private:
        RNA _first;
        RNA _second;
};

std::ostream& operator<<(std::ostream& os, const DNA& dna){
    os << dna.getFirst();
    for(int i = 0; i < dna.getFirst().getSequence().size() ; i++){
        os << "| ";
    }
    os << std::endl;
    os << dna.getSecond();
    return os;
}