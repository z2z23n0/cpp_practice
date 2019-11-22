//
// Created by Zeno on 2019/11/22.
//
#include <utility>

template <typename T> class node;
template <typename T> void swap(node<T> & a, node<T> & b);

template<typename T> class node {
private:
    node<T>* left;
    node<T>* right;
    T value;

public:
    friend void swap<>(node<T>&, node<T>&);
};

template <typename T> void swap(node<T> & a, node<T> & b) {
    std::swap(a.left, b.left);
    std::swap(a.right, b.right);
    std::swap(a.value, b.value);
}

int main() {
    node<int> x, y;
    swap(x, y);
}
