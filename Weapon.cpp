//
// Created by tjensen on 4/30/2020.
//

#include "Weapon.h"

void Weapon::Equip() {
    attack = 5;
}

void Weapon::Unequip() {
    attack = 0;
}

unsigned short Weapon::GetAttack() const {
    return attack;
}

string Weapon::GetName() {
    return name;
}
