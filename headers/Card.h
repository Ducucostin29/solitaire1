//
// Created by User on 1/8/2024.
//

#ifndef OOP_CARD_H
#define OOP_CARD_H
#include <ostream>
#include <string>
#include <sstream>
#include <wabtags.h>
#include "Suite.h"
#include "Gender.h"

class Card {
public:
    ///Constructor parametrizat al clasei Card
    Card(Suite suit, CardGender gender, bool bookup): suit(suit), gender(gender), BookUp(bookup){}
    ///Getter pentru gender
    CardGender getGender();
    ///Getter pentru suita
    Suite getSuite();
    ///Functie ce intoarce cartea cu fata in jos
    void Flip();
    ///Supraincarcarea operatorului "<<"
    friend std::ostream &operator<<(std::ostream &out, const Card &card) {

        std::ostringstream str;
        if (card.BookUp) {
            const std::string suite[] = {"Red_Heart", "Diamond", "Club", "Black_Heart"};
            const std::string gene[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
            str << gene[card.gender] << " " << suite[card.suit] << std::endl;
        } else {
            str << "Face Down" << std::endl;
        }
        out << str.str() ;
        return out;
    }
///Atributele clasei
private:
    Suite suit;
    CardGender gender;
    bool BookUp;
};


#endif //OOP_CARD_H
