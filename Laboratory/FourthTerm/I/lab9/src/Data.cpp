#include "Data.h"

IntData::~IntData() {}

int IntData::getInt()const{
    return value;
}

IntData::operator IntData*() {
    return this;
}

Data* IntData::clone() const {
    return new IntData(*this);
}

void IntData::print(std::ostream& os) const {
    os << value;
}

bool IntData::equals(Data* obj) const{
    return this->value == static_cast<IntData*>(obj)->value;
}

StringData::~StringData() {}

std::string StringData::getString()const{
    return value;
}

StringData::operator StringData*() {
    return this;
}

Data* StringData::clone() const {
    return new StringData(*this);
}

void StringData::print(std::ostream& os) const {
    os << "\"" << value << "\"";
}

bool StringData::equals(Data* obj) const{
    return this->value == static_cast<StringData*>(obj)->value;
}

FloatData::~FloatData() {}

float FloatData::getFloat()const{
    return value;
}

FloatData::operator FloatData*() {
    return this;
}

Data* FloatData::clone() const {
    return new FloatData(*this);
}

void FloatData::print(std::ostream& os) const {
    os << value;
}

bool FloatData::equals(Data* obj) const{
    return this->value == static_cast<FloatData*>(obj)->value;
}

Boolean::~Boolean() {}

bool Boolean::getBool()const{
    return value;
}

Boolean::operator Boolean*() {
    return this;
}

Data* Boolean::clone() const {
    return new Boolean(*this);
}

void Boolean::print(std::ostream& os) const {
    if(value)
        os << "true";
    else
        os << "false";
}

bool Boolean::equals(Data* obj) const{
    return this->value == static_cast<Boolean*>(obj)->value;
}