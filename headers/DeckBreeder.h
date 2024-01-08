//
// Created by User on 1/8/2024.
//

#ifndef OOP_DECKBREEDER_H
#define OOP_DECKBREEDER_H
#include "Deck.h"
#include "Card.h"


class DeckBreeder: public Deck{
public:
    ///Constructorul clasei
    explicit DeckBreeder(Suite color,int index): Deck("breeder",index,13){
        this->color = color;
    }

    ///Fuctia vituala completed fiind definita in clasa Deck si arta daca un deck crescator s-a completat
    bool completed() override {
            if(!Deck::completed()) return false;

            for(unsigned long long i=0; i< this->cards.size()-1;i++) {
                if (this->cards[i]->getGender() >= this->cards[i+1]->getGender())
                    return false;
            }
            return true;
    }
///Atributele clasei
protected:
    Suite color;

    ///Functia validation care pune carte peste carte in deck-urile cresacatoare
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
