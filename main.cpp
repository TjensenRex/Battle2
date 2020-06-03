#include <iostream>
#include <vector>
#include <map>
#include "Human.h"
#include "Swordsman.h"
#include "Wizard.h"
#include "Enemy.h"
#include <cstdlib>
#include <ctime>

using namespace std;

const static string TEST_DUMMY = "Mark-ENEMY";
const static short PARTY_SIZE = 3;

int main()
{
    map<string, Human*> playerRoster;
    string playerName;
    string classChoice;
    playerRoster.emplace(TEST_DUMMY, new Enemy(TEST_DUMMY)); // This player's residency will only last as long as his usefulness 3:)
    vector<Human*> partyList(0);
    vector<Human*> combatList(0);
    short target;

    cout << "Welcome to Fantasy Battle Simulation!" << endl;
    cout << "Please create a player by choosing a class: \nWizard \nSwordsman" << endl;
    getline(cin, classChoice);

    /* This first part prompts a user to type a class name until a valid class name is entered. Eventually, might try to
     * create an "inventory" class or vector data member for "Human" that can hold items which modify the player's stats */
    while (classChoice != "Done")
    {
        while ((classChoice != "Wizard") && (classChoice != "Swordsman"))
        {
            //if ((classChoice != "Wizard") && (classChoice != "Swordsman"))
            //{
                cout << classChoice << ". Sorry, that is not in our classes. Please try again." << endl;
                getline(cin, classChoice);
           // }
        }
        cout << "And what will their name be?" << endl;
        //loop until a unique name is entered
        do
            {
            getline(cin, playerName);
            if (playerRoster.count(playerName))
            {
                cout << "That name already exists. Please choose another." << endl;
                continue;
            }
            else {
                break;
            }
        }
        while (playerRoster.count(playerName));

        if (classChoice == "Wizard")
        {
            playerRoster.emplace(playerName, new Wizard(playerName));
            cout << "Wizard " << playerRoster[playerName]->GetName() << " created." << endl;
        }
        else if (classChoice == "Swordsman")
        {
            playerRoster.emplace(playerName, new Swordsman(playerName));
            cout << "Swordsman " << playerName << " created." << endl;
        }
        cout << endl << "Create another character by typing a class name, or type \"Done\" to finish." << endl;
        getline(cin, classChoice);
    }
    //A player may choose from a list comprised of as many characters as they created
    cout << endl;
    for (pair<string, Human*> characterName : playerRoster)
    {
        cout << characterName.first << endl;
    }
    //loop until three valid characters are selected, displaying a list of current selections
    for (int i = 0; i < PARTY_SIZE;)
    {
        cout << "Choose from the list to create your party: " << endl;
        for (Human* character : partyList)
        {
            cout << character->GetName() << endl;
        }

        getline(cin, playerName);
        if (playerRoster.count(playerName) == 1)
        {
            partyList.push_back(playerRoster[playerName]);
            cout << partyList.at(i)->GetName() << " added." << endl;
            ++i;
        }
    }

    cout << endl;
    cout << "For this battle, you will face " << playerRoster[TEST_DUMMY]->GetName() << "." << endl;
    srand((unsigned)time(0));

    for (Human* character : partyList)
    {
        if (combatList.empty())
        {
            combatList.push_back(character);
        }
        else
            {
            //combatList is randomly populated with the players from partyList
            target = rand() % combatList.size();
            combatList.insert(combatList.begin() + target, character);
        }
    }

    //Enemy is randomly inserted in combatList
    target = rand() % combatList.size();
    combatList.insert(combatList.begin() + target, playerRoster[TEST_DUMMY]);
    for (Human* character : combatList)
    {
        cout << character->GetName() << endl;
    }
    cout << endl;

    //Swordsman: 9Swordsman. Enemy: 5Enemy. Wizard: 6Wizard.
    /* This is meant to be a kind of turn-based combat, going until the enemy or the party reaches 0 hitpoints
     * Eventually, would like to learn how to call this as part of a larger program */
    try
    {
        while (playerRoster[TEST_DUMMY]->GetHealth() > 0)
        {
            for (Human *currentPlayer : combatList)
            {
                if (typeid(*currentPlayer).name() != typeid(Enemy).name())
                {
                    //attack steps for party members
                    if (currentPlayer->GetHealth() > 0)
                    {
                        cout << playerRoster[TEST_DUMMY]->GetName() << ": " << playerRoster[TEST_DUMMY]->GetHealth()
                             << "hp"
                             << endl << endl;
                        cout << currentPlayer->GetName() << ", it is your turn. What will you do?" << endl;

                        currentPlayer->DisplayStats();
                        currentPlayer->DisplayActions(playerRoster[TEST_DUMMY]);
                        cout << endl;
                        //check if Enemy is defeated
                        if (playerRoster[TEST_DUMMY]->GetHealth() <= 0)
                        {
                            throw string (playerRoster[TEST_DUMMY]->GetName() + " is defeated. The party wins!\n");
                        }
                    }
                    else
                        {
                        continue;
                    }
                }
                else if (typeid(*currentPlayer).name() == typeid(Enemy).name())
                {
                    //attack steps for Enemy types
                    bool attacked = false;

                    while (!attacked)
                    {
                        target = rand() % combatList.size();
                        if (combatList.at(target)->GetHealth() <= 0)
                        {
                            target = rand() % combatList.size();
                        }
                        //Enemy auto-attacks
                        else if (typeid(*combatList.at(target)).name() != typeid(Enemy).name())
                        {
                            currentPlayer->Attack(combatList.at(target));
                            attacked = true;
                            //check if Enemy's target has 0 or less hitpoints
                            if (combatList.at(target)->GetHealth() <= 0)
                            {
                                cout << combatList.at(target)->GetName() << " has fallen." << endl;
                            }
                        }
                    }
                }
            }
            //check if party is defeated
            if ((partyList.at(0)->GetHealth() <= 0) && (partyList.at(1)->GetHealth() <= 0) &&
               (partyList.at(2)->GetHealth() <= 0))
            {
                throw string ("The party is defeated.\n");
            }
        }
    }
    catch(string battleEnd)
    {
        cout << battleEnd;
    }

    return 0;
}
