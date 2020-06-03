//
// Created by tjensen on 5/7/2020.
//

#include "Enemy.h"

Enemy::Enemy(string playerName)
{
    name = std::move(playerName);
    health = 80;
    attack = 40;
    defense = 5;
}
