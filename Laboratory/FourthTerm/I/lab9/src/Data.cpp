#include "Data.h"

// ----------------------------- IntData -----------------------------

IntData::operator IntData*() {
    return this;
}

bool IntData::equals(Data* obj) const{
    return this->value == static_cast<IntData*>(obj)->value;
}

Data* IntData::clone() const {
    return new IntData(*this);
}

void IntData::print(std::ostream& os) const{
    os << value;
}

bool IntData::isNumeric() const { 
    return true; 
}

std::string IntData::toString() const { 
    return std::to_string(value); 
}

// ----------------------------- FloatData -----------------------------

FloatData::operator FloatData*() {
    return this;
}

bool FloatData::equals(Data* obj) const{
    return this->value == static_cast<FloatData*>(obj)->value;
}

Data* FloatData::clone() const {
    return new FloatData(*this);
}

void FloatData::print(std::ostream& os) const {
    os << value;
}

bool FloatData::isNumeric() const { 
    return true; 
}

std::string FloatData::toString() const { 
    return std::to_string(value); 
}

// ----------------------------- Boolean -----------------------------

Boolean::operator Boolean*() {
    return this;
}

bool Boolean::equals(Data* obj) const{
    return this->value == static_cast<Boolean*>(obj)->value;
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

bool Boolean::isNumeric() const { 
    return false; 
}

std::string Boolean::toString() const { 
    return (value ? "true" : "false"); 
}

// ----------------------------- StringData -----------------------------

StringData::operator StringData*() {
    return this;
}

bool StringData::equals(Data* obj) const{
    return this->value == static_cast<StringData*>(obj)->value;
}

Data* StringData::clone() const {
    return new StringData(*this);
}

void StringData::print(std::ostream& os) const {
    os << "\"" << value << "\"";
}

bool StringData::isNumeric() const { 
    return false; 
}

std::string StringData::toString() const { 
    return value; 
}