import pygame

class Subwindow:
    def __init__(self, x, y, width, height, color = None):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.color = color
        self.rect = pygame.Rect(x, y, width, height)

    def draw(self, game, screen):
        if self.color is None:
            return
        color = self.color
        rect = self.rect
        pygame.draw.rect(screen, color, rect)

    def dimensions(self):
        return self.width, self.height

    def inside(self, x, y):
        if x is None or y is None:
            return False
        return self.rect.collidepoint(x, y)
