
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.3 �Zakresy� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    double* pd = new double[3];
    pd[2] = 2.2;
    pd[4] = 4.4;
    pd[-3] = -3.3;

    double* p = new double;        // Alokuje liczb� typu double.
    double* q = new double[1000];  // Alokuje tysi�c liczb typu double.

    q[700] = 7.7;                  // Dobrze
    q = p;                         // Niech q wskazuje to samo, co p.
    double d = q[700];             // B��d dost�pu poza zakresem!
}

//------------------------------------------------------------------------------
