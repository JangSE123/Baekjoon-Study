import sys
from collections import deque
sys.setrecursionlimit(10**7)

input = sys.stdin.readline

def dfs(start):
    visited[start] = True
    order.append(start)

    for nxt in graph[start]:
        if not visited[nxt]:
            dfs(nxt)
    
def bfs(start):
    q = deque([start])
    visited[start] = True

    while q:
        cur = q.popleft()
        order.append(cur)

        for nxt in graph[cur]:
            if not visited[nxt]:
                visited[nxt] = True
                q.append(nxt)

def main():
    global graph, visited, order

    N, M, V = map(int, input().split())

    graph = [[] for _ in range(N + 1)]

    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    for i in range(1, N + 1):
        graph[i].sort()

    visited = [False] * (N + 1)
    order = []
    dfs(V)
    print(*order)

    visited = [False] * (N + 1)
    order = []
    bfs(V)
    print(*order)

if __name__ == "__main__":
    main()