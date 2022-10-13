//
// Created by Ferhat Sencer on 9/26/22.
//

#ifndef FTLIBRARY_LIST_H
#define FTLIBRARY_LIST_H

#include <iostream>

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
        List();

        List(const List &value);

        ~List();

        List(std::initializer_list<T> value);

        void push_back(const List<T> &value);

        T &at(int index);

        T &front();

        T &back();

        int size();

        void pop_back();

        bool is_empty();

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


    template<class T>
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
#endif //FTLIBRARY_LIST_H
