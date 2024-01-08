//
// Created by User on 1/8/2024.
//

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

#include <exception>

template <typename  T> class Exception : public std::exception{
public:
    explicit Exception(T msg){
        this->message = msg;
    };
    T display(){
        return this->message;
    }
private:
    T message;
};

#endif //OOP_EXCEPTION_H
