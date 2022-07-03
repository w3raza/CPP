
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.6.1 „Wyjœcie” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <stdio.h>

//------------------------------------------------------------------------------

void f(const char* p)
{
	printf("Witaj, œwiecie!\n");
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

char a[] = { 'a', 'b' };        /* Brak koñcowego zera. */

//------------------------------------------------------------------------------

void f2(char* s, int i) 
{
	printf("goof %s\n", i);     /* Nieprzechwycony b³¹d. */
	printf("goof %d: %s\n", i); /* Nieprzechwycony b³¹d. */
	printf("goof %s\n", a);     /* Nieprzechwycony b³¹d. */


}

//------------------------------------------------------------------------------

int fprintf(FILE* stream, const char* format, ...);

//------------------------------------------------------------------------------

int main()
{
	fprintf(stdout,"Witaj,œwiecie!\n"); // Dok³adnie jak printf("Witaj,œwiecie!\n");
	FILE* ff = fopen("My_file","w");    // Otwiera plik My_file do zapisu.
	fprintf(ff,"Witaj,œwiecie!\n");     // Zapisuje "Witaj,Œwiecie!\n" w pliku My_file.

	fclose(ff);
}

//------------------------------------------------------------------------------
