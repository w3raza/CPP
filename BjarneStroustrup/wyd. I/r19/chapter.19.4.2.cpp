
//
// To jest przyk³adowy kod z podrozdzia³u 19.4.2 „Wyznanie na temat makr” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

//------------------------------------------------------------------------------

// Klasa do raportowania o b³êdach zakresu.
struct out_of_range 
{
    out_of_range(const std::string& error_message) {}
};

//------------------------------------------------------------------------------

struct Range_error : out_of_range { // Ulepszony wektor zg³aszaj¹cy b³êdy zakresu.
    int index;
    Range_error(int i) :out_of_range("B³¹d zakresu"), index(i) { }
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

// Obrzydliwa sztuczka przy u¿yciu makra, której celem jest uzyskanie kontrolowanego wektora:
#define vector Vector

int main()
try
{
    vector<int> v(10);
    v[20] = 5; // Próba dostêpu do nieprawid³owego indeksu.
}
catch (std::exception& e) {
    std::cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    std::cerr << "Ojej: nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
