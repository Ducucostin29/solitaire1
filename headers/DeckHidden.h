//
// Created by User on 1/8/2024.
//

#ifndef OOP_DECKHIDDEN_H
#define OOP_DECKHIDDEN_H
#include "Deck.h"

class DeckHidden: public Deck{
public:
    DeckHidden(): Deck("hidden",0,0){}

protected:

    bool validation(Card*)override{
        return true;
    }
};


#endif //OOP_DECKHIDDEN_H
