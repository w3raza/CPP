
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.5 ��a�cuchy w stylu j�zyka C� ksi��ki
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

    if (s1==s2) {        /* s1 i s2 wskazuj� t� sam� tablic� */
        /* (zwykle nie o to chodzi programi�cie) */
    }

    if (strcmp(s1,s2)==0) {    /* s1 i s2 przechowuj� takie same znaki */

    }

    strcmp("pies","pies")==0;
    strcmp("ma�pa","dodo")<0;    /* �ma�pa� wyst�puje w s�owniku za �dodo�. */
    strcmp("�winia","krowa")>0;     /* ��winia� wyst�puje w s�owniku za s�owem �krowa�. */

    // D�ugo�� �a�cuch�w w stylu j�zyka C mo�na sprawdzi� za pomoc� funkcji strlen():

    int lgt = strlen(s1);

    // Jeden �a�cuch w stylu j�zyka C mo�na skopiowa� do drugiego (w��cznie z ko�cowym zerem).

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
