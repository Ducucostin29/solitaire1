#include "headers//Game.h"

int main() {
    Game *joc ;
    joc = new Game();
    std::cout << *joc;
    joc->Moves();


//    MyVector<Game*> *v2 = new MyVector<Game*>();
//    v2->push_back(joc);
//    std::cout << *v2;
//    std::cout << " element pe v0"  << *(*v2)[0];
//    v2->clear();
//    delete v2

    delete joc;
}
