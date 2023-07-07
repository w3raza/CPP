

#include <iostream>

using namespace std;

template<typename T = int>
struct box{
    T _val;
    
    box& operator=(int el){
        _val = el;
        
        return *this;
    }
    
    operator double() const{
        return static_cast<double>(_val);
    }
};

template<typename T, int I = 2>
struct CArray{
    T* _arr;
    size_t _size;
    
    CArray(): _size(I), _arr(new T[I]){}
    CArray(const CArray& other): _size(other._size), _arr(other._arr){}
    
    T operator[](size_t i) const{
        return _arr[i];
    }
    
    T& operator[](size_t i){
        return _arr[i];
    }
};

int main()
{
	CArray< box< >, 2 > a;
	double d = a[0] = a[1] = 1;

	const CArray< box< int > > b = a;
	b[0] = b[1] = 2;

	cout << "d = " << d << "\ta[0] = " << a[0] << "\ta[1] = " 	<< a[1] << endl;
	cout << "b[0] = " << b[0] << "\tb[1] = " << b[1];
	
	return 0;
}