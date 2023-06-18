#ifndef PAIR_H
#define PAIR_H

#include <iostream>

template<class T, class U>
struct Pair {
    T first;
    U second;

    friend std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        return os << pair.first << ',' << pair.second;
    }
};

template<class T, class U>
Pair(T, U) -> Pair<T, U>;

#endif //PAIR_H