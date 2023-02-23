
#include <iostream>
#include "Matrix.h"

namespace Numeric_lib {

//-----------------------------------------------------------------------------

template<class T> std::ostream& operator<<(std::ostream& os, const Matrix<T>& v)
{
    os << '{';

    for (Index i = 0; i<v.dim1(); ++i) {
        os << "  ";
        os << v(i);
    }

    os << '}';
    return os;
}

//-----------------------------------------------------------------------------

template<class T> std::ostream& operator<<(std::ostream& os, const Matrix<T,2>& m)
{
    os << "{\n";

    for (Index i = 0; i<m.dim1(); ++i)
        os << m[i] << '\n';

    os << '}';
    return os;
}

//-----------------------------------------------------------------------------

template<class T> std::istream& operator>>(std::istream& is, Matrix<T>& v)
{
    char ch;
    is >> ch;

    if (ch!='{') error("Brak '{' w Matrix<T,1> na wejœciu.");

    for (Index i = 0; i<v.dim1(); ++i)
        is >> v(i);

    is >> ch;

    if (ch!='}') error("Brak '{' w Matrix<T,1> na wejœciu.");
  
    return is;
}

//-----------------------------------------------------------------------------

template<class T> std::istream& operator>>(std::istream& is, Matrix<T,2>& m)
{
    char ch;
    is >> ch;

    if (ch!='{') error("Brak '{' w Matrix<T,2> na wejœciu.");

    for (Index i = 0; i<m.dim1(); ++i)
    {
        Matrix<T,1> tmp(m.dim2());
        is >> tmp;
        m[i] = tmp;
    }

    is >> ch;

    if (ch!='}') error("Brak '{' w Matrix<T,2> na wejœciu.");

    return is;
}

//-----------------------------------------------------------------------------

}
