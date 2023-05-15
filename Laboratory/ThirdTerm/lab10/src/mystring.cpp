#include "mystring.h"

// konstruktor tworzący napis na podstawie tekstu
mystring::String::String(const char * string){
    _string = new char[strlen(string) + 1];
    strcpy(_string, string);
}

// konstruktor kopiujący
mystring::String::String(const mystring::String& s) {
    _string = new char[strlen(s._string) + 1];
    strcpy((char*)_string, s._string);
}

// konstruktor przenoszący
mystring::String::String(mystring::String&& other) noexcept {
    _string = other._string;
    other._string = new char[strlen(_string) + 1];
}

mystring::String::~String() {
    delete[] _string;
}

// operator przypisania kopiujący
mystring::String& mystring::String::operator=(const char* s) {
    if (_string != s) {
        delete[] _string;
        _string = new char[strlen(s) + 1];
        strcpy(_string, s);
    }
    return *this;
}

// operator przypisania przenoszący
mystring::String& mystring::String::operator=(mystring::String&& other) noexcept {
    if (this != &other) {
        delete[] _string;
        _string = other._string;
        other._string = nullptr;
    }
    return *this;
}

mystring::String mystring::String::operator+(const char* s) const {
    char* newstr = new char[strlen(_string) + strlen(s) + 1];
    strcpy(newstr, _string);
    strcat(newstr, s);
    String result(newstr);
    delete[] newstr;
    return result;
}

mystring::String mystring::String::operator+(const mystring::String& s) const {
    return operator+(s._string);
}

void mystring::String::print(const char* name) const{
    std::cout << name << _string << std::endl;
}

bool mystring::String::operator==(const String& obj) const{
    return _string == obj._string;
}

char * mystring::String::getString() const{
    return _string;
}

std::ostream& mystring::operator<<(std::ostream& os, const mystring::String& obj){
    return os << obj.getString();
}

mystring::String mystring::operator*(int n, const mystring::String& obj){
    size_t new_size = strlen(obj.getString()) * n;
    char* new_buffer = new char[new_size + 1];
    std::strcpy(new_buffer, obj.getString());
    for (size_t i = 1; i < n; ++i) {
        std::strcat(new_buffer, obj.getString());
    }
    return String(new_buffer);
}

mystring::String mystring::operator+(const char* s, const mystring::String& str){
    return String(s) + str;
}
