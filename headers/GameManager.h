//
// Created by User on 1/8/2024.
//

#ifndef OOP_GAMEMANAGER_H
#define OOP_GAMEMANAGER_H

#include "Game.h"


class GameManager {
public:
    ~GameManager(){
        delete game;
    }

    static GameManager& getInstance(){
        static GameManager instance;
        return instance;
    }

    [[nodiscard]] Game* getGame() const{
        return game;
    }
private:
    Game *game;
    GameManager() : game(new Game()){}
};


#endif //OOP_GAMEMANAGER_H
