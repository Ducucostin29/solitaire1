//
// Created by User on 1/8/2024.
//

#ifndef OOP_LIST_H
#define OOP_LIST_H
#include <cstdlib>
#include "Exception.h"
#include <ostream>

///Template pentru Lista
template <typename T> class Node {
public:
    Node<T> * next;
    T value;
    explicit Node(T value){
        this->next = nullptr;
        this->value = value ;
    }
};


template <typename T>class [[maybe_unused]] List {
private:
    Node<T>* start;
    Node<T>* end;
    size_t n{};
public:
    explicit List(){
        this->n = 0;
        this->start = nullptr;
        this->end = nullptr;
    }
    ~List(){
        this->clear();
    }
    bool empty(){
        return this->n==0;
    }

    [[maybe_unused]] void push_back(T obj){
        if(end== nullptr){
            this->start=new Node<T>(obj);
            this->end=this->start;
        }else{
            Node<T> *old = this->end;
            this->end=new Node<T>(obj);
            old->next = this->end;
        }
        this->n++;
    }
    void clear(){
        Node<T> *it = this->start;
        while (it != nullptr){
            Node<T> *aux = it->next;
            delete it;
            it = aux;
        }
    }

    friend std::ostream &operator<<(std::ostream &out, const List<T> &myList){
        Node<T> *it = myList.start;
        while (it != nullptr) {
            out << "  " << it->value;
            it=it->next;
        }
        return out;
    }

    T operator [](size_t i) const {
        if( i >= this->n) throw Exception<char*>((char*) "Impossible \n");
        Node<T> *it = this->start;
        while (it != nullptr){
            if ( i == 0 )
                return it->value;
            it = it->next;
            i--;
        }
        throw Exception<char*>((char*) "Impossible \n");
    }

    [[maybe_unused]] T back(){
        if(this->empty())throw Exception<char*>((char*) "Impossible \n");
        return this->end->value;
    }

    [[maybe_unused]] [[nodiscard]] size_t size() const {
        return this->n;
    }

};


#endif //OOP_LIST_H
