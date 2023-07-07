#include<iostream>

struct S{
  S(){ std::cout << "S ";}
  ~S() {std::cout << "~S ";}
};

struct A : public S{
  A(){ std::cout << "A ";}
  ~A() {std::cout << "~A ";}
};

struct B : public A{
  B() { std::cout << "B ";}
  ~B() {std::cout << "~B ";}
};

struct C : virtual public A{
  C(){ std::cout << "C ";}
  ~C() {std::cout << "~C ";}
};

struct D : C, virtual public B{
  D(){ std::cout << "D " << std::endl;}
  ~D() {std::cout << "~D ";}
  C c;
};

int main(){
D d;
}
/*
S A S A B C S A C D
~D ~C ~A ~S ~C ~B ~A ~S ~A ~S */