#include "headers//GameManager.h"


int main() {

    GameManager& gameManager = GameManager::getInstance();
    Game* game = gameManager.getGame();
    std::cout << *game;
    game->Moves();
    return 0;
}

