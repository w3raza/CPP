
//
// To jest przyk³adowy kod z podrozdzia³u 23.4 „S³owniki” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>

using namespace std;

//------------------------------------------------------------------------------

// Obiekt klasy message to zgodnie z nasz¹ definicj¹ para iteratorów wektora vector<string> (naszego wektora wierszy tekstu):
typedef vector<string>::const_iterator Line_iter;

class Message {  // Message wskazuje pierwszy i ostatni wiersz wiadomoœci.
    Line_iter first;
    Line_iter last;
public:
    Message(Line_iter p1, Line_iter p2) :first(p1), last(p2) { }
    Line_iter begin() const { return first; }
    Line_iter end() const { return last; }
    // ...
};

//------------------------------------------------------------------------------

typedef vector<Message>::const_iterator Mess_iter;

//------------------------------------------------------------------------------

// Mail_file przechowuje wszystkie wiersze z pliku i wiadomoœci
struct Mail_file {        // Mail_file przechowuje wszystkie wiersze z pliku
                          // i u³atwia dostêp do wiadomoœci.
    string name;          // nazwa pliku
    vector<string> lines; // uporz¹dkowane wiersze
    vector<Message> m;    // uporz¹dkowane wiadomoœci

    Mail_file(const string& n);  // wczytuje plik n do lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

//------------------------------------------------------------------------------

// Znajduje nazwê nadawcy wiadomoœci.
// Zwraca true, jeœli znajdzie nazwê i
// Wstawia nazwê nadawcy do s, jeœli j¹ znajdzie
bool find_from_addr(const Message* m, string& s);

//------------------------------------------------------------------------------

// Zwraca temat wiadomoœci, jeœli jest, lub "" w przeciwnym przypadku
string find_subject(const Message* m);

//------------------------------------------------------------------------------

int main()
{
    Mail_file mfile("my-mail-file.txt");        // Inicjacja mfile zawartoœci¹ pliku.

    // Najpierw gromadzone s¹ wszystkie wiadomoœci w kontenerze multimap:

    multimap<string, const Message*> sender;

    for (Mess_iter p = mfile.begin(); p!=mfile.end(); ++p) {
        const Message& m = *p;
        string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }

    // Iteracja przez kontener multimap
    // i wydobywanie tematów wiadomoœci od Jana Zebry:
    typedef multimap<string, const Message*>::const_iterator MCI;
    pair<MCI,MCI> pp = sender.equal_range("Jan Zebra");
    for(MCI p = pp.first; p!=pp.second; ++p)
        cout << find_subject(p->second) << '\n';
}

//------------------------------------------------------------------------------
