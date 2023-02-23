
//
// To jest kod pomocniczy do budowy GUI do rozdziałów 12-16 książki
// „Programming -- Principles and Practice Using C++” Bjarne Stroustrupa
//

#include "Simple_window.h"

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,0), 70, 20, "Next", cb_next),
    button_pushed(false)
{
    attach(next_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// zmodyfikowana pętla zdarzeń:
// obsługa wszystkich zdarzeń  (domyślnie), kończy, gdy button_pushed jest true
// umożliwia korzystanie z grafiki bez inwersji sterowania
{
    show();
    button_pushed = false;
#if 1
    // prostsza procedura obsługi
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // Aby obsłużyć przypadek, gdy użytkownik naciśnie przycisk X w oknie, aby
    // zamknąć aplikację, zmień warunek na 0, aby włączyć tę gałąź.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// wywołaj Simple_window::next() dla okna zlokalizowanego w punkcie pw
{  
    reference_to<Simple_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
}

//------------------------------------------------------------------------------
