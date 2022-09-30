//
// Created by Ferhat Sencer on 9/26/22.
//

#ifndef FTLIBRARY_FLIST_H
#define FTLIBRARY_FLIST_H

template<class T>
struct FLinkedList {
    FLinkedList(const T& v) {
        value = v;
        next = 0;
        previous = 0;
    }

    T value;
    FLinkedList<T>* next;
    FLinkedList<T>* previous;
};


template<class T>
class FList {
    int m_size;
    FLinkedList<T>* _begin;
    FLinkedList<T>* _end;

public:
    FList(){
        _begin = 0;
        _end = 0;
        m_size = 0;
    }
    FList(const FList& value){
        _begin = 0;
        _end = 0;
        m_size = 0;

        for(FLinkedList<T>* current = value._begin ; current != 0; current = current->next)
            push_back(current->value);

    }
    ~FList(){
        FLinkedList<T> * first = _begin;
        while (first != 0)
        {
            FLinkedList <T> * next = first->next;
            delete first;
            first = next;
        }
    }

    bool is_empty();
    int size();
    void pop_back();
    void push_back(const T& value){

        FLinkedList<T>* temp = new FLinkedList<T>(value);

        if(_begin == 0){
            _begin = _end = temp;
        }
        else{
            temp->previous = _end;
            _end->next = temp;
            _end = temp;
        }
        m_size++;
    }

    void show(){
        FLinkedList<T>* temp = _begin;
        while(_begin->next != nullptr){
            std::cout << temp->value;
            temp = temp->next;
        }
    }

    class iterator;

    iterator begin(){
        return iterator(_begin);
    }

    iterator end(){
        return iterator(_end);
    }
};


template<class T>
class iterator{
    T* current;

public:

    iterator(){
        current = 0;
    }
//    iterator(FLinkedList<T>* v){
//        current = v;
//    }
    iterator(iterator<T>* v){
        current = v->current;
    }

    T & operator*(){
        return current -> value;
    }

    iterator operator++(){
        current++;
        return *this;
    }

    bool operator==(const iterator & value) const{
        return ( this->current == value.current );
    }

};


#endif //FTLIBRARY_FLIST_H
