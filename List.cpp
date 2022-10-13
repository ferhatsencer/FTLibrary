//
// Created by Ferhat Sencer on 10/11/22.
//

#include "List.h"

template<class T>
FerhatLib::List<T>::List(): m_begin(0), m_end(0), m_size(0) {

}

template<class T>
FerhatLib::List<T>::List(const List &value) : m_begin(0), m_end(0), m_size(0) {
    for (LList<T> *current = value.m_begin; current != 0; current = current->next)
        push_back(current->value);
}

template<class T>
FerhatLib::List<T>::~List() {
    LList<T> *first = m_begin;
    while (first != 0) {
        LList<T> *next = first->next;
        delete first;
        first = next;
    }
}

template<class T>
FerhatLib::List<T>::List(std::initializer_list<T> value) {
    for (auto element: value) {
        push_back(element);
    }
}

template<class T>
FerhatLib::List<T> &FerhatLib::List<T>::operator=(const List<T> &value) {
    if (this == value) { return *this; }
    List<T> *tmp = m_begin;
    for (tmp = m_begin; m_begin != nullptr; delete tmp) {
        m_begin = m_begin->next;
    }
    m_size = value.m_size;
    m_begin = value.m_begin;
    m_end = value.m_end;
}

template<class T>
void FerhatLib::List<T>::push_back(const T &value) {

    auto *temp = m_begin;

    if (m_begin == nullptr) {
        m_begin = m_end = new LList<T>(value);
    } else {
//                temp->previous = m_end;
//                m_end->next = temp;
//                m_end = temp;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = new LList<T>(value);
    }
    m_size++;
}

template<class T>
void FerhatLib::List<T>::show() {
    for (LList<T> *temp = m_begin; m_begin->next != nullptr; temp = temp->next)
        std::cout << temp->value;
}

//template<class T>
//iterator FerhatLib::List<T>::begin() {
//    return iterator(m_begin);
//}
//
//template<class T>
//iterator FerhatLib::List<T>::end() {
//    return iterator(m_end);
//}

template<class T>
FerhatLib::iterator<T>::iterator(): current(0) {

}

template<class T>
FerhatLib::iterator<T>::iterator(iterator<T> *v): current(v->current) {

}

template<class T>
T &FerhatLib::iterator<T>::operator*() {
    return current->value;
}

template<class T>
FerhatLib::iterator<T> FerhatLib::iterator<T>::operator++() {
    current++;
    return *this;
}

template<class T>
bool FerhatLib::iterator<T>::operator==(const iterator &value) const {
    return (this->current == value.current);
}