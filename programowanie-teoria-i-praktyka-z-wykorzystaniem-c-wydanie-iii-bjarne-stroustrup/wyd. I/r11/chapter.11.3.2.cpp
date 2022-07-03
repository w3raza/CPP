
//
// To jest przyk�adowy kod z podrozdzia�u 11.3.2 �Pliki binarne� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

template<class T>
char* as_bytes(T& i)    // Traktuje T jako sekwencj� bajt�w.
{
    void* addr = &i;    // Pobiera adres pierwszego bajta
    // w pami�ci, w kt�rej zosta� zapisany obiekt.
    return static_cast<char*>(addr); // Traktuje t� pami�� jako bajty.
}

//------------------------------------------------------------------------------

int main()
try
{
    // Otwieramy strumie� istream w binarnym trybie odczytu pliku:
	cout << "Podaj nazw� pliku wej�ciowego:\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str(),ios_base::binary);    // Uwaga: tryb strumienia
    // �binary� oznacza dla niego, �e ma si� za bardzo nie ciekawi� znaczeniem bajt�w.
    if (!ifs) error("Nie mo�na otworzy� pliku wej�ciowego ", name);

    // Otwieramy strumie� ostream w binarnym trybie do zapisu:
    cout << "Podaj nazw� pliku wyj�ciowego:\n";
    cin >> name;
    ofstream ofs(name.c_str(),ios_base::binary);    // Uwaga: tryb strumienia
        // �binary� oznacza dla niego, �e ma si� za bardzo nie ciekawi� znaczeniem bajt�w.
    if (!ofs) error("Nie mo�na otworzy� pliku wyj�ciowego ",name);

    vector<int> v;

    // Odczyt z pliku binarnego:
    int i;
    while (ifs.read(as_bytes(i),sizeof(int))) // Uwaga: wczytywanie bajt�w.
        v.push_back(i);    

    //  operacje przy u�yciu v

    // Zapisywanie do pliku binarnego:
    for(int i=0; i<v.size(); ++i)
        ofs.write(as_bytes(v[i]),sizeof(int));    // Uwaga: zapisywanie bajt�w.
    return 0;
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
