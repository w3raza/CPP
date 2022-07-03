
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.1 �Alokacja obiekt�w w pami�ci wolnej� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    int  n  = 7;
    int* pi = new int;          // Alokuje jedn� liczb� typu int.
    int* qi = new int[4];       // Alokuje cztery liczby typu int (tablic� czterech liczb typu int).

    double* pd = new double;    // Alokuje jedn� liczb� typu double.
    double* qd = new double[n]; // Alokuje n liczb typu double (tablic� n liczb typu double).

    // Wska�niki na obiekty r�nych typ�w s� r�nych typ�w. Na przyk�ad:

    //pi = pd;    // B��d: nie mo�na przypisa� typu double* do int*.
    //pd = pi;    // B��d: nie mo�na przypisa� typu int* do double*.
}

//------------------------------------------------------------------------------
