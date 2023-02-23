
//
// To jest przyk�adowy kod z podrozdzia�u 23.2 ��a�cuchy� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

basic_string<Unicode> a_unicode_string;

//typedef basic_string<char> string;    // string oznacza basic_string<char>.

template<class T>
string to_string(const T& t)
{
    ostringstream os;
    os << t;
    return os.str();
}

//------------------------------------------------------------------------------

struct bad_from_string : std::bad_cast
    // Klasa do raportowania b��d�w zwi�zanych z rzutowaniem �a�cuch�w.
{
    const char* what() const throw()    // Przes�oni�cie funkcji what() klasy bad_cast.
    {
        return "bad cast from string";
    }
};

//------------------------------------------------------------------------------

template<class T> T from_string(const string& s)
{
    istringstream is(s);
    T t;
    if (!(is >> t)) throw bad_from_string();
    return t;
}

//------------------------------------------------------------------------------

void do_something(const string s)
try
{
    int i = from_string<int>(s);
    // ...
}
catch (bad_from_string e) {
    error ("Niepoprawny �a�cuch na wej�ciu.",s);
};

//------------------------------------------------------------------------------

int main()
try
{
    string s1 = to_string(12.333);
    string s2 = to_string(1+5*6-99/7);
    double d = from_string<double>("12.333");
    do_something("Gdyby k�zka nie skaka�a");
    int g = from_string<int>("Gdyby k�zka nie skaka�a");    // oops!
}
catch (std::exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
};

//------------------------------------------------------------------------------

struct bad_lexical_cast : std::bad_cast
{
    const char* what() const throw() { return "Nieprawid�owe rzutowanie"; }
};

//------------------------------------------------------------------------------

template<typename Target, typename Source>
Target lexical_cast(Source arg)
{
    std::stringstream interpreter;
    Target result;

    if (!(interpreter << arg)        // Wczytuje arg do strumienia.
        || !(interpreter >> result)        // Wczytuje result ze strumienia.
        || !(interpreter >> std::ws).eof())    // Zosta�o co� w strumieniu?
        throw bad_lexical_cast();

    return result;
}

//------------------------------------------------------------------------------
