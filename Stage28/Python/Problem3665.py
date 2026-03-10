import sys
from collections import deque

input = sys.stdin.readline

def main():
    T = int(input())

    for _ in range(T):
        n = int(input())
        last = list(map(int, input().split()))

        graph = [[False]*(n+1) for _ in range(n+1)]
        indegree = [0]*(n+1)

        for i in range(n):
            for j in range(i+1, n):
                graph[last[i]][last[j]] = True
                indegree[last[j]] += 1

        m = int(input())

        for _ in range(m):
            a, b = map(int, input().split())

            if graph[a][b]:
                graph[a][b] = False
                graph[b][a] = True
                indegree[b] -= 1
                indegree[a] += 1
            else:
                graph[b][a] = False
                graph[a][b] = True
                indegree[a] -= 1
                indegree[b] += 1

        q = deque()

        for i in range(1, n+1):
            if indegree[i] == 0:
                q.append(i)

        result = []
        certain = True
        cycle = False

        for _ in range(n):
            if not q:
                cycle = True
                break

            if len(q) > 1:
                certain = False

            now = q.popleft()
            result.append(now)

            for j in range(1, n+1):
                if graph[now][j]:
                    indegree[j] -= 1
                    if indegree[j] == 0:
                        q.append(j)

        if cycle:
            print("IMPOSSIBLE")
        elif not certain:
            print("?")
        else:
            print(*result)

if __name__ == "__main__":
    main()