//
// Created by tjensen on 4/24/2020.
//

#include "Wizard.h"

Wizard::Wizard(string playerName)
{
    name = std::move(playerName);
    mana = 50;
    attack = 20;
}

void Wizard::Attack(Human *defender)
{
    if (mana >= 15)
    {
        mana = mana - 15;
        cout << name << " casts a mighty fireball at " << defender->GetName() << " for 15 Mana, dealing "
             << attack - defender->GetDefense() << " damage." << endl;
        defender->TakeDamage(attack);
    }
    else
        {
        cout << "Not enough Mana! Instead, " << name << " focuses their mind to gather ambient energy." << endl;
        mana = mana + 20;
    }
}

void Wizard::Heal()
{
    if (mana >= 15)
    {
        mana = mana - 15;
        cout << name << " casts a healing spell, healing " << attack << " hp for 15 Mana." << endl;
        health = health + attack;
        if (health > BASE_HEALTH)
        {
            health = BASE_HEALTH;
        }
    }
    else
        {
        cout << "Not enough Mana! Instead, " << name << " focuses their mind to gather ambient energy." << endl;
        mana = mana + 20;
    }
}

void Wizard::DisplayStats()
{
    cout << "hp: " << health << endl
         << "mana: " << mana << endl
         << "defense: " << defense << endl
         << "attack: " << attack << endl;
}

void Wizard::DisplayActions(Human *defender)
{
    string userChoice;

    cout << "Attack\nHeal" << endl;
    getline(cin, userChoice);
    if (userChoice == "Attack")
    {
        Attack(defender);
    }
    else if (userChoice == "Heal")
    {
        Heal();
    }
    else
        {
        cout << "That is not a valid action. Please try again." << endl;
        DisplayActions(defender);
    }
}
