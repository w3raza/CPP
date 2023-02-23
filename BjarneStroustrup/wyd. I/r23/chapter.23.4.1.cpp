
//
// To jest przyk�adowy kod z podrozdzia�u 23.4.1 �Szczeg�y implementacyjne� ksi��ki
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

// Mail_file przechowuje wszystkie wiersze z pliku
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

Mail_file::Mail_file(const string& n)
    // Otwiera plik o nazwie n.
    // Wczytuje wiersze z n do wektora lines.
    // Znajduje wiadomo�ci w lines i zapisuje je w m.
    // Dla uproszczenia zak�adamy, �e ka�d� wiadomo�� ko�czy wiersz "����".
{
    ifstream in(n.c_str());    // otwiera plik
    if (!in) {
        cerr << "nieudane " << n << '\n';
        exit(1);
    }
    
    string s;
    while (getline(in,s)) lines.push_back(s);    // buduje wektor wierszy

    Line_iter first = lines.begin();    // buduje wektor wiadomo�ci
    for (Line_iter p = lines.begin(); p!=lines.end(); ++p) {
        if (*p == "----") {    // koniec wiadomo�ci
            m.push_back(Message(first,p));
            first = p+1;     // ���� nie jest cz�ci� wiadomo�ci
        }
    }
}

//------------------------------------------------------------------------------

int is_prefix(const string& s, const string& p)
    // Czy *p jest pierwsz� cz�ci� s?
{
    int n = p.size();
    if (string(s,0,n)==p) return n;
    return 0;
}

//------------------------------------------------------------------------------

bool find_from_addr(const Message* m, string& s)
{
    for(Line_iter p = m->begin(); p!=m->end(); ++p)
        if (int n = is_prefix(*p,"From: ")) {
            s = string(*p,n);
            return true;
        }
    return false;
}

//------------------------------------------------------------------------------

string find_subject(const Message& m)
{
    for(Line_iter p = m.begin(); p!=m.end(); ++p)
        if (int n = is_prefix(*p,"Subject: ")) return string(*p,n);
    return "";
}

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
        cout << find_subject(*p->second) << '\n';
}

//------------------------------------------------------------------------------
