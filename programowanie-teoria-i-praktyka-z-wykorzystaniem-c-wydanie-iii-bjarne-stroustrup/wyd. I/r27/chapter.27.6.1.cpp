
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.6.1 �Wyj�cie� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <stdio.h>

//------------------------------------------------------------------------------

void f(const char* p)
{
	printf("Witaj, �wiecie!\n");
	printf(p);
}

//------------------------------------------------------------------------------

int printf(const char* format, ...);

//------------------------------------------------------------------------------

void f1(double d, char* s, int i, char ch)
{
	printf("double %g string %s int %d char %c\n", d, s, i, ch);
}

//------------------------------------------------------------------------------

char a[] = { 'a', 'b' };        /* Brak ko�cowego zera. */

//------------------------------------------------------------------------------

void f2(char* s, int i) 
{
	printf("goof %s\n", i);     /* Nieprzechwycony b��d. */
	printf("goof %d: %s\n", i); /* Nieprzechwycony b��d. */
	printf("goof %s\n", a);     /* Nieprzechwycony b��d. */


}

//------------------------------------------------------------------------------

int fprintf(FILE* stream, const char* format, ...);

//------------------------------------------------------------------------------

int main()
{
	fprintf(stdout,"Witaj,�wiecie!\n"); // Dok�adnie jak printf("Witaj,�wiecie!\n");
	FILE* ff = fopen("My_file","w");    // Otwiera plik My_file do zapisu.
	fprintf(ff,"Witaj,�wiecie!\n");     // Zapisuje "Witaj,�wiecie!\n" w pliku My_file.

	fclose(ff);
}

//------------------------------------------------------------------------------
