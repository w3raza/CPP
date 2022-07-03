
//
// To jest przyk³adowy kod z podrozdzia³u 17.9 „WskaŸniki i referencje” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
	int x = 10;
	int* p = &x;   // Do utworzenia wskaŸnika potrzebny jest operator &.
	*p = 7;        // Przypisanie do x poprzez p za pomoc¹ *.
	int x2 = *p;   // Odczyt x poprzez p.
	int* p2 = &x2; // Tworzy wskaŸnik do innej liczby typu int.
	p2 = p;        // p2 i p wskazuj¹ x.
	p = &x2;       // Zmiana obiektu wskazywanego przez p.


	// Odpowiednik tego kodu dla referencji wygl¹da nastêpuj¹co:
	int y = 10;
	int& r = y;   // & jest w typie, nie w inicjatorze.
	r = 7;        // Przypisanie do y poprzez r (nie potrzeba operatora *).
	int y2 = r;   // Odczyt y poprzez r (nie potrzeba operatora *).
	int& r2 = y2; // Utworzenie referencji do innego obiektu typu int.
	r2 = r;       // Wartoœæ y przypisana do y2.
	r = &y2;      // B³¹d: nie mo¿na zmieniæ wartoœci referencji
	// (nie ma przypisania int* do int&).

}

//------------------------------------------------------------------------------
