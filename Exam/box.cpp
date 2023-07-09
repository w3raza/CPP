#include <iostream>

template<typename T = int>
class box {
    public:
        T value;

        T& operator=(const T& val){
            value = val;
            return value;
        }

        friend std::ostream& operator<<(std::ostream& os, const box<T>& o){
            return os << o.value;
        }
};

template<typename T, size_t N = 2>
class CArray {
private:
    T* _arr;
    unsigned _size;
public:
    CArray(): _size(N), _arr(new T[N]){}
        // Copy constructor
    CArray(const CArray& a): _size(a._size), _arr(new T[_size]){
        for(unsigned i=0;i<a._size;i++){
            _arr[i]=a._arr[i];
        }
    }
    ~CArray(){
        delete[] _arr;
    }

    T& operator[](size_t index) const{
        return _arr[index];
    }
};

int main()
{
    using namespace std;
    CArray< box< >, 2 > a;
	double d = a[0] = a[1] = 1;

	const CArray< box< int > > b = a;
	b[0] = b[1] = 2;

	cout << "d = " << d << "\ta[0] = " << a[0] << "\ta[1] = " 	<< a[1] << endl;
	cout << "b[0] = " << b[0] << "\tb[1] = " << b[1];
	
	return 0;
}

/*
d = 1	a[0] = 1	a[1] = 1
b[0] = 2	b[1] = 2
*/