
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.6 �Dealokacja pami�ci wolnej� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    // Dwukrotne usuni�cie tego samego obiektu jest powa�nym b��dem. Na przyk�ad:

    int* p = new int(5);
    delete p;    // Dobrze: p wskazuje obiekt utworzony przez new.
    // � nigdzie tu p nie jest u�ywany �
    delete p;    // B��d: p wskazuje pami�� b�d�c� w posiadaniu managera pami�ci wolnej.

    {
        int* p = 0;
        delete p;    // Dobrze: nic nie trzeba robi�.
        delete p;    // Te� dobrze: nadal nic nie trzeba robi�.
    }
}

//------------------------------------------------------------------------------
