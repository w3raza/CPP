
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.5.4 „Kwestia stylu” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

char* p1;      // p jest wskaŸnikiem na obiekt typu char.
char *p2;      /* p to coœ, z czego mo¿na wy³uskaæ znak. */
char c, *p, a[177], *f(); /* Dozwolone, ale myl¹ce. */

//------------------------------------------------------------------------------

int main()
{
	char c = 'a';  /* Znak oznaczaj¹cy koniec danych wejœciowych pobieranych przez funkcjê f() */
	char* p = 0;  /* Ostatni znak wczytany przez funkcjê f(). */
	char a[177];  /* bufor wejœciowy */
	char* f();    /* Wczytuje do bufora a; zwraca wskaŸnik na pierwszy wczytany znak. */
}

//------------------------------------------------------------------------------
