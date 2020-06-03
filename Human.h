//
// Created by tjensen on 4/24/2020.
//

#pragma once

#include <iostream>
#include <string>
#include "Weapon.h"
using namespace std;

const static short BASE_HEALTH = 50;
const static short BASE_ATTACK = 5;
const static short BASE_DEF = 0;

class Human {
public:
    explicit Human(string playerName = "none");
    virtual void Attack(Human* defender);
    virtual void DisplayStats();
    virtual void DisplayActions(Human* defender);
    void TakeDamage(unsigned short damage);
    short GetHealth() const;
    unsigned short GetDefense() const;
    string GetName() const;

protected:
    short health;
    unsigned short attack;
    unsigned short defense;
    string name;
    Weapon weapon;
};
