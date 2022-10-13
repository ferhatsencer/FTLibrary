//
// Created by Ferhat Sencer on 10/13/22.
//

#include "Vector.h"

template<class T>
FerhatLib::Vector<T>::Vector() {
    array = new T[ARRAY_CAPACITY];
    capacity = ARRAY_CAPACITY;
    m_size = 0;
}

template<class T>
FerhatLib::Vector<T>::Vector(const Vector &value) : m_size(value.m_size) {
    //m_size = value.m_size;
    array = new T[value.m_size];
    for (int index = 0; index < value.m_size; ++index)
        array[index] = value.array[index];
}

template<class T>
FerhatLib::Vector<T>::~ Vector() {
    delete[] array;
}

template<class T>
FerhatLib::Vector<T> &FerhatLib::Vector<T>::operator=(const Vector<T> &value) {
    if (this == &value) { return *this; }

    if (value.m_size <= capacity) {
        for (int index = 0; index < value.m_size; ++index) {
            array[index] = value.array[index];
            m_size = value.m_size;
            return *this;
        }
    }

    T *p = new T[value.m_size];

    for (int index = 0; index < value.m_size; ++index)
        p[index] = value.array[index];

    delete[] array;
    m_size = value.m_size;
    capacity = value.m_size;
    array = p;
    return *this;
}

template<class T>
T FerhatLib::Vector<T>::getElement(int index) {
    if (index < m_size)
        return array[index];
}

template<class T>
void FerhatLib::Vector<T>::push_back(T data) {
    if (m_size == capacity) {//look later there could be logical mistake
        T *temp = new T[ARR_RESIZE_CAPACITY * capacity];

        for (int i = 0; i < capacity; i++) {
            temp[i] = array[i];
        }

        delete[] array;
        capacity *= ARR_RESIZE_CAPACITY;
        array = temp;
    }

    array[m_size] = data;
    m_size++;
}

template<class T>
void FerhatLib::Vector<T>::replace(T data, int index) {
    if (index == capacity)
        push_back(data);
    else
        array[index] = data;
}

template<class T>
void FerhatLib::Vector<T>::show() {
    for (int i = 0; i < m_size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}