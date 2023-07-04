//Dokoncz program tak, aby działał w podany w komentarzu sposob. Proszę dokładnie uzasadnić odpowiedź.
#include <iostream> //std::cout
#include <typeinfo> //typeid
#include <type_traits> //std::is_pod
#include <array>
#include <vector>
#include <cstring> //std::memcpy

// Uzupełnij 1
template <bool val>
struct IsPod {
	static void Print() { std::cout << "Copying POD data\n"; }
};

template <>
struct IsPod<false> {
	static void Print() { std::cout << "Copying non-POD data\n"; }
};

template <typename T>
void memcopy(T*, T*, unsigned) {
	IsPod<std::is_pod<T>::value>::Print();
}


struct A { int x;}; struct B {virtual void f() {} int a;};

template <typename T>
void test() {
	T src[10] = {}, dst[10];
	std::cout << typeid(T).name() << " id_pod = " <<std::is_pod<T>::value << ", ";
	memcopy(src, dst, sizeof(src)/sizeof(T));
}

int main() {

	test<A>(); test<B>();
	test<std::array<A,10>>();
	test<std::vector<A>>();

    return 0;
}
/*Wyynik działania programu*/
//A is_pod = 1, Copying POD data
//B is_pod = 0, Copying non-POD data
//std::array<A,10> is_pod = 1, Copying POD data
//std::vector<A> is_pod = 0, Copying non-POD data

// //Dokoncz program tak, aby działał w podany w komentarzu sposob. Proszę dokładnie uzasadnić odpowiedź.
// //Uzupełnij 1

// struct A { int x;}; struct B {virtual void f() {} int a;};

// template <typename T>
// void test() {
// 	T src[10] = {}, dst[10];
// 	std::cout << typeid(T).name() << " id_pod = " <<std::is_pod<T>::value << ", ";
// 	memcopy(src, dst, sizeof(src)/sizeof(T));
// }

// int main() {

// 	test<A>(); test<B>();
// 	test<std::array<A,10>>();
// 	test<std::vector<A>>();

//     return 0;
// }
// /*Wyynik działania programu*/
// //A is_pod = 1, Copying POD data
// //B is_pod = 0, Copying non-POD data
// //std::array<A,10> is_pod = 1, Copying POD data
// //std::vector<A> is_pod = 0, Copying non-POD data

// memcopy function for POD types
/*
std::enable_if<!std::is_pod<T>::value>::type jest więc typem zwracanym przez funkcję memcopy tylko wtedy, gdy T nie jest typem POD.
W praktyce, ponieważ std::enable_if<>::type jest zdefiniowane jako void (dla prawdziwych warunków), 
memcopy jest funkcją typu void. Zastosowanie std::enable_if po prostu pozwala nam na wybranie tej konkretnej implementacji memcopy tylko dla typów nie-POD. 
Analogicznie, druga wersja memcopy jest wybierana tylko dla typów POD.
*/
// template <typename T>
// typename std::enable_if<std::is_pod<T>::value>::type
// memcopy(T* src, T* dst, size_t count) {
//     std::memcpy(dst, src, count * sizeof(T));
//     std::cout << "Copying POD data\n";
// }

// // memcopy function for non-POD types
// template <typename T>
// typename std::enable_if<!std::is_pod<T>::value>::type
// memcopy(T* src, T* dst, size_t count) {
//     for (size_t i = 0; i < count; ++i) {
//         dst[i] = src[i];
//     }
//     std::cout << "Copying non-POD data\n";
// }