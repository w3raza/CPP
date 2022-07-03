
//
// Przyk³adowy kod z rozdzia³u 5.5.3 "Raportowanie b³êdów" ksi¹¿ki
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

// Prosi u¿ytkownika o podanie odpowiedzi „tak” lub „nie”.
// Zwraca wartoœæ 'z' oznaczaj¹c¹ z³¹ odpowiedŸ (tzn. inn¹ ni¿ tak lub nie).

char ask_user(string question)
{
    cout << question << "? (tak lub nie)\n";
    string answer = " ";
    cin >> answer;
    if (answer =="t" || answer=="tak") return 't'; 
    if (answer =="n" || answer=="nie") return 'n';
    return 'z';    // 'z' oznacza „z³a odpowiedŸ”.
}

//------------------------------------------------------------------------------


int area(int length, int width);    // Oblicza pole powierzchni prostok¹ta.

int framed_area(int x, int y)       // Oblicza pole powierzchni w ramce.
{ 
    const int frame_width = 2;
    if (x-frame_width<=0 || y-frame_width<=0)
        error("Argument funkcji area() wywo³anej przez framed_area() nie jest dodatni.");
    return area(x-frame_width,y-frame_width);
}

//------------------------------------------------------------------------------

// Oblicza pole powierzchni prostok¹ta.
// Wartoœæ zwrotna –1 oznacza z³y argument.
int area(int length, int width)
{
    if (length<=0 || width <=0) return -1;
    return length*width;
}

//------------------------------------------------------------------------------

int f(int x, int y, int z)
{
    cout << "x=" << x << "; y=" << y << "; z=" << z << endl;

    int area1 = area(x,y);
    if (area1<=0) error("Pole powierzchni nie jest dodatnie.");
    int area2 = framed_area(1,z);
    int area3 = framed_area(y,z);
    double ratio = double(area1)/area3;
    // ...

    cout << "area1=" << area1 << endl
         << "area2=" << area2 << endl
         << "area3=" << area3 << endl;
}

//------------------------------------------------------------------------------

int main()
try
{
    f( 1, 2, 3);
    f(-1, 2, 3);
    f( 1,-2, 3);
    f(-1,-2, 3);
    f( 1, 2,-3);
    f(-1, 2,-3);
    f( 1,-2,-3);
    f(-1,-2,-3);
    char answer = ask_user("Przeczyta³eœ wyniki?");
}
catch (exception& e) {
    cerr << "B³¹d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj¹tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
