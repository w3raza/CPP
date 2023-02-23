#ifndef WINDOW_GUARD
#define WINDOW_GUARD 1

#include "fltk.h"

#include "std_lib_facilities.h"

#include "Point.h"
//#include "GUI.h"

namespace Graph_lib {

class Shape;	// „deklaracja z wyprzedeniem” Shape
class Widget;

class Window : public Fl_Window { 
public: 
	Window(int w, int h, const string& title );			// system wybiera lokalizacjê
	Window(Point xy, int w, int h, const string& title );	// lewy górny róg w xy
	virtual ~Window() { }

	int x_max() const { return w; }
	int y_max() const { return h; }

	void resize(int ww, int hh) { w=ww, h=hh; size(ww,hh); }

	void set_label(const string& s) { label(s.c_str()); }

	void attach(Shape& s);
	void attach(Widget& w);

	void detach(Shape& s);	// usuwa s z kszta³tów
	void detach(Widget& w);	// usuwa w z okna (dezaktywacja wywo³añ zwrotnych)

	void put_on_top(Shape& p);	// umieszcza p na innych kszta³tach

protected:
	void draw();
     
private:
	  vector<Shape*> shapes;	// kszta³ty do³¹czone do okna
	  int w,h;					// rozmiar okna

	  void init();
}; 

int gui_main();	// wywo³anie g³ównej pêtli zdarzeñ biblioteki GUI

inline int x_max() { return Fl::w(); }	// szerokoœæ ekranu w pikselach
inline int y_max() { return Fl::h(); }	// wysokoœæ ekranu w pikselach

}
#endif
