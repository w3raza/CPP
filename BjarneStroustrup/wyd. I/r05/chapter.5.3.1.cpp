
//
// Przyk³adowy kod z rozdzia³u 5.3.1 "B³êdy sk³adni" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width);    // Oblicza pole powierzchni prostok¹ta.

//------------------------------------------------------------------------------

int main()
{
	// int s1 = area(7; // B³¹d: brak znaku ).
	// int s1 = area(7) // B³¹d: brak znaku ;.
	// Int s3 = area(7); // B³¹d: Nie ma typu Int.
	// int s4 = area('7); // B³¹d: brak drugiego znaku do pary (nie ma znaku ').

		return area(4,4);
}

//------------------------------------------------------------------------------

int area(int length, int width)
{
    return length*width;
}

//------------------------------------------------------------------------------
