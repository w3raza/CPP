
//
// To jest przyk³adowy kod z podrozdzia³u 17.4.1 „Alokacja obiektów w pamiêci wolnej” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

int main()
{
    int  n  = 7;
    int* pi = new int;          // Alokuje jedn¹ liczbê typu int.
    int* qi = new int[4];       // Alokuje cztery liczby typu int (tablicê czterech liczb typu int).

    double* pd = new double;    // Alokuje jedn¹ liczbê typu double.
    double* qd = new double[n]; // Alokuje n liczb typu double (tablicê n liczb typu double).

    // WskaŸniki na obiekty ró¿nych typów s¹ ró¿nych typów. Na przyk³ad:

    //pi = pd;    // B³¹d: nie mo¿na przypisaæ typu double* do int*.
    //pd = pi;    // B³¹d: nie mo¿na przypisaæ typu int* do double*.
}

//------------------------------------------------------------------------------
