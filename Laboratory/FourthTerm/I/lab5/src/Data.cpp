#include "Data.h"

IntData::~IntData() {std::cout << "~IntData()" << std::endl;}

IntData::operator IntData*() {
    return this;
}

Data* IntData::clone() const {
    return new IntData(*this);
}

void IntData::print(std::ostream& os) const {
    os << value;
}

StringData::~StringData() {std::cout << "~StringData()" << std::endl;}

StringData::operator StringData*() {
    return this;
}

Data* StringData::clone() const {
    return new StringData(*this);
}

void StringData::print(std::ostream& os) const {
    os << "\"" << value << "\"";
}