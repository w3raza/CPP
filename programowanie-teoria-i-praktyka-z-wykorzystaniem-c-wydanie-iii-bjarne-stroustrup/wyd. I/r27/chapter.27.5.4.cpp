
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.5.4 �Kwestia stylu� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

char* p1;      // p jest wska�nikiem na obiekt typu char.
char *p2;      /* p to co�, z czego mo�na wy�uska� znak. */
char c, *p, a[177], *f(); /* Dozwolone, ale myl�ce. */

//------------------------------------------------------------------------------

int main()
{
	char c = 'a';  /* Znak oznaczaj�cy koniec danych wej�ciowych pobieranych przez funkcj� f() */
	char* p = 0;  /* Ostatni znak wczytany przez funkcj� f(). */
	char a[177];  /* bufor wej�ciowy */
	char* f();    /* Wczytuje do bufora a; zwraca wska�nik na pierwszy wczytany znak. */
}

//------------------------------------------------------------------------------
