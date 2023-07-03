#include <iostream>

struct A { int x;};
struct B {virtual void print() {} int a;};

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

template <typename T>
void test() {
	T src[10] = {}, dst[10];
	std::cout << "Type ... is_pod = " << std::is_pod<T>::value << ", ";
	memcopy(src, dst, sizeof(src)/sizeof(T));
}

int main() {

	test<A>();
	test<B>();

    return 0;
}
/*Wyjście programu*/
// Type ... is_pod = 1, Copying POD data
// Type ... is_pod = 0, Copying non-POD data