//
// Created by User on 1/8/2024.
//

#include "../headers/Deck.h"

    Deck::~Deck(){
        for(size_t i=0;i< this->cards.size();i++)
            delete this->cards[i];
}
    bool Deck::addcard(Card *card) {
        if(validation(card)){
            this->cards.push_back(card);
            return true;
        }
        return false;
}
   bool Deck::completed() {
       return this->cards.size() == this->CardsNeedWin;
}
