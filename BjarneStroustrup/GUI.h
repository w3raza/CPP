
//
// To jest kod pomocniczy do budowy GUI do rozdzia³ów 12-16 ksi¹¿ki
// „Programming -- Principles and Practice Using C++” Bjarne Stroustrupa
//

#ifndef GUI_GUARD
#define GUI_GUARD

#include "Window.h"
#include "Graph.h"

namespace Graph_lib {

//------------------------------------------------------------------------------

    typedef void* Address;    // Address to synonim void*
    typedef void(*Callback)(Address, Address);    // Typ funkcji wymagany przez FLTK dla wszystkich wywo³añ zwrotnych

//------------------------------------------------------------------------------

    template<class W> W& reference_to(Address pw)
    // traktuje adres jako referencjê do W
    {
        return *static_cast<W*>(pw);
    }

//------------------------------------------------------------------------------

    class Widget {
    // Widget to uchwyt to Fl_widget — to *nie* jest Fl_widget.
    // Staramy siê trzymaæ nasze klasy interfejsu z dala od FLTK.
    public:
        Widget(Point xy, int w, int h, const string& s, Callback cb)
            : loc(xy), width(w), height(h), label(s), do_it(cb)
        {}

        virtual void move(int dx,int dy) { hide(); pw->position(loc.x+=dx, loc.y+=dy); show(); }
        virtual void hide() { pw->hide(); }
        virtual void show() { pw->show(); }
        virtual void attach(Window&) = 0;

        Point loc;
        int width;
        int height;
        string label;
        Callback do_it;

        virtual ~Widget() { }

    protected:
        Window* own;    // ka¿dy Widget nale¿y do okna
        Fl_Widget* pw;  // po³¹czenie z Widget FLTK
    private:
        Widget& operator=(const Widget&); // nie kopiuj obiektów Widget
        Widget(const Widget&);
    };

//------------------------------------------------------------------------------

    struct Button : Widget {
        Button(Point xy, int w, int h, const string& label, Callback cb)
            : Widget(xy,w,h,label,cb)
        {}

        void attach(Window&);
    };

//------------------------------------------------------------------------------

    struct In_box : Widget {
        In_box(Point xy, int w, int h, const string& s)
            :Widget(xy,w,h,s,0) { }
        int get_int();
        string get_string();

        void attach(Window& win);
    };

//------------------------------------------------------------------------------

    struct Out_box : Widget {
        Out_box(Point xy, int w, int h, const string& s)
            :Widget(xy,w,h,s,0) { }
        void put(int);
        void put(const string&);

        void attach(Window& win);
    };

//------------------------------------------------------------------------------

    struct Menu : Widget {
        enum Kind { horizontal, vertical };
        Menu(Point xy, int w, int h, Kind kk, const string& label)
            : Widget(xy,w,h,label,0), k(kk), offset(0)
        {}

        Vector_ref<Button> selection;
        Kind k;
        int offset;
        int attach(Button& b);      // Menu nie usuwa &b
        int attach(Button* p);      // Menu usuwa p

        void show()                 // pokazuje wszystkie przyciski
        {
            for (unsigned int i = 0; i<selection.size(); ++i)
                selection[i].show();
        }
        void hide()                 // ukrywa wszystkie przyciski
        {
            for (unsigned int i = 0; i<selection.size(); ++i) 
                selection[i].hide(); 
        }
        void move(int dx, int dy)   // przesuwa wszystkie przyciski
        {
            for (unsigned int i = 0; i<selection.size(); ++i) 
                selection[i].move(dx,dy);
        }

        void attach(Window& win)    // do³¹cza wszystkie przyciski
        {
            for (int i=0; i<selection.size(); ++i) win.attach(selection[i]);
            own = &win;
        }

    };

//------------------------------------------------------------------------------

} // of namespace Graph_lib

#endif // GUI_GUARD
