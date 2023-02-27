#include <iostream>

// lvalue - obiekt, który zajmuje pewną identyfikowalną lokalizację w pamięci

int x = 2;     // x-lvalue 2-rvalue
int x = i;     // lvalue=lvalue
int x = i + 2; // lvalue = rvalue
int *ptr = &i; // lvalue=lvalue
// int *ptr = &(i+2) ERROR
// 2=i ERROR
int sum(int x, int y) { return x + y; } // x+y rvalue
int i = sum(3, 4);                      // sum(3,4) - rvalue

// Refrence
int i;
int &r = i;       // lvalue=lvalue
                  // int &r = 2 ERROR
const int &r = 2; // OK
int v[3];
int *(v + 2); //(v+2) - rvalue , *(v+2) - lvalue

// function/operator is rvalue
int &foo()
{
    return i;
}
// operator generete lvalue

//  & przyjmuje L-wartości
//  & with const przyjmuje L/R-wartości
//&& przyjmuje R-wartości
void PrintName(const std::string &name)
{
    std::cout << name << std::endl;
}

int main()
{
    std::string name = "Wiktoria";
    std::string lastName = "Zaczyk";

    std::string fullName = name + " " + lastName; // lvalue = rvalue

    PrintName(name + " " + lastName); // rvalue
    PrintName(fullName);              // lvalue

    foo() = 5;

    dog d1;     // d1 - lvalue
    d1 = dog(); // dog() is rvalue
}

class dog
{
};
