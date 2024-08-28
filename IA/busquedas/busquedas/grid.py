import matplotlib as mpl
import pygame
from subwindow import Subwindow

cmap = mpl.colormaps["viridis"]


class Grid(Subwindow):
    def __init__(self, x, y, game, cell_width, cell_height):
        rows, columns = game.dimensions()
        self.offset_x = x
        self.offset_y = y
        self.cell_width = cell_width
        self.cell_height = cell_height
        width = columns * cell_width
        height = rows * cell_height
        super().__init__(x, y, width, height, pygame.Color((76, 93, 125)))

    def draw(self, game, screen):
        super().draw(game, screen)
        rows, columns = game.dimensions()
        cell_width = self.cell_width
        cell_height = self.cell_height
        for row in range(rows):
            y = row * cell_height + self.offset_y
            for column in range(columns):
                x = column * cell_width + self.offset_x
                if game.is_blocked(row, column):
                    pygame.draw.rect(
                        screen, (0, 0, 0), pygame.Rect(x, y, cell_width, cell_height)
                    )
                elif (row, column) in game.states:
                    prop = 1 - 0.8 * (game.states[(row, column)].cost) / (
                        rows * columns
                    )
                    color = tuple(int(255 * c) for c in cmap(prop)[:-1])
                    pygame.draw.rect(
                        screen,
                        color,
                        pygame.Rect(x, y, cell_width, cell_height),
                    )
                else:
                    pygame.draw.rect(
                        screen,
                        (255, 255, 255),
                        pygame.Rect(x, y, cell_width, cell_height),
                    )
        if self.inside(game.mouse_x, game.mouse_y):
            hover_row = (game.mouse_y - self.offset_y) // cell_height
            hover_col = (game.mouse_x - self.offset_x) // cell_width
            pygame.draw.rect(
                screen,
                (233, 227, 27),
                pygame.Rect(
                    cell_width * hover_col + self.offset_x,
                    cell_height * hover_row + self.offset_y,
                    cell_width,
                    cell_height,
                ),
                2,
            )
        pygame.draw.rect(
            screen,
            (32, 227, 36),
            pygame.Rect(
                cell_width * game.beg_pos[1] + self.offset_x,
                cell_height * game.beg_pos[0] + self.offset_y,
                cell_width,
                cell_height,
            ),
            3,
        )
        pygame.draw.rect(
            screen,
            (63, 141, 65),
            pygame.Rect(
                cell_width * game.end_pos[1] + self.offset_x,
                cell_height * game.end_pos[0] + self.offset_y,
                cell_width,
                cell_height,
            ),
            3,
        )

        if game.current_node is None:
            return
        states = [node.state for node in game.current_node.path()]
        if len(states) > 1:
            pygame.draw.lines(
                screen,
                (207, 31, 0),
                False,
                [
                    (
                        col * cell_width + cell_width // 2,
                        row * cell_height + 32 + cell_height // 2,
                    )
                    for (row, col) in states
                ],
                5,
            )

    def handle_simple_click(self, game, shift, alt):
        if not self.inside(game.mouse_x, game.mouse_y):
            return
        row = (game.mouse_y - self.offset_y) // self.cell_height
        col = (game.mouse_x - self.offset_x) // self.cell_width
        if shift:
            game.change_beg(row, col)
        elif alt:
            game.change_end(row, col)
        elif game.in_pen_mode():
            game.add_block(row, col)
        elif game.in_eraser_mode():
            game.del_block(row, col)
