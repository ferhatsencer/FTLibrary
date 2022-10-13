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
        Vector();

        Vector(const Vector &value);

        ~ Vector();

        void push_back(const Vector<T> &value);

        T &at(int index);

        T &operator[](int index);

        int size();

        void pop_back();

        bool is_empty();

        //void splice(const iterator<T> pos, T &other);

        Vector<T> &operator=(const Vector<T> &value);

        T getElement(int index);

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

        void push_back(T data);

        void replace(T data, int index);

        void show();

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
        explicit iterator(T *v) : current(v) {

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