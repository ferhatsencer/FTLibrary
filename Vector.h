#include <iostream>

#define ARRAY_CAPACITY 1
#define ARR_RESIZE_CAPACITY 2

namespace FerhatLib {

    using namespace std;

    template<class T>
    class Vector {
        T *array;
        int m_size;
        int capacity;

    public:
        Vector() {
            array = new T[ARRAY_CAPACITY];
            capacity = ARRAY_CAPACITY;
            m_size = 0;
        }

        Vector(const Vector &value) : m_size(value.m_size) {
            //m_size = value.m_size;
            array = new T[value.m_size];
            for (int index = 0; index < value.m_size; ++index)
                array[index] = value.array[index];
        }

        ~ Vector() {
            delete[] array;
        }

        void push_back(const Vector<T> &value);

        T &at(int index);

        T &operator[](int index);

        int size();

        void pop_back();

        bool is_empty();

        void splice(const iterator<T> pos, T &other);

        Vector<T> &operator=(const Vector<T> &value) {
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

        T getElement(int index) {
            if (index < m_size)
                return array[index];
        }

//        T &operator[](int i) {
//            return array[i];
//        }
//
//        void pop_back() {
//            array[m_size] = nullptr;
//            m_size--;
//        }

        int getSize() {
            return m_size;
        }

        int getCapacity() {
            return capacity;
        }

        void push_back(T data) {
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

        void replace(T data, int index) {
            if (index == capacity)
                push_back(data);
            else
                array[index] = data;
        }

        void show() {
            for (int i = 0; i < m_size; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }

        class iterator;

        iterator begin() {
            return iterator(&array[0]);
        }

        iterator end() {
            return iterator(&array[m_size]);
        }

    };

    template<class T>
    class Vector<T>::iterator {

        T *current;

    public:
        explicit iterator(T *v) {
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

        bool operator<(const iterator &b) const {

            return *current < *b.current;//need to be implemented < operator overload.
        }

        using iterator_category = std::output_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = value_type *;
        using reference = value_type &;

    };

}