import pygame
import sys

# Inicializamos juego
pygame.init()

# Colores
WHITE = (128,128,128)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

# Dimensiones de la pantalla
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Tower of Hanoi")

# Define peg dimensions
PEG_WIDTH = 10
PEG_HEIGHT = 300
PEG_COLOR = BLACK

# Define disk dimensions
DISK_HEIGHT = 30
DISK_COLOR = BLUE

# Function to draw pegs
def draw_pegs():
    pygame.draw.rect(screen, PEG_COLOR, (200, 100, PEG_WIDTH, PEG_HEIGHT))
    pygame.draw.rect(screen, PEG_COLOR, (400, 100, PEG_WIDTH, PEG_HEIGHT))
    pygame.draw.rect(screen, PEG_COLOR, (600, 100, PEG_WIDTH, PEG_HEIGHT))

# Function to draw disks
def draw_disks(state):
    for i, peg in enumerate(state):
        x = 200 + 200 * i
        y = 370
        for j, disk in enumerate(peg):
            width = 200 - 65 * j
            pygame.draw.rect(screen, DISK_COLOR, (x - width / 2, y - DISK_HEIGHT / 2, width, DISK_HEIGHT))
            y -= DISK_HEIGHT

# Main game loop
def main():
    clock = pygame.time.Clock()
    running = True

    state = [[3, 2, 1], [], []]  # Initial state of the Tower of Hanoi puzzle

    while running:
        screen.fill(WHITE)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

        draw_pegs()
        draw_disks(state)

        pygame.display.flip()
        clock.tick(60)

    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
