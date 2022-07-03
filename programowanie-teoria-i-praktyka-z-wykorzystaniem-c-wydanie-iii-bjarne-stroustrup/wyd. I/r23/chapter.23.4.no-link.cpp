
//
// To jest przyk�adowy kod z podrozdzia�u 23.4 �S�owniki� ksi��ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>

using namespace std;

//------------------------------------------------------------------------------

// Obiekt klasy message to zgodnie z nasz� definicj� para iterator�w wektora vector<string> (naszego wektora wierszy tekstu):
typedef vector<string>::const_iterator Line_iter;

class Message {  // Message wskazuje pierwszy i ostatni wiersz wiadomo�ci.
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

// Mail_file przechowuje wszystkie wiersze z pliku i wiadomo�ci
struct Mail_file {        // Mail_file przechowuje wszystkie wiersze z pliku
                          // i u�atwia dost�p do wiadomo�ci.
    string name;          // nazwa pliku
    vector<string> lines; // uporz�dkowane wiersze
    vector<Message> m;    // uporz�dkowane wiadomo�ci

    Mail_file(const string& n);  // wczytuje plik n do lines

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

//------------------------------------------------------------------------------

// Znajduje nazw� nadawcy wiadomo�ci.
// Zwraca true, je�li znajdzie nazw� i
// Wstawia nazw� nadawcy do s, je�li j� znajdzie
bool find_from_addr(const Message* m, string& s);

//------------------------------------------------------------------------------

// Zwraca temat wiadomo�ci, je�li jest, lub "" w przeciwnym przypadku
string find_subject(const Message* m);

//------------------------------------------------------------------------------

int main()
{
    Mail_file mfile("my-mail-file.txt");        // Inicjacja mfile zawarto�ci� pliku.

    // Najpierw gromadzone s� wszystkie wiadomo�ci w kontenerze multimap:

    multimap<string, const Message*> sender;

    for (Mess_iter p = mfile.begin(); p!=mfile.end(); ++p) {
        const Message& m = *p;
        string s;
        if (find_from_addr(&m,s))
            sender.insert(make_pair(s,&m));
    }

    // Iteracja przez kontener multimap
    // i wydobywanie temat�w wiadomo�ci od Jana Zebry:
    typedef multimap<string, const Message*>::const_iterator MCI;
    pair<MCI,MCI> pp = sender.equal_range("Jan Zebra");
    for(MCI p = pp.first; p!=pp.second; ++p)
        cout << find_subject(p->second) << '\n';
}

//------------------------------------------------------------------------------
