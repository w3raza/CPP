
//
// To jest przyk³adowy kod z podrozdzia³u 11.7 „Stosowanie niestandardowych separatorów” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

class Punct_stream { // Podobna do istream, ale umo¿liwia rozszerzanie
                     // zestawu bia³ych znaków.
public:
    Punct_stream(istream& is)
        : source(is), sensitive(true) { }

    void whitespace(const string& s)       // s jest zbiorem bia³ych znaków.
    { white = s; }    
    void add_white(char c) { white += c; } // Dodaje znak do zbioru bia³ych znaków.
    bool is_whitespace(char c);            // Czy c nale¿y do zbioru bia³ych znaków?

    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; }

    Punct_stream& operator>>(string& s);
    operator bool();
private:
    istream& source;       // Ÿród³o znaków
    istringstream buffer;  // Formatowanie wykonuje bufor.
    string white;          // Znaki uznawane za „bia³e”.
    bool sensitive;        // Czy strumieñ rozpoznaje wielkoœæ liter?
};

//------------------------------------------------------------------------------

Punct_stream& Punct_stream::operator>>(string& s)
{
    while (!(buffer>>s)) {    // Próba wczytania danych z bufora.
        if (buffer.bad() || !source.good()) return *this;
        buffer.clear();

        string line;
        getline(source,line); // Pobranie wiersza danych ze Ÿród³a (source).

        // Zastêpowanie znaków zgodnie z potrzeb¹:
        for (int i =0; i<line.size(); ++i)
            if (is_whitespace(line[i]))
                line[i]= ' ';
            else if (!sensitive)
                line[i] = tolower(line[i]);

        buffer.str(line);     // Wstawianie ³añcucha do strumienia.
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
// Przyjmuje tekst. Tworzy posortowan¹ listê wszystkich s³ów w tym tekœcie,
// ignoruje interpunkcjê i ró¿nice wielkoœci liter oraz
// usuwa duplikaty z danych wyjœciowych.

{
    Punct_stream ps(cin);
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~"); // Zauwa¿, ¿e \" oznacza " w ³añcuchu.
    ps.case_sensitive(false);

    cout << "Wpisz s³owa.\n";
    vector<string> vs;
    string word;
    while (ps>>word) vs.push_back(word);    // Wczytuje s³owa.

    sort(vs.begin(),vs.end());              // Sortuje w porz¹dku leksykograficznym.
    for (int i=0; i<vs.size(); ++i)         // Zapisuje s³ownik.
        if (i==0 || vs[i]!=vs[i-1]) cout << vs[i] << endl;
}

//------------------------------------------------------------------------------
