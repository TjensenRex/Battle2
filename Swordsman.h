//
// Created by tjensen on 4/24/2020.
//

#ifndef BATTLE2_SWORDSMAN_H
#define BATTLE2_SWORDSMAN_H

#include "Human.h"
#include <string>

class Swordsman : public Human {
public:
    Swordsman(string playerName = "none");
    void MartialStrike();
    void Attack(Human *defender);
    void DisplayActions(Human* defender);
private:
    bool martialActive;
};


#endif //BATTLE2_SWORDSMAN_H
