from human import Human


class Wizard(Human):
    def __init__(self, player_name):
        Human.__init__(self, player_name)
        self._mana = 50
        self._attack = 20

    def attack(self, other):
        if self._mana >= 15:
            self._mana -= 15
            print(self._name, 'casts a mighty fireball at', other.get_name(), 'for 15 mana, dealing',
                  self._attack - other.get_defense(), 'damage.')
            other.take_damage(self._attack)

        else:
            print('Not enough Mana! Instead,', self._name, 'focuses their mind to gather ambient energy.')
            self._mana += 20

    def heal(self):
        if self._mana >= 15:
            self._mana -= 15
            print(self._name, 'casts a healing spell, healing', self._attack, 'hp for 15 mana.')
            self._health += self._attack
            if self._health > 50:
                self._health = 50

        else:
            print('Not enough Mana! Instead,', self._name, 'focuses their mind to gather ambient energy.')
            self._mana += 20

    def display_stats(self):
        print('hp:', self._health,
              '\nmana:', self._mana,
              '\ndefense:', self._defense,
              '\nattack:', self._attack)

    def display_actions(self, other):
        print('Attack\nHeal')
        user_choice = input()
        if user_choice == 'Attack':
            self.attack(other)

        elif user_choice == 'Heal':
            self.heal()

        else:
            print('That is not a valid action. Please try again.')
            self.display_actions(other)
