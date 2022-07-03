
/*
    Ostrze¿enie: do budowy tej niewielkiej biblioteki macierzy wielowymiarowych
	wykorzystano kilka rzeczy, o których nie wspomina siê na podstawowych kursach programowania.

    (c) Bjarne Stroustrup, Texas A&M University. 

    Biblioteki tej mo¿na u¿ywaæ w dowolny sposób, pod warunkiem ujawnienia jej pochodzenia.
*/

#ifndef MATRIX_LIB
#define MATRIX_LIB

#include<string>
#include<algorithm>
//#include<iostream>

namespace Numeric_lib {

//-----------------------------------------------------------------------------

struct Matrix_error {
    std::string name;
    Matrix_error(const char* q) :name(q) { }
    Matrix_error(std::string n) :name(n) { }
};

//-----------------------------------------------------------------------------

inline void error(const char* p)
{
    throw Matrix_error(p);
}

//-----------------------------------------------------------------------------

typedef long Index;    // Nadal nie lubiê typów bez znaku.

//-----------------------------------------------------------------------------

// Ogólny szablon Matrix jest tylko wzorcem do tworzenia specjalizacji:
template<class T = double, int D = 1> class Matrix {
    // Klasa macierzy wielowymiarowych
    // ( ) - indeksowanie wielowymiarowe
    // [ ] - robienie wycinków w stylu jêzyka C: tworzy macierz N-1 wymiarow¹ z macierzy N wymiarowej
    // row() - równowa¿na z [ ]
    // column() - nie zaimplementowana, poniewa¿ wymaga „kroku” (stride)
    // = - semantyka kopiowania
    // ( ) i [ ] s¹ kontrolowane pod wzglêdem zakresu
    // slice() - zwraca podzakresy
private:
    Matrix();    // Tego nie powinno nigdy byæ kompilowane
};

//-----------------------------------------------------------------------------

template<class T = double, int D = 1> class Row ;    // Deklaracja z wyprzedzeniem

//-----------------------------------------------------------------------------

// Obiekty funkcyjne dla ró¿nych operacji apply():

template<class T> struct Assign {
    void operator()(T& a, const T& c) { a = c; }
};

template<class T> struct Add_assign {
    void operator()(T& a, const T& c) { a += c; }
};
template<class T> struct Mul_assign {
    void operator()(T& a, const T& c) { a *= c; }
};
template<class T> struct Minus_assign {
    void operator()(T& a, const T& c) { a -= c; }
};
template<class T> struct Div_assign {
    void operator()(T& a, const T& c) { a /= c; }
};
template<class T> struct Mod_assign {
    void operator()(T& a, const T& c) { a %= c; }
};
template<class T> struct Or_assign {
    void operator()(T& a, const T& c) { a |= c; }
};
template<class T> struct Xor_assign {
    void operator()(T& a, const T& c) { a ^= c; }
};
template<class T> struct And_assign {
    void operator()(T& a, const T& c) { a &= c; }
};

template<class T> struct Not_assign {
    void operator()(T& a) { a = !a; }
};

template<class T> struct Not {
    T operator()(T& a) { return !a; }
};

template<class T> struct Unary_minus {
    T operator()(T& a) { return -a; }
};

template<class T> struct Complement {
    T operator()(T& a) { return ~a; }
};

//-----------------------------------------------------------------------------

// Matrix_base reprezentuje wspóln¹ czêœæ klas Matrix:
template<class T> class Matrix_base {
    // Macierze przechowuj¹ swoje elementy w obiektach typu Matrix_base i maj¹ semantykê kopiowania
    // Matrix_base wykonuje operacje na elementach
protected:
    T* elem;    // Wektor? Nie — nie da³oby siê ³atwo utworzyæ wektora dla wycinka
    const Index sz;    
    mutable bool owns;
    mutable bool xfer;
public:
    Matrix_base(Index n) :elem(new T[n]()), sz(n), owns(true), xfer(false)
        // Macierz n elementów (domyœlnie inicjowana)
    {
        // std::cerr << "new[" << n << "]->" << elem << "\n";
    }

    Matrix_base(Index n, T* p) :elem(p), sz(n), owns(false), xfer(false)
        // Deskryptor macierzy n elementów bêd¹cych w posiadaniu kogoœ innego.
    {
    }

    ~Matrix_base()
    {
        if (owns) {
            // std::cerr << "delete[" << sz << "] " << elem << "\n";
            delete[]elem;
        }
    }

    // W razie potrzeby mo¿na dostaæ siê do surowej macierzy:
          T* data()       { return elem; }
    const T* data() const { return elem; }
    Index    size() const { return sz; }

    void copy_elements(const Matrix_base& a)
    {
        if (sz!=a.sz) error("copy_elements()");
        for (Index i=0; i<sz; ++i) elem[i] = a.elem[i];
    }

    void base_assign(const Matrix_base& a) { copy_elements(a); }

    void base_copy(const Matrix_base& a)
    {
        if (a.xfer) {          // a ma zostaæ usuniêty,
                               // a wiêc mo¿na przenieœæ prawa w³asnoœci zamiast kopiowaæ.
            // std::cerr << "xfer @" << a.elem << " [" << a.sz << "]\n";
            elem = a.elem;
            a.xfer = false;    // Uwaga — modyfikuje Ÿród³o.
            a.owns = false;
        }
        else {
            elem = new T[a.sz];
            // std::cerr << "base copy @" << a.elem << " [" << a.sz << "]\n";
            copy_elements(a);
        }
        owns = true;
        xfer = false;
    }

    // Aby dostaæ siê do elementów lokalnej macierzy z funkcji bez kopiowania:
    void base_xfer(Matrix_base& x)
    {
        if (owns==false) error("Nie mo¿na wykonaæ funkcji xfer() — nie w³aœciciel");
        owns = false;     // Teraz elementy s¹ zabezpieczone przed usuniêciem przez pierwotnego w³aœciciela.
        x.xfer = true;
        x.owns = true;
    }

    template<class F> void base_apply(F f) { for (Index i = 0; i<size(); ++i) f(elem[i]); }
    template<class F> void base_apply(F f, const T& c) { for (Index i = 0; i<size(); ++i) f(elem[i],c); }
private:
    void operator=(const Matrix_base&);    // Nie zwyk³a kopia baz.
    Matrix_base(const Matrix_base&);
};

//-----------------------------------------------------------------------------

template<class T> class Matrix<T,1> : public Matrix_base<T> {
    const Index d1;

protected:
    // Do u¿ytku przez Row:
    Matrix(Index n1, T* p) : Matrix_base<T>(n1,p), d1(n1)
    {
        // std::cerr << "Tworzy macierz 1-wymiarow¹ z danych.\n";
    }

public:

    Matrix(Index n1) : Matrix_base<T>(n1), d1(n1) { }

    Matrix(Row<T,1>& a) : Matrix_base<T>(a.dim1(),a.p), d1(a.dim1()) 
    { 
        // std::cerr << "Tworzy macierz 1-wymiarow¹ z Row.\n";
    }

    // Konstruktor kopiuj¹cy: pozwala wykonaæ kopiowanie bazie:
    Matrix(const Matrix& a) : Matrix_base<T>(a.size(),0), d1(a.d1)
    {
        // std::cerr << "Konstruktor kopiuj¹cy\n";
        this->base_copy(a);
    }

    template<int n> 
    Matrix(const T (&a)[n]) : Matrix_base<T>(n), d1(n)
        // Dedukcja n (i T), Matrix_base alokuje T[n]
    {
        // std::cerr << "Konstruktor macierzy\n";
        for (Index i = 0; i<n; ++i) this->elem[i]=a[i];
    }

    Matrix(const T* p, Index n) : Matrix_base<T>(n), d1(n)
        // Matrix_base alokuje T[n]
    {
        // std::cerr << "Konstruktor macierzy\n";
        for (Index i = 0; i<n; ++i) this->elem[i]=p[i];
    }

    template<class F> Matrix(const Matrix& a, F f) : Matrix_base<T>(a.size()), d1(a.d1)
        // Tworzy now¹ macierz z elementami bêd¹cymi funkcjami elementów a:
        // nie modyfikuje, dopóki f nie zostanie zaprogramowana do modyfikowania swojego argumentu.
        // T f(const T&) mo¿e byæ typowym rodzajem f.
    {
        for (Index i = 0; i<this->sz; ++i) this->elem[i] = f(a.elem[i]); 
    }

    template<class F, class Arg> Matrix(const Matrix& a, F f, const Arg& t1) : Matrix_base<T>(a.size()), d1(a.d1)
        // Tworzy now¹ macierz z elementami bêd¹cymi funkcjami elementów a:
        // nie modyfikuje, dopóki f nie zostanie zaprogramowana do modyfikowania swojego argumentu.
        // T f(const T&, const Arg&) mo¿e byæ typowym rodzajem f.
    {
        for (Index i = 0; i<this->sz; ++i) this->elem[i] = f(a.elem[i],t1); 
    }

    Matrix& operator=(const Matrix& a)
        // Przypisanie kopiuj¹ce: pozwala wykonaæ kopiowanie bazie.
    {
        // std::cerr << "Przypisanie kopiuj¹ce (" << this->size() << ',' << a.size()<< ")\n";
        if (d1!=a.d1) error("B³¹d d³ugoœci w 1D=");
        this->base_assign(a);
        return *this;
    }

    ~Matrix() { }

    Index dim1() const { return d1; }    // Liczba elementów w wierszu

    Matrix xfer()    // Tworzy macierz do przenoszenia elementów poza zakres.
    {
        Matrix x(dim1(),this->data()); // Tworzy deskryptor.
        this->base_xfer(x);                  // Przenosi (tymczasowo) prawo w³asnoœci na x.
        return x;
    }

    void range_check(Index n1) const
    {
        // std::cerr << "Sprawdzanie zakresu: (" << d1 << "): " << n1 << "\n"; 
        if (n1<0 || d1<=n1) error("B³¹d zakresu 1D: wymiar 1");
    }

    // Indeksowanie:
          T& operator()(Index n1)       { range_check(n1); return this->elem[n1]; }
    const T& operator()(Index n1) const { range_check(n1); return this->elem[n1]; }

    // Tworzenie wycinków (to samo, co indeksowanie macierzy jednowymiarowych):
          T& operator[](Index n)       { return row(n); }
    const T& operator[](Index n) const { return row(n); }

          T& row(Index n)       { range_check(n); return this->elem[n]; }
    const T& row(Index n) const { range_check(n); return this->elem[n]; }

    Row<T,1> slice(Index n)
        // Elementy od a[n] dalej
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;// Jeden poza koñcem
        return Row<T,1>(d1-n,this->elem+n);
    }

    const Row<T,1> slice(Index n) const
        // Elementy od a[n] dalej
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;// Jeden poza koñcem
        return Row<T,1>(d1-n,this->elem+n);
    }

    Row<T,1> slice(Index n, Index m)
        // m elementów zaczynaj¹c od a[n]
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;    // Jeden poza koñcem
        if (m<0) m = 0;
        else if (d1<n+m) m=d1-n;
        return Row<T,1>(m,this->elem+n);
    }

    const Row<T,1> slice(Index n, Index m) const
        // m elementów zaczynaj¹c od a[n]
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;    // Jeden poza koñcem
        if (m<0) m = 0;
        else if (d1<n+m) m=d1-n;
        return Row<T,1>(m,this->elem+n);
    }

    // Operacje elementowe:
    template<class F> Matrix& apply(F f) { this->base_apply(f); return *this; }
    template<class F> Matrix& apply(F f,const T& c) { this->base_apply(f,c); return *this; }

    Matrix& operator=(const T& c)  { this->base_apply(Assign<T>(),c);       return *this; }

    Matrix& operator*=(const T& c) { this->base_apply(Mul_assign<T>(),c);   return *this; }
    Matrix& operator/=(const T& c) { this->base_apply(Div_assign<T>(),c);   return *this; }
    Matrix& operator%=(const T& c) { this->base_apply(Mod_assign<T>(),c);   return *this; }
    Matrix& operator+=(const T& c) { this->base_apply(Add_assign<T>(),c);   return *this; }
    Matrix& operator-=(const T& c) { this->base_apply(Minus_assign<T>(),c); return *this; }

    Matrix& operator&=(const T& c) { this->base_apply(And_assign<T>(),c);   return *this; }
    Matrix& operator|=(const T& c) { this->base_apply(Or_assign<T>(),c);    return *this; }
    Matrix& operator^=(const T& c) { this->base_apply(Xor_assign<T>(),c);   return *this; }

    Matrix operator!() { return xfer(Matrix(*this,Not<T>())); }
    Matrix operator-() { return xfer(Matrix(*this,Unary_minus<T>())); }
    Matrix operator~() { return xfer(Matrix(*this,Complement<T>()));  }

    template<class F> Matrix apply_new(F f) { return xfer(Matrix(*this,f)); }
    
    void swap_rows(Index i, Index j)
        // Funkcja swap_rows() wykorzystuje pamiêæ odpowiadaj¹c¹ jednemu wierszowi, aby zmaksymalizowaæ wydajnoœæ.
        // Zamienianie elementów parami trzeba napisaæ samodzielnie.
    {
        if (i == j) return;
    /*
        Matrix<T,1> temp = (*this)[i];
        (*this)[i] = (*this)[j];
        (*this)[j] = temp;
    */
        Index max = (*this)[i].size();
        for (Index ii=0; ii<max; ++ii) std::swap((*this)(i,ii),(*this)(j,ii));
    }
};

//-----------------------------------------------------------------------------

template<class T> class Matrix<T,2> : public Matrix_base<T> {
    const Index d1;
    const Index d2;

protected:
    // Do u¿ytku przez Row:
    Matrix(Index n1, Index n2, T* p) : Matrix_base<T>(n1*n2,p), d1(n1), d2(n2) 
    {
        // std::cerr << "Tworzy macierz trójwymiarow¹ z danych.\n";
    }

public:

    Matrix(Index n1, Index n2) : Matrix_base<T>(n1*n2), d1(n1), d2(n2) { }

    Matrix(Row<T,2>& a) : Matrix_base<T>(a.dim1()*a.dim2(),a.p), d1(a.dim1()), d2(a.dim2())
    { 
        // std::cerr << "Tworzy macierz dwuwymiarow¹ z Row.\n";
    }

    // // Konstruktor kopiuj¹cy — pozwala wykonaæ kopiowanie bazie:
    Matrix(const Matrix& a) : Matrix_base<T>(a.size(),0), d1(a.d1), d2(a.d2)
    {
        // std::cerr << "Konstruktor kopiuj¹cy\n";
        this->base_copy(a);
    }

    template<int n1, int n2> 
    Matrix(const T (&a)[n1][n2]) : Matrix_base<T>(n1*n2), d1(n1), d2(n2)
        // Dedukuje n1, n2 (i T), Matrix_base alokuje T[n1*n2]
    {
        // std::cerr << "Konstruktor macierzy\n";
        for (Index i = 0; i<n1; ++i)
            for (Index j = 0; j<n2; ++j) this->elem[i*n2+j]=a[i][j];
    }

    template<class F> Matrix(const Matrix& a, F f) : Matrix_base<T>(a.size()), d1(a.d1), d2(a.d2)
        // Tworzy now¹ macierz z elementami bêd¹cymi funkcjami elementów a:
        // nie modyfikuje, dopóki f nie zostanie zaprogramowana do modyfikowania swojego argumentu.
        // T f(const T&)by³aby typowym rodzajem f
    {
        for (Index i = 0; i<this->sz; ++i) this->elem[i] = f(a.elem[i]); 
    }

    template<class F, class Arg> Matrix(const Matrix& a, F f, const Arg& t1) : Matrix_base<T>(a.size()), d1(a.d1), d2(a.d2)
        // Tworzy now¹ macierz z elementami bêd¹cymi funkcjami elementów a:
        // nie modyfikuje, dopóki f nie zostanie zaprogramowana do modyfikowania swojego argumentu.
        // T f(const T&, const Arg&)by³aby typowym rodzajem f
    {
        for (Index i = 0; i<this->sz; ++i) this->elem[i] = f(a.elem[i],t1); 
    }

    Matrix& operator=(const Matrix& a)
        // Przypisanie kopiuj¹ce — pozwala bazie wykonaæ kopiowanie
    {
        // std::cerr << "Przypisanie kopiuj¹ce (" << this->size() << ',' << a.size()<< ")\n";
        if (d1!=a.d1 || d2!=a.d2) error("B³¹d d³ugoœci w 2D =");
        this->base_assign(a);
        return *this;
    }

    ~Matrix() { }
    
    Index dim1() const { return d1; }    // Liczba elementów w wierszu
    Index dim2() const { return d2; }    // Liczba elementów w kolumnie

    Matrix xfer()    // Tworzy macierz do przeniesienia elementów poza zakres.
    {
        Matrix x(dim1(),dim2(),this->data()); // Tworzy deskryptor
        this->base_xfer(x);            // Przenosi (tymczasowo) prawo w³asnoœci na x
        return x;
    }

    void range_check(Index n1, Index n2) const
    {
        // std::cerr << "Sprawdzanie zakresu: (" << d1 << "," << d2 << "): " << n1 << " " << n2 << "\n";
        if (n1<0 || d1<=n1) error("B³¹d zakresu 2D: wymiar 1");
        if (n2<0 || d2<=n2) error("B³¹d zakresu 2D: wymiar 2");
    }

    // Indeksowanie
          T& operator()(Index n1, Index n2)       { range_check(n1,n2); return this->elem[n1*d2+n2]; }
    const T& operator()(Index n1, Index n2) const { range_check(n1,n2); return this->elem[n1*d2+n2]; }

    // Tworzenie wycinków (zwraca wiersz):
          Row<T,1> operator[](Index n)       { return row(n); }
    const Row<T,1> operator[](Index n) const { return row(n); }

          Row<T,1> row(Index n)       { range_check(n,0); return Row<T,1>(d2,&this->elem[n*d2]); }
    const Row<T,1> row(Index n) const { range_check(n,0); return Row<T,1>(d2,&this->elem[n*d2]); }

    Row<T,2> slice(Index n)
        // wiersze [n:d1)
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;    // Jeden poza koñcem
        return Row<T,2>(d1-n,d2,this->elem+n*d2);
    }

    const Row<T,2> slice(Index n) const
        // wiersze [n:d1)
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;    // Jeden poza koñcem
        return Row<T,2>(d1-n,d2,this->elem+n*d2);
    }

    Row<T,2> slice(Index n, Index m)
        // wiersze [n:m)
    {
        if (n<0) n=0;
        if(d1<m) m=d1;    // Jeden poza koñcem
        return Row<T,2>(m-n,d2,this->elem+n*d2);

    }

    const Row<T,2> slice(Index n, Index m) const
        // wiersze [n:sz)
    {
        if (n<0) n=0;
        if(d1<m) m=d1;    // Jeden poza koñcem
        return Row<T,2>(m-n,d2,this->elem+n*d2);
    }

    // Column<T,1> column(Index n); // Jeszcze nie zaimplementowana — wymaga kroków (stride) i operacji na kolumnach

    // Operacje elementowe
    template<class F> Matrix& apply(F f)            { this->base_apply(f);   return *this; }
    template<class F> Matrix& apply(F f,const T& c) { this->base_apply(f,c); return *this; }

    Matrix& operator=(const T& c)  { this->base_apply(Assign<T>(),c);       return *this; }

    Matrix& operator*=(const T& c) { this->base_apply(Mul_assign<T>(),c);   return *this; }
    Matrix& operator/=(const T& c) { this->base_apply(Div_assign<T>(),c);   return *this; }
    Matrix& operator%=(const T& c) { this->base_apply(Mod_assign<T>(),c);   return *this; }
    Matrix& operator+=(const T& c) { this->base_apply(Add_assign<T>(),c);   return *this; }
    Matrix& operator-=(const T& c) { this->base_apply(Minus_assign<T>(),c); return *this; }

    Matrix& operator&=(const T& c) { this->base_apply(And_assign<T>(),c);   return *this; }
    Matrix& operator|=(const T& c) { this->base_apply(Or_assign<T>(),c);    return *this; }
    Matrix& operator^=(const T& c) { this->base_apply(Xor_assign<T>(),c);   return *this; }

    Matrix operator!() { return xfer(Matrix(*this,Not<T>())); }
    Matrix operator-() { return xfer(Matrix(*this,Unary_minus<T>())); }
    Matrix operator~() { return xfer(Matrix(*this,Complement<T>()));  }

    template<class F> Matrix apply_new(F f) { return xfer(Matrix(*this,f)); }
    
    void swap_rows(Index i, Index j)
        // Funkcja swap_rows() u¿ywa pamiêci odpowiadaj¹cej jednemu wierszowi, aby zmaksymalizowaæ wydajnoœæ
        // Zamienianie parami trzeba zaimplementowaæ samodzielnie
    {
        if (i == j) return;
    /*
        Matrix<T,1> temp = (*this)[i];
        (*this)[i] = (*this)[j];
        (*this)[j] = temp;
    */
        Index max = (*this)[i].size();
        for (Index ii=0; ii<max; ++ii) std::swap((*this)(i,ii),(*this)(j,ii));
    }
};

//-----------------------------------------------------------------------------

template<class T> class Matrix<T,3> : public Matrix_base<T> {
    const Index d1;
    const Index d2;
    const Index d3;

protected:
    // Do u¿ytku przez Row:
    Matrix(Index n1, Index n2, Index n3, T* p) : Matrix_base<T>(n1*n2*n3,p), d1(n1), d2(n2), d3(n3) 
    {
        // std::cerr << "Tworzy macierz trójwymiarow¹ z danych.\n";
    }

public:

    Matrix(Index n1, Index n2, Index n3) : Matrix_base<T>(n1*n2*n3), d1(n1), d2(n2), d3(n3) { }

    Matrix(Row<T,3>& a) : Matrix_base<T>(a.dim1()*a.dim2()*a.dim3(),a.p), d1(a.dim1()), d2(a.dim2()), d3(a.dim3())
    { 
        // std::cerr << "Tworzy macierz trójwymiarow¹ z Row.\n";
    }

    // // Konstruktor kopiuj¹cy — pozwala wykonaæ kopiowanie bazie:
    Matrix(const Matrix& a) : Matrix_base<T>(a.size(),0), d1(a.d1), d2(a.d2), d3(a.d3)
    {
        // std::cerr << "Konstruktor kopiuj¹cy\n";
        this->base_copy(a);
    }

    template<int n1, int n2, int n3> 
    Matrix(const T (&a)[n1][n2][n3]) : Matrix_base<T>(n1*n2), d1(n1), d2(n2), d3(n3)
        // Dedukcja n1, n2, n3 (i T), Matrix_base alokuje T[n1*n2*n3]
    {
        // std::cerr << "Konstruktor macierzy\n";
        for (Index i = 0; i<n1; ++i)
            for (Index j = 0; j<n2; ++j)
                for (Index k = 0; k<n3; ++k)
                    this->elem[i*n2*n3+j*n3+k]=a[i][j][k];
    }

    template<class F> Matrix(const Matrix& a, F f) : Matrix_base<T>(a.size()), d1(a.d1), d2(a.d2), d3(a.d3)
        // Tworzy now¹ macierz z elementami bêd¹cymi funkcjami elementów a:
        // nie modyfikuje, dopóki f nie zostanie zaprogramowana do modyfikowania swojego argumentu.
        // T f(const T&)by³aby typowym rodzajem f
    {
        for (Index i = 0; i<this->sz; ++i) this->elem[i] = f(a.elem[i]); 
    }

    template<class F, class Arg> Matrix(const Matrix& a, F f, const Arg& t1) : Matrix_base<T>(a.size()), d1(a.d1), d2(a.d2), d3(a.d3)
        // Tworzy now¹ macierz z elementami bêd¹cymi funkcjami elementów a:
        // nie modyfikuje, dopóki f nie zostanie zaprogramowana do modyfikowania swojego argumentu.
        // T f(const T&, const Arg&)by³aby typowym rodzajem f
    {
        for (Index i = 0; i<this->sz; ++i) this->elem[i] = f(a.elem[i],t1); 
    }

    Matrix& operator=(const Matrix& a)
        // Przypisanie kopiuj¹ce — pozwala bazie wykonaæ kopiowanie
    {
        // std::cerr << "Przypisanie kopiuj¹ce (" << this->size() << ',' << a.size()<< ")\n";
        if (d1!=a.d1 || d2!=a.d2 || d3!=a.d3) error("B³¹d d³ugoœci w 2D =");
        this->base_assign(a);
        return *this;
    }

    ~Matrix() { }

    Index dim1() const { return d1; }    // Liczba elementów w wierszu
    Index dim2() const { return d2; }    // Liczba elementów w kolumnie
    Index dim3() const { return d3; }    // Liczba elementów w g³¹b

    Matrix xfer()    // Tworzy macierz do przeniesienia elementów poza zakres.
    {
        Matrix x(dim1(),dim2(),dim3(),this->data()); // Tworzy deskryptor
        this->base_xfer(x);            // Przenosi (tymczasowo) prawo w³asnoœci na x
        return x;
    }

    void range_check(Index n1, Index n2, Index n3) const
    {
        // std::cerr << "Sprawdzanie zakresu: (" << d1 << "," << d2 << "): " << n1 << " " << n2 << "\n";
        if (n1<0 || d1<=n1) error("B³¹d zakresu 3D: wymiar 1");
        if (n2<0 || d2<=n2) error("B³¹d zakresu 3D: wymiar 2");
        if (n3<0 || d3<=n3) error("B³¹d zakresu 3D: wymiar 3");
    }

    // Indeksowanie
          T& operator()(Index n1, Index n2, Index n3)       { range_check(n1,n2,n3); return this->elem[d2*d3*n1+d3*n2+n3]; }; 
    const T& operator()(Index n1, Index n2, Index n3) const { range_check(n1,n2,n3); return this->elem[d2*d3*n1+d3*n2+n3]; };

    // Tworzenie wycinków (zwraca wiersz):
          Row<T,2> operator[](Index n)       { return row(n); }
    const Row<T,2> operator[](Index n) const { return row(n); }

          Row<T,2> row(Index n)       { range_check(n,0,0); return Row<T,2>(d2,d3,&this->elem[n*d2*d3]); }
    const Row<T,2> row(Index n) const { range_check(n,0,0); return Row<T,2>(d2,d3,&this->elem[n*d2*d3]); }

    Row<T,3> slice(Index n)
        // wiersze [n:d1)
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;    // Jeden poza koñcem
        return Row<T,3>(d1-n,d2,d3,this->elem+n*d2*d3);
    }

    const Row<T,3> slice(Index n) const
        // wiersze [n:d1)
    {
        if (n<0) n=0;
        else if(d1<n) n=d1;    // Jeden poza koñcem
        return Row<T,3>(d1-n,d2,d3,this->elem+n*d2*d3);
    }

    Row<T,3> slice(Index n, Index m)
        // wiersze [n:m)
    {
        if (n<0) n=0;
        if(d1<m) m=d1;    // Jeden poza koñcem
        return Row<T,3>(m-n,d2,d3,this->elem+n*d2*d3);

    }

    const Row<T,3> slice(Index n, Index m) const
        // wiersze [n:sz)
    {
        if (n<0) n=0;
        if(d1<m) m=d1;    // Jeden poza koñcem
        return Row<T,3>(m-n,d2,d3,this->elem+n*d2*d3);
    }

    // Column<T,2> column(Index n); // Jeszcze nie zaimplementowana — wymaga kroków (stride) i operacji na kolumnach

    // Operacje elementowe
    template<class F> Matrix& apply(F f)            { this->base_apply(f);   return *this; }
    template<class F> Matrix& apply(F f,const T& c) { this->base_apply(f,c); return *this; }

    Matrix& operator=(const T& c)  { this->base_apply(Assign<T>(),c);       return *this; }
                                                                            
    Matrix& operator*=(const T& c) { this->base_apply(Mul_assign<T>(),c);   return *this; }
    Matrix& operator/=(const T& c) { this->base_apply(Div_assign<T>(),c);   return *this; }
    Matrix& operator%=(const T& c) { this->base_apply(Mod_assign<T>(),c);   return *this; }
    Matrix& operator+=(const T& c) { this->base_apply(Add_assign<T>(),c);   return *this; }
    Matrix& operator-=(const T& c) { this->base_apply(Minus_assign<T>(),c); return *this; }

    Matrix& operator&=(const T& c) { this->base_apply(And_assign<T>(),c);   return *this; }
    Matrix& operator|=(const T& c) { this->base_apply(Or_assign<T>(),c);    return *this; }
    Matrix& operator^=(const T& c) { this->base_apply(Xor_assign<T>(),c);   return *this; }

    Matrix operator!() { return xfer(Matrix(*this,Not<T>())); }
    Matrix operator-() { return xfer(Matrix(*this,Unary_minus<T>())); }
    Matrix operator~() { return xfer(Matrix(*this,Complement<T>()));  }

    template<class F> Matrix apply_new(F f) { return xfer(Matrix(*this,f)); }
    
    void swap_rows(Index i, Index j)
        // Funkcja swap_rows() u¿ywa pamiêci odpowiadaj¹cej jednemu wierszowi, aby zmaksymalizowaæ wydajnoœæ
        // Zamienianie parami trzeba zaimplementowaæ samodzielnie
    {
        if (i == j) return;
        
        Matrix<T,2> temp = (*this)[i];
        (*this)[i] = (*this)[j];
        (*this)[j] = temp;
    }
};

//-----------------------------------------------------------------------------

template<class T> Matrix<T> scale_and_add(const Matrix<T>& a, T c, const Matrix<T>& b)
    //  saxpy z jêzyka Fortran (fma oznacza „fused multiply-ad”).
    // Czy konstruktor kopiuj¹cy zostanie wywo³any dwa razy i zniweczy optymalizacjê xfer?
{
    if (a.size() != b.size()) error("Nieprawid³owe rozmiary dla scale_and_add()");
    Matrix<T> res(a.size());
    for (Index i = 0; i<a.size(); ++i) res[i] += a[i]*c+b[i];
    return res.xfer();
}

//-----------------------------------------------------------------------------

template<class T> T dot_product(const Matrix<T>&a , const Matrix<T>& b)
{
    if (a.size() != b.size()) error("Nieprawid³owe rozmiary dla iloczynu skalarnego.");
    T sum = 0;
    for (Index i = 0; i<a.size(); ++i) sum += a[i]*b[i];
    return sum;
}

//-----------------------------------------------------------------------------

template<class T, int N> Matrix<T,N> xfer(Matrix<T,N>& a)
{
    return a.xfer();
}

//-----------------------------------------------------------------------------

template<class F, class A>            A apply(F f, A x)        { A res(x,f);   return xfer(res); }
template<class F, class Arg, class A> A apply(F f, A x, Arg a) { A res(x,f,a); return xfer(res); }

//-----------------------------------------------------------------------------

// Domyœlne wartoœci T i D zosta³y zadeklarowane wczeœniej.
template<class T, int D> class Row {
    // Ogólna wersja istnieje tylko po to, aby mo¿na by³o tworzyæ specjalizacje.
private:
        Row();
};

//-----------------------------------------------------------------------------

template<class T> class Row<T,1> : public Matrix<T,1> {
public:
    Row(Index n, T* p) : Matrix<T,1>(n,p)
    {
    }

    Matrix<T,1>& operator=(const T& c) { this->base_apply(Assign<T>(),c); return *this; }

    Matrix<T,1>& operator=(const Matrix<T,1>& a)
    {
        return *static_cast<Matrix<T,1>*>(this)=a;
    }
};

//-----------------------------------------------------------------------------

template<class T> class Row<T,2> : public Matrix<T,2> {
public:
    Row(Index n1, Index n2, T* p) : Matrix<T,2>(n1,n2,p)
    {
    }
        
    Matrix<T,2>& operator=(const T& c) { this->base_apply(Assign<T>(),c); return *this; }

    Matrix<T,2>& operator=(const Matrix<T,2>& a)
    {
        return *static_cast<Matrix<T,2>*>(this)=a;
    }
};

//-----------------------------------------------------------------------------

template<class T> class Row<T,3> : public Matrix<T,3> {
public:
    Row(Index n1, Index n2, Index n3, T* p) : Matrix<T,3>(n1,n2,n3,p)
    {
    }

    Matrix<T,3>& operator=(const T& c) { this->base_apply(Assign<T>(),c); return *this; }

    Matrix<T,3>& operator=(const Matrix<T,3>& a)
    {
        return *static_cast<Matrix<T,3>*>(this)=a;
    }
};

//-----------------------------------------------------------------------------

template<class T, int N> Matrix<T,N-1> scale_and_add(const Matrix<T,N>& a, const Matrix<T,N-1> c, const Matrix<T,N-1>& b)
{
    Matrix<T> res(a.size());
    if (a.size() != b.size()) error("Nieprawid³owe rozmiary dla scale_and_add");
    for (Index i = 0; i<a.size(); ++i) res[i] += a[i]*c+b[i];
    return res.xfer();
}

//-----------------------------------------------------------------------------

template<class T, int D> Matrix<T,D> operator*(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r*=c; }
template<class T, int D> Matrix<T,D> operator/(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r/=c; }
template<class T, int D> Matrix<T,D> operator%(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r%=c; }
template<class T, int D> Matrix<T,D> operator+(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r+=c; }
template<class T, int D> Matrix<T,D> operator-(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r-=c; }

template<class T, int D> Matrix<T,D> operator&(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r&=c; }
template<class T, int D> Matrix<T,D> operator|(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r|=c; }
template<class T, int D> Matrix<T,D> operator^(const Matrix<T,D>& m, const T& c) { Matrix<T,D> r(m); return r^=c; }

//-----------------------------------------------------------------------------

}
#endif
