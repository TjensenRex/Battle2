from human import Human


class Enemy(Human):
    def __init__(self, player_name):
        super().__init__(player_name)
        self._name = player_name
        self._health = 80
        self._attack = 40
        self._defense = 5
