//
// Created by Ferhat Sencer on 9/26/22.
//

#ifndef FTLIBRARY_FLIST_H
#define FTLIBRARY_FLIST_H

template<class T>
struct FLinkedList {
    FLinkedList(const T &v) {
        value = v;
        next = 0;
        previous = 0;
    }

    T value;
    FLinkedList<T> *next;
    FLinkedList<T> *previous;
};


template<class T>
class FList {
    int m_size;
    FLinkedList<T> *m_begin;
    FLinkedList<T> *m_end;

public:
    FList() {
        m_begin = 0;
        m_end = 0;
        m_size = 0;
    }

    FList(const FList &value) : m_begin(0), m_end(0), m_size(0) {
        for (FLinkedList<T> *current = value.m_begin; current != 0; current = current->next)
            push_back(current->value);
    }

    ~FList() {
        FLinkedList<T> *first = m_begin;
        while (first != 0) {
            FLinkedList<T> *next = first->next;
            delete first;
            first = next;
        }
    }

    FList<T> &operator=(const FList<T> &value) {
        if (this == value) { return *this; }
        FList<T> *tmp = m_begin;
        for (tmp = m_begin; m_begin != nullptr; delete tmp) {
            m_begin = m_begin->next;
        }
        m_size = value.m_size;
        m_begin = value.m_begin;
        m_end = value.m_end;
    }

    bool is_empty();

    int size();

    void pop_back();

    void push_back(const T &value) {

        FLinkedList<T> *temp = new FLinkedList<T>(value);

        if (m_begin == 0) {
            m_begin = m_end = temp;
        } else {
            temp->previous = m_end;
            m_end->next = temp;
            m_end = temp;
        }
        m_size++;
    }

    void show() {
        FLinkedList<T> *temp = m_begin;
        while (m_begin->next != nullptr) {
            std::cout << temp->value;
            temp = temp->next;
        }
    }

    class iterator;

    iterator begin() {
        return iterator(m_begin);
    }

    iterator end() {
        return iterator(m_end);
    }
};


template<class T>
class iterator {
    T *current;

public:

    iterator() {
        current = 0;
    }

//    iterator(FLinkedList<T>* v){
//        current = v;
//    }
    iterator(iterator<T> *v) {
        current = v->current;
    }

    T &operator*() {
        return current->value;
    }

    iterator operator++() {
        current++;
        return *this;
    }

    bool operator==(const iterator &value) const {
        return (this->current == value.current);
    }

};


#endif //FTLIBRARY_FLIST_H
