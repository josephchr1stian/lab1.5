//
// Created by Joseph Garcia on 3/14/24.
//

#ifndef LINKED_LIST_IMPLEMENTATION_REVERSE_ITERATOR_H
#define LINKED_LIST_IMPLEMENTATION_REVERSE_ITERATOR_H
#include <iterator>
#include "Node.h"

template <typename T>
class Reverse_Iterator: public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    Node<T>* _current;

public:


    Reverse_Iterator();

    Reverse_Iterator(Node<T> * current);


    // ++ prefix
    Reverse_Iterator& operator++();

    //++Postfix
    Reverse_Iterator operator++(int);

    // -- prefix
    Reverse_Iterator& operator--();

    //--Postfix
    Reverse_Iterator operator--(int);

    //dereference, member function that will change the object
    T& operator*();

    T const &operator*(int);

    template<typename U>
    friend bool operator==(const Reverse_Iterator<U> & lhs, const Reverse_Iterator<U>& rhs);

    template<typename U>
    friend bool operator!=(const Reverse_Iterator<U> & lhs, const Reverse_Iterator<U>& rhs);

};
#include "Reverse_Iterator.cpp"

#endif //LINKED_LIST_IMPLEMENTATION_REVERSE_ITERATOR_H
