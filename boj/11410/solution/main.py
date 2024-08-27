import sys
input = lambda: sys.stdin.readline().rstrip()

#N=int(input())


from collections import defaultdict, deque
import sys

class MinCostMaxFlow:
    def __init__(self, n):
        self.n = n
        self.adj = defaultdict(list)
        self.cost = {}
        self.capacity = {}
        self.flow = {}
        self.parent = {}

    def add_edge(self, u, v, capacity, cost):
        self.adj[u].append(v)
        self.adj[v].append(u)
        self.cost[(u, v)] = cost
        self.cost[(v, u)] = -cost
        self.capacity[(u, v)] = capacity
        self.capacity[(v, u)] = 0
        self.flow[(u, v)] = 0
        self.flow[(v, u)] = 0

    def shortest_path(self, source, sink):
        dist = {node: float('inf') for node in range(self.n)}
        in_queue = {node: False for node in range(self.n)}
        self.parent = {node: None for node in range(self.n)}
        dist[source] = 0
        queue = deque([source])
        in_queue[source] = True

        while queue:
            u = queue.popleft()
            in_queue[u] = False
            for v in self.adj[u]:
                if self.capacity[(u, v)] - self.flow[(u, v)] > 0 and dist[v] > dist[u] + self.cost[(u, v)]:
                    dist[v] = dist[u] + self.cost[(u, v)]
                    self.parent[v] = u
                    if not in_queue[v]:
                        queue.append(v)
                        in_queue[v] = True

        return dist[sink] != float('inf')

    def min_cost_max_flow(self, source, sink):
        max_flow = 0
        min_cost = 0

        while self.shortest_path(source, sink):
            # Determine the maximum flow along the path found by BFS
            increment_flow = float('inf')
            v = sink
            while v != source:
                u = self.parent[v]
                increment_flow = min(increment_flow, self.capacity[(u, v)] - self.flow[(u, v)])
                v = u

            # Apply the flow along the path
            v = sink
            while v != source:
                u = self.parent[v]
                self.flow[(u, v)] += increment_flow
                self.flow[(v, u)] -= increment_flow
                min_cost += increment_flow * self.cost[(u, v)]
                v = u

            max_flow += increment_flow

        return max_flow, min_cost

# Example Usage
N = 4  # Number of cities
source = 0  # Start city (0-indexed)
sink = N  # End city (N-indexed, virtual sink)

# Instantiate the graph
mcmf = MinCostMaxFlow(N + 1)

# Add edges (A, B, C for graph connections)
# For example purposes, the adjacency matrix and people count might look like this:
A = [7, 4, 5, 3]
C = [
    [0, 5, 6, 3],
    [5, 0, 4, 2],
    [6, 4, 0, 7],
    [3, 2, 7, 0]
]

# Add the edges and capacities
for i in range(N):
    mcmf.add_edge(source, i + 1, A[i], 0)  # Connect source to each city with capacity A[i]
    for j in range(N):
        if i != j:
            mcmf.add_edge(i + 1, j + 1, float('inf'), C[i][j])

max_flow, min_cost = mcmf.min_cost_max_flow(source, sink)

print(f"최대 유량: {max_flow}, 최소 비용: {min_cost}")
