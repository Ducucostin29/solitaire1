//
// Created by User on 1/8/2024.
//

#ifndef OOP_DECKBREEDER_H
#define OOP_DECKBREEDER_H
#include "Deck.h"
#include "Card.h"


class DeckBreeder: public Deck{
public:
    explicit DeckBreeder(Suite color,int index): Deck("breeder",index,13){
        this->color = color;
    }
    bool completed() override {
            if(!Deck::completed()) return false;

            for(unsigned long long i=0; i< this->cards.size()-1;i++) {
                if (this->cards[i]->getGender() >= this->cards[i+1]->getGender())
                    return false;
            }
            return true;
    }

protected:
    Suite color;
    bool validation(Card *cart) override{
        if (this->color != cart->getSuite())return false;

        if (this->givelastcard() == nullptr) {
            if (cart->getGender() == Ace) return true;
        } else {
            if (this->givelastcard()->getGender() + 1 == cart->getGender()) return true;
        }

        return false;
    }
};


#endif //OOP_DECKBREEDER_H
