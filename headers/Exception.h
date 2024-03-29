//
// Created by User on 1/8/2024.
//

#ifndef OOP_EXCEPTION_H
#define OOP_EXCEPTION_H

#include <exception>

///Template pentr custom exception
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

class ExceptionOutOfDeck : public std::exception{
public:
    [[nodiscard]] const char* what() const noexcept override;
};

#endif //OOP_EXCEPTION_H
