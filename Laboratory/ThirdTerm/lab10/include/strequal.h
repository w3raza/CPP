#pragma once
#include "mystring.h"

namespace mystring{
    class StrEqual{
        public:
            StrEqual(const String& string): _string(string.getString()){}
            bool operator()(const mystring::String& obj) const{
                return _string == obj.getString();
            }   
        private:
            const char * _string;
    };
}