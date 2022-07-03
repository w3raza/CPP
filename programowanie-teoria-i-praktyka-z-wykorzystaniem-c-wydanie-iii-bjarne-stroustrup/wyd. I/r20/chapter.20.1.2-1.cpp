
//
// To jest przyk�adowy kod z podrozdzia�u 20.1.2 �Uog�lnianie kodu� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

double* get_from_jack(int* count);  // Jacek wstawia liczby typu double do tablicy
//i zwraca liczb� element�w w *count.

vector<double>* get_from_jill();    // Agatka nape�nia wektor.

void fct()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);    
    vector<double>* jill_data = get_from_jill();    
    double h = -1;
    double* jack_high;    // Wska�nik jack_high b�dzie wskazywa� element o najwy�szej warto�ci.
    double* jill_high;    // Wska�nik jill_high b�dzie wskazywa� element o najwy�szej warto�ci.

    for (int i=0; i<jack_count; ++i)
        if (h< jack_data[i])
            jack_high = &jack_data [i];    // Zapisuje adres najwi�kszego elementu.

    h = -1;
    vector<double>& v = *jill_data;
    for (int i=0; i<v.size(); ++i) 
        if (h<v[i])
            jill_high = &v[i];

    cout << "Jill's max: " << *jill_high
        << "; Jack's max: " << *jack_high;

    delete[] jack_data;
    delete jill_data;
}

//------------------------------------------------------------------------------

int main()
{
    fct();
}

//------------------------------------------------------------------------------

double* get_from_jack(int* count)
{
    if (!count)
        return 0;

    const int n = 10;

    double* arr = new double[n];

    if (arr)
    {
        *count = n;

        for (int i = 0; i < n; ++i)
            arr[i] = i;
    }

    return arr;
}

//------------------------------------------------------------------------------

vector<double>* get_from_jill()
{
    const int n = 10;

    vector<double>* arr = new vector<double>(n);

    if (arr)
    {
        for (int i = 0; i < n; ++i)
            (*arr)[i] = i;
    }

    return arr;
}

//------------------------------------------------------------------------------
