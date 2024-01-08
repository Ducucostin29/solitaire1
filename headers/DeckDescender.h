//
// Created by User on 1/8/2024.
//

#ifndef OOP_DECKDESCENDER_H
#define OOP_DECKDESCENDER_H
#include "Deck.h"
#include <vector>
#include "Matchdif.h"

class DeckDescender : public Deck{
public:
    ///Constructorul clasei
    explicit DeckDescender(const std::vector<Card*>&cardsinit,int index) : Deck("descending",index,0){
        for(auto i: cardsinit)
            this->cards.push_back(i);
    }

protected:

    ///Functia validation care valideaza daca pe un Deck descrescator se afla o carte mai mare si are culoarea si numarul mai mare cu
    ///unu fata de cartea pe care vrei sa o muti atunci poti sa o muti sau daca un Deck descrescator este gata iar ultima carte a unui Deck
    ///tot descrescator este King atunci pot sa mut cartea acolo
    bool validation(Card *cart) override{
        if (this->givelastcard() == nullptr) {
            if (cart->getGender() == King)return true;
        } else if (this->givelastcard()->getGender() == cart->getGender() + 1 &&
                   matchOpus(cart->getSuite(), givelastcard()->getSuite()))
            return true;
        return false;
    }
};


#endif //OOP_DECKDESCENDER_H
