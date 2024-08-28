import math
from search import SearchProblem

sqrt2 = math.sqrt(2)


class GridProblem(SearchProblem):
    def __init__(self, game):
        self.game = game

    def state_test(self, value):
        if not isinstance(value, tuple):
            return False
        if not len(value) == 2:
            return False
        row, column = value
        rows, columns = self.game.dimensions()
        if not isinstance(row, int) or not (0 <= row < rows):
            return False
        if not isinstance(column, int) or not (0 <= column < columns):
            return False
        if self.game.is_blocked(row, column):
            return False
        return True

    def action_test(self, value):
        return value in (
            {(i, j) for i in range(-1, 2) for j in range(-1, 2)} - {(0, 0)}
        )

    def initial_state(self):
        return self.game.beg_pos

    def goal_test(self, state):
        return state == self.game.end_pos

    def valid_state(self, state):
        row, col = state
        return self.game.valid(row, col) and not self.game.is_blocked(row, col)

    def actions(self, state):
        a = []
        row, col = state
        if self.valid_state((row - 1, col - 1)):
            a.append((-1, -1))
        if self.valid_state((row - 1, col)):
            a.append((-1, 0))
        if self.valid_state((row - 1, col + 1)):
            a.append((-1, +1))
        if self.valid_state((row, col + 1)):
            a.append((0, +1))
        if self.valid_state((row + 1, col + 1)):
            a.append((+1, +1))
        if self.valid_state((row + 1, col)):
            a.append((+1, 0))
        if self.valid_state((row + 1, col - 1)):
            a.append((+1, -1))
        if self.valid_state((row, col - 1)):
            a.append((0, -1))
        return a

    def state_from(self, state, action):
        srow, scol = state
        arow, acol = action
        return (srow + arow, scol + acol)

    def cost_from(self, state, action):
        arow, acol = action
        if arow + acol == 1:
            return 1
        return sqrt2

    def state_value(self, state):
        x1, y1 = state
        x2, y2 = self.game.end_pos
        return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
