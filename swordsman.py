from human import Human

_static_attack = 10
_static_health = 60
_static_defense = 5


class Swordsman(Human):
    def __init__(self, player_name):
        super().__init__(player_name)
        self._attack = _static_attack
        self._health = _static_health
        self._defense = _static_defense
        self._martial_active = False

    def martial_strike(self):
        if not self._martial_active:
            self._martial_active = True
            print(self._name, 'focuses their physical prowess, doubling their defense and increasing their attack!')
            self._attack = self._attack * 1.8
            self._defense = self._defense * 2

        else:
            print('This is already active')

    def attack(self, other):
        if not self._martial_active:
            print(self._name, 'attacks', other.get_name(), 'for', self._attack - other.get_defense(), 'damage.')
            other.take_damage(self._attack)

        elif self._martial_active:
            print(self._name, 'unleashes their pent-up fury!')
            print(other.get_name(), 'takes', self._attack - other.get_defense(), 'damage.')
            other.take_damage(self._attack)
            self._martial_active = False
            self._attack = _static_attack
            self._defense = _static_defense

    def display_actions(self, other):
        print('Attack\nMartial Strike')
        user_choice = input()
        if user_choice == 'Attack':
            self.attack(other)

        elif user_choice == 'Martial Strike':
            self.martial_strike()

        else:
            print('That is not a valid action. Please try again.')
