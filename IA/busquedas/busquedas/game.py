from __future__ import annotations
from typing import Any, Iterable, Optional, Callable, Iterator
import pprint
import matplotlib as mpl
from search import SearchProblem, SearchNode
from problem import GridProblem
import search


class Game:
    def __init__(self, rows: int, columns: int):
        assert 0 < rows
        assert 0 < columns
        self.grid = [[0 for _ in range(columns)] for _ in range(rows)]
        self.beg_pos: tuple[int, int] = (0, 0)
        self.end_pos: tuple[int, int] = (rows - 1, columns - 1)
        self.mouse_x: Optional[int] = None
        self.mouse_y: Optional[int] = None
        self.tool: str = "pen"
        self.status: str = "paused"
        self.algorithm: Callable[
            [SearchProblem], Iterator[Optional[SearchNode]]
        ] = search.backtracking_tree_search_step
        self.problem: Optional[SearchProblem] = None
        self.nodes = None
        self.states = {}
        self.current_node = None

    def dimensions(self):
        return len(self.grid), len(self.grid[0])

    def is_paused(self):
        return self.status == "paused"

    def is_playing(self):
        return self.status == "playing"

    def play(self):
        if self.is_playing():
            return
        self.status = "playing"

    def pause(self):
        if self.is_paused():
            return
        self.status = "paused"

    def in_pen_mode(self):
        return self.tool == "pen"

    def in_eraser_mode(self):
        return self.tool == "eraser"

    def pen_mode(self):
        self.tool = "pen"

    def eraser_mode(self):
        self.tool = "eraser"

    def ensure_nodes(self):
        if self.problem is None:
            self.problem = GridProblem(self)
            self.nodes = self.algorithm(self.problem)
            return self.nodes
        elif self.nodes is None:
            self.nodes = self.algorithm(self.problem)
            return self.nodes
        else:
            return self.nodes

    def do_step(self):
        nodes = self.ensure_nodes()
        node = next(nodes, "finished")
        if node == "finished":
            return
        if node is None:
            return
        self.current_node = node
        if self.states.get(node.state, False):
            prev_node = self.states[node.state]
            if node.cost < prev_node.cost:
                self.states[node.state] = node
        else:
            self.states[node.state] = node
                

    def step(self):
        if self.is_playing():
            return
        self.do_step()
        

    def stop(self):
        self.status = "paused"
        self.problem = None
        self.nodes = None
        self.states = {}
        self.current_node = None

    def trash(self):
        rows, columns = self.dimensions()
        self.grid = [[0 for _ in range(columns)] for _ in range(rows)]
        self.stop()

    def set_algorithm(self, algorithm):
        self.algorithm = algorithm
        self.stop()

    def valid(self, row, column):
        rows, columns = self.dimensions()
        return (0 <= row < rows) and (0 <= column < columns)

    def is_blocked(self, row, column):
        return self.grid[row][column] == 1

    def change_beg(self, row, column):
        self.beg_pos = (row, column)

    def change_end(self, row, column):
        self.end_pos = (row, column)

    def add_block(self, row, column):
        self.grid[row][column] = 1

    def del_block(self, row, column):
        self.grid[row][column] = 0

    def __repr__(self):
        return f"""\
grid = \n{pprint.pformat(self.grid, compact=True, width=120)}
beg_pos = {self.beg_pos}
end_pos = {self.end_pos}
mouse_x = {self.mouse_x}
mouse_y = {self.mouse_y}
tool = {self.tool}
status = {self.status}
algorithm = {self.algorithm}
        """


# cmap = mpl.colormaps["inferno"]
