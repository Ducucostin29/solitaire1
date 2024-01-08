//
// Created by User on 1/8/2024.
//

#ifndef OOP_MATCHDIF_H
#define OOP_MATCHDIF_H

#include "Suite.h"
#include "Gender.h"

static bool matchOpus(Suite color, Suite match) {
    if (color <= 1 && match >= 2) return true;
    if (color >= 2 && match <= 1) return true;
    return false;
}

#endif //OOP_MATCHDIF_H
