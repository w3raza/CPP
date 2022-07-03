
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.5.1 ��a�cuchy w stylu j�zyka C i const" ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

const char* p = "asdf";    // Teraz nie mo�na zapisywa� w "asdf" poprzez p.

//------------------------------------------------------------------------------

extern "C" char* strchr(const char* s, int c); /* Znajduje c w sta�ej s (nie C++). */

//------------------------------------------------------------------------------

int main()
{
	char* p = "asdf";
	p[2] = 'x'; 

	const char aa[] = "asdf";    /* aa jest tablic� sta�ych. */
	char* q = strchr(aa, 'd');          /* Znajduje 'd'. */
	*q = 'x';                           /* Zmienia 'd' w aa na 'x'. */

}

//------------------------------------------------------------------------------
