
//
// To jest przyk�adowy kod z podrozdzia�u 21.5.3 �Iloczyn skalarny� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <list>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

template<class In, class In2, class T>
T inner_product(In first, In last, In2 first2, T init)
// Uwaga: w ten spos�b mno�y si� dwa wektory (wynikiem jest wielko�� skalarna).
{
    while(first!=last) {
        init  = init + (*first) * (*first2);    // Mno�y pary element�w.
        ++first;
        ++first2;
    }
    return init;
}

//------------------------------------------------------------------------------

int main()
{
    // Oblicza indeks Dow Jones Industrial:
    vector<double> dow_price;        // cena akcji ka�dej sp�ki
    dow_price.push_back(81.86); 
    dow_price.push_back(34.69);
    dow_price.push_back(54.45);
    // ...

    list<double> dow_weight;    // waga ka�dej sp�ki w indeksie
    dow_weight.push_back(5.8549);    
    dow_weight.push_back(2.4808);
    dow_weight.push_back(3.8940);
    // ...

    double dji_index = inner_product(        // mno�y pary (weight,value) i sumuje
        dow_price.begin(), dow_price.end(),
        dow_weight.begin(),
        0.0);

    cout << "Warto�� DJI " << dji_index << '\n';
}

//------------------------------------------------------------------------------
