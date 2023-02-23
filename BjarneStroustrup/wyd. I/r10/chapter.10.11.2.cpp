
//
// To jest przyk�adowy kod z podrozdzia�u 10.11.2 �Odczytywanie struktur warto�ci� ksi��ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const int not_a_reading = -7777;    // Mniej ni� zero bezwzgl�dne.
const int not_a_month = -1;

//------------------------------------------------------------------------------

struct Day {
    vector<double> hour;
    Day();    // Inicjacja godzin warto�ci� �nieodczyt�.
};

//------------------------------------------------------------------------------

Day::Day() : hour(24)
{
    for (int i = 0; i<hour.size(); ++i) hour[i]=not_a_reading;
}

//------------------------------------------------------------------------------

struct Month {        // Miesi�c pomiar�w temperatury.
    int month;        // <0,11>, stycze� == 0.
    vector<Day> day;  // <1,31>, jeden wektor odczyt�w na dzie�.
    Month()           // W miesi�cu mo�e by� najwy�ej 31 dni (zmarnowany element day[0]).
        :month(not_a_month), day(32) { }
};

//------------------------------------------------------------------------------

struct Year {             // Rok wynik�w pomiar�w temperatury, zorganizowany wed�ug miesi�cy.
    int year;             // Liczba dodatnia == rok.
    vector<Month> month;  // <0,11>, stycze� == 0.
    Year() :month(12) { } // W roku jest 12 miesi�cy.
};

//------------------------------------------------------------------------------

struct Reading {
    int day;
    int hour;
    double temperature;
};

//------------------------------------------------------------------------------

int month_to_int(string s);
bool is_valid(const Reading& r);
void end_of_loop(istream& ist, char term, const string& message);

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Reading& r)
// Wczytuje wynik pomiaru temperatury z is do r.
// format: ( 3 4 9.7 )
// Sprawdza format, ale nie sprawdza poprawno�ci danych.
{
    char ch1;
    if (is>>ch1 && ch1!='(') {    // Czy to mo�e by� Reading?
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2!=')') error("Nieprawid�owy odczyt."); // Problemy z odczytem.
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Month& m)
// Wczytuje miesi�c z is do m.
// format: { month feb ... }
{
    char ch = 0;
    if (is >> ch && ch!='{') {
        is.unget();
        is.clear(ios_base::failbit);    // Nie uda�o si� wczyta� miesi�ca.
        return is;
    }

    string month_marker;
    string mm;    
    is >> month_marker >> mm;
    if (!is || month_marker!="month") error("Niepoprawny pocz�tek miesi�ca.");
    m.month = month_to_int(mm);

    Reading r;
    int no_of_duplicate_readings = 0;
    int no_invalid_readings = 0;

    while (is >> r)
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
                ++no_of_duplicate_readings;
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
            ++no_invalid_readings;
    end_of_loop(is,'}',"Niepoprawny koniec miesi�ca.");
    return is;
}

//------------------------------------------------------------------------------

const int implausible_min = -200;
const int implausible_max = 200;

bool is_valid(const Reading& r)
// Szybki test.
{
    if (r.day<1 || 31<r.day) return false;
    if (r.hour<0 || 23<r.hour) return false;
    if (r.temperature<implausible_min|| implausible_max<r.temperature)
        return false;
    return true;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Year& y)
// Wczytuje rok z is do y.
// format: { year 1972 � }
{
    char ch;
    is >> ch;
    if (ch!='{') {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker!="year") error("Niepoprawny pocz�tek roku.");
    y.year = yy;

    while(true) {
        Month m;    // W ka�dym cyklu tworzy czyst� zmienn� m.
        if(!(is >> m)) break;
        y.month[m.month] = m;
    }

    end_of_loop(is,'}',"Niepoprawne zako�czenie roku.");
    return is;
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail()) { // U�ywa term jako znaku ko�ca i/lub znaku oddzielaj�cego.
        ist.clear();
        char ch;
        if (ist>>ch && ch==term) return;    // Wszystko w porz�dku.
        error(message);
    }
}

//------------------------------------------------------------------------------

vector<string> month_input_tbl;    // month_input_tbl[0]=="jan"

void init_input_tbl(vector<string>& tbl)
// Inicjacja wektora reprezentacji danych wej�ciowych.
    tbl.push_back("jan");
    tbl.push_back("feb");
    tbl.push_back("mar");
    tbl.push_back("apr");
    tbl.push_back("may");
    tbl.push_back("jun");
    tbl.push_back("jul");
    tbl.push_back("aug");
    tbl.push_back("sep");
    tbl.push_back("oct");
    tbl.push_back("nov");
    tbl.push_back("dec");
}

//------------------------------------------------------------------------------

int month_to_int(string s)
// Czy s jest nazw� miesi�ca? Je�li tak, zwraca jej indeks z zakresu <0,11>, w przeciwnym przypadku zwraca �1.
{
    for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
    return -1;
}

//------------------------------------------------------------------------------

vector<string> month_print_tbl;    // month_print_tbl[0]=="January"

void init_print_tbl(vector<string>& tbl)
// Inicjacja wektora reprezentacji wyj�ciowych.
{
    tbl.push_back("Stycze�");
    tbl.push_back("Luty");
    tbl.push_back("Marzec");
    tbl.push_back("Kwiecie�");
    tbl.push_back("Maj");
    tbl.push_back("Czerwiec");
    tbl.push_back("Lipiec");
    tbl.push_back("Sierpie�");
    tbl.push_back("Wrzesie�");
    tbl.push_back("Pa�dziernik");
    tbl.push_back("Listopad");
    tbl.push_back("Grudzie�");
}

//------------------------------------------------------------------------------

string int_to_month(int i)
// Zakres numer�w miesi�cy: [0:11].
{
    if (i<0 || 12<=i) error("Nieprawid�owy indeks miesi�ca.");
    return month_print_tbl[i];
}

//------------------------------------------------------------------------------

void print_year(ostream& ost, const Year& y)
{
    ost << y.year << ' ';
}

//------------------------------------------------------------------------------

int main()
try
{
    // Inicjacja tablic reprezentacji:
    init_print_tbl(month_print_tbl);
    init_input_tbl(month_input_tbl);

    // Otwarcie pliku wej�ciowego.
    cout << "Podaj nazw� pliku z danymi.\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str());
    if (!ifs) error("Nie mo�na otworzy� pliku.",name);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);    // Zg�asza dla bad().

    // Otwiera plik wyj�ciowy:
    cout << "Podaj nazw� pliku wyj�ciowego:\n";
    cin >> name;
    ofstream ofs(name.c_str());
    if (!ofs) error("Nie mo�na otworzy� pliku wyj�ciowego.",name);

    // Wczytuje dowoln� liczb� lat:
    vector<Year> ys;
    while(true) {    
        Year y;        // W ka�dym cyklu tworzy nowy rok.
        if (!(ifs>>y)) break;
        ys.push_back(y);
    }
    cout << "Wczytano wyniki pomiar�w z " << ys.size() << " lat.\n";

    for (int i = 0; i<ys.size(); ++i) print_year(ofs,ys[i]);
}
catch (exception& e) {
    cerr << "B��d: " << e.what() << '\n'; 
    return 1;
}
catch (...) {
    cerr << "Nieznany wyj�tek!\n"; 
    return 2;
}

//------------------------------------------------------------------------------
