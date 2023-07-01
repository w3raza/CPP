#include "Fraction.h"
#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;
using namespace OOP;

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
  Fraction a = ReadFraction();
  cout << a;
}