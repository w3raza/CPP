
//
// To jest przyk�adowy kod z podrozdzia�u 26.3.6 �Znajdowanie za�o�e�, kt�re si� nie potwierdzaj�� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <algorithm>
#include <iostream>
#include <stdexcept>

//------------------------------------------------------------------------------

struct Bad_sequence {};

//------------------------------------------------------------------------------

struct Not_ordered {};

//------------------------------------------------------------------------------

template<class Iter, class T>
bool b2(Iter first, Iter last, const T& value)
{
	// Sprawdza czy <first,last) to sekwencja:
	if (last<first) throw Bad_sequence();

	// Sprawdza czy sekwencja jest posortowana:
	if (2<last-first) 
		for (Iter p = first+1; p<last; ++p)
			if (*p<*(p-1)) throw Not_ordered();

	// Wszystko jest w porz�dku, wywo�ujemy funkcj� binary_search():
	return std::binary_search(first,last,value);
}

//------------------------------------------------------------------------------

/* Pseudokod

template<class Iter, class T> // Ostrze�enie: zawiera pseudokod.
bool binary_search (Iter first, Iter last, const T& value)
{
if (w��czony test) {
if (Iter jest iteratorem dost�pu swobodnego) {
// Sprawdza czy <first,last) to sekwencja:
if (last<first) throw Bad_sequence();
}

// Sprawdza czy sekwencja jest uporz�dkowana:
if (first!=last) {
Iter prev = first;
for (Iter p = ++first; p!=last; ++p, ++prev)
if (*p<*prev) throw Not_ordered();
}
}

// Wyszukiwanie binarne.
}
*/

//------------------------------------------------------------------------------

int main()
try
{
	int a[] = {2,3,5,7,11,13,17,19};

	return b2(a, a+sizeof(a)/sizeof(a[0]), 7);
}
catch (std::exception& e) {
	std::cerr << "B��d: " << e.what() << '\n'; 
	return 1;
}
catch (...) {
	std::cerr << "Nieznany wyj�tek!\n"; 
	return 2;
}

//------------------------------------------------------------------------------
