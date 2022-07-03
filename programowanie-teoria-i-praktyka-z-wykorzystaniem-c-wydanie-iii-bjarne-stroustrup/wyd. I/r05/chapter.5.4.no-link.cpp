
//
// Przyk�adowy kod z rozdzia�u 5.4 "B��dy konsolidacji" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int area(int length, int width);    // Oblicza pole powierzchni prostok�ta.

//------------------------------------------------------------------------------

int main()
{
    int x = area(2,3);
}

//------------------------------------------------------------------------------

//int area(int x, int y) { return x*y; } // Nasza funkcja area().

// Funkcje o takiej samej nazwie, ale innych typach nie zostan� skojarzone i b�d� ignorowane:

double area(double x, double y) { return x*y; }    // Nie nasza funkcja area().

int area(int x, int y, char unit) { return x*y; }  // Nie nasza funkcja area().

//------------------------------------------------------------------------------
