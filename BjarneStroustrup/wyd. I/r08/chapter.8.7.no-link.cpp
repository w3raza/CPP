
//
// To jest przyk�adowy kod z podrozdzia�u 8.7 �Przestrzenie nazw� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

namespace Graph_lib {
    struct Color { /* ... */ };
    struct Shape { /* ... */ };
    struct Line : Shape { /* ... */ };
    struct Function : Shape { /* ... */ }; 
    struct Text : Shape { /* ... */ };
    // ...
    int gui_main() { /* ... */ return 0; }
}

//------------------------------------------------------------------------------

namespace TextLib {
    class Text { /* ... */ };
    class Glyph {  /* ... */ };
    class Line {  /* ... */ };
    // ...
}

//------------------------------------------------------------------------------
