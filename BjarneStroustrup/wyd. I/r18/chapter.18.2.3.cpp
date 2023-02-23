
//
// To jest przyk�adowy kod z podrozdzia�u 18.2.3 �Terminologia zwi�zana z kopiowaniem� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    // Przyk�ad kopiowania p�ytkiego.
    {
        int* p = new int(77);
        int* q = p;           // Kopiuje wska�nik p.
        *p = 88;    // Zmienia warto�� liczby typu int wskazywanej przez wska�niki p i q.
    }

    // Przyk�ad kopiowania g��bokiego:
    {
        int* p = new int(77);
        int* q = new int(*p); // Alokuje nowy obiekt typu int i kopiuje do niego warto�� wskazywan� przez p.
        *p = 88;              // Zmienia warto�� obiektu typu int wskazywanego przez p.
    }
}

//------------------------------------------------------------------------------
