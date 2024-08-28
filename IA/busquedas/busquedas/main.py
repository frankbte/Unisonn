from window import Window

if __name__ == "__main__":
    window = Window(
        rows=15,
        columns=15,
        cell_width=40,
        cell_height=40,
    )
    while True:
        window.handle_events()
        window.update()
        window.draw()
