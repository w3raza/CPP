// Zadanie 1
/*
Proszę uzupełnić program, stosując standard nie niszy ni C++14, tylko w podanych miejsach 
i zgodnie z podanymi warunkami, tak aby wynik jego działania był zgodny z podanym w 
komentarzu na koncu kodu. Proszę podać najprostszą moliwą poprawnie działającą 
implementację. Kod proszę opatrzyć komentarzami, dokładnie uzasadniającymi uzycie 
konstrukcje. Brak poprawnego uzasadnenia lub niespełnienie warunkow jest roznoznaczne z 
brakiem odpowiedzi.
*/

#include <iostream>

/* UZUPELNIJ 1 - 
holder_type ma przechowywać obiekt na stosie lub stercie 
w zaleźności od ich rozmiarow oraz mieć moliwość przechowywania
innych poprawnie zdefiniowanych typow
 */

struct big { char t[64]; };

int mian(){
    //zawartość a musi być przechowywana na stosie
    holder_type<long> a;
    //zawartość as musi być przechowywana na stercie
    holder_type<long, 8> aa;
    //zawartość b musi być przechowywana na stercie
    holder_type<big> b;
    //zawartość bb musi być przechowywana na stosie,
    //bo rozmiar graniczny ustawiony na 128 bajtow
    holder_type<big, 128> bb;

    *aa = *a = 5;
    *b = *bb;
    a = a;
    bb = bb;
    //odkomentowanie ponizszej lini musi powodować bład kompilacji
    //aa = aa;
}

/* Wyjście programu
scoped
on_head
on_head
scoped
*/