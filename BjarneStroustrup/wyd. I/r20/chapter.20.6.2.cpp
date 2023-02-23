
//
// To jest przyk³adowy kod z podrozdzia³u 20.6.2 „Iteracja” ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

typedef vector<char> Line;    // Wiersz jest wektorem znaków.

//------------------------------------------------------------------------------

class Text_iterator { // Œledzi pozycjê wiersza i znaku w wierszu.
    list<Line>::iterator ln;
    Line::iterator pos;
public:
    typedef forward_iterator_tag iterator_category;
    typedef char value_type;
    typedef size_t difference_type;
    typedef char* pointer;
    typedef char& reference;

    // Zaczyna iterator w pozycji znakowej pp wiersza ll:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp)
        :ln(ll), pos(pp) { }

    char& operator*() { return *pos; }
    Text_iterator& operator++();
    bool operator==(const Text_iterator& other) const;
    bool operator!=(const Text_iterator& other) const { return !(*this==other); }
};

//------------------------------------------------------------------------------

Text_iterator& Text_iterator::operator++()
{
    if (pos==(*ln).end()) {
        ++ln;            // przejœcie do nastêpnego wiersza
        pos = (*ln).begin();
    }
    ++pos;                // przejœcie do nastêpnego znaku
    return *this;
}

//------------------------------------------------------------------------------

bool Text_iterator::operator==(const Text_iterator& other) const
{ 
    return ln == other.ln && pos == other.pos;
}

//------------------------------------------------------------------------------

struct Document {
    list<Line> line; 
    Document() { line.push_back(Line()); }
    Text_iterator begin()      // Pierwszy znak pierwszego wiersza.
    { return Text_iterator(line.begin(), line.begin()->begin()); }    
    Text_iterator end()        // Jedno miejsce za ostatnim wierszem.
    { 
        list<Line>::iterator last = line.end(); 
        --last; 
        return Text_iterator(last, last->end()); 
    }
};

//------------------------------------------------------------------------------

void print(Document& d)
{
    for (Text_iterator p = d.begin(); p!=d.end(); ++p) cout << *p;
}

//------------------------------------------------------------------------------

template<class Iter> Iter advance(Iter p, int n)
{
    while (n>0) { ++p; --n; }    // do przodu
    return p;
}

//------------------------------------------------------------------------------

void erase_line(Document& d, int n)
{
    if (n<0 || d.line.size()<=n) return;    // Ignoruje wiersze spoza zakresu.
    d.line.erase(advance(d.line.begin(), n));
}

//------------------------------------------------------------------------------

bool match(Text_iterator first, Text_iterator last, const string& s)
{
    string::const_iterator p;

    for(p = s.begin(); 
        p != s.end() && first != last && *p == *first; 
        ++p, ++first)
    {}

    return p == s.end();
}

//------------------------------------------------------------------------------

Text_iterator find_text(Text_iterator first, Text_iterator last, const string& s)
{
    if (s.size()==0) return last;    // Nie mo¿na szukaæ pustego ³añcucha.
    char first_char = s[0];
    while (true) {
        Text_iterator p = find(first,last,first_char);
        if (p==last || match(p,last,s)) return p;
    }
}

//------------------------------------------------------------------------------

int main()
{
    Document my_doc;

    Text_iterator p =
        find_text(my_doc.begin(), my_doc.end(),"sekret\nzagroda");
    if (p==my_doc.end())
        cout << "Nie znaleziono.";
    else {
        // Jakieœ instrukcje
    }

    print(my_doc);
}

//------------------------------------------------------------------------------
