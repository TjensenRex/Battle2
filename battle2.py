from swordsman import Swordsman
from wizard import Wizard
from enemy import Enemy
import random

player_roster = {'Mark_ENEMY': Enemy('Mark_ENEMY')}
player_name = 'none'
party_list = []
combat_list = []
party_size = 3
i = 0

print('Welcome to Fantasy Battle Simulation!')
print('Please create a player by choosing a class: \nWizard \nSwordsman')
class_choice = input()

while class_choice != 'Done':
    while (class_choice != 'Wizard') and (class_choice != 'Swordsman'):
        print('Sorry, that is not in our classes. Please try again.')
        class_choice = input()

    print('And what will their name be?')
    player_name = input()

    while player_name in player_roster:
        print('That name already exists. Please choose another.')
        player_name = input()

    if class_choice == 'Wizard':
        player_roster[player_name] = Wizard(player_name)
        print('Wizard', player_name, 'created.')

    elif class_choice == 'Swordsman':
        player_roster[player_name] = Swordsman(player_name)
        print('Swordsman', player_name, 'created.')

    print('Create another character by typing a class name, or type \"Done\" to finish.')
    class_choice = input()

print()
for name in player_roster.keys():
    print(name)

while i < party_size:
    print('Choose from the list to create your party:')
    for name in party_list:
        print(name)

    player_name = input()
    if player_name in player_roster:
        party_list.append(player_name)
        print(party_list[i], 'added.')
        i += 1

print('\nFor this battle, you will face', player_roster['Mark_ENEMY'].get_name())
random.seed()

for character in party_list:
    if len(combat_list) == 0:
        combat_list.append(character)

    else:
        target = random.randint(0, len(combat_list))
        combat_list.insert(target, character)

target = random.randint(0, len(combat_list))
combat_list.insert(target, player_roster['Mark_ENEMY'].get_name())
for person in combat_list:
    print(person)

print()
try:
    while player_roster['Mark_ENEMY'].get_health() > 0:
        for combatant in combat_list:
            if type(player_roster[combatant]) != Enemy:
                if player_roster[combatant].get_health() > 0:
                    print('{opponent}: {health} hp'.format(opponent=player_roster['Mark_ENEMY'].get_name(),
                                                           health=player_roster['Mark_ENEMY'].get_health()))
                    print(f'{combatant}, it is your turn. What will you do?')
                    player_roster[combatant].display_stats()
                    player_roster[combatant].display_actions(player_roster['Mark_ENEMY'])
                    print()

                    if player_roster['Mark_ENEMY'].get_health() <= 0:
                        raise ValueError(
                            '{} is defeated. The party wins!'.format(player_roster['Mark_ENEMY'].get_name()))

                else:
                    continue

            elif type(player_roster[combatant]) == Enemy:
                target = random.randint(0, (len(combat_list) - 1))
                attacked = False

                while not attacked:
                    if player_roster[combat_list[target]].get_health() <= 0:
                        target = random.randint(0, (len(combat_list) - 1))

                    elif type(player_roster[combat_list[target]]) != Enemy:
                        player_roster[combatant].attack(player_roster[combat_list[target]])
                        attacked = True
                        if player_roster[combat_list[target]].get_health() <= 0:
                            print(player_roster[combat_list[target]].get_name(), 'has fallen.')

                    else:
                        target = random.randint(0, (len(combat_list) - 1))
        if ((player_roster[party_list[0]].get_health() <= 0) and (player_roster[party_list[1]].get_health() <= 0) and
                (player_roster[party_list[2]].get_health() <= 0)):
            raise ValueError('The party is defeated.\n')

except ValueError as end_message:
    print(end_message)
