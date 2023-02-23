
//
// To jest przyk³adowy kod z podrozdzia³u 17.4.4 „Inicjacja” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

//------------------------------------------------------------------------------

class X
{
public:
    X() {}          // Konstruktor domyœlny.
};

//------------------------------------------------------------------------------

class Y
{
public:
    Y(int) {}       // Konstruktor jednoargumentowy.
                    // Nie ma domyœlnego konstruktora.
};

//------------------------------------------------------------------------------

int main()
{
    double* p0;                    // Niezainicjowany: mo¿e spowodowaæ k³opoty.
    double* p1 = new double;       // Alokuje niezainicjowany obiekt typu double.
    double* p2 = new double(5.5);  // Tworzy i inicjuje obiekt typu double o wartoœci 5.5.
    double* p3 = new double[5];    // Alokuje 5 niezainicjowanych obiektów typu double.

    // Oczywiœcie zadeklarowanie wskaŸnika p0 bez jego zainicjowania oznacza proszenie siê o k³opoty.
    *p0 = 7.0;

    double* p4 = new double[5];
    for (int i = 0; i<5; ++i) p4[i] = i;

    X* px1 = new X;                // Jeden obiekt typu X zainicjowany domyœln¹ wartoœci¹.
    X* px2 = new X[17];            // 17 zainicjowanych obiektów typu X.

    //Y* py1 = new Y;                // B³¹d: nie ma domyœlnego konstruktora.
    //Y* py2 = new Y[17];            // B³¹d: nie ma domyœlnego konstruktora.
    Y* py3 = new Y(13);            // Dobrze: zainicjowano wartoœci¹ 13.
}

//------------------------------------------------------------------------------
