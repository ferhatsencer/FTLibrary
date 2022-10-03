#include <iostream>

#define ARRAY_CAPACITY 1
#define ARR_RESIZE_CAPACITY 2

using namespace std;

template<class T>
class FVector {
    T *array;
    int size;
    int capacity;

public:
    FVector() {
        array = new T[ARRAY_CAPACITY];
        capacity = ARRAY_CAPACITY;
        size = 0;
    }

    FVector(const FVector &value) {
        size = value.size;
        array = new T[value.size];
        for (int index = 0; index < value.size; ++index)
            array[index] = value.array[index];
    }

    ~ FVector() {
        delete[] array;
    }

    FVector<T> &operator=(const FVector<T> &value) {
        if (this == &value) { return *this; }

        if (value.size <= capacity) {
            for (int index = 0; index < value.size; ++index) {
                array[index] = value.array[index];
                size = value.size;
                return *this;
            }
        }

        T *p = new T[value.size];

        for (int index = 0; index < value.size; ++index)
            p[index] = value.array[index];

        delete[] array;
        size = value.size;
        capacity = value.size;
        array = p;
        return *this;
    }

    T getElement(int index) {
        if (index < size)
            return array[index];
    }

    T &operator[](int i) {
        return array[i];
    }

    void pop_back() {
        array[size] = nullptr;
        size--;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void push_back(T data) {
        if (size == capacity) {//look later there could be logical mistake
            T *temp = new T[ARR_RESIZE_CAPACITY * capacity];

            for (int i = 0; i < capacity; i++) {
                temp[i] = array[i];
            }

            delete[] array;
            capacity *= ARR_RESIZE_CAPACITY;
            array = temp;
        }

        array[size] = data;
        size++;
    }

    void replace(T data, int index) {
        if (index == capacity)
            push_back(data);
        else
            array[index] = data;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    class iterator;

    iterator begin() {
        return iterator(&array[0]);
    }

    iterator end() {
        return iterator(&array[size]);
    }

};

template<class T>
class FVector<T>::iterator {

    T *current;

public:
    iterator(T *v) {
        current = v;
    }

    T &operator*() {
        return *current;
    }

    iterator &operator++() {
        current++;
        return *this;
    }

    bool operator==(const iterator &b) const {
        return *current == *b.current;
    }

};

