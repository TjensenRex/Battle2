//
// Created by tjensen on 4/24/2020.
//

#include "Human.h"

Human::Human(string playerName)
{
    name = playerName;
    health = BASE_HEALTH;
    attack = BASE_ATTACK + weapon.GetAttack();
    defense = BASE_DEF;
}
void Human::Attack(Human* defender)
{
    cout << name << " attacks " << defender->GetName() << " for " << attack - defender->GetDefense() << " damage." << endl;
    defender->TakeDamage(attack);
}
void Human::DisplayActions(Human* defender)
{

    if (health <= 0)
    {
        cout << name << " is currently unconscious." << endl;
        return;
    }
    cout << "Attack" << endl;
    Attack(defender);
}
void Human::TakeDamage(int damage)
{
    health = health - (damage - defense);
}
int Human::GetHealth() const
{
    return health;
}
int Human::GetDefense() const
{
    return defense;
}
string Human::GetName() const
{
    return name;
}

void Human::DisplayStats()
{
    cout << "hp: " << health << endl
         << "defense: " << defense << endl
         << "attack: " << attack << endl;
}
