#include <iostream>
#include "Punkt.h"

using namespace std;

int main(int argc, char * argv[])
{
	Punkt a;

	a.SetX(10.0);
	a.SetY(10.0);

	cout << "a.m_x, a.m_y = " << a.GetX() << ", " << a.GetX() << endl << endl;

	Punkt *f = new Punkt(10, 20);
	delete f;
}
