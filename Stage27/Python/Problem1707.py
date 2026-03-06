import sys
from collections import deque

input = sys.stdin.readline

def bfs(start):
    queue = deque([start])
    color[start] = 1

    while queue:
        cur = queue.popleft()

        for nxt in graph[cur]:
            if color[nxt] == 0:
                color[nxt] = -color[cur]
                queue.append(nxt)
            elif color[nxt] == color[cur]:
                return False
    return True

def main():
    K = int(input())

    for _ in range(K):
        V, E = map(int, input().split())

        global graph, color
        graph = [[] for _ in range(V + 1)]
        color = [0] * (V + 1)

        for _ in range(E):
            u, v = map(int, input().split())
            graph[u].append(v)
            graph[v].append(u)

        is_bipartite = True

        for i in range(1, V + 1):
            if color[i] == 0:
                if not bfs(i):
                    is_bipartite = False
                    break

        print("YES" if is_bipartite else "NO")

if __name__ == "__main__":
    main()