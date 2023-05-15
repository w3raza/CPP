#include "Data.h"

IntData::~IntData() {}

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


FloatData::operator FloatData*() {
    return this;
}

Data* FloatData::clone() const {
    return new FloatData(*this);
}

void FloatData::print(std::ostream& os) const {
    os << "\"" << value << "\"";
}

bool FloatData::equals(Data* obj) const{
    return this->value == static_cast<FloatData*>(obj)->value;
}