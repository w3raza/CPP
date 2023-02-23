
//
// To jest przyk�adowy kod z podrozdzia�u 11.7 �Stosowanie niestandardowych separator�w� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Punct_stream { // Podobna do istream, ale umo�liwia rozszerzanie
                     // zestawu bia�ych znak�w.
public:
    Punct_stream(istream& is)
        : source(is), sensitive(true) { }

    void whitespace(const string& s)       // s jest zbiorem bia�ych znak�w.
    { white = s; }    
    void add_white(char c) { white += c; } // Dodaje znak do zbioru bia�ych znak�w.
    bool is_whitespace(char c);            // Czy c nale�y do zbioru bia�ych znak�w?

    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; }

    Punct_stream& operator>>(string& s);
    operator bool();
private:
    istream& source;       // �r�d�o znak�w
    istringstream buffer;  // Formatowanie wykonuje bufor.
    string white;          // Znaki uznawane za �bia�e�.
    bool sensitive;        // Czy strumie� rozpoznaje wielko�� liter?
};

//------------------------------------------------------------------------------

Punct_stream& Punct_stream::operator>>(string& s)
{
    while (!(buffer>>s)) {    // Pr�ba wczytania danych z bufora.
        if (buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        getline(source,line); // Pobranie wiersza danych ze �r�d�a (source).

        // Zast�powanie znak�w zgodnie z potrzeb�:
        for (int i =0; i<line.size(); ++i)
            if (is_whitespace(line[i]))
                line[i]= ' ';
            else if (!sensitive)
                line[i] = tolower(line[i]);

        buffer.str(line);     // Wstawianie �a�cucha do strumienia.
    }
    return *this;
}

//------------------------------------------------------------------------------

bool Punct_stream::is_whitespace(char c)
{
    for (int i = 0; i<white.size(); ++i) if (c==white[i]) return true;
    return false;
}

//------------------------------------------------------------------------------

Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && source.good();
}

//------------------------------------------------------------------------------

int main()
// Przyjmuje tekst. Tworzy posortowan� list� wszystkich s��w w tym tek�cie,
// ignoruje interpunkcj� i r�nice wielko�ci liter oraz
// usuwa duplikaty z danych wyj�ciowych.

{
    Punct_stream ps(cin);
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~"); // Zauwa�, �e \" oznacza " w �a�cuchu.
    ps.case_sensitive(false);

    cout << "Wpisz s�owa.\n";
    vector<string> vs;
    string word;
    while (ps>>word) vs.push_back(word);    // Wczytuje s�owa.

    sort(vs.begin(),vs.end());              // Sortuje w porz�dku leksykograficznym.
    for (int i=0; i<vs.size(); ++i)         // Zapisuje s�ownik.
        if (i==0 || vs[i]!=vs[i-1]) cout << vs[i] << endl;
}

//------------------------------------------------------------------------------
