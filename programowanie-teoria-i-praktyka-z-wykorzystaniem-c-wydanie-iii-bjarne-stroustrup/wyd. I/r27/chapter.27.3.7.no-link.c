/*
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.3.7 �Przestrzenie nazw� ksi��ki
// �Programming -- Principles and Practice Using C++� Bjarne'a Stroustrupa
//
*/

/*----------------------------------------------------------------------------*/

// W bs.h:
typedef struct bs_string { /* ... */ char* str; } bs_string; // �a�cuch Bjarne'a
typedef int bs_bool ;          /* Typ logiczny Bjarne'a. */

/*----------------------------------------------------------------------------*/

// W pete.h:
typedef char* pete_string;     /* �a�cuch Pete'a. */
typedef char pete_bool ;       /* Typ logiczny Pete'a. */

/*----------------------------------------------------------------------------*/
