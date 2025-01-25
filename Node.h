//
// Created by Joseph Garcia on 3/12/24.
//

#ifndef LINKED_LIST_IMPLEMENTATION_NODE_H
#define LINKED_LIST_IMPLEMENTATION_NODE_H
template <typename T>
struct Node
{
    T data;
    Node<T> * prev = nullptr, * next = nullptr;
};

#endif //LINKED_LIST_IMPLEMENTATION_NODE_H
