
//
// Przyk�adowy kod z rozdzia�u 5.3.2 "B��dy typ�w" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width);    // Oblicza pole powierzchni prostok�ta.

//------------------------------------------------------------------------------

int main()
{
	// int x0 = arena(7); // B��d: niezadeklarowana funkcja.
	// int x1 = area(7); // B��d: nieprawid�owa liczba argument�w.
	// int x2 = area("seven",2); // B��d: pierwszy argument ma nieprawid�owy typ.

	return area(4,4);
}

//------------------------------------------------------------------------------

int area(int length, int width)
{
    return length*width;
}

//------------------------------------------------------------------------------
