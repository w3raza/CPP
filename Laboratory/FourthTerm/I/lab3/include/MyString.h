#pragma once
#include <cstring>
#include <iostream>
#include <vector>

class MyString{
    public:
    MyString() = default;
    MyString(const std::string& s): _string(s){}
    MyString(const char* s): _string(s){}

    std::string str()const;

    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;

    void* operator new(std::size_t size) {
        std::cout << "[MyString] Overloading new operator with size: " << size << std::endl;
        return std::allocator<MyString>{}.allocate(1);
    }
    
    void operator delete(void* ptr) noexcept {
        std::cout << "[MyString] Overloading delete operator" << std::endl;
        std::allocator<MyString>{}.deallocate(static_cast<MyString*>(ptr), 1);
    }

    private:
    std::string _string;
};