#pragma once

#include <unordered_map>
#include "cat.h"
#include "animation.h"

struct GameState 
{
    std::unordered_map<Direction, Animation> walkAnims;
    Animation scratchAnim {};
    Animation washAnim {};

    void initAnims();
    void updateAnims();
    void cleanAnims();
};
