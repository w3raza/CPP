
//
// To jest przyk³adowy kod z podrozdzia³u 11.4 „Strumienie ³añcuchowe” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double str_to_double(string s)
// Jeœli to mo¿liwe, konwertuje znaki znajduj¹ce siê w s na wartoœci zmiennoprzecinkowe.
{
    istringstream is(s);    // Tworzy strumieñ, aby mo¿na by³o odczytywaæ dane z s.
    double d;
    is >> d;
    if (!is) error("B³¹d formatu double: ",s);
    return d;
}

//------------------------------------------------------------------------------


void test()
try
{
    double d1 = str_to_double("12.4");               // testowanie
    double d2 = str_to_double("1.34e-3");
    double d3 = str_to_double("twelve point three"); // Wywo³a funkcjê error().
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
}
catch (...) {
    cerr << "Nieznany wyj¹tek.\n"; 
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
    ostringstream os;    // Strumieñ do budowania komunikatu.
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
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek.\n"; 
    return 2;
}

//------------------------------------------------------------------------------
