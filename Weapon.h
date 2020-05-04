//
// Created by tjensen on 4/30/2020.
//

#ifndef BATTLE2_WEAPON_H
#define BATTLE2_WEAPON_H

#include <string>
#include <iostream>
using namespace std;

class Weapon {
public:
    void Equip();
    void Unequip();
    int GetAttack() const;
    string GetName();
private:
    string name = "sword";
    unsigned int attack = 0;
};


#endif //BATTLE2_WEAPON_H
