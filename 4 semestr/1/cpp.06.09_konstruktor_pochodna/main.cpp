#include <iostream>
#include <string>
#include "Rec.h"

/////////////////////////////////////////////////////////////////////////
namespace OOP {

class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, const std::string& Opis = "") : Rec(x, y), m_Opis(Opis)
	{ std::cout << "Konstruktor RecLbl(" << (m_Opis.length() > 0 ? m_Opis : "NoName") << ")\n"; }

	void SetOpis(std::string Opis)
	{ m_Opis = Opis; }

	std::string GetOpis() const
	{ return m_Opis; }

protected:
	std::string m_Opis;
};
}//end of namespace OOP

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[]) {
	using namespace std;
	using namespace OOP;

	const RecLbl aRecLbl;
}

