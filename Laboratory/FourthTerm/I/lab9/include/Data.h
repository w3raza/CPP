#pragma once
#include <iostream>

class Data {
public:
  virtual ~Data() {};
  virtual bool equals(Data* obj) const = 0;
  virtual Data* clone() const = 0;
  virtual void print(std::ostream& os) const = 0;
  virtual bool isNumeric() const = 0;
  virtual std::string toString() const = 0;
};

class IntData : public Data {
public:
  IntData(int value) : value(value) {}
  operator IntData*();
  virtual bool equals(Data* obj) const override;
  virtual Data* clone() const override;
  virtual void print(std::ostream& os) const override;
  virtual bool isNumeric() const override;
  virtual std::string toString() const override;

private:
  int value;
};

class FloatData : public Data {
public:
  FloatData(float value) : value(value) {}
  operator FloatData*();
  virtual bool equals(Data* obj) const override;
  virtual Data* clone() const override;
  virtual void print(std::ostream& os) const override;
  virtual bool isNumeric() const override;
  virtual std::string toString() const override;

private:
  float value;
};

class Boolean : public Data {
public:
  Boolean(bool value) : value(value) {}
  operator Boolean*();
  virtual bool equals(Data* obj) const override;
  virtual Data* clone() const override;
  virtual void print(std::ostream& os) const override;
  virtual bool isNumeric() const override;
  virtual std::string toString() const override;

private:
  bool value;
};

class StringData : public Data {
public:
  StringData(std::string value) : value(value) {}
  operator StringData*();
  virtual bool equals(Data* obj) const override;
  virtual Data* clone() const override;
  virtual void print(std::ostream& os) const override;
  virtual bool isNumeric() const override;
  virtual std::string toString() const override;

private:
  std::string value;
};