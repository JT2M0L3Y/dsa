from collections import deque

def topological_sort(num_courses, prerequisites):
    graph = [[] for _ in range(num_courses)]
    indegree = [0] * num_courses
    for course, prereq in prerequisites:
        graph[prereq].append(course)
        indegree[course] += 1
    q = deque([i for i in range(num_courses) if indegree[i] == 0])
    order = []
    while q:
        course = q.popleft()
        order.append(course)
        for nxt in graph[course]:
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                q.append(nxt)
    return order

if __name__ == "__main__":
    print(topological_sort(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))
