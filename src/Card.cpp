//
// Created by User on 1/8/2024.
//

#include "../headers/Card.h"

CardGender Card::getGender() {
    return this->gender;
}

Suite Card::getSuite() {
    return this->suit;
}

void Card::Flip() {
    BookUp=!BookUp;
}