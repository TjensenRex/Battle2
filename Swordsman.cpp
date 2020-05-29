//
// Created by tjensen on 4/24/2020.
//

#include "Swordsman.h"
const int BASE_ATK = 5;
const int BASE_HP = 60;
const int BASE_DF = 5;
Swordsman::Swordsman(string playerName)
{
    weapon.Equip();
    name = playerName;
    attack = BASE_ATK + weapon.GetAttack();
    health = BASE_HP;
    defense = BASE_DF;
    martialActive = false;
}

void Swordsman::MartialStrike()
{
    if (!martialActive)
    {
        martialActive = true;
        cout << name << " focuses their physical prowess, doubling their defense and increasing their attack!" << endl;
        attack = attack * 1.8;
        defense = defense * 2;
    }
    else if (martialActive)
    {
        cout << "This is already active." << endl;
    }
}

void Swordsman::Attack(Human* defender)
{
    if (!martialActive)
    {
        cout << name << " attacks " << defender->GetName() << " for " << attack - defender->GetDefense() << " damage." << endl;
        defender->TakeDamage(attack);
    }
    else if (martialActive)
    {
        cout << name << " unleashes their pent-up fury!" << endl;
        cout << defender->GetName() << " takes " << attack - defender->GetDefense() << " damage." << endl;
        defender->TakeDamage(attack);
        martialActive = false;
        attack = BASE_ATK + weapon.GetAttack();
        defense = BASE_DF;
    }
}

void Swordsman::DisplayActions(Human* defender)
{
    string userChoice;

    cout << "Attack\nMartial Strike" << endl;
    getline(cin, userChoice);
    if (userChoice == "Attack")
    {
        Attack(defender);
    }
    else if (userChoice == "Martial Strike")
    {
        MartialStrike();
    }
    else
        {
        cout << "That is not a valid action. Please try again." << endl;
        DisplayActions(defender);
    }
}
