#ifndef LIST_H
#define LIST_H

#include "Rational.h"
#include <vector>

template<typename T>
struct TNode;

struct Node {
    virtual ~Node() = default;

    template <typename T> 
    bool isType() const { return dynamic_cast<const TNode<T>*>(this) != nullptr; }
};

template<typename T>
struct TNode : Node {
    T value;

    explicit TNode(const T& val) : value(val) {}

    T get() const { return value; }
};

class List {
    std::vector<Node*> nodes;

public:
    List() : nodes() {}

    template<typename T>
    void add(T val) {
        auto newnode = new TNode{val};
        nodes.push_back(newnode);
    }

    const Node* head() const {
        return nodes.back();
    }

    ~List() {
        for(auto node : nodes) {
            delete node;
        }
    }
};

#endif //LIST_H
