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
    explicit Game() {
        this->GameInitialization();
    }

    ~Game() {
        delete this->hidden;
        for (int i = 0; i < 4; i++)
            delete this->breed[i];
        for (int i = 0; i < 7; i++)
            delete this->desc[i];

    }
    void GameInitialization();

    friend std::ostream &operator<<(std::ostream &out, const Game &game) {
        out << "Game: " << std::endl;
        out << *game.hidden;
        for(size_t i=0;i<game.breed.size();i++)
            out<<*game.breed[i];
        for(size_t i=0;i<game.desc.size();i++)
            out<<*game.desc[i];
        return out;
    }

    static std::vector<Card *> Random(std::vector<Card *> const &v);

    bool Win();

    void Moves();

private:
    DeckHidden *hidden{};
    Vector<DeckBreeder *> breed;
    Vector<DeckDescender *> desc;
    void MoveCard();
    void MoveCard2();
};


#endif //OOP_GAME_H
