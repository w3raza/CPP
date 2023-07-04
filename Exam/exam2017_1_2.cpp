#include <iostream>

// Definiujemy abstrakcyjną klasę bazową, która będzie wymagać od każdej klasy dziedziczącej
// implementacji funkcji print_to_stream. Wszystkie klasy, które mogą być drukowane, muszą 
// dziedziczyć po tej klasie.
struct is_printable
{
	virtual std::ostream& print(std::ostream& os) const = 0;
};

struct A : is_printable{
	const char* _name;

	A(const char* name): _name(name){}
	std::ostream& print(std::ostream& os) const override{
		return os << _name;
	}
};

struct B : is_printable{
	int _number;

	B(const int& num): _number(num){}
	std::ostream& print(std::ostream& os) const override{
		return os << _number;
	}
};

// Przeładowanie operatora << dla wszystkich klas dziedziczących po is_printable.
// Funkcja ta będzie wywoływać funkcję print z odpowiedniej klasy.
std::ostream& operator<<(std::ostream& os, const is_printable& obj){
	return obj.print(os);
}


int main() {
	A a{"Tekst"};
	B b{123};

	std::cout << "a=" << a << ";\tb=" << b << ";\n";
	is_printable& a_r = a; is_printable& b_r = b; 
	std::cout << "a=" << a_r << ";\tb=" << b_r << ";\n";

    return 0;
}
/*Wyjście programu*/
//a=Tekst;	b=123;
// a=Tekst;	b=123;