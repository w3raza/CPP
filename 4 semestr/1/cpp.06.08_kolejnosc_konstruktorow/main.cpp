#include <iostream>
#include <string>
#include "Rec.h"

namespace OOP {

class RecLbl: public Rec {
public:
	RecLbl(double x = 0, double y = 0, const std::string& Opis = "") : m_Opis(Opis)
	{
		m_x = x;
		m_y = y;
		std::cout << "Konstruktor RecLbl(" << m_Opis << ")\n"; 
	}

	~RecLbl()
	{std::cout << "Destruktor RecLbl(" << m_Opis << ")\n"; }

	void SetOpis(const std::string& Opis)
	{m_Opis = Opis;}

	const std::string& GetOpis() const
	{ return m_Opis;}

protected:
	std::string m_Opis;
};

}//end of namespace OOP

/////////////////////////////////////////////////////////////////////////
int main(int argc, char * argv[])
{
	using namespace std;
	using namespace OOP;

	const RecLbl aRecLbl(5, 5, "aRecLbl");
	cout << "--------------------------------------" << endl;
	RecLbl bRecLbl(5, 5, "bRecLbl");
	cout << "--------------------------------------" << endl;
}

