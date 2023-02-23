
//
// To jest przyk³adowy kod z podrozdzia³u 17.4.6 „Dealokacja pamiêci wolnej” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    // Dwukrotne usuniêcie tego samego obiektu jest powa¿nym b³êdem. Na przyk³ad:

    int* p = new int(5);
    delete p;    // Dobrze: p wskazuje obiekt utworzony przez new.
    // … nigdzie tu p nie jest u¿ywany …
    delete p;    // B³¹d: p wskazuje pamiêæ bêd¹c¹ w posiadaniu managera pamiêci wolnej.

    {
        int* p = 0;
        delete p;    // Dobrze: nic nie trzeba robiæ.
        delete p;    // Te¿ dobrze: nadal nic nie trzeba robiæ.
    }
}

//------------------------------------------------------------------------------
