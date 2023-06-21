#include "List.h"

List::~List()
 {
    for (Data* el : elements) {
            delete[] el;
    }
    elements.clear();
}

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

List List::reverse() const {
    List reversed;
    reversed.elements = this->elements; // kopiujemy elementy
    std::reverse(reversed.elements.begin(), reversed.elements.end()); // odwracamy kopię
    return reversed; // zwracamy nową listę z odwróconymi elementami
}

Data* List::find(const Data& data) const{
    Data* cloned = data.clone();
    
    for(auto* el : elements){
        if(el == cloned){
            return el;
        }
    }
    return nullptr;
}

List List::copy_if(bool _is) const{
    List new_list;

    if(_is){
        for(auto el: elements){
            if(!el->isNumber()){
                new_list.insert(*el);
            }
        }
    }else{
        for(auto el: elements){
            if(el->isNumber()){
                new_list.insert(*el);
            }
        }
    }

    return new_list;
}

std::vector<double> List::eval() const{
    std::vector<double> _vec;

    for(auto el: elements){
        _vec.push_back(el->eval());
    }
    return _vec;
}
