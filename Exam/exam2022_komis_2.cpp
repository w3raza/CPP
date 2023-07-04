#include <iostream>

class Int_t{
private:
    int _val;
public:
    Int_t() = default;
    Int_t(int el): _val(el){}
    
    friend std::ostream& operator<<(std::ostream& os, const Int_t& obj){
        return os << obj._val;
    }
};

template <typename T, size_t N>
struct array{
    array() {}
    explicit array(const array& a) {}

    T _arr[N];
};

template <typename T , size_t N>
void set_for_each(array<T,N>& a, int value){
    for (auto& i : a._arr) {
        i = value;
    }
}

template <typename T, size_t N>
void printer(array<T,N>& a){
    for (const auto& i : a._arr){
        std::cout << i << ", ";
    }
}

class Int_t;

int main(){
    // array to typ parametryzowany - Int_t jako przykład
    // (ma działać z innymi typami), rozmiar dowolny
    typedef array<Int_t, 7> ar_t;
    ar_t t;
    //ar_t t2 = t; //odkomentowanie powoduje błąd kompilacji
     //t = t; //odkomentowanie powoduje błąd kompilacji
    set_for_each(t, 7);
    printer(t);
}

/* Wyjście programu
7, 7, 7, 7, 7, 7, 7,
*/

// // Zadanie 2
// /*
// Proszę uzupełnić program, stosując standard nie niszy ni C++14, tylko w podanych miejsach 
// i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
// komentarzu na koncu kodu. Proszę podać najprostszą moliwą poprawnie działającą 
// implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi uzycie 
// konstrukcje. Brak poprawnego uzasadnenia lub niespełnienie warunkow jest roznoznaczne z 
// brakiem odpowiedzi.
// */

// #include <iostream>

// /* UZUPELNIJ 1 - Warunek: pojedyncza klasa */

// template </* UZUPELNIJ 2 */>
// struct array{
// /* UZUPELNIJ 3 - cialo array */
// };

// template </* UZUPELNIJ 4 */>
// void set_for_each(/* UZUPELNIJ 5 */){
//     /* UZUPELNIJ 6 - cialo set_for_each
//         Warunek: maksymalnie 1 znak ':' i maks. 2 znak ';' */
// }

// template </* UZUPELNIJ 7 */>
// void printer(/* UZUPELNIJ 8 */){
//     /* UZUPELNIJ 9 - cialo printer
//         Warunek: maksymalnie 1 znak ':' i maks. 2 znak ';' */
// }

// class Int_t;

// int main(){
//     // array to typ parametryzowany - Int_t jako przykład
//     // (ma działać z innymi typami), rozmiar dowolny
//     typedef array<Int_t, 7> ar_t;
//     ar_t t;
//     // a_r t2 = t; //odkomentowanie powoduje błąd kompilacji
//     // t = t; //odkomentowanie powoduje błąd kompilacji
//     set_for_each(t, 7);
//     printer(t);
// }

// /* Wyjście programu
// 7, 7, 7, 7, 7, 7, 7,
// */