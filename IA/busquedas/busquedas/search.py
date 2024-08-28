from __future__ import annotations
from abc import ABC, abstractmethod
from typing import Any, Iterable, Optional, Iterator
import heapq
import sys

sys.setrecursionlimit(10000)

State = Any
Action = Any


class SearchProblem(ABC):
    @abstractmethod
    def state_test(self, value: Any) -> bool:
        """
        Tests if the given value is a state.
        """
        ...

    @abstractmethod
    def action_test(self, value: Any) -> bool:
        """
        Test if the given value is an action.
        """
        ...

    @abstractmethod
    def initial_state(self) -> State:
        """
        Returns the initial state.
        """
        ...

    @abstractmethod
    def goal_test(self, state: State) -> bool:
        """
        Test if the given state is final
        """
        ...

    @abstractmethod
    def actions(self, state: State) -> Iterable[Action]:
        """
        Returns the actions that can be
        performed in the given state.
        """
        ...

    @abstractmethod
    def state_from(self, state: State, action: Action) -> State:
        """
        Returns the state that results from
        performing the given action in the
        given state.
        """
        ...

    @abstractmethod
    def cost_from(self, state: State, action: Action) -> float:
        """
        Returns the cost that results from
        performing the given action in the
        given state.
        """
        ...

    def path_cost(
        self, accumulated: float, state1: State, action: Action, state2: State
    ) -> float:
        return accumulated + self.cost_from(state1, action)

    def state_value(self, state: State) -> Any:
        raise NotImplementedError


class SearchNode:
    def __init__(
        self,
        state: State,
        parent: Optional[SearchNode] = None,
        action: Optional[Action] = None,
        cost: float = 0,
    ):
        self.state = state
        self.parent = parent
        self.action = action
        self.cost = cost
        self.depth = 0 if parent is None else parent.depth + 1

    def __repr__(self) -> str:
        return f"<Node {self.action} -> {self.state}>"

    def expand(self, problem: SearchProblem) -> Iterable[SearchNode]:
        def child_node(action: Action) -> SearchNode:
            next_state = problem.state_from(self.state, action)
            next_cost = problem.path_cost(
                self.cost,
                self.state,
                action,
                next_state,
            )
            return SearchNode(
                next_state,
                self,
                action,
                next_cost,
            )

        return [child_node(action) for action in problem.actions(self.state)]

    def path(self) -> list[SearchNode]:
        node = self
        trace = []
        while node is not None:
            trace.append(node)
            node = node.parent
        trace.reverse()
        return trace

    def actions(self) -> list[Action]:
        return [node.action for node in self.path()[1:]]

    def __lt__(self, other):
        return self.state < other.state

def filter_cycles(node, nodes):
    next_nodes = []
    for next_node in nodes:
        if next_node.state in [pnode.state for pnode in node.path()]:
            continue
        next_nodes.append(next_node)
    return next_nodes

##########################
# ALGORITMOS DE BUSQUEDA #
##########################

def backtracking_tree_search_step(problem: SearchProblem) -> Iterator[Optional[SearchNode]]:
    best_node = SearchNode(None, cost=float("inf"))
    frontier = [SearchNode(problem.initial_state())]
    while frontier:
        node = frontier.pop()
        yield node
        if not problem.goal_test(node.state):
            frontier.extend(filter_cycles(node, node.expand(problem)))
        elif node.cost < best_node.cost:
            best_node = node
    if best_node.state is None:
        yield None
    yield best_node

def depth_first_tree_search_step(problem: SearchProblem) -> Iterator[Optional[SearchNode]]:
    frontier = [SearchNode(problem.initial_state())]
    while frontier:
        node = frontier.pop()
    raise NotImplementedError
    yield None

def breadth_first_tree_search_step(problem: SearchProblem) -> Iterator[Optional[SearchNode]]:
    frontier = [SearchNode(problem.initial_state())]
    while frontier:
        node = frontier.pop(0)
    raise NotImplementedError
    yield None

def iterative_deepening_tree_search_step(problem: SearchProblem) -> Iterator[Optional[SearchNode]]:
    def depth_first_tree_search_step(depth: int) -> Iterator[Optional[SearchNode]]:
        raise NotImplementedError
    depth = 1
    while True:
        yield from depth_first_tree_search_step(depth)
        depth += 1

def uniform_cost_search_step(problem: SearchProblem) -> Iterator[Optional[SearchNode]]:
    frontier = []
    visited = set()
    heapq.heappush(frontier, (0, SearchNode(problem.initial_state())))
    while frontier:
        _, node = heapq.heappop(frontier)
        if node.state in visited:
            continue
        visited.add(node.state)
    raise NotImplementedError
    yield None

def a_star_search_step(problem: SearchProblem) -> Iterator[Optional[SearchNode]]:
    raise NotImplementedError
