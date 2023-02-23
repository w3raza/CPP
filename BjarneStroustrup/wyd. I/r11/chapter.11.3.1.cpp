
//
// To jest przyk³adowy kod z podrozdzia³u 11.3.1 „Tryby otwierania plików” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <fstream>

//------------------------------------------------------------------------------

using namespace std;

int main()
{
    const char* name  = "myfile0";
    const char* name1 = "myfile1";
    const char* name2 = "myfile2";

    ofstream of1(name1);    // stosuje domyœlny tryb ios_base::out
    ifstream if1(name2);    // stosuje domyœlny tryb ios_base::in

    ofstream ofs(name, ios_base::app);            // strumienie ofstream pracuj¹ domyœlnie w trybie out
    fstream fs("myfile", ios_base::in|ios_base::out); // in i out

    if (!fs)
    {
        // Nie da³o siê otworzyæ pliku w ten sposób.
    }

    ifstream ifs("redungs");
    if (!ifs)
    {
        // B³¹d: nie mo¿na otworzyæ pliku „readings” w trybie do odczytu.
    }

    {
        ofstream ofs("nie-ma-takiego-pliku");        // Utworzy nowy plik o nazwie nie-ma-takiego-pliku.
        ofstream ifs("nie-ma-pliku-o-takiej-nazwie"); // B³¹d: strumieñ ifs bêdzie w innym stanie ni¿ good().
    }
}

//------------------------------------------------------------------------------
