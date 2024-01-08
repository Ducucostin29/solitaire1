//
// Created by User on 1/8/2024.
//

#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H

#include "Game.h"
#include <memory>


class GameManager {
public:

    GameManager() : game(std::make_unique<Game>()) {}

    static GameManager& getInstance(){
        static GameManager instance;
        return instance;
    }

    [[nodiscard]] Game* getGame() const{
        return game.get();
    }

    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

private:
    std::unique_ptr<Game> game;
};


#endif //OOP_GAMEMANAGER_H
