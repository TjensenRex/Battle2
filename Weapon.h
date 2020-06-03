//
// Created by tjensen on 4/30/2020.
//

#pragma once

#include <string>
#include <iostream>
using namespace std;

class Weapon {
public:
    void Equip();
    void Unequip();
    unsigned short GetAttack() const;
    string GetName();
private:
    string name = "sword";
    unsigned short attack = 0;
};
