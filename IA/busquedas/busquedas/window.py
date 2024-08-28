import sys
import pygame

from game import Game
from toolbar import Toolbar
from grid import Grid

class Window:
    def __init__(self, **config):
        rows = config.get("rows", 30)
        columns = config.get("columns", 30)
        cell_width = config.get("cell_width", 20)
        cell_height = config.get("cell_height", 20)
        self.game = Game(rows, columns)
        self.toolbar = Toolbar(self.game)
        toolbar_width, toolbar_height = self.toolbar.dimensions()
        self.grid = Grid(0, toolbar_height, self.game, cell_width, cell_height)
        pygame.init()
        grid_width, grid_height = self.grid.dimensions()
        width = max(grid_width, toolbar_width)
        height = grid_height + toolbar_height
        self.screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption("Algoritmos de búsqueda")
        self.clock = pygame.time.Clock()

    def handle_events(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return self.shutdown()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                return self.shutdown()
            if event.type == pygame.KEYDOWN and event.key == pygame.K_h:
                print(self.game)
            if event.type == pygame.MOUSEMOTION:
                x, y = pygame.mouse.get_pos()
                self.game.mouse_x = x
                self.game.mouse_y = y
                clicked, _, _ = pygame.mouse.get_pressed()
                if clicked:
                    shift = pygame.key.get_mods() & pygame.KMOD_SHIFT
                    alt = pygame.key.get_mods() & pygame.KMOD_ALT
                    self.handle_dragged_click(shift, alt)
            if event.type == pygame.MOUSEBUTTONDOWN:
                shift = pygame.key.get_mods() & pygame.KMOD_SHIFT
                alt = pygame.key.get_mods() & pygame.KMOD_ALT
                self.handle_simple_click(shift, alt)

    def update(self):
        if self.game.is_playing():
            self.game.do_step()
        self.clock.tick(120)

    def draw(self):
        self.toolbar.draw(self.game, self.screen)
        self.grid.draw(self.game, self.screen)
        pygame.display.flip()

    def shutdown(self):
        pygame.quit()
        sys.exit()

    def handle_simple_click(self, shift, alt):
        self.toolbar.handle_simple_click(self.game)
        self.grid.handle_simple_click(self.game, shift, alt)

    def handle_dragged_click(self, shift, alt):
        self.grid.handle_simple_click(self.game, shift, alt)
