//
// Created by Joseph Garcia on 3/12/24.
//

#ifndef LINKED_LIST_IMPLEMENTATION_LINKEDLIST_CPP
#define LINKED_LIST_IMPLEMENTATION_LINKEDLIST_CPP

#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() = default;


template<typename T>
void LinkedList<T>::addFirstNode(Node<T> *node) {
    head = node;
    tail = node;
    listSize++;

}

template<typename T>
Node<T> *LinkedList<T>::createNode(const T &data) {
    Node<T> * ptr = new Node<T> ;
    ptr->data = data;
    //listSize ++;
    return ptr;
}

template<typename T>
void LinkedList<T>::push_front(Node<T> *node) {

    if (head == nullptr)
        addFirstNode(node);
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
        listSize++;
    }

}

template<typename T>
void LinkedList<T>::push_back(Node<T> *node) {

    if (head == nullptr || tail == nullptr)
        addFirstNode(node);
    else
    {
        node->prev = tail;
        tail->next = node;
        tail= node;
        listSize++;
    }


}

template<typename T>
Node<T> *LinkedList<T>::search(const T &data) {

    Node<T> * walker;
    walker = head;
    /*if (walker->data == data)
    {
        return walker;
    }*/
    while (walker->data != data)
    {
        walker = walker->next;
        /*if (walker->data == data)
            return walker;
        if (walker->next == nullptr)
            return nullptr;*/
    }
    return walker;

}



template<typename T>
void LinkedList<T>::remove(Node<T> *node)
{
    if (node == nullptr)
    {
        std::cout<< "The entered item was not found in the list"<<std::endl;
    }
    else if (head == node)
        pop_front();
    else if (tail == node)
        pop_back();
    else
    {
        Node<T> * previous, next;
        previous = node->prev;
        next = node->next;
        previous->next = next;
        next.prev = previous;
        listSize--;
        delete node;
    }
}
template <typename T>
void LinkedList<T>:: remove(const T& item)
{
    remove(search(item));
}

template<typename T>
void LinkedList<T>::pop_back() {
    tail->prev->next = nullptr;
    Node<T> * temp = tail;
    tail = tail->prev;
    listSize--;
    delete  temp;
}

template<typename T>
void LinkedList<T>::pop_front() {
    head->next->prev = nullptr;
    Node<T> * temp = head;
    head = head->next;
    listSize--;
    delete temp;
}


template<typename T>
void LinkedList<T>::push_front(const T& item)
{
    push_front(createNode(item));
}

template<typename T>
void LinkedList<T>::push_back(const T& item)
{
    push_back(createNode(item));
}


template<typename T>
std::ostream & operator<<(std::ostream & out, const LinkedList<T>& list)
{
   Node<T> * walker = list.head;
    while (walker != nullptr)
    {
        out << walker->data << "-";
        walker = walker->next;
    }
    return out;
}

template<typename T>
const Node<T> *LinkedList<T>::getHead() const {
    return head;
}

template<typename T>
const Node<T> *LinkedList<T>::getTail() const {
    return tail;
}

template<typename T>
Node<T> *LinkedList<T>::getHead() {
    return head;
}

template<typename T>
Node<T> *LinkedList<T>::getTail() {
    return tail;
}

template<typename T>
NodeIterator<T> LinkedList<T>::begin() {

    return NodeIterator<T>(head);
}

template<typename T>
NodeIterator<T> LinkedList<T>::end() {
    return NodeIterator<T>(nullptr);
}

template<typename T>
const Const_Iterator<T>LinkedList<T>::cbegin()
{

    return Const_Iterator<T>(head);
}

template<typename T>
const Const_Iterator<T> LinkedList<T>::cend() {
    return Const_Iterator<T>(nullptr);
}

template<typename T>
Reverse_Iterator<T> LinkedList<T>::rbegin() {
    return Reverse_Iterator<T>(tail);
}

template<typename T>
Reverse_Iterator<T> LinkedList<T>::rend() {
    return Reverse_Iterator<T>(nullptr);
}


/*template<typename T>
LinkedList<T> &LinkedList<T>::operator++() {
    iterator++;
    const_iterator++;
    reverse_iterator++;
    return this;
}*/

/*template<typename T>
LinkedList<T> LinkedList<T>::operator++(int) {
    iterator++;
    const_iterator++;
    reverse_iterator++;
    return this;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator--() {
    iterator--;
    const_iterator--;
    reverse_iterator--;
    return this;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator--(int) {
    iterator--;
    const_iterator--;
    reverse_iterator--;
    return this;
}*/

/*template<typename T>
T &LinkedList<T>::operator*() {
    return iterator.data;
}*/


/*template<typename T>
bool operator==(const LinkedList<T> & lhs, const LinkedList<T>& rhs)
{
    return lhs._current == rhs._current;
}

template<typename T>
bool operator!=(const LinkedList<T> & lhs, const LinkedList<T>& rhs)
{
    return lhs._current != rhs._current;
}*/

#endif
