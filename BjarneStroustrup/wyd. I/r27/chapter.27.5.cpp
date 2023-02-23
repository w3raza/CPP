
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.5 „£añcuchy w stylu jêzyka C” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <string>

using namespace std;

//------------------------------------------------------------------------------

char* p = "asdf";
char s[ ] = "asdf";

//------------------------------------------------------------------------------

int main()
{
    const char* s1 = "asdf";
    const char* s2 = "asdf";

    if (s1==s2) {        /* s1 i s2 wskazuj¹ tê sam¹ tablicê */
        /* (zwykle nie o to chodzi programiœcie) */
    }

    if (strcmp(s1,s2)==0) {    /* s1 i s2 przechowuj¹ takie same znaki */

    }

    strcmp("pies","pies")==0;
    strcmp("ma³pa","dodo")<0;    /* „ma³pa” wystêpuje w s³owniku za „dodo”. */
    strcmp("œwinia","krowa")>0;     /* „œwinia” wystêpuje w s³owniku za s³owem „krowa”. */

    // D³ugoœæ ³añcuchów w stylu jêzyka C mo¿na sprawdziæ za pomoc¹ funkcji strlen():

    int lgt = strlen(s1);

    // Jeden ³añcuch w stylu jêzyka C mo¿na skopiowaæ do drugiego (w³¹cznie z koñcowym zerem).

    char s3[10];
    strcpy(s3,s2);    /* Kopiuje znaki z s2 do s3 */

    string id = "nazwa";
    string addr = "nazwa.com";
    string s = id + '@' + addr;
}

//------------------------------------------------------------------------------

char* cat(const char* id, const char* addr)
{
    int sz = strlen(id)+strlen(addr)+2;
    char* res = (char*) malloc(sz);
    strcpy(res,id);
    res[strlen(id)+1] = '@';
    strcpy(res+strlen(id)+2,addr);
    res[sz-1]=0;
    return res;
}

//------------------------------------------------------------------------------
