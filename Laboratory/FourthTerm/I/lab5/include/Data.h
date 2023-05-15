#pragma once
#include <iostream>

class Data {
public:
  virtual ~Data() {};
  virtual Data* clone() const = 0;
  virtual void print(std::ostream& os) const = 0;
};

class IntData : public Data {
public:
  IntData(int value) : value(value) {}
  IntData(const IntData& other) : value(other.value) {}
  ~IntData();
  operator IntData*();
  Data* clone() const override;
  void print(std::ostream& os) const override;
private:
  int value;
};

class StringData : public Data {
public:
  StringData(std::string value) : value(value) {}
  ~StringData();
  operator StringData*();
  Data* clone() const override;
  void print(std::ostream& os) const override;
private:
  std::string value;
};