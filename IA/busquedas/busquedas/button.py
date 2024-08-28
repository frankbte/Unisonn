import pygame
from subwindow import Subwindow

class Button(Subwindow):
    def __init__(self, x, y, width, height, icon_path):
        self.image = pygame.image.load(icon_path)
        self.hover = False
        self.enabled = True
        self.active = False
        super().__init__(x, y, width, height)

    def draw(self, game, screen):
        screen.blit(self.image, (self.x, self.y))

    def draw_rect(self, screen, color):
        pygame.draw.rect(screen, color, self.rect)

    def draw_active(self, screen):
        self.draw_rect(screen, (233, 227, 27))

    def draw_disabled(self, screen):
        self.draw_rect(screen, (175, 187, 210))

    def draw_hover(self, screen):
        self.draw_rect(screen, (96, 145, 236))

    def draw_enabled(self, screen):
        self.draw_rect(screen, (76, 93, 125))
