import heapq

def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    pq = [(0, start)]
    while pq:
        cost, node = heapq.heappop(pq)
        if cost > dist[node]:
            continue
        for nxt, weight in graph[node]:
            new_cost = cost + weight
            if new_cost < dist[nxt]:
                dist[nxt] = new_cost
                heapq.heappush(pq, (new_cost, nxt))
    return dist

if __name__ == "__main__":
    graph = {
        'A': [('B', 2), ('C', 5)],
        'B': [('C', 1), ('D', 4)],
        'C': [('D', 1)],
        'D': []
    }
    print(dijkstra(graph, 'A'))
