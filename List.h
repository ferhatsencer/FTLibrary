//
// Created by Ferhat Sencer on 9/26/22.
//

#ifndef FTLIBRARY_LIST_H
#define FTLIBRARY_LIST_H

namespace FerhatLib {

    template<class T>
    struct LList {
        explicit LList(const T &v) : value(v), next(0), previous(0) {

        }

        T value;
        LList<T> *next;
        LList<T> *previous;
    };


    template<class T>
    class List {
        int m_size{};
        LList<T> *m_begin;
        LList<T> *m_end;

    public:
        List() {
            m_begin = 0;
            m_end = 0;
            m_size = 0;
        }

        List(const List &value) : m_begin(0), m_end(0), m_size(0) {
            for (LList<T> *current = value.m_begin; current != 0; current = current->next)
                push_back(current->value);
        }

        ~List() {
            LList<T> *first = m_begin;
            while (first != 0) {
                LList<T> *next = first->next;
                delete first;
                first = next;
            }
        }

        List(std::initializer_list<T> value) {
            for (auto element: value) {
                push_back(element);
            }
        }

        void push_back(const List<T> &value);

        T &at(int index);

        T &front();

        T &back();

        int size();

        void pop_back();

        bool is_empty();

        List<T> &operator=(const List<T> &value) {
            if (this == value) { return *this; }
            List<T> *tmp = m_begin;
            for (tmp = m_begin; m_begin != nullptr; delete tmp) {
                m_begin = m_begin->next;
            }
            m_size = value.m_size;
            m_begin = value.m_begin;
            m_end = value.m_end;
        }


        void push_back(const T &value) {

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

        void show() {
            for (LList<T> *temp = m_begin; m_begin->next != nullptr; temp = temp->next)
                std::cout << temp->value;
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

//    iterator(LList<T>* v){
//        current = v;
//    }
        explicit iterator(iterator<T> *v) {
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

}
#endif //FTLIBRARY_LIST_H
