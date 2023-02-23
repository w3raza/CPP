
//
// To jest przyk³adowy kod z podrozdzia³u 23.4.1 „Szczegó³y implementacyjne” ksi¹¿ki
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

// Mail_file przechowuje wszystkie wiersze z pliku
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

Mail_file::Mail_file(const string& n)
    // Otwiera plik o nazwie n.
    // Wczytuje wiersze z n do wektora lines.
    // Znajduje wiadomoœci w lines i zapisuje je w m.
    // Dla uproszczenia zak³adamy, ¿e ka¿d¹ wiadomoœæ koñczy wiersz "––––".
{
    ifstream in(n.c_str());    // otwiera plik
    if (!in) {
        cerr << "nieudane " << n << '\n';
        exit(1);
    }
    
    string s;
    while (getline(in,s)) lines.push_back(s);    // buduje wektor wierszy

    Line_iter first = lines.begin();    // buduje wektor wiadomoœci
    for (Line_iter p = lines.begin(); p!=lines.end(); ++p) {
        if (*p == "----") {    // koniec wiadomoœci
            m.push_back(Message(first,p));
            first = p+1;     // –––– nie jest czêœci¹ wiadomoœci
        }
    }
}

//------------------------------------------------------------------------------

int is_prefix(const string& s, const string& p)
    // Czy *p jest pierwsz¹ czêœci¹ s?
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
        cout << find_subject(*p->second) << '\n';
}

//------------------------------------------------------------------------------
