#pragma once
#include "Data.h"

class List {
public:
  enum Position {Begin, End};

  List();
  ~List();
  List(const List& other);
  List& operator=(const List& other);
  List& insert(Data* data, Position pos = End);
  void print() const;
  bool find(Data* obj) const;
  List& operator<<(List& list);

private:
  struct Node {
    Data* data;
    Node* next;
    Node(Data* data) : data(data), next(nullptr) {}
    ~Node() { delete[] data; }
  };
  Node* head;

  void copy(const List& other);
  void clear();
};
