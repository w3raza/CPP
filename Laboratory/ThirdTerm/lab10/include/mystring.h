#pragma once
#include<iostream>

namespace mystring{
    class String{
        public:
            String(const char* s = "");
            String(const String& s);
            String(String&& other) noexcept;
            ~String();
            String& operator=(const char* s);
            String& operator=(String&& other) noexcept;
            void print(const char* name = "")const;
            bool operator==(const String& obj) const;
            char * getString() const;
            String operator+(const char* s) const;
            String operator+(const String& s) const;

        private:
            char * _string;
    };
    std::ostream& operator<<(std::ostream& os, const String& obj);
    String operator*(int n, const String& obj);
    String operator+(const char* s, const String& str);
}