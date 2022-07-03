
//
// To jest przyk³adowy kod z podrozdzia³u 21.6.3 „Jeszcze jeden przyk³ad zastosowania s³ownika” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <map>
#include <string>
#include <utility>

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

double weighted_value(
    const pair<string,double>& a,
    const pair<string,double>& b
)    // Wydobycie wartoœci i mno¿enie.
{
    return a.second * b.second;
}

//------------------------------------------------------------------------------

int main()
{
    // Tworzymy s³ownik (symbol,cena):

    map<string,double> dow_price;
    // Indeks Dow Jones Industrial (symbol,cena);
    // Aktualne kursy znajduj¹ siê na stronie www.djindexes.com.
    dow_price["MMM"] = 81.86; 
    dow_price ["AA"] = 34.69;
    dow_price ["MO"] = 54.45;
    // ...

    // S³ownik (symbol,waga):

    map<string,double> dow_weight;            // dow (symbol,waga)

    dow_weight.insert(make_pair("MMM", 5.8549));    
    dow_weight.insert(make_pair("AA",2.4808));
    dow_weight.insert(make_pair("MO",3.8940));    
    // ...

    // S³ownik (symbol,nazwa):

    map<string,string> dow_name;              // dow (symbol,nazwa)
    dow_name["MMM"] = "3M Co."; 
    dow_name["AA"]  = "Alcoa Inc.";
    dow_name["MO"]  = "Altria Group Inc.";
    // ...

    Dziêki powy¿szym s³ownikom mo¿na wygodnie pobraæ wszystkie rodzaje informacji:

    double alcoa_price  = dow_price ["AA"];   // Odczytuje wartoœci ze s³ownika.
    double altria_price = dow_price ["MO"];

    if (dow_price.find("INTC") != dow_price.end()) // Znajduje pozycjê w s³owniku.
        cout << "Intel is in the Dow\n";

    typedef map<string,double>::const_iterator Dow_iterator;

    // Drukuje cenê ka¿dej spó³ki w indeksie Dow:
    for (Dow_iterator p = dow_price.begin(); p!=dow_price.end(); ++p) {
        const string& symbol = p->first;      // symbol gie³dowy
        cout << symbol << '\t'
             << p->second << '\t'
             << dow_name[symbol] << '\n';
    }

    double dji_index =
        inner_product(dow_price.begin(),      // wszystkie spó³ki
                      dow_price.end(),
                      dow_weight.begin(),     // wagi spó³ek
                      0.0,                    // wartoœæ pocz¹tkowa
                      plus<double>(),         // dodawanie (jak zwykle)
                      weighted_value);        // Wydobywa wartoœci i wagi oraz
                                              // mno¿y je.
    cout << "DJI=" << dji_index << endl;
}

//------------------------------------------------------------------------------
