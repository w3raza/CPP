// zad 1
// Napisz następujące deklaracje:
// a) wskaźnik tablicy( o wymiarach 4 na 7 ) wskaźników funkcji void fun(void) : 
    void (*tablica[4][7])(void); // Deklaracja tablicy wskaźników do funkcji
    void (*(*wskaznik)[4][7])(void); // Deklaracja wskaźnika do tablicy wskaźników do funkcji
// b) wskaźnik do stłej znakowej : 
    const char mojaStala = 'A'; 
    const char *wskaznik = &mojaStala;  // deklaracja wskaźnika do stałej znakowej
// c) stały wskanik do liczby całkowitej :
    const int *wskaznik;  // deklaracja stałego wskaźnika do liczby całkowitej


// zad 2
/* Co oznaczają poszczególne deklaracje?
- char * p[10] //10-el tablica wskaźników na char
- char *p() //deklarację funkji, nie przyjmuje nic, zwraca wsk na char
- char (*r)[10] //wskaźnik do tablicy 10-el charów
- char p(char *);// funkcja, przyjmuje wsk na char, zwraca char przez wartość
- char (*p)(char[]);//wsk na funkcję, któa przyjmuje wskaźnik na 1. el tablcy (char) i zwraca char przez wartość
*/