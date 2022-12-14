//
// Created by Ferhat Sencer on 9/26/22.
//

#ifndef FTLIBRARY_LIST_H
#define FTLIBRARY_LIST_H

#include <iostream>

namespace FerhatLib {

    template<typename T>
    struct LList {
        explicit LList(const T &v) : value(v), next(nullptr), previous(nullptr) {

        }

        T value;
        LList<T> *next;
        LList<T> *previous;
    };


    template<typename T>
    class List {
        int m_size{};
        LList<T> *m_begin{};
        LList<T> *m_end{};

    public:
        List();

        List(const List &l);

        ~List();

        List(std::initializer_list<T> value);

//        void push_back(const List<T> &value);
//
//        T &at(int index);
//
//        T &front();
//
//        T &back();
//
//        int size();
//
//        void pop_back();
//
//        bool is_empty();

        List<T> &operator=(const List<T> &value);

        void push_back(const T &value);

        void show();

        class iterator;

        iterator begin() {
            return iterator(m_begin);
        }

        iterator end() {
            return iterator(m_end);
        }
    };


    template<typename T>
    class iterator {
        T *current;

    public:

        iterator();

//    iterator(LList<T>* v){
//        current = v;
//    }
        explicit iterator(iterator<T> *v);

        T &operator*();

        iterator operator++();

        bool operator==(const iterator &value) const;

    };

}

template<typename T>
FerhatLib::List<T>::List(): m_begin(0), m_end(0), m_size(0) {

}

template<typename T>
FerhatLib::List<T>::List(const List &l) : m_begin(0), m_end(0), m_size(0) {
    for (LList<T> *current = l.m_begin; current != nullptr; current = current->next)
        push_back(current->value);
}

template<class T>
FerhatLib::List<T>::~List() {
    auto temp = m_begin;
    while (temp != 0) {
        auto next = temp->next;
        delete temp;
        temp = next;
    }
}

template<typename T>
FerhatLib::List<T>::List(std::initializer_list<T> value) {
    for (auto element: value) {
        push_back(element);
    }
}

template<typename T>
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

template<typename T>
void FerhatLib::List<T>::push_back(const T &value) {

//    auto temp = m_begin;
    auto temp = new LList<T>(value);
    if (m_begin == nullptr) {
        m_begin = m_end = temp;
    } else {
        temp->previous = m_end;
        m_end->next = temp;
        m_end = temp;
//        while (temp->next != nullptr)
//            temp = temp->next;

//        temp->next = new LList<T>(value);
//        m_end = temp->next;
    }
    m_size++;
}

template<typename T>
void FerhatLib::List<T>::show() {
    auto temp = m_begin;
    if (temp == nullptr) {
        std::cout << "Empty" << std::endl;
    } else {
        do {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        } while (temp != nullptr);
    }
}

//template<typename T>
//iterator FerhatLib::List<T>::begin() {
//    return iterator(m_begin);
//}
//
//template<typename T>
//iterator FerhatLib::List<T>::end() {
//    return iterator(m_end);
//}

template<typename T>
FerhatLib::iterator<T>::iterator(): current(0) {

}

template<typename T>
FerhatLib::iterator<T>::iterator(iterator<T> *v): current(v->current) {

}

template<typename T>
T &FerhatLib::iterator<T>::operator*() {
    return current->value;
}

template<typename T>
FerhatLib::iterator<T> FerhatLib::iterator<T>::operator++() {
    current++;
    return *this;
}

template<typename T>
bool FerhatLib::iterator<T>::operator==(const iterator &value) const {
    return (this->current == value.current);
}

#endif //FTLIBRARY_LIST_H
