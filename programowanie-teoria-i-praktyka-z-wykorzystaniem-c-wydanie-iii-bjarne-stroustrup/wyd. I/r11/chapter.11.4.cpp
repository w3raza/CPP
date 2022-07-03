
//
// To jest przyk�adowy kod z podrozdzia�u 11.4 �Strumienie �a�cuchowe� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double str_to_double(string s)
// Je�li to mo�liwe, konwertuje znaki znajduj�ce si� w s na warto�ci zmiennoprzecinkowe.
{
    istringstream is(s);    // Tworzy strumie�, aby mo�na by�o odczytywa� dane z s.
    double d;
    is >> d;
    if (!is) error("B��d formatu double: ",s);
    return d;
}

//------------------------------------------------------------------------------


void test()
try
{
    double d1 = str_to_double("12.4");               // testowanie
    double d2 = str_to_double("1.34e-3");
    double d3 = str_to_double("twelve point three"); // Wywo�a funkcj� error().
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
}
catch (...) {
    cerr << "Nieznany wyj�tek.\n"; 
}

//------------------------------------------------------------------------------

struct Temperature 
{
    double temp;
    string unit;
};

//------------------------------------------------------------------------------

void my_code(string label, Temperature temp)
{
    // ...
    ostringstream os;    // Strumie� do budowania komunikatu.
    os << setw(8) << label << ": "
       << fixed << setprecision(5) << temp.temp << temp.unit;
    //someobject.display(Point(100,100), os.str().c_str());
    // ...
}

//------------------------------------------------------------------------------

int get_next_number() // Pobiera numer pliku dziennika.
{
    static int n = 0;
    return n;
}

//------------------------------------------------------------------------------

int main()
try
{
    test();
    int seq_no = get_next_number();       // Pobiera numer pliku dziennika.
    ostringstream name;
    name << "plik" << seq_no;           // np. plik17
    ofstream logfile(name.str().c_str()); // np. otwiera plik17
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek.\n"; 
    return 2;
}

//------------------------------------------------------------------------------
