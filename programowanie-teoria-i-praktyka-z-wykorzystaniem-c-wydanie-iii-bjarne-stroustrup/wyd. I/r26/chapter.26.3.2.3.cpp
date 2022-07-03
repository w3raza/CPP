
//
// To jest przyk³adowy kod z podrozdzia³u 26.3.2.3 „Sekwencje losowe” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

int rand_int(int max) { return rand()%max; }

//------------------------------------------------------------------------------

int rand_int(int min, int max) { return rand_int(max-min)+min; }

//------------------------------------------------------------------------------

template<class T>
string to_string(const T& t)
{
	ostringstream os;
	os << t;
	return os.str();
}

//------------------------------------------------------------------------------

void make_test(const string& lab, int n, int base, int spread)
// Drukuje opis testu z etykiet¹ lab na wyjœciu.
// Generuje sekwencjê n elementów zaczynaj¹c od base.
// Œrednia odleg³oœæ miêdzy elementami wynosi spread.
{
	cout << "{ " << lab << " " << n << " { ";
	vector<int> v;
	int elem = base;
	for (int i = 0; i<n; ++i) {           // tworzy elementy
		elem+= rand_int(spread);
		v.push_back(elem);
	}

	int val = base+ rand_int(elem-base);  // tworzy wartoœæ do szukania
	bool found = false;
	for (int i = 0; i<n; ++i) {           // Drukuje elementy i sprawdza czy val zosta³ znaleziony.
		if (v[i]==val) found = true;
		cout << v[i] << " ";
	}
	cout << "} " << found << " }\n";
}

//------------------------------------------------------------------------------

int main()
{
	int no_of_tests = rand_int(10);       // Tworzy oko³o 5 testów.
	for (int i = 0; i<no_of_tests; ++i) {
		string lab = "rand_test_";
		make_test(lab+to_string(i),       // to_string z podrozdzia³u 23.2.
			rand_int(500),                // liczba elementów
			0,                       // podstawa
			rand_int(50));           // rozproszenie

	}
}

//------------------------------------------------------------------------------
