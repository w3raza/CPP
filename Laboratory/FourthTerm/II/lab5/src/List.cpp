#include "List.h"

List& List::insert(const Data& data, const Position& p){
    Data* cloned = data.clone();
    switch (p)
    {
    case Begin:
        elements.insert(elements.begin(), cloned);
        break;
    case End:
        elements.push_back(cloned);
        break;
    default:
        break;
    }
    return *this;
}

 void List::print()const{
    std::cout << "[ ";
    for(auto* el: elements){
        el->print();
        std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const List& l){
    l.print();
    return os;
}  