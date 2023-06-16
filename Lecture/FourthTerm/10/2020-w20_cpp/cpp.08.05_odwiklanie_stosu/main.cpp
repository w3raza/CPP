#include <iostream>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////
class Test1
{
public:
  Test1(string nazwa = "") : m_nazwa(nazwa)
  {
    cout << "Konstruktor Test1(" << m_nazwa << ")\n";
  }

  virtual ~Test1() { cout << "Destruktor Test1(" << m_nazwa << ")\n"; }

  virtual void print() const { cout << m_nazwa << "\n"; }

protected:
  string m_nazwa;
};

/////////////////////////////////////////////////////////////////////////
class Test2 : public Test1
{
public:
  Test2(string nazwa = "") : Test1(nazwa)
  {
    cout << "Konstruktor Test2(" << m_nazwa << ")\n";
  }

  virtual ~Test2() { cout << "Destruktor Test2(" << m_nazwa << ")\n"; }
};

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{

  Test1  a("aTest1");
  Test2  b("bTest2");
  Test1 *ptr;

  try
  {
    int   a = 0;
    Test1 c("cTest1");
    Test2 d("dTest2");

    ptr = new Test1("ptrTest1");

    cout << "\nRzucam\n";
    throw a;
  }
  catch (const int &)
  {
    cout << "\nPo zlapaniu wyjatku\n";
  }
  ptr->print();
}