
//
// Przyk³adowy kod z rozdzia³u 5.3.2 "B³êdy typów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width);    // Oblicza pole powierzchni prostok¹ta.

//------------------------------------------------------------------------------

int main()
{
	// int x0 = arena(7); // B³¹d: niezadeklarowana funkcja.
	// int x1 = area(7); // B³¹d: nieprawid³owa liczba argumentów.
	// int x2 = area("seven",2); // B³¹d: pierwszy argument ma nieprawid³owy typ.

	return area(4,4);
}

//------------------------------------------------------------------------------

int area(int length, int width)
{
    return length*width;
}

//------------------------------------------------------------------------------
