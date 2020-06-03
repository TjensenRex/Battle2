//
// Created by tjensen on 4/24/2020.
//

#pragma once

#include "Human.h"
#include <string>
class Wizard : public Human {
public:
    explicit Wizard(string playerName);
    void DisplayStats() override;
    void Attack( Human* defender) override;
    void Heal();
    void DisplayActions(Human* defender) override;
private:
    unsigned short mana;
};
