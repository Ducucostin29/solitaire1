//
// Created by User on 1/8/2024.
//

#ifndef OOP_DECK_H
#define OOP_DECK_H

#include "Card.h"
#include <string>
#include <vector>
//#include "VectorM.h"


class Deck {
public:
    ///Constructor parametrizat al clasei Deck
    Deck(const char *name, int index, unsigned long long int cardsneedwin):Name(name),Index(index),CardsNeedWin(cardsneedwin){}
    ///Destructor
    virtual ~Deck();
    ///Functie care adauga carti la final
    bool addcard(Card *card);
    ///Supraincarcarea operatorului "<<"
    friend std::ostream &operator<<(std::ostream &out, const Deck &deck) {
        out << deck.Name << " "<< deck.Index+1 << std::endl;

        for (size_t i=0; i< deck.cards.size(); i++)
            out << " " << *deck.cards[i];

        return out;
    }
    ///Functie care decide daca jocul s-a termina
    virtual bool completed();
    ///Functie care da ultima carte
    Card *givelastcard(){
        if(this->cards.empty()) {return nullptr;}
        return this->cards.back();
    }

    ///Atributele clasei
protected:
    std::string Name;
    int Index;
    unsigned long long int CardsNeedWin;
    virtual bool validation(Card *card)=0;
    std::vector<Card*> cards;
};


#endif //OOP_DECK_H
