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

const static string TEST_DUMMY = "Mark";
const static int PARTY_SIZE = 3;

int main() {
    map<string, Human*> playerRoster;
    string playerName;
    string classChoice;
    playerRoster.emplace(TEST_DUMMY, new Enemy(TEST_DUMMY)); // This player's residency will only last as long as his usefulness 3:)
    //FIXME: create an Enemy class for more challenging opponents
    vector<Human*> partyList(0);
    vector<Human*> combatList(0);
    int target;

    cout << "Welcome to Fantasy Battle Simulation!" << endl;
    cout << "Please create a player by choosing a class: \nWizard \nSwordsman" << endl;
    getline(cin, classChoice);

    /* This first part prompts a user to type a class name until a valid class name is entered. Although "Human" is the
     * base class of these two classes, it is not available as an option. Eventually, might try to create an "inventory"
     * class or vector data member for "Human" that can hold items which modify the player's stats */
    while (classChoice != "Done") {

        while ((classChoice != "Wizard") && (classChoice != "Swordsman")) {
            if ((classChoice != "Wizard") && (classChoice != "Swordsman")) {
                cout << classChoice << ". Sorry, that is not in our classes. Please try again." << endl;
                getline(cin, classChoice);
            }
        }
        cout << "And what will their name be?" << endl;
        do {
            getline(cin, playerName);
            if (playerRoster.count(playerName) == 1) {
                cout << "That name already exists. Please choose another." << endl;
                continue;
            }
            else {
                break;
            }
        }while (playerRoster.count(playerName) == 1);

        if (classChoice == "Wizard") {
            playerRoster.emplace(playerName, new Wizard(playerName));
            cout << "Wizard " << playerRoster[playerName]->GetName() << " created." << endl;
        }
        else if (classChoice == "Swordsman") {
            playerRoster.emplace(playerName, new Swordsman(playerName));
            cout << "Swordsman " << playerName << " created." << endl;
        }
        cout << endl << "Create another character by typing a class name, or type \"Done\" to finish." << endl;
        getline(cin, classChoice);
    }
    //A player may choose from a list comprised of as many characters as they created
    cout << endl;
    for (pair<string, Human*> characterName : playerRoster) {
        cout << characterName.first << endl;
    }
    for (int i = 0; i < PARTY_SIZE;) {
        cout << "Choose from the list to create your party: " << endl;
        for (Human* character : partyList) {
            cout << character->GetName() << endl;
        }

        getline(cin, playerName);
        for (pair<string, Human*> characterName : playerRoster) {
            if (characterName.first == playerName) {
                partyList.push_back(characterName.second);
                cout << partyList.at(i)->GetName() << " added." << endl;
                ++i;
            }
        }
    }

    cout << endl;
    cout << "For this battle, you will face " << playerRoster[TEST_DUMMY]->GetName() << "." << endl;
    srand(time(0));

    for (Human* character : partyList) {
        if (combatList.size() == 0){
            combatList.push_back(character);
        }
        else {
            target = rand() % combatList.size();
            cout << target << endl;
            combatList.insert(combatList.begin() + target, character);
            cout << "character added" << endl;
        }
    }
    cout << "list size: " << combatList.size() << endl;

    for(Human* names : combatList) {
        cout << combatList.size() << endl << names->GetName() << endl;
    }
    cout << endl;

    /* This is meant to be a kind of turn-based combat, going until the enemy or the party reaches 0 hitpoints
     * Eventually, would like to learn how to call this as part of a larger program */
    /*party system needs:
     * going in an order determined randomly by the system.*/
    while(playerRoster[TEST_DUMMY]->GetHealth() > 0) {
        for(Human* currentPlayer : combatList) {

            cout << playerRoster[TEST_DUMMY]->GetName() << ": " << playerRoster[TEST_DUMMY]->GetHealth() << "hp" << endl << endl;
            cout << currentPlayer->GetName() << ", it is your turn. What will you do?" << endl;
            currentPlayer->DisplayStats();
            currentPlayer->DisplayActions(playerRoster[TEST_DUMMY]);
            cout << endl;

            if (playerRoster[TEST_DUMMY]->GetHealth() <= 0) {
                break;
            }
        }
        if (playerRoster[TEST_DUMMY]->GetHealth() <= 0) {
            cout << playerRoster[TEST_DUMMY]->GetName() << " is defeated. The party wins!" << endl;
            break;
        }

        target = rand() % 3;

        playerRoster[TEST_DUMMY]->Attack(combatList.at(target));

        if (combatList.at(target)->GetHealth() <= 0) {
            cout << playerRoster[playerName]->GetName() << " has fallen. " << endl;
            combatList.erase(combatList.begin() + target);
        }
    }

    return 0;
}
