//
// Created by User on 1/8/2024.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <ostream>
#include "Exception.h"
#include "Vector.h"
#include "../headers/DeckHidden.h"
#include "../headers/DeckBreeder.h"
#include "../headers/DeckDescender.h"

class Game {
public:
    ///Constructorul clasei
    explicit Game() {
        this->GameInitialization();
    }
    ///Destructorul clasei
    ~Game() {
        delete this->hidden;
        for (int i = 0; i < 4; i++)
            delete this->breed[i];
        for (int i = 0; i < 7; i++)
            delete this->desc[i];

    }

    ///Functie care reda toate Deck-urile si le initializeaza
    void GameInitialization();

    ///Supraincarcarea operatorului "<<"
    friend std::ostream &operator<<(std::ostream &out, const Game &game) {
        out << "Game: " << std::endl;
        out << *game.hidden;
        for(size_t i=0;i<game.breed.size();i++)
            out<<*game.breed[i];
        for(size_t i=0;i<game.desc.size();i++)
            out<<*game.desc[i];
        return out;
    }

    ///Functie pentru a ordona cartile random
    static std::vector<Card *> Random(std::vector<Card *> const &v);

    ///Functie care arata daca jocul este terminat
    bool Win();

    ///Functie care misca cartile
    void Moves();

    ///Atributele clasei
private:
    DeckHidden *hidden{};
    Vector<DeckBreeder *> breed;
    Vector<DeckDescender *> desc;
    void MoveCard();
    void MoveCard2();
};


#endif //OOP_GAME_H
