//
// Created by User on 1/8/2024.
//
#include "../headers/Exception.h"

[[maybe_unused]]const char  *ExceptionOutOfDeck::what() const noexcept {
    return "Object is out of deck";
}