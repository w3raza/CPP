
//
// To jest przyk³adowy kod z podrozdzia³u 18.2.3 „Terminologia zwi¹zana z kopiowaniem” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    // Przyk³ad kopiowania p³ytkiego.
    {
        int* p = new int(77);
        int* q = p;           // Kopiuje wskaŸnik p.
        *p = 88;    // Zmienia wartoœæ liczby typu int wskazywanej przez wskaŸniki p i q.
    }

    // Przyk³ad kopiowania g³êbokiego:
    {
        int* p = new int(77);
        int* q = new int(*p); // Alokuje nowy obiekt typu int i kopiuje do niego wartoœæ wskazywan¹ przez p.
        *p = 88;              // Zmienia wartoœæ obiektu typu int wskazywanego przez p.
    }
}

//------------------------------------------------------------------------------
