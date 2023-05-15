#include "MyList.h"

 MyList::~MyList() {
    while(head) {
        std::cout << "Destruktor MyList";
        Element* temp = head;
        head = head->getNext();
        delete temp;
    }
}

void MyList::add(const int* tab, int size) {
    Element* newElem = new Element(tab, size);
    newElem->setNext(head);
    head = newElem;
}

void  MyList::add(Element* elem) {
    elem->setNext(head);
    head = elem;
}

void  MyList::removeFirst() {
    Element* p = head;
    if (p != nullptr) {
        p = p->getNext();
        std::cout << "Destruktor Element: "; p->printElem(); std::cout << std::endl;
        delete[] p;
    }
}

Element* MyList::getHead() const { return head; }

bool  MyList::isEmpty() const { return head == nullptr; }

void  MyList::print(std::string listName) const {
    std::cout << listName << " = <";
    if(!isEmpty()){
        for (Element* p = head; p != nullptr; p = p->getNext()) {
            p->printElem();
            std::cout << (p->getNext() ? " " : "");
        }
    }
    std::cout << ">" << std::endl;
}

void  MyList::copyRev(const MyList* src) {
    if (src == nullptr) {
        return;
    }

    Element* srcElem = src->getHead();
    Element* prevElem = nullptr;

    while (srcElem) {
        int size = srcElem->getSize();
        int* tab = new int[size];
        std::memcpy(tab, srcElem->getArr(), size * sizeof(int));
        Element* newElem = new Element(tab, size);
        newElem->setNext(prevElem);
        prevElem = newElem;
        srcElem = srcElem->getNext();
    }

    head = prevElem;
}

// MyList::MyList() : _head(nullptr) {}

// MyList::MyList(const MyList& other) {
//     _head = nullptr;
//     Element* curr = other._head;
//     while (curr != nullptr) {
//         add(new Element(curr->getArr(), curr->getSize()));
//         curr = curr->getNext();
//     }
// }

// MyList::~MyList(){
//     Element* curr = _head;
//     while (curr != nullptr) {
//         Element* next = curr->getNext();
//         delete[] curr;
//         curr = next;
//     }
// }

// void MyList::add(Element *e){
//     e->setNext(_head);
//     _head = e;
// }

// void MyList::add(const int *arr, int size){
//     add(new Element(arr, size));
// }

// Element* MyList::getHead() const{
//     return _head;
// }

// bool MyList::isEmpty() const{
//     if(this->_head == nullptr){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// void MyList::print(std::string _string) const{
//     std::cout << _string << " = ";
//     if(!isEmpty()){
//         std::cout << "<";
//         Element* next = this->getHead()->getNext();
//         while(next != nullptr){
//             next->printElem();
//             next = next->getNext();
//             if(next != nullptr){
//                 std::cout << ",";
//             }
//         }
//         std::cout << ">" << std::endl;
//     }
// }

// void MyList::copyRev(const MyList* list){
//     _head = nullptr;
//     Element* curr = list->getHead();
//     while (curr != nullptr) {
//         add(new Element(curr->getArr(), curr->getSize()));
//         curr = curr->getNext();
//     }
// }
// void MyList::removeFirst(){
//     if(!isEmpty()){
//         Element* next = _head;

//         while(next != nullptr){
//             if(next->getNext() == nullptr){
//                 std::cout << "Destruktor Element: ";
//                 next->printElem(); 
//                 std::cout << std::endl;
//                 delete[] next;
//                 break;
//             }else{
//                 next = next->getNext();
//             }
//         }
//     }
// }