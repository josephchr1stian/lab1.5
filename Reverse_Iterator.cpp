//
// Created by Joseph Garcia on 3/14/24.
//

#ifndef LINKED_LIST_IMPLEMENTATION_REVERSE_ITERATOR_CPP
#define LINKED_LIST_IMPLEMENTATION_REVERSE_ITERATOR_CPP
#include "Reverse_Iterator.h"


template<typename T>
Reverse_Iterator<T>::Reverse_Iterator() = default;

template<typename T>
Reverse_Iterator<T>::Reverse_Iterator(Node<T> *current) {
    _current = current;

}

template<typename T>
Reverse_Iterator<T> &Reverse_Iterator<T>::operator++() {
    _current = _current->prev;
    return *this;
}

template<typename T>
Reverse_Iterator<T> Reverse_Iterator<T>::operator++(int) {
    Reverse_Iterator<T> temp = *this; // Create a copy of our iterator
    _current = _current->prev; // Increment our iterator
    return temp; //Return the pre incremented copy
}

template<typename T>
Reverse_Iterator<T> &Reverse_Iterator<T>::operator--() {
    _current = _current->next;
    return *this;
}

template<typename T>
Reverse_Iterator<T> Reverse_Iterator<T>::operator--(int) {
    NodeIterator<T> temp = *this; // Create a copy of our iterator
    _current = _current->next; // Increment our iterator
    return temp; //Return the pre incremented copy
}

template<typename T>
T &Reverse_Iterator<T>::operator*() {
    return _current->data;
}

template<typename T>
T const & Reverse_Iterator<T>::operator*(int)
{
    return _current->data;
}

template<typename T>
bool operator==(const Reverse_Iterator<T> & lhs, const Reverse_Iterator<T>& rhs)
{
    return lhs._current = rhs._current;
}

template<typename T>
bool operator!=(const Reverse_Iterator<T> & lhs, const Reverse_Iterator<T>& rhs)
{
    return lhs._current != rhs._current;
}

#endif