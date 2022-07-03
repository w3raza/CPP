#include <iostream>

class Point
{
public:
    Point(double x = 0.0, double y = 0.0)
    {
        _x = x;
        _y = y;
    }

    void SetX(double x)
    {
        _x = x;
    }

    void SetY(double y)
    {
        _y = y;
    }

    double GetX() const
    {
        return _x;
    }

    double GetY() const
    {
        return _y;
    }

    void printOut() const
    {
        std::cout << _x << ", " << _y;
    }

private:
    double _x;
    double _y;
};
/////////////////////////////////////////////////////////////////////////
int main()
{
    using namespace std;

    unsigned n;
    cout << "Podaj liczbe elementow klasy do stworzenia: \n";
    // cin >> n;

    n = 5;
    if (n < 1)
        return 0;

    /* Nie można w ten sposób
	Point *f = new Point = {Point(1, 1),
										Point(2, 2),
										Point(3, 3)};
*/

    //wskażnik do nowych obiektów Point
    Point *fPoint = new Point[n];

    //ustawienie wartości
    for (unsigned i = 0; i < n; ++i)
        (fPoint + i)->SetX(i), (fPoint + i)->SetY(i + 1);

    //wypisanie
    for (unsigned i = 0; i < n; ++i)
        cout << i << "; ", (fPoint + i)->printOut(), cout << endl;

    //nowy obiekt Point
    cout << "---------- fPointA -----------------\n";
    Point *fPointA = new Point(2, 2);

    fPointA->printOut();
    //Zapis oznaczający dokładnie to samo
    //(*fPointA).printOut();

    cout << endl;

    //kasacja obiektu pokazywanego przez fPointA
    delete fPointA;

    cout << "----- fPointA = fPoint -------------\n";

    //przypisanie wskaźników
    fPointA = fPoint;

    //uzycie innego wskaźnika
    for (unsigned i = 0; i < n; ++i)
        cout << i << "; ", (fPointA + i)->printOut(), cout << endl;

    delete[] fPointA;
    //fPoint->SetX(1); //BLAD

    unsigned Row = 4;
    unsigned Col = 2;

    //new = musi zawierac domyslny konstruktor
    //Tablica wskaźników do wskaźnika typu Point
    Point **fPointTab = new Point *[Row];

    //Wypełnienie tablicy wskaźników tablicami 'Col' elementowymi
    for (unsigned i = 0; i < Row; i++)
        fPointTab[i] = new Point[Col];

    for (unsigned i = 0; i < Row; i++)
        for (unsigned j = 0; j < Col; j++)
        {
            fPointTab[i][j].SetX(i);
            fPointTab[i][j].SetY(j);
        }

    //wypisanie
    cout << "----- **fPointTab ----------------\n";
    for (unsigned i = 0; i < Row; i++)
    {
        cout << i << ": ";
        for (unsigned j = 0; j < Col; j++)
        {
            //			cout << i << "," << j << ": ";
            cout << "(";
            fPointTab[i][j].printOut();
            cout << ")\t";
        }
        cout << endl;
    }

    //usunięcie tablic
    for (unsigned i = 0; i < Row; i++)
        delete[] fPointTab[i];

    delete[] fPointTab;
}
//Pola bitowe typ skladnika klasy dane przechowywane są na okreslonej liczbie bitów
// #include <iostream>
// class Port
// {
// public:
//     unsigned read : 1;
//     unsigned status : 1;
//     unsigned data : 6;
// };
// /////////////////////////////////////////////////////////////////////////
// class PortInt
// {
// public:
//     unsigned read;
//     unsigned status;
//     unsigned data;
// };
// /////////////////////////////////////////////////////////////////////////
// int main()
// {
//     using namespace std;

//     Port aPort;
//     aPort.read = 1;
//     aPort.status = 0;
//     aPort.data = 63;
//     cout << aPort.read << ", " << aPort.status << ", " << aPort.data << endl;

//     aPort.read = 0;
//     aPort.status = 2;
//     aPort.data = 562;
//     cout << aPort.read << ", " << aPort.status << ", " << aPort.data << endl;

//     cout << "sizeof(Port)    = " << sizeof(Port) << endl;
//     cout << "sizeof(PortInt) = " << sizeof(PortInt) << endl;
// }
