_static_health = 50
_static_attack = 5
_static_def = 0


class Human:
    def __init__(self, player_name):
        self._name = player_name
        self._health = _static_health
        self._attack = _static_attack
        self._defense = _static_def

    def attack(self, other):
        print(self._name, 'attacks', other.get_name(), 'for', self._attack - other.get_defense(), 'damage.')
        other.take_damage(self._attack)

    def display_stats(self):
        print('hp:', self._health,
              '\ndefense:', self._defense,
              '\nattack:', self._attack)

    def display_actions(self, other):
        if self._health <= 0:
            print(self._name, 'is currently unconscious.')
            return

        print('Attack')
        Human.attack(other)

    def take_damage(self, damage):
        self._health = self._health - (damage - self._defense)

    def get_health(self):
        return self._health

    def get_defense(self):
        return self._defense

    def get_name(self):
        return self._name
