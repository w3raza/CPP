#include <iostream>

class Point 
{ 
public: 
	Point(double x = 0.0, double y = 0.0)
	{_x = x;  _y = y; }
	
	void SetX(double x)
		{_x = x;}

	void SetY(double y)
		{_y = y;}

	double GetX() const
		{ return _x; }

	double GetY() const
		{ return _y; }

	void printOut() const
		{std::cout << _x << ", " << _y;}

private: 
	double _x; 
	double _y; 
}; 
/////////////////////////////////////////////////////////////////////////
int main()
{
	using namespace std;
	
	unsigned n;
	cout << "Podaj liczbe elementow klasy do stworzenia: ";
	// cin >> n;

	n = 5;
	if (n < 1)
		return 0;

/* Nie mo�na w ten spos�b
	Point *f = new Point = {Point(1, 1),
										Point(2, 2),
										Point(3, 3)};
*/
	
	//wska�nik do nowych obiekt�w Point
	Point *fPoint = new Point[n];

	//ustawienie warto�ci
	for(unsigned i = 0; i < n; ++i)
		(fPoint+i)->SetX(i), (fPoint+i)->SetY(i+1);

	//wypisanie
	for(unsigned i = 0; i < n; ++i)
		cout << i << "; ", (fPoint+i)->printOut(), cout << endl;

	//nowy obiekt Point
	cout << "---------- fPointA -----------------\n";
	Point *fPointA = new Point(2, 2);

	fPointA->printOut();
	//Zapis oznaczaj�cy dok�adnie to samo
	//(*fPointA).printOut();

	cout << endl;

	//kasacja obiektu pokazywanego przez fPointA
	delete fPointA;

	cout << "----- fPointA = fPoint -------------\n";

	//przypisanie wska�nik�w
	fPointA = fPoint;

	//uzycie innego wska�nika 
	for(unsigned i = 0; i < n; ++i)
		cout << i << "; ", (fPointA+i)->printOut(), cout << endl;

	delete [] fPointA;
	//fPoint->SetX(1); //BLAD

	unsigned Row = 4;
	unsigned Col = 2;

	//Tablica wska�nik�w do wska�nika typu Point
	Point **fPointTab = new Point*[Row];

	//Wype�nienie tablicy wska�nik�w tablicami 'Col' elementowymi
	for(unsigned i = 0; i < Row; i++)
		fPointTab[i] = new Point[Col];

	for(unsigned i = 0; i < Row; i++)
		for(unsigned j = 0; j < Col; j++)
		{
			fPointTab[i][j].SetX(i);
			fPointTab[i][j].SetY(j);
		}

	//wypisanie
	cout << "----- **fPointTab ----------------\n";
	for(unsigned i = 0; i < Row; i++)
	{
		cout << i << ": ";
		for(unsigned j = 0; j < Col; j++)
		{
//			cout << i << "," << j << ": ";
			cout << "(";
			fPointTab[i][j].printOut();
			cout << ")\t";
		}
		cout << endl;
	}

	//usuni�cie tablic
	for(unsigned i = 0; i < Row; i++)
		delete [] fPointTab[i];

	delete [] fPointTab;
}
