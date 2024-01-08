//
// Created by User on 1/8/2024.
//

#ifndef OOP_VECTOR_H
#define OOP_VECTOR_H
#include <cstdlib>
#include <ostream>
#include "Exception.h"

template <typename  T>class Vector {
private:
    T* point;
    size_t n{};
public:
    Vector(){
        this->point= nullptr;
        this->clear();
    }
    ~Vector() {
        free(this->point);
    };
    void clear(){
        if (this->point != nullptr)
            free(this->point);
        this->point= (T*) calloc(0,sizeof (T));
        this->n=0;
    }
    void push_back(T obj){
        this->point=(T*)realloc(this->point,sizeof(T) * (this->n +1));

        this->n++;
        this->point[this->n-1]=obj;
    }
    friend std::ostream &operator<<(std::ostream &out, const Vector<T> &Vector){
        for(size_t i=0;i<Vector.n;i++)
            out << "  " << Vector.point[i];
        return out;
    }

    T operator [](size_t i) const {
        if( i >= this->n) throw Exception<char*>((char*) "Impossible \n");
        return this->point[i];
    }
    bool empty(){
        return this->n==0;
    }

    [[maybe_unused]] T back(){
        if(this->empty())throw Exception<char*>((char*) "Impossiblel \n");
        return this->point[n-1];
    }

    [[nodiscard]] size_t size() const {
        return this->n;
    }

};


#endif //OOP_VECTOR_H
