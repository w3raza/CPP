
//
// To jest przyk³adowy kod z podrozdzia³u 11.3.2 „Pliki binarne” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class T>
char* as_bytes(T& i)    // Traktuje T jako sekwencjê bajtów.
{
    void* addr = &i;    // Pobiera adres pierwszego bajta
    // w pamiêci, w której zosta³ zapisany obiekt.
    return static_cast<char*>(addr); // Traktuje tê pamiêæ jako bajty.
}

//------------------------------------------------------------------------------

int main()
try
{
    // Otwieramy strumieñ istream w binarnym trybie odczytu pliku:
	cout << "Podaj nazwê pliku wejœciowego:\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str(),ios_base::binary);    // Uwaga: tryb strumienia
    // „binary” oznacza dla niego, ¿e ma siê za bardzo nie ciekawiæ znaczeniem bajtów.
    if (!ifs) error("Nie mo¿na otworzyæ pliku wejœciowego ", name);

    // Otwieramy strumieñ ostream w binarnym trybie do zapisu:
    cout << "Podaj nazwê pliku wyjœciowego:\n";
    cin >> name;
    ofstream ofs(name.c_str(),ios_base::binary);    // Uwaga: tryb strumienia
        // „binary” oznacza dla niego, ¿e ma siê za bardzo nie ciekawiæ znaczeniem bajtów.
    if (!ofs) error("Nie mo¿na otworzyæ pliku wyjœciowego ",name);

    vector<int> v;

    // Odczyt z pliku binarnego:
    int i;
    while (ifs.read(as_bytes(i),sizeof(int))) // Uwaga: wczytywanie bajtów.
        v.push_back(i);    

    //  operacje przy u¿yciu v

    // Zapisywanie do pliku binarnego:
    for(int i=0; i<v.size(); ++i)
        ofs.write(as_bytes(v[i]),sizeof(int));    // Uwaga: zapisywanie bajtów.
    return 0;
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
