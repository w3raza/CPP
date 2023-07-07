//Old exam
#include <iostream>

template<typename T>
struct box{
    T _val;
    box(const T& val) : _val(val){}
    
    void print() const{
        std::cout << "Typ = " << _val << std::endl;
    }
};

template<>
struct box<char>{
    char _val;
    explicit box(const char& val) : _val(val){}
    
    void print() const{
        std::cout << "Typ char = " << _val << std::endl;
    }
};

int main(){
  
  box<int> b1 = -1;
  box<unsigned> b2 = 2;
  box<double> b3 = 2.14;
  box<char> b4 = box<char>('C');
  //odkomentowanie ponizszej linijki bedzie sygnalizowac blad, C w ASCII = 67
  //box<char> b5 = 'C';
  b1.print(); //Wypisuje: Typ T = -1
  b2.print(); //Wypisuje: Typ T = 2;
  b3.print(); //WYpisuje: Typ T = 2.14;
  b4.print(); //Wypisuje: Typ char = 67;
}
/*
Typ = -1
Typ = 2
Typ = 2.14
Typ char = C
*/