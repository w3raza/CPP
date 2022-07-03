
//
// To jest przyk³adowy kod z podrozdzia³u 21.5.4 „Uogólnianie funkcji inner_product()” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class In2, class T, class BinOp, class BinOp2 >
T inner_product(In first, In last, In2 first2, T init, BinOp op, BinOp2 op2)
{
    while(first!=last) {
        init  = op(init, op2(*first, *first2));
        ++first;
        ++first2;
    }
    return init;
}

//------------------------------------------------------------------------------

int main()
{
    // Oblicza indeks Dow Jones Industrial:
    vector<double> dow_price;        // cena akcji ka¿dej spó³ki
    dow_price.push_back(81.86); 
    dow_price.push_back(34.69);
    dow_price.push_back(54.45);
    // ...

    list<double> dow_weight;    // waga ka¿dej spó³ki w indeksie
    dow_weight.push_back(5.8549);    
    dow_weight.push_back(2.4808);
    dow_weight.push_back(3.8940);
    // ...

    double dji_index = inner_product(        // mno¿y pary (weight,value) i sumuje
        dow_price.begin(), dow_price.end(),
        dow_weight.begin(),
        0.0,
        plus<double>(),
        multiplies<double>());

    cout << "Wartoœæ DJI " << dji_index << '\n';
}

//------------------------------------------------------------------------------
