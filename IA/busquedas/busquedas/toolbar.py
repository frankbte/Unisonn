import pygame
from subwindow import Subwindow
from button import Button
import search


class PenButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/pen.png")

    def draw(self, game, screen):
        if game.in_pen_mode():
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.pen_mode()


class EraserButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/eraser.png")

    def draw(self, game, screen):
        if game.in_eraser_mode():
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.eraser_mode()


class PlayButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/play.png")

    def draw(self, game, screen):
        if game.is_playing():
            self.draw_disabled(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.play()

class PauseButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/pause.png")

    def draw(self, game, screen):
        if game.is_paused():
            self.draw_disabled(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.pause()

class StepButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/step.png")

    def draw(self, game, screen):
        if game.is_playing():
            self.draw_disabled(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.step()

class DoubleStepButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/dstep.png")

    def draw(self, game, screen):
        if game.is_playing():
            self.draw_disabled(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        for _ in range(500):
            game.step()

class StopButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/stop.png")

    def draw(self, game, screen):
        if self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.stop()

class TrashButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 32, 32, "./assets/trash.png")

    def draw(self, game, screen):
        if self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.trash()

class BacktrackingButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 64, 32, "./assets/route-bt.png")

    def draw(self, game, screen):
        if game.algorithm == search.backtracking_tree_search_step:
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.set_algorithm(search.backtracking_tree_search_step)

class DepthFirstButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 64, 32, "./assets/route-dfs.png")

    def draw(self, game, screen):
        if game.algorithm == search.depth_first_tree_search_step:
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.set_algorithm(search.depth_first_tree_search_step)

class BreadthFirstButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 64, 32, "./assets/route-bfs.png")

    def draw(self, game, screen):
        if game.algorithm == search.breadth_first_tree_search_step:
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.set_algorithm(search.breadth_first_tree_search_step)

class IterativeDeepeningButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 64, 32, "./assets/route-dfsid.png")

    def draw(self, game, screen):
        if game.algorithm == search.iterative_deepening_tree_search_step:
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.set_algorithm(search.iterative_deepening_tree_search_step)

class UniformCostButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 64, 32, "./assets/route-ucs.png")

    def draw(self, game, screen):
        if game.algorithm == search.uniform_cost_search_step:
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.set_algorithm(search.uniform_cost_search_step)

class AStarButton(Button):
    def __init__(self, x, y):
        super().__init__(x, y, 64, 32, "./assets/route-astar.png")

    def draw(self, game, screen):
        if game.algorithm == search.a_star_search_step:
            self.draw_active(screen)
        elif self.inside(game.mouse_x, game.mouse_y):
            self.draw_hover(screen)
        else:
            self.draw_enabled(screen)
        super().draw(game, screen)

    def handle_simple_click(self, game):
        game.set_algorithm(search.a_star_search_step)

class Toolbar(Subwindow):
    def __init__(self, game):
        self.buttons = [
            PenButton(0 * 32, 0),
            EraserButton(1 * 32, 0),
            PlayButton(2 * 32, 0),
            PauseButton(3 * 32, 0),
            StepButton(4 * 32, 0),
            DoubleStepButton(5 * 32, 0),
            StopButton(6 * 32, 0),
            TrashButton(7 * 32, 0),
            BacktrackingButton(8 * 32, 0),
            DepthFirstButton(10 * 32, 0),
            BreadthFirstButton(12 * 32, 0),
            IterativeDeepeningButton(14 * 32, 0),
            UniformCostButton(16 * 32, 0),
            AStarButton(18 * 32, 0),
        ]
        width = sum(button.dimensions()[0] for button in self.buttons)
        super().__init__(0, 0, width, 32)

    def draw(self, game, screen):
        super().draw(game, screen)
        for button in self.buttons:
            button.draw(game, screen)

    def handle_simple_click(self, game):
        x, y = game.mouse_x, game.mouse_y
        if not self.inside(x, y):
            return
        for button in self.buttons:
            if button.inside(x, y):
                button.handle_simple_click(game)
