#include <iostream>
#include <string>
#include "Rec.h"

/////////////////////////////////////////////////////////////////////////
class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, std::string Opis = "") : m_Opis(Opis) {
		m_x = x;
		m_y = y;
	}
	void SetOpis(std::string Opis)
	{m_Opis = Opis;}

	std::string GetOpis() const
	{ return m_Opis;}

protected:
	std::string m_Opis;
};

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[]) {
	using namespace std;
	
	const RecLbl bRecLbl(5, 5, "bRecLbl");
	
	cout << "Pole " << bRecLbl.GetOpis() << " = " << bRecLbl.Pole() << endl;
}

