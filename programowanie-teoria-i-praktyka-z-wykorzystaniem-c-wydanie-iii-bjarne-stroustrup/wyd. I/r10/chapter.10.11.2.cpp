
//
// To jest przyk³adowy kod z podrozdzia³u 10.11.2 „Odczytywanie struktur wartoœci” ksi¹¿ki 
// "Programowanie. Teoria i praktyka z wykorzystaniem C++" Bjarne'a Stroustrupa.
//

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

const int not_a_reading = -7777;    // Mniej ni¿ zero bezwzglêdne.
const int not_a_month = -1;

//------------------------------------------------------------------------------

struct Day {
    vector<double> hour;
    Day();    // Inicjacja godzin wartoœci¹ „nieodczyt”.
};

//------------------------------------------------------------------------------

Day::Day() : hour(24)
{
    for (int i = 0; i<hour.size(); ++i) hour[i]=not_a_reading;
}

//------------------------------------------------------------------------------

struct Month {        // Miesi¹c pomiarów temperatury.
    int month;        // <0,11>, styczeñ == 0.
    vector<Day> day;  // <1,31>, jeden wektor odczytów na dzieñ.
    Month()           // W miesi¹cu mo¿e byæ najwy¿ej 31 dni (zmarnowany element day[0]).
        :month(not_a_month), day(32) { }
};

//------------------------------------------------------------------------------

struct Year {             // Rok wyników pomiarów temperatury, zorganizowany wed³ug miesiêcy.
    int year;             // Liczba dodatnia == rok.
    vector<Month> month;  // <0,11>, styczeñ == 0.
    Year() :month(12) { } // W roku jest 12 miesiêcy.
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
// Sprawdza format, ale nie sprawdza poprawnoœci danych.
{
    char ch1;
    if (is>>ch1 && ch1!='(') {    // Czy to mo¿e byæ Reading?
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2!=')') error("Nieprawid³owy odczyt."); // Problemy z odczytem.
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Month& m)
// Wczytuje miesi¹c z is do m.
// format: { month feb ... }
{
    char ch = 0;
    if (is >> ch && ch!='{') {
        is.unget();
        is.clear(ios_base::failbit);    // Nie uda³o siê wczytaæ miesi¹ca.
        return is;
    }

    string month_marker;
    string mm;    
    is >> month_marker >> mm;
    if (!is || month_marker!="month") error("Niepoprawny pocz¹tek miesi¹ca.");
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
    end_of_loop(is,'}',"Niepoprawny koniec miesi¹ca.");
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
// format: { year 1972 … }
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
    if (!is || year_marker!="year") error("Niepoprawny pocz¹tek roku.");
    y.year = yy;

    while(true) {
        Month m;    // W ka¿dym cyklu tworzy czyst¹ zmienn¹ m.
        if(!(is >> m)) break;
        y.month[m.month] = m;
    }

    end_of_loop(is,'}',"Niepoprawne zakoñczenie roku.");
    return is;
}

//------------------------------------------------------------------------------

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail()) { // U¿ywa term jako znaku koñca i/lub znaku oddzielaj¹cego.
        ist.clear();
        char ch;
        if (ist>>ch && ch==term) return;    // Wszystko w porz¹dku.
        error(message);
    }
}

//------------------------------------------------------------------------------

vector<string> month_input_tbl;    // month_input_tbl[0]=="jan"

void init_input_tbl(vector<string>& tbl)
// Inicjacja wektora reprezentacji danych wejœciowych.
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
// Czy s jest nazw¹ miesi¹ca? Jeœli tak, zwraca jej indeks z zakresu <0,11>, w przeciwnym przypadku zwraca –1.
{
    for (int i=0; i<12; ++i) if (month_input_tbl[i]==s) return i;
    return -1;
}

//------------------------------------------------------------------------------

vector<string> month_print_tbl;    // month_print_tbl[0]=="January"

void init_print_tbl(vector<string>& tbl)
// Inicjacja wektora reprezentacji wyjœciowych.
{
    tbl.push_back("Styczeñ");
    tbl.push_back("Luty");
    tbl.push_back("Marzec");
    tbl.push_back("Kwiecieñ");
    tbl.push_back("Maj");
    tbl.push_back("Czerwiec");
    tbl.push_back("Lipiec");
    tbl.push_back("Sierpieñ");
    tbl.push_back("Wrzesieñ");
    tbl.push_back("PaŸdziernik");
    tbl.push_back("Listopad");
    tbl.push_back("Grudzieñ");
}

//------------------------------------------------------------------------------

string int_to_month(int i)
// Zakres numerów miesiêcy: [0:11].
{
    if (i<0 || 12<=i) error("Nieprawid³owy indeks miesi¹ca.");
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

    // Otwarcie pliku wejœciowego.
    cout << "Podaj nazwê pliku z danymi.\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str());
    if (!ifs) error("Nie mo¿na otworzyæ pliku.",name);

    ifs.exceptions(ifs.exceptions()|ios_base::badbit);    // Zg³asza dla bad().

    // Otwiera plik wyjœciowy:
    cout << "Podaj nazwê pliku wyjœciowego:\n";
    cin >> name;
    ofstream ofs(name.c_str());
    if (!ofs) error("Nie mo¿na otworzyæ pliku wyjœciowego.",name);

    // Wczytuje dowoln¹ liczbê lat:
    vector<Year> ys;
    while(true) {    
        Year y;        // W ka¿dym cyklu tworzy nowy rok.
        if (!(ifs>>y)) break;
        ys.push_back(y);
    }
    cout << "Wczytano wyniki pomiarów z " << ys.size() << " lat.\n";

    for (int i = 0; i<ys.size(); ++i) print_year(ofs,ys[i]);
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
