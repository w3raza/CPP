#pragma once
#include <iostream>
#include <memory>
#include <optional>

#define EXTENDED

template<typename T>
struct Node{
    T _data;
    std::shared_ptr<Node<T>> _next;

    Node(const T& data) : _data(data), _next(nullptr){}
    T data();
};

template<typename T>
class CircularList{
private:
    std::shared_ptr<Node<T>> _head;
    std::shared_ptr<Node<T>> _tail;
public:
    CircularList();
    CircularList<T>& push_front(const T& data);
    CircularList<T>& push_back(const T& data);
    void print() const;
    CircularList<T>& add_sorted(const T& data);
    std::shared_ptr<Node<T>> find(const T& data) const;
    std::shared_ptr<Node<T>> getNext(std::shared_ptr<Node<T>> node) const;
#ifdef EXTENDED 
    void remove(const T& data);
#endif
};