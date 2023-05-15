#include "StringFun.h"

void PrintNames(const std::vector<MyString>& names) {
  for (const auto& name : names) {
    std::cout << name.str() << " ";
  }
  std::cout << std::endl;
}

MyStringContainer::MyStringContainer(const MyStringContainer& other) {
  for (auto& ptr : other._container) {
    AddMStr(new MyString(*ptr));
  }
}

MyStringContainer::~MyStringContainer() {
  for (auto& ptr : _container) {
    delete ptr;
  }
}

void MyStringContainer::AddMStr(MyString* s) {
    _container.push_back(s);
}

std::vector<MyString> MyStringContainer::GetSorted(std::string s) const{
    std::vector<MyString> vec;
    vec.reserve(_container.size());
    
    std::transform(std::begin(_container), std::end(_container),
               std::back_inserter(vec),[](MyString* str){return *str;});
    if(s == "ASC"){
       std::sort(vec.begin(), vec.end(), Less());
    }else{
        std::sort(vec.begin(), vec.end(), Greater());
    }
    return vec;
}

// inicjalizacja statycznego składnika klasy MyStringContainer
const std::vector<std::function<bool(const MyString&, const MyString&)>>& MyStringContainer::m_sortFuncs = {Less(), Greater()};

const std::vector<std::function<bool(const MyString&, const MyString&)>>& MyStringContainer::SortFunc(){
  return m_sortFuncs;
}