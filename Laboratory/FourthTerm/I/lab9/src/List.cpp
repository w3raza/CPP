#include "List.h"

List::List() : head(nullptr) {}

List::~List() {
  clear();
}

List::List(const List& other) {
  copy(other);
}

List& List::operator=(const List& other) {
  if (this != &other) {
    clear();
    copy(other);
  }
  return *this;
}

List& List::insert(Data* data, Position pos) {
  Node* newNode = new Node(data);
  if (pos == Begin) {
    newNode->next = head;
    head = newNode;
  }
  else {
    if (head == nullptr) {
      head = newNode;
    }
    else {
      Node* last = head;
      while (last->next != nullptr) {
        last = last->next;
      }
      last->next = newNode;
    }
  }
  return *this;
}

void List::print() const {
  std::cout << "[";
  Node* node = head;
  while (node != nullptr) {
    node->data->print(std::cout);
    node = node->next;
    if (node != nullptr) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
  delete[] node;
}

void List::copy(const List& other) {
  if (other.head == nullptr) {
    head = nullptr;
  }
  else {
    head = new Node(other.head->data->clone());
    Node* last = head;
    Node* otherNode = other.head->next;
    while (otherNode != nullptr) {
      last->next = new Node(otherNode->data->clone());
      last = last->next;
      otherNode = otherNode->next;
    }
  }
}

void List::clear() {
  while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    temp->data->~Data();
  }
}

bool List::find(Data* obj) const{
  Node* node = head;
  while (node != nullptr) {
    if((node->data != nullptr) && node->data->equals(obj)){
      return true;
    }
    node = node->next;
  }
  return false;
}

List& List::operator<<(List& other){ 
  Node* node = other.head;
  if(node == nullptr || this->head == node){
    return *this;
  }
  else {
    while (node != nullptr) {
      insert(node->data);
      node = node->next;
    }
    other.clear();
  }
  return *this;
}

bool List::operator!=(List& other)const{
  return this->head != other.head;
}

List List::numeric(){
  List new_list = List(); 
  Node* node = head;
  while (node != nullptr) {
    if(instanceof<IntData>(node->data)){
      new_list.insert(node->data);
    }
    node = node->next;
  } 
  delete[] node;

  return new_list;
}

List List::convert_to_stringdata() {
  List result;
  Node* current = head;
  
  while (current != nullptr) {
    if (dynamic_cast<const IntData*>(current->data) != nullptr) {
      const IntData* intData = dynamic_cast<const IntData*>(current->data);
      result.insert(StringData(std::to_string(intData->getInt())));
    } else if (dynamic_cast<const FloatData*>(current->data) != nullptr) {
      const FloatData* floatData = dynamic_cast<const FloatData*>(current->data);
      result.insert(StringData(std::to_string(floatData->getFloat())));
    } else if (dynamic_cast<const Boolean*>(current->data) != nullptr) {
      const Boolean* boolData = dynamic_cast<const Boolean*>(current->data);
      result.insert(StringData(boolData->getBool() ? "true" : "false"));
    } else if (dynamic_cast<const StringData*>(current->data) != nullptr) {
      const StringData* stringData = dynamic_cast<const StringData*>(current->data);
      result.insert(stringData->clone());
    }
    current = current->next;
  }
  return result;
}