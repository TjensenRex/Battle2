//
// Created by tjensen on 4/24/2020.
//

#pragma once

#include "Human.h"
#include <string>

class Swordsman : public Human {
public:
    explicit Swordsman(string playerName = "none");
    void MartialStrike();
    void Attack(Human *defender) override;
    void DisplayActions(Human* defender) override;
private:
    bool martialActive;
};
