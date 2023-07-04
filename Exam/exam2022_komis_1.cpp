#include <iostream>

template<typename T, size_t size = 16, bool = (sizeof(T) >= size)>
struct holder_type;

//sterta
template<typename T, size_t size>
struct holder_type<T, size, true>{
    // używamy przechowywania na stercie, gdy rozmiar T jest większy niż zadany size
    T* _data;

    holder_type() : _data(new T[size]) { std::cout << "on_head" << std::endl; }
    ~holder_type(){ delete[] _data;}

    T& operator*(){ return *_data;}

    T& operator=(const holder_type& other) = delete;
};

//stos
template<typename T, size_t size>
struct holder_type<T, size, false>{
    // używamy przechowywania na stosie, gdy rozmiar T jest mniejszy lub równy niż zadany size
    T _data;

    holder_type() { std::cout << "scoped" << std::endl; }

    T& operator*(){ return _data;}

};

struct big { char t[64]; };

int main(){
    //zawartość a musi być przechowywana na stosie
    holder_type<long> a;
    //zawartość as musi być przechowywana na stercie
    holder_type<long, 8> aa;
    //zawartość b musi być przechowywana na stercie
    holder_type<big> b;
    //zawartość bb musi być przechowywana na stosie,
    //bo rozmiar graniczny ustawiony na 128 bajtow
    holder_type<big, 128> bb;

    *aa = *a = 5;
    *b = *bb;
    a = a;
    bb = bb;
    //odkomentowanie ponizszej lini musi powodować bład kompilacji
    //aa = aa;
}

/* Wyjście programu
scoped
on_head
on_head
scoped
*/

// // Zadanie 1
// /*
// Proszę uzupełnić program, stosując standard nie niszy ni C++14, tylko w podanych miejsach 
// i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
// komentarzu na koncu kodu. Proszę podać najprostszą moliwą poprawnie działającą 
// implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi uzycie 
// konstrukcje. Brak poprawnego uzasadnenia lub niespełnienie warunkow jest roznoznaczne z 
// brakiem odpowiedzi.
// */

// #include <iostream>

// /* UZUPELNIJ 1 - 
// holder_type ma przechowywać obiekt na stosie lub stercie 
// w zaleźności od ich rozmiarow oraz mieć moliwość przechowywania
// innych poprawnie zdefiniowanych typow
//  */

// struct big { char t[64]; };

// int mian(){
//     //zawartość a musi być przechowywana na stosie
//     holder_type<long> a;
//     //zawartość as musi być przechowywana na stercie
//     holder_type<long, 8> aa;
//     //zawartość b musi być przechowywana na stercie
//     holder_type<big> b;
//     //zawartość bb musi być przechowywana na stosie,
//     //bo rozmiar graniczny ustawiony na 128 bajtow
//     holder_type<big, 128> bb;

//     *aa = *a = 5;
//     *b = *bb;
//     a = a;
//     bb = bb;
//     //odkomentowanie ponizszej lini musi powodować bład kompilacji
//     //aa = aa;
// }

// /* Wyjście programu
// scoped
// on_head
// on_head
// scoped
// */


/* Resolve 2*/
//#include <iostream>

// /* UZUPELNIJ 1 - 
// holder_type ma przechowywać obiekt na stosie lub stercie 
// w zaleźności od ich rozmiarow oraz mieć moliwość przechowywania
// innych poprawnie zdefiniowanych typow
//  */

// template<typename T, size_t stack_size = 16>
// class holder_type{
// private:
//     // Bufor przechowujący dane obiektu
//     union{
//         T stack_data; //stos
//         T* heap_data; //sterta
//     }data;

//     // Flag indicating whether the data is on heap or not
//     bool is_on_heap;

// public:
//     holder_type() : is_on_heap(sizeof(T) >= stack_size){
//         if(is_on_heap){
//             data.heap_data = new T[sizeof(T)];
//             std::cout << "on_heap\n";
//         }else{
//             new (&data.stack_data) T();
//             std::cout << "scoped\n";
//         }
//     }

//     ~holder_type(){
//         if(is_on_heap){
//             delete [] data.heap_data;
//         }
//     }

//     holder_type& operator=(const holder_type& other){
//         if(!is_on_heap){
//             data.stack_data = other.data.stack_data;
//         }else{
//             throw std::logic_error("Heap data assignment not allowed");
//         }
//         return *this;
//     }

//     T* operator->(){
//         return is_on_heap ? reinterpret_cast<T*>(data.heap_data) : &data.stack_data;
//     }

//     T& operator*(){
//         return *(this->operator->());
//     }
// };

// struct big { char t[64]; };

// int main(){
//     //zawartość a musi być przechowywana na stosie
//     holder_type<long> a; //long 8 bajtow
//     //zawartość as musi być przechowywana na stercie
//     holder_type<long, 8> aa;
//     //zawartość b musi być przechowywana na stercie
//     holder_type<big> b;
//     //zawartość bb musi być przechowywana na stosie,
//     //bo rozmiar graniczny ustawiony na 128 bajtow
//     holder_type<big, 128> bb;

//     *aa = *a = 5;
//     *b = *bb;
//     a = a;
//     bb = bb;
//     //odkomentowanie ponizszej lini musi powodować bład kompilacji
//     //aa = aa;
// }