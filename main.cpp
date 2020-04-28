#include <iostream>
#include <vector>
#include <map>
#include "Human.h"
#include "Swordsman.h"
#include "Wizard.h"

using namespace std;

const static string TEST_DUMMY = "Mark";

int main() {
    map<string, Human*> playerRoster;
    string playerName;
    string classChoice;
    playerRoster.emplace(TEST_DUMMY, new Swordsman(TEST_DUMMY));
    // This player's residency will only last as long as his usefulness 3:)

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
            if (playerRoster.count(playerName) == 1){
                cout << "That name already exists. Please choose another." << endl;
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
    cout << "Choose one of your characters to play as:" << endl;
    for (pair<string, Human*> characterName : playerRoster) {
        cout << characterName.first << endl;
    }
    getline(cin, playerName);

    cout << endl;
    cout << "For this battle, you will face " << playerRoster[TEST_DUMMY]->GetName() << "." << endl;

    /* This is meant to be a kind of turn-based combat, going until one of the participants reaches 0 hitpoints
     * Eventually, would like to figure out how to do this for a "party" of players, and learn how to call this as part
     * of a larger program */
    while ((playerRoster[playerName]->GetHealth() > 0) && (playerRoster[TEST_DUMMY]->GetHealth() > 0)) {
        cout << playerRoster[TEST_DUMMY]->GetName() << ": " << playerRoster[TEST_DUMMY]->GetHealth() << "hp" << endl;
        playerRoster[playerName]->DisplayStats();
        cout << "Choose your action: " << endl;
        playerRoster[playerName]->DisplayActions(playerRoster[TEST_DUMMY]);

        if (playerRoster[TEST_DUMMY]->GetHealth() <= 0) {
            cout << playerRoster[TEST_DUMMY]->GetName() << " is defeated. " << playerRoster[playerName]->GetName() << " wins!" << endl;
            break;
        }
        playerRoster[TEST_DUMMY]->Attack(playerRoster[playerName]);

        if (playerRoster[playerName]->GetHealth() <= 0) {
            cout << playerRoster[playerName]->GetName() << " is defeated. " << playerRoster[TEST_DUMMY]->GetName() << " wins!" << endl;
            break;
        }
    }
    return 0;
}
