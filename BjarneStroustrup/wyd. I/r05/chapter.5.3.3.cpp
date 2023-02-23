
//
// Przyk³adowy kod z rozdzia³u 5.3.3 "Nie b³êdy" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width);    // Oblicza pole powierzchni prostok¹ta.

//------------------------------------------------------------------------------

int main()
{
	int x4 = area(10,–7); // OK, ale jaki prostok¹t ma szerokoœæ minus 7?
	int x5 = area(10.7,9.3); // OK, ale wywo³anie zostanie zamienione na area(10,9).
	char x6 = area(100, 9999); // OK, ale obetnie wynik.

	return area(4,4);
}

//------------------------------------------------------------------------------

int area(int length, int width)
{
    return length*width;
}

//------------------------------------------------------------------------------
