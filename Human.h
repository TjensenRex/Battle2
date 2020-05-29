//
// Created by tjensen on 4/24/2020.
//

#ifndef BATTLE2_HUMAN_H
#define BATTLE2_HUMAN_H

#include <iostream>
#include <string>
#include "Weapon.h"
using namespace std;

const static int BASE_HEALTH = 50;
const static int BASE_ATTACK = 5;
const static int BASE_DEF = 0;

class Human {
public:
    Human(string playerName = "none");
    virtual void Attack(Human* defender);
    virtual void DisplayStats();
    virtual void DisplayActions(Human* defender);
    void TakeDamage(int damage);
    int GetHealth() const;
    int GetDefense() const;
    string GetName() const;

protected:
    unsigned int health;
    unsigned int attack;
    unsigned int defense;
    string name;
    Weapon weapon;
};


#endif //BATTLE2_HUMAN_H
