
//
// Przyk�adowy kod z rozdzia�u 5.3.3 "Nie b��dy" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width);    // Oblicza pole powierzchni prostok�ta.

//------------------------------------------------------------------------------

int main()
{
	int x4 = area(10,�7); // OK, ale jaki prostok�t ma szeroko�� minus 7?
	int x5 = area(10.7,9.3); // OK, ale wywo�anie zostanie zamienione na area(10,9).
	char x6 = area(100, 9999); // OK, ale obetnie wynik.

	return area(4,4);
}

//------------------------------------------------------------------------------

int area(int length, int width)
{
    return length*width;
}

//------------------------------------------------------------------------------
