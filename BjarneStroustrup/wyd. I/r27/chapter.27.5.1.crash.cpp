
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.5.1 „£añcuchy w stylu jêzyka C i const" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

const char* p = "asdf";    // Teraz nie mo¿na zapisywaæ w "asdf" poprzez p.

//------------------------------------------------------------------------------

extern "C" char* strchr(const char* s, int c); /* Znajduje c w sta³ej s (nie C++). */

//------------------------------------------------------------------------------

int main()
{
	char* p = "asdf";
	p[2] = 'x'; 

	const char aa[] = "asdf";    /* aa jest tablic¹ sta³ych. */
	char* q = strchr(aa, 'd');          /* Znajduje 'd'. */
	*q = 'x';                           /* Zmienia 'd' w aa na 'x'. */

}

//------------------------------------------------------------------------------
