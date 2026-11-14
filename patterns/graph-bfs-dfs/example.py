from collections import deque

def connected_components(n, edges):
    graph = [[] for _ in range(n)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    visited = [False] * n
    count = 0
    for start in range(n):
        if visited[start]:
            continue
        count += 1
        q = deque([start])
        visited[start] = True
        while q:
            node = q.popleft()
            for nxt in graph[node]:
                if not visited[nxt]:
                    visited[nxt] = True
                    q.append(nxt)
    return count

if __name__ == "__main__":
    print(connected_components(5, [[0, 1], [1, 2], [3, 4]]))
