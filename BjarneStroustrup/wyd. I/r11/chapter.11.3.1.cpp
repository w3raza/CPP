
//
// To jest przyk�adowy kod z podrozdzia�u 11.3.1 �Tryby otwierania plik�w� ksi��ki 
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

    ofstream of1(name1);    // stosuje domy�lny tryb ios_base::out
    ifstream if1(name2);    // stosuje domy�lny tryb ios_base::in

    ofstream ofs(name, ios_base::app);            // strumienie ofstream pracuj� domy�lnie w trybie out
    fstream fs("myfile", ios_base::in|ios_base::out); // in i out

    if (!fs)
    {
        // Nie da�o si� otworzy� pliku w ten spos�b.
    }

    ifstream ifs("redungs");
    if (!ifs)
    {
        // B��d: nie mo�na otworzy� pliku �readings� w trybie do odczytu.
    }

    {
        ofstream ofs("nie-ma-takiego-pliku");        // Utworzy nowy plik o nazwie nie-ma-takiego-pliku.
        ofstream ifs("nie-ma-pliku-o-takiej-nazwie"); // B��d: strumie� ifs b�dzie w innym stanie ni� good().
    }
}

//------------------------------------------------------------------------------
