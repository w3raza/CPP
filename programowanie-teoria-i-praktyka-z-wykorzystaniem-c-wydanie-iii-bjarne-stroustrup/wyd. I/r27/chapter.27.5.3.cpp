
//
// To jest oprzyk�adowy kod z podrozdzia�u 27.5.3 �Przyk�ad � funkcja strcpy()� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

char* strcpy(char* p, const char* q)
{
    while (*p++ = *q++);
    return p;
}

//------------------------------------------------------------------------------

int main()
{
    char buf[10];
    strcpy(buf, "Witajcie");
    return buf[0];
}

//------------------------------------------------------------------------------
