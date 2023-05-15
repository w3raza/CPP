#include <iostream> 

char silnia(int i){
    if(i < 0){
        std::cout << "brak rozwiązania ";
        return 0;
    }else{
        int silnia = 1;
        for(int j = i; 1 < j; j--){
            silnia *= j;
        }
        std::cout << silnia;
        return 0;
    }
}

int silnia_rec(int i){
    if(i <2){
        return 1;
    }
    return i*silnia_rec(i-1);
}