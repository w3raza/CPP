
//
// To jest przyk³adowy kod z podrozdzia³u 24.9 „Liczby zespolone” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <complex>
#include <numeric>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

namespace my
{
    template<class Scalar> class complex {
        // Liczba zespolona to para wartoœci skalarnych — zasadniczo para wspó³rzêdnych.
        Scalar re, im;
    public: 
        complex(const Scalar & r, const Scalar & i) :re(r), im(i) { }
        complex(const Scalar & r) :re(r),im(Scalar ()) { }
        complex() :re(Scalar ()), im(Scalar ()) { }

        Scalar real() { return re; }    // czêœæ rzeczywista
        Scalar imag() { return im; }    // czêœæ urojona

        // operatory:  =  +=  -=  *=  /=
    };
}

//------------------------------------------------------------------------------

typedef complex<double> dcmplx;    // Czasami wektor complex<double> potrafi byæ bardzo rozleg³y.

//------------------------------------------------------------------------------

void f(dcmplx z, vector< complex<double> >& vc)
{
    dcmplx z2 = pow(z,2);
    dcmplx z3 = z2*9.0+vc[3];
    dcmplx  sum = accumulate(vc.begin(), vc.end(), dcmplx());
    // ...
    //if (z2<z3) // B³¹d: nie ma operatora < dla liczb zespolonych.
}

//------------------------------------------------------------------------------

int main()
{
    dcmplx d[10] = {
        dcmplx(1,2), 
        dcmplx(2,3), 
        dcmplx(3,4), 
        dcmplx(4,5), 
        dcmplx(5,6), 
        dcmplx(6,7), 
        dcmplx(7,8), 
        dcmplx(8,9), 
        dcmplx(9,0), 
        dcmplx(0,1)
    };
    vector<dcmplx> v(d,d+10);
    f(d[0], v);
}

//------------------------------------------------------------------------------
