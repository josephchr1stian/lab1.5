//
// Created by Joseph Garcia on 3/13/24.
//
#ifndef LINKED_LIST_IMPLEMENTATION_NODEITERATOR_CPP
#define LINKED_LIST_IMPLEMENTATION_NODEITERATOR_CPP
#include "NodeIterator.h"

template<typename T>
NodeIterator<T>::NodeIterator() = default;

template<typename T>
NodeIterator<T>::NodeIterator(Node<T> *current) {
     _current = current;

}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator++() {
    _current = _current->next; // Advance our pointer
    return *this; // Return a dereferenced this, which is a reference, which is a pointer.
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator++(int) {
    NodeIterator<T> temp = *this; // Create a copy of our iterator
    _current = _current->next; // Increment our iterator
    return temp; //Return the pre incremented copy
}

template<typename T>
NodeIterator<T> &NodeIterator<T>::operator--() {
    _current = _current->prev;
    return *this;
}

template<typename T>
NodeIterator<T> NodeIterator<T>::operator--(int) {
    NodeIterator<T> temp = *this; // Create a copy of our iterator
    _current = _current->prev; // decrement our iterator
    return temp; //Return the pre incremented copy
}

template<typename T>
T& NodeIterator<T>::operator*() {
    return _current->data;
}

template<typename T>
T const & NodeIterator<T>::operator*(int)
        {
    return _current->data;
}

template<typename T>
bool operator==(const NodeIterator<T> & lhs, const NodeIterator<T>& rhs)
{
    return lhs._current = rhs._current;
}

template<typename T>
bool operator!=(const NodeIterator<T> & lhs, const NodeIterator<T>& rhs)
{
    return lhs._current != rhs._current;
}


#endif