
//
// To jest przyk�adowy kod z podrozdzia�u 26.6.1 �Kontrolowanie czasu� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <ctime>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

void do_something()
{
	static int i = 0;
	++i;
}

//------------------------------------------------------------------------------

int main()
{
	int n = 10000000;           // Wywo�uje funkcj� do_something() n razy.

	clock_t t1 = clock();
	if (t1 == clock_t(-1)) {    // clock_t(�1) oznacza �clock() nie zadzia�a�a�
		cerr << "Przykro mi, nie ma zegara.\n";
		exit(1);
	}

	for (int i = 0; i<n; i++) do_something();    // p�tla mierzenia czasu

	clock_t t2 = clock();
	if (t2 == clock_t(-1)) {
		cerr << "Przepe�nienie zegara.\n";
		exit(2);
	}
	cout << "Wykonanie funkcji do_something() " << n << " razy zaj�o "
		<< double(t2�t1)/CLOCKS_PER_SEC << " sekund."
		<< " (precyzja pomiaru: "
		<< CLOCKS_PER_SEC << " sekundy)\n";
}

}

//------------------------------------------------------------------------------
