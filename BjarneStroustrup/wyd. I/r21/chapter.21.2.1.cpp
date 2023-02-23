
//
// To jest przyk³adowy kod z podrozdzia³u 21.2.1 "Kilka przyk³adów z programowania ogólnego" ksi¹¿ki
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

    // Zaczyna iterator od znaku pp wiersza ll.
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
        ++ln;            // Przechodzi do nastêpnego wiersza.
        pos = (*ln).begin();
    }
    ++pos;                // Przechodzi do nastêpnego znaku.
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

void f(vector<int>& v, int x)     // Dzia³a dla wektorów liczb typu int.
{
    vector<int>::iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end())     { /* znaleziono x */ }
    // ...
}

//------------------------------------------------------------------------------

void f(list<string>& v, string x) // Dzia³a dla listy ³añcuchów.
{
    list<string>::iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end()) { /* znaleziono x */ }
    // ...
}

//------------------------------------------------------------------------------

void f(Document& v, char x)       // Dzia³a dla obiektów typu Document.
{
    Text_iterator p = find(v.begin(),v.end(),x);
    if (p!=v.end())     { /* znaleziono x */ }
    // ...
}

//------------------------------------------------------------------------------

int main()
{
    // Dzia³a dla wektorów liczb typu int.
    {
        int initializer[7] = {1,2,3,4,5,6,7};
        int* first = initializer;
        int* last  = initializer+7;

        vector<int> v(first,last);
        f(v,4);
    }

    // Dzia³a dla listy ³añcuchów.
    {
        const char*  initializer[7] = {"one","two","three","four","five","six","seven"};
        const char** first = initializer;
        const char** last  = initializer+7;

        list<string> l(first,last);
        f(l,"four");
    }

    // Dzia³a dla obiektów typu Document.
    {
        Document d;

        f(d,'A');
    }
}

//------------------------------------------------------------------------------
