/*
   std_lib_facilities.h
*/

/*
	Prosty nag³ówek wykorzystywany na pocz¹tku kursu „Programming: Principles and Practice using C++ (wydanie drugie)”.
	Do³¹cza najczêœciej u¿ywane standardowe nag³ówki (do przestrzeni globalnej)
	oraz implementuje minimaln¹ obs³ugê wyj¹tków i b³êdów.

	Uczniowie: na razie nie musicie rozumieæ zawartoœci plików nag³ówkowych.
	Wszystko zostanie wyjaœnione z czasem. Ten nag³ówek jest po to, abyœcie nie musieli
	zrozumieæ wszystkiego na raz.

	Od rozdzia³u 10 ten plik bêdzie ju¿ niepotrzebny, a po rozdziale 21. bêdziecie wszystko w nim rozumieæ.

	Poprawka z dnia 25 kwietnia 2010 r.: dodano funkcjê simple_error()
	
	Poprawka z dnia 25 listopada 2013 r.: usuniêto obs³ugê kompilatorów sprzed C++11, zaczêto u¿ywaæ C++11: <chrono>
	Poprawka z dnia 25 listopada 2013 r.: dodano kilka algorytmów kontenerowych
	Poprawka z dnia 8 czerwca 2014 r.: dodano #ifndef, aby obejœæ s³ab¹ obs³ugê C++11 przez Microsoft C++11
	Poprawka z dnia 2 lutego 2015 r.: funkcji randint() mo¿na przekazywaæ ziarno (zobacz æwiczenie 5.13).
	Poprawka z dnia 15 czerwca: hack defaultfloat dla starszych GCC
*/

#ifndef H112
#define H112 020215L


#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>

//------------------------------------------------------------------------------
#if __GNUC__ && __GNUC__ < 5
inline ios_base& defaultfloat(ios_base& b)	// to augment fixed and scientific as in C++11
{
	b.setf(ios_base::fmtflags(0), ios_base::floatfield);
	return b;
}
#endif
//------------------------------------------------------------------------------

using Unicode = long;

//------------------------------------------------------------------------------

using namespace std;

template<class T> string to_string(const T& t)
{
	ostringstream os;
	os << t;
	return os.str();
}

struct Range_error : out_of_range {	// rozszerzone raportowanie b³êdów zakresu wektora
	int index;
	Range_error(int i) :out_of_range("B³¹d zakresu: "+to_string(i)), index(i) { }
};


// prosty wektor ze sprawdzaniem zakresu (bez sprawdzania iteratora):
template< class T> struct Vector : public std::vector<T> {
	using size_type = typename std::vector<T>::size_type;

#ifdef _MSC_VER
	// Microsoft jeszcze nie obs³uguje dziedziczenia konstruktorów C++11
	Vector() { }
	explicit Vector(size_type n) :std::vector<T>(n) {}
	Vector(size_type n, const T& v) :std::vector<T>(n,v) {}
	template <class I>
	Vector(I first, I last) : std::vector<T>(first, last) {}
	Vector(initializer_list<T> list) : std::vector<T>(list) {}
#else
	using std::vector<T>::vector;	// konstruktor dziedzicz¹cy
#endif

	T& operator[](unsigned int i) // zamiast zwracaæ at(i);
	{
		if (i<0||this->size()<=i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
	const T& operator[](unsigned int i) const
	{
		if (i<0||this->size()<=i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
};

// obrzydliwa sztuczka pozwalaj¹ca uzyskaæ wektor ze sprawdzaniem zakresu:
#define vector Vector

// ³añcuch z prostym sprawdzaniem zakresu (bez sprawdzania iteratora):
struct String : std::string {
	using size_type = std::string::size_type;
//	using string::string;

	char& operator[](unsigned int i) // zamiast zwracaæ at(i);
	{
		if (i<0||size()<=i) throw Range_error(i);
		return std::string::operator[](i);
	}

	const char& operator[](unsigned int i) const
	{
		if (i<0||size()<=i) throw Range_error(i);
		return std::string::operator[](i);
	}
};


namespace std {

    template<> struct hash<String>
    {
        size_t operator()(const String& s) const
        {
            return hash<std::string>()(s);
        }
    };

} // of namespace std


struct Exit : runtime_error {
	Exit(): runtime_error("Exit") {}
};

// error() to po prostu przebranie dla throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s+s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s <<": " << i;
	error(os.str());
}


template<class T> char* as_bytes(T& i)	// potrzebne dla binarnego wejœcia-wyjœcia
{
	void* addr = &i;	// pobiera adres pierwszego bajtu
						// pamiêci, w której zapisano obiekt
	return static_cast<char*>(addr); // traktowanie tej pamiêci jako bajtów
}


inline void keep_window_open()
{
	cin.clear();
	cout << "Naciœnij klawisz, aby zakoñczyæ.\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s=="") return;
	cin.clear();
	cin.ignore(120,'\n');
	for (;;) {
		cout << "Naciœnij " << s << ", aby zakoñczyæ.\n";
		string ss;
		while (cin >> ss && ss!=s)
			cout << "Naciœnij " << s << ", aby zakoñczyæ.\n";
		return;
	}
}



// funkcja b³êdu, której nale¿y u¿ywaæ tylko do wprowadzenia funkcji error() w rozdziale 5:
inline void simple_error(string s)	// drukuje B³¹d: s i zamyka program
{
	cerr << "B³¹d: " << s << '\n';
	keep_window_open();		// dla niektórych œrodowisk Windows
	exit(1);
}

// udostêpnia std::min() i std::max() w systemach z nieokrzesanymi makrami:
#undef min
#undef max


// Rzutowanie zawê¿aj¹ce (konwersja typów) z kontrol¹ w czasie dzia³ania programu. Zobacz ???.
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r)!=a) error(string("info loss"));
	return r;
}

// generatory liczb losowych. Zobacz 24.7.

default_random_engine& get_rand()
{
	static default_random_engine ran;
	return ran;
};

void seed_randint(int s) { get_rand().seed(s); }

inline int randint(int min, int max) {  return uniform_int_distribution<>{min, max}(get_rand()); }

inline int randint(int max) { return randint(0, max); }

//inline double sqrt(int x) { return sqrt(double(x)); }	// to match C++0x

// algorytmy kontenerowe. Zobacz 21.9.

template<typename C>
using Value_type = typename C::value_type;

template<typename C>
using Iterator = typename C::iterator;

template<typename C>
	// requires Container<C>()
void sort(C& c)
{
	std::sort(c.begin(), c.end());
}

template<typename C, typename Pred>
// requires Container<C>() && Binary_Predicate<Value_type<C>>()
void sort(C& c, Pred p)
{
	std::sort(c.begin(), c.end(), p);
}

template<typename C, typename Val>
	// requires Container<C>() && Equality_comparable<C,Val>()
Iterator<C> find(C& c, Val v)
{
	return std::find(c.begin(), c.end(), v);
}

template<typename C, typename Pred>
// requires Container<C>() && Predicate<Pred,Value_type<C>>()
Iterator<C> find_if(C& c, Pred p)
{
	return std::find_if(c.begin(), c.end(), p);
}

#endif //H112
