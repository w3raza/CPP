#include <iostream>

// /* UZUPEŁNIJ 1 - Warunek: pojedyncza klasa */
class Double_t{
public:
    double _val;
    Double_t(){}
    Double_t(const double& val): _val(val){}
    
    friend std::ostream& operator<<(std::ostream& os, const Double_t& d){
        return os << d._val;
    }
};

template <typename T, size_t size>
struct vector{
    T _vec[size];
    
    vector() = default; /// bo vec_t v;
    vector(const vector& other) = delete; //bo vec_t v2 = v; //odkomentowanie powoduje błąd kompilacji
    vector& operator=(const vector& other) = delete; //bo v = v; //odkomentowanie powoduje błąd kompilacji
};

template <typename T, size_t size>
void multiply_by_scalar(vector<T, size>& vec, double d){
    /* UZUPEŁNIJ 6 - ciało multiply_by_scalar
        Warunek: maksymalnie 1 znak ':' i maks. 2 znak ';' */
    for(auto& el : vec._vec){
        el._val = d;
    }
}

template <typename T, size_t size>
void print_vector(vector<T, size>& vec){
    /* UZUPEŁNIJ 9 - ciało print_vector
        Warunek: maksymalnie 1 znak ':' i maks. 2 znak ';' */
    for(const auto& el : vec._vec){
        std::cout << el << ", ";
    } 
    std::cout << "\n";
}

class Double_t;

int main(){
    // vector to typ parametryzowany - Double_t jako przykład
    // (ma działać z innymi typami), rozmiar dowolny
    typedef vector<Double_t, 5> vec_t;
    vec_t v;
    // vec_t v2 = v; //odkomentowanie powoduje błąd kompilacji
    // v = v; //odkomentowanie powoduje błąd kompilacji
    multiply_by_scalar(v, 2.0);
    print_vector(v);
}

/* Wyjście programu
2.0, 2.0, 2.0, 2.0, 2.0,
*/


// /*
// Proszę uzupełnić program, stosując standard nie niższy niż C++14, tylko w podanych miejscach 
// i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
// komentarzu na końcu kodu. Proszę podać najprostszą możliwą poprawnie działającą 
// implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi użycie 
// konstrukcji. Brak poprawnego uzasadnienia lub niespełnienie warunków jest równoznaczne z 
// brakiem odpowiedzi.
// */

// #include <iostream>

// /* UZUPEŁNIJ 1 - Warunek: pojedyncza klasa */

// template </* UZUPEŁNIJ 2 */>
// struct vector{
// /* UZUPEŁNIJ 3 - ciało vector */
// };

// template </* UZUPEŁNIJ 4 */>
// void multiply_by_scalar(/* UZUPEŁNIJ 5 */){
//     /* UZUPEŁNIJ 6 - ciało multiply_by_scalar
//         Warunek: maksymalnie 1 znak ':' i maks. 2 znak ';' */
// }

// template </* UZUPEŁNIJ 7 */>
// void print_vector(/* UZUPEŁNIJ 8 */){
//     /* UZUPEŁNIJ 9 - ciało print_vector
//         Warunek: maksymalnie 1 znak ':' i maks. 2 znak ';' */
// }

// class Double_t;

// int main(){
//     // vector to typ parametryzowany - Double_t jako przykład
//     // (ma działać z innymi typami), rozmiar dowolny
//     typedef vector<Double_t, 5> vec_t;
//     vec_t v;
//     // vec_t v2 = v; //odkomentowanie powoduje błąd kompilacji
//     // v = v; //odkomentowanie powoduje błąd kompilacji
//     multiply_by_scalar(v, 2.0);
//     print_vector(v);
// }

// /* Wyjście programu
// 2.0, 2.0, 2.0, 2.0, 2.0,
// */
