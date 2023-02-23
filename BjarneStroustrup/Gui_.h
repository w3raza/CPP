#ifndef GUI_GUARD
#define GUI_GUARD

#include "Point.h"
#include "fltk.h"
#include "Window.h"
#include "Graph.h"
//#include<vector>
//#include<string>

namespace Graph_lib {
	
typedef void* Address;
typedef void (*Callback)(Address,Address);	// Typ funkcji wymagany przez FLTK dla wszystkich wywo³añ zwrotnych

template<class W> W& reference_to(Address pw)
	//  traktuje adres jako referencjê do W
{
		return *static_cast<W*>(pw);
}


class Widget {
	// Widget to uchwyt to Fl_widget — to *nie* jest Fl_widget.
	// Staramy siê trzymaæ nasze klasy interfejsu z dala od FLTK.
public:
	Widget(Point xy, int w, int h, const string& s, Callback cb)
		:loc(xy), width(w), height(h), label(s), do_it(cb)
	{ }

	virtual void move(int dx,int dy) { hide(); pw->position(loc.x+=dx, loc.y+=dy); show(); }
	virtual void hide() { pw->hide(); }
	virtual void show() { pw->show(); }
	virtual void attach(Window&) = 0;	// ka¿dy Widget definiuje przynajmniej jedn¹ akcjê dla window

	Point loc;
	int width;
	int height;
	string label;
	Callback do_it;

	virtual ~Widget() { }

	/*
	Widget(const Widget& a) :loc(a.loc) { error("Próba skopiowania Widget przez konstruktor."); }
	Widget& operator=(const Widget& a)
	{
			error("Próba skopiowania Widget przez przypisanie.");
			return *this;
	}
	*/

protected:
	Window* own;	// ka¿dy Widget nale¿y do okna
	Fl_Widget* pw;
private:
	Widget& operator=(const Widget&);	// nie kopiuj obiektów Widget
	Widget(const Widget&);
};

class Button : public Widget {
public:
	Button(Point xy, int ww, int hh, const string& s, Callback cb)
	:Widget(xy,ww,hh,s,cb)
	{ 
	}
	void attach(Window& win);
};

struct In_box : Widget {
	In_box(Point xy, int w, int h, const string& s)
		:Widget(xy,w,h,s,0)
		{
		}
	int get_int();
	string get_string();

	void attach(Window& win);
};

struct Out_box : Widget {
	Out_box(Point xy, int w, int h, const string& s/*, Window& win*/)
		:Widget(xy,w,h,s,0)
		{
		}
	void put(int);
	void put(const string&);

	void attach(Window& win);
};

struct Menu : Widget {
	enum Kind { horizontal, vertical };
	Menu(Point xy, int w, int h, Kind kk, const string& s);
	Vector_ref<Button> selection;
	Kind k;
	int offset;
	int attach(Button& b);	// do³¹cza przycisk; Menu nie usuwa &b
	int attach(Button* p);	// do³¹cza nowy przycisk; Menu usuwa p
	void show() { for (int i = 0; i<selection.size(); ++i) selection[i].show(); }
	void hide() { for (int i = 0; i<selection.size(); ++i) selection[i].hide(); }
	void move(int dx, int dy)
		{ for (int i = 0; i<selection.size(); ++i) selection[i].move(dx,dy); }
//	int insert(int i, const Button& b);	// nie zaimplementowano

	void attach(Window& win)
	{
		for (int i=0; i<selection.size(); ++i) win.attach(selection[i]);
	}	

};

}
#endif

