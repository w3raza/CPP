
//
// To jest oprzyk³adowy kod z podrozdzia³u 27.5.3 „Przyk³ad — funkcja strcpy()” ksi¹¿ki
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
