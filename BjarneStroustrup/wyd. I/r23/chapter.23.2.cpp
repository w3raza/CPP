
//
// To jest przyk³adowy kod z podrozdzia³u 23.2 „£añcuchy” ksi¹¿ki
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
    // Klasa do raportowania b³êdów zwi¹zanych z rzutowaniem ³añcuchów.
{
    const char* what() const throw()    // Przes³oniêcie funkcji what() klasy bad_cast.
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
    error ("Niepoprawny ³añcuch na wejœciu.",s);
};

//------------------------------------------------------------------------------

int main()
try
{
    string s1 = to_string(12.333);
    string s2 = to_string(1+5*6-99/7);
    double d = from_string<double>("12.333");
    do_something("Gdyby kózka nie skaka³a");
    int g = from_string<int>("Gdyby kózka nie skaka³a");    // oops!
}
catch (std::exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
};

//------------------------------------------------------------------------------

struct bad_lexical_cast : std::bad_cast
{
    const char* what() const throw() { return "Nieprawid³owe rzutowanie"; }
};

//------------------------------------------------------------------------------

template<typename Target, typename Source>
Target lexical_cast(Source arg)
{
    std::stringstream interpreter;
    Target result;

    if (!(interpreter << arg)        // Wczytuje arg do strumienia.
        || !(interpreter >> result)        // Wczytuje result ze strumienia.
        || !(interpreter >> std::ws).eof())    // Zosta³o coœ w strumieniu?
        throw bad_lexical_cast();

    return result;
}

//------------------------------------------------------------------------------
