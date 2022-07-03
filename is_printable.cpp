#include <iostream>

class is_printable {
public:
	virtual void print(std::ostream&) const {}
};

class A: public is_printable {
public:
	A(const char* str=""): s(str) {}
	void print(std::ostream& o) const { o << s; }
private:
	const char* s;
};

class B: public is_printable {
public:
	B(int value=0): val(value) {}
	void print(std::ostream& o) const { o << val; }
private:
	int val;
};

std::ostream& operator << (std::ostream& s, const is_printable& o) {
	o.print(s);
	return s;
}

std::ostream& operator << (std::ostream& s, const is_printable& o);

int main() {
	A a{"Tekst"};
	B b{123};

	std::cout << "a=" << a << ";\tb=" << b << ";\n";
	is_printable& a_r = a; is_printable& b_r = b; 
	std::cout << "a=" << a_r << ";\tb=" << b_r << ";\n";

    return 0;
}


