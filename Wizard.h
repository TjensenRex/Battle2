//
// Created by tjensen on 4/24/2020.
//

#ifndef BATTLE2_WIZARD_H
#define BATTLE2_WIZARD_H

#include "Human.h"
#include <string>
class Wizard : public Human {
public:
    Wizard(string playerName);
    void DisplayStats();
    int GetMana() const;
    void Attack( Human* defender);
    void Heal();
    void DisplayActions(Human* defender);
private:
    unsigned int mana;
};


#endif //BATTLE2_WIZARD_H
