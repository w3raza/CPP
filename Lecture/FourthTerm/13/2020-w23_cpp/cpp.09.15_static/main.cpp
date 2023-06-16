#include "CFraction.h"
#include "OOPFunTemplates.h"
#include <exception>
#include <iostream>

namespace OOP {
/////////////////////////////////////////////////////////////////////////
template <typename T> class BoxOpis
{
public:
  static int nr;
  static T   last;

  BoxOpis()
  {
    nr++;
  }

  ~BoxOpis()
  {
    nr--;
  }

  void SetT(const T &obj)
  {
    last = box = obj;
  }

  void SetOpis(const std::string &opis)
  {
    this->opis = opis;
  }

  T GetT() const
  {
    return box;
  }

  const std::string& GetOpis() const
  {
    return opis;
  }

private:
  T           box;
  std::string opis;
};
/////////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream &operator<<(std::ostream &o, const BoxOpis<T> &K)
{
  o << K.GetOpis().c_str() << ": " << K.GetT();
  return o;
}

// Skladniki statyczne dla BoxOpis
template <typename T> int BoxOpis<T>::nr;
template <typename T> T   BoxOpis<T>::last;

} // End of namespace

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  using namespace std;

  OOP::BoxOpis<double> a, b, c, f;

  f.SetT(3.14159);
  f.SetOpis("M_PI");

  cout << "Skladniki statyczne BoxOpis<double>: " << OOP::BoxOpis<double>::nr << ", "
       << OOP::BoxOpis<double>::last << endl;

  OOP::BoxOpis<OOP::CFraction> aF, bF, fF;

  fF.SetT(OOP::CFraction(1, 4));

  cout << "Skladniki statyczne BoxOpis<CFraction>: " << OOP::BoxOpis<OOP::CFraction>::nr
       << ", " << OOP::BoxOpis<OOP::CFraction>::last << endl;

  return 0;
}
