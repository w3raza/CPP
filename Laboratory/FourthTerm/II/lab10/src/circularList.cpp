#include "circularList.h" 

template<typename T>
T Node<T>::data() {
    return _data;
}

template<typename T>
CircularList<T>::CircularList() : _head(nullptr), _tail(nullptr) {}

template<typename T>
CircularList<T>& CircularList<T>::push_front(const T& data) {
    auto newNode = std::make_shared<Node<T>>(data);
    if (!_head) {
        _head = _tail = newNode;
        _tail->_next = _head;
    }
    else {
        newNode->_next = _head;
        _head = newNode;
        _tail->_next = _head;
    }
    return *this;
}

template<typename T>
CircularList<T>& CircularList<T>::push_back(const T& data){
    auto newNode = std::make_shared<Node<T>>(data);
    if (!_head) {
        _head = _tail = newNode;
        _tail->_next = _head;
    }
    else {
        _tail->_next = newNode;
        _tail = newNode;
        _tail->_next = _head;
    }
    return *this;
}

template<typename T>
void CircularList<T>::print() const{
    if(!_head){
        std::cout << "Lista pusta\n";
        return;
    }else{
        auto temp = _head;
        do{
            std::cout << temp->_data << " ";
            temp = temp->_next;
        }while (temp != _head);

        std::cout << std::endl;
    }
}

template<typename T>
CircularList<T>& CircularList<T>::add_sorted(const T& data){
    auto newNode = std::make_shared<Node<T>>(data);
    if (!_head) {
        _head = _tail = newNode;
        _tail->_next = _head;
    }
    else {
        if (_head->_data >= newNode->_data) {
            newNode->_next = _head;
            _head = newNode;
            _tail->_next = _head;
        }
        else if (_tail->_data <= newNode->_data) {
            _tail->_next = newNode;
            _tail = newNode;
            _tail->_next = _head;
        }
        else {
            auto curr = _head;
            while (curr->_next != _head && curr->_next->_data < newNode->_data){
                curr = curr->_next;
            }
            newNode->_next = curr->_next;
            curr->_next = newNode;
        }
    }
    return *this;
}

template<typename T>
std::shared_ptr<Node<T>> CircularList<T>::find(const T& data) const{
    if (!_head) return nullptr;
    auto curr = _head;
    do {
        if (curr->_data == data) return curr;
        curr = curr->_next;
    } while (curr != _head);
    return nullptr;
}

template<typename T>
std::shared_ptr<Node<T>> CircularList<T>::getNext(std::shared_ptr<Node<T>> node) const{
    if (!node || !node->_next) return nullptr;
    return node->_next;
}

#ifdef EXTENDED 
template<typename T>
void CircularList<T>::remove(const T& data) {
    if (!_head) return;
    if (_head->_data == data) {
        if (_head == _tail) {
            _head = _tail = nullptr;
        } else {
            _head = _head->_next;
            _tail->_next = _head;
        }
    }
    else {
        auto curr = _head;
        while (curr->_next != _head && curr->_next->_data != data)
            curr = curr->_next;
        if (curr->_next != _head) {
            curr->_next = curr->_next->_next;
            if (curr->_next == _head) _tail = curr;
        }
    }
}
#endif

template class CircularList<int>;
template class CircularList<std::string>;
template class CircularList<double>;
template class Node<std::string>;