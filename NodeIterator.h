//
// Created by Joseph Garcia on 3/13/24.
//

#ifndef LINKED_LIST_IMPLEMENTATION_NODEITERATOR_H
#define LINKED_LIST_IMPLEMENTATION_NODEITERATOR_H
#include "Node.h"
#include <iterator>
template <typename T>
class NodeIterator :  public std::iterator<std::bidirectional_iterator_tag, T>
{
private:
    Node<T> * _current ;
public:
    NodeIterator();

    explicit NodeIterator(Node<T> * current);

    // ++ prefix
    NodeIterator& operator++();

    //++Postfix
    NodeIterator operator++(int);

    // -- prefix
    NodeIterator& operator--();

    //--Postfix
    NodeIterator operator--(int);

    //dereference, member function that will change the object
    T& operator*();

    T const &operator*(int);

    template<typename U>
    friend bool operator==(const NodeIterator<U> & lhs, const NodeIterator<U>& rhs);

    template<typename U>
    friend bool operator!=(const NodeIterator<U> & lhs, const NodeIterator<U>& rhs);





};

#include "NodeIterator.cpp"
#endif //LINKED_LIST_IMPLEMENTATION_NODEITERATOR_H
