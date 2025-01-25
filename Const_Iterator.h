//
// Created by Joseph Garcia on 3/14/24.
//

#ifndef LINKED_LIST_IMPLEMENTATION_CONST_ITERATOR_H
#define LINKED_LIST_IMPLEMENTATION_CONST_ITERATOR_H


template <typename T>
class Const_Iterator: public std::iterator<std::bidirectional_iterator_tag, T> {
private:
    Node<T> * _current;
public:

    Const_Iterator();

    Const_Iterator(Node<T> * current);


    // ++ prefix
    const Const_Iterator& operator++();

    //++Postfix
    const Const_Iterator operator++(int);

    // -- prefix
    const Const_Iterator& operator--();

    //--Postfix
    const Const_Iterator operator--(int);

    //dereference, member function that will change the object
    const T& operator*();

    T const &operator*(int);

    template<typename U>
    friend bool operator==(const Const_Iterator<U> & lhs, const Const_Iterator<U>& rhs);

    template<typename U>
    friend bool operator!=(const Const_Iterator<U> & lhs, const Const_Iterator<U>& rhs);



};

#include "Const_Iterator.cpp"
#endif //LINKED_LIST_IMPLEMENTATION_CONST_ITERATOR_H
