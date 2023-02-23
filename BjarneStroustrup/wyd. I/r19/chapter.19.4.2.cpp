
//
// To jest przyk�adowy kod z podrozdzia�u 19.4.2 �Wyznanie na temat makr� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

//------------------------------------------------------------------------------

// Klasa do raportowania o b��dach zakresu.
struct out_of_range 
{
    out_of_range(const std::string& error_message) {}
};

//------------------------------------------------------------------------------

struct Range_error : out_of_range { // Ulepszony wektor zg�aszaj�cy b��dy zakresu.
    int index;
    Range_error(int i) :out_of_range("B��d zakresu"), index(i) { }
};

//------------------------------------------------------------------------------

template<class T> struct Vector : public std::vector<T> {
    typedef typename std::vector<T>::size_type size_type;

    Vector() { }
    Vector(size_type n) :std::vector<T>(n) {}
    Vector(size_type n, const T& v) :std::vector<T>(n,v) {}

    T& operator[](unsigned int i) // zamiast return at(i);
    {
        if (i<0||this->size()<=i) throw Range_error(i);
        return std::vector<T>::operator[](i);
    }

    const T& operator[](unsigned int i) const
    {
        if (i<0||this->size()<=i) throw Range_error(i);
        return std::vector<T>::operator[](i);
    }
};

//------------------------------------------------------------------------------

// Obrzydliwa sztuczka przy u�yciu makra, kt�rej celem jest uzyskanie kontrolowanego wektora:
#define vector Vector

int main()
try
{
    vector<int> v(10);
    v[20] = 5; // Pr�ba dost�pu do nieprawid�owego indeksu.
}
catch (std::exception& e) {
    std::cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    std::cerr << "Ojej: nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
