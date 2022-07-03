
//
// To jest przyk�adowy kod z podrozdzia�u 17.4.4 �Inicjacja� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class X
{
public:
    X() {}          // Konstruktor domy�lny.
};

//------------------------------------------------------------------------------

class Y
{
public:
    Y(int) {}       // Konstruktor jednoargumentowy.
                    // Nie ma domy�lnego konstruktora.
};

//------------------------------------------------------------------------------

int main()
{
    double* p0;                    // Niezainicjowany: mo�e spowodowa� k�opoty.
    double* p1 = new double;       // Alokuje niezainicjowany obiekt typu double.
    double* p2 = new double(5.5);  // Tworzy i inicjuje obiekt typu double o warto�ci 5.5.
    double* p3 = new double[5];    // Alokuje 5 niezainicjowanych obiekt�w typu double.

    // Oczywi�cie zadeklarowanie wska�nika p0 bez jego zainicjowania oznacza proszenie si� o k�opoty.
    *p0 = 7.0;

    double* p4 = new double[5];
    for (int i = 0; i<5; ++i) p4[i] = i;

    X* px1 = new X;                // Jeden obiekt typu X zainicjowany domy�ln� warto�ci�.
    X* px2 = new X[17];            // 17 zainicjowanych obiekt�w typu X.

    //Y* py1 = new Y;                // B��d: nie ma domy�lnego konstruktora.
    //Y* py2 = new Y[17];            // B��d: nie ma domy�lnego konstruktora.
    Y* py3 = new Y(13);            // Dobrze: zainicjowano warto�ci� 13.
}

//------------------------------------------------------------------------------
