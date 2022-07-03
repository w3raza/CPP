
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.5.2 „Operacje na bajtach” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <stddef.h>

//------------------------------------------------------------------------------

/* Kopiuje n bajtów z s2 do s1 (jak strcpy()): */
void* memcpy(void* s1, const void* s2, size_t n);

/* Kopiuje n bajtów z s2 do s1 (<s1,s1+n) mo¿e siê czêœciowo pokrywaæ z <s2,s2+n)): */
void* memmove(void* s1, const void* s2, size_t n);

/* Porównuje n bajtów z s2 z bajtami z s1 (jak strcmp()): */
int memcmp(const void* s1, const void* s2, size_t n);

/* Znajduje c (po konwersji na typ char bez znaku) w pierwszych n bajtach s: */
void* memchr(const void* s, int c, size_t n);

/* Kopiuje c (po konwersji na typ char bez znaku)
  do ka¿dego z n pierwszych bajtów, na które wskazuje s: */
void* memset(void* s, int c, size_t n);


//------------------------------------------------------------------------------
