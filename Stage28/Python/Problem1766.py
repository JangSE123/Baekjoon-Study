import sys
import heapq

input = sys.stdin.readline

def main():
    N, M = map(int, input().split())

    graph = [[] for _ in range(N + 1)]
    indegree = [0] * (N + 1)

    for _ in range(M):
        A, B = map(int, input().split())
        graph[A].append(B)
        indegree[B] += 1

    pq = []

    for i in range(1, N + 1):
        if indegree[i] == 0:
            heapq.heappush(pq, i)

    while pq:
        now = heapq.heappop(pq)
        print(now, end=' ')

        for nxt in graph[now]:
            indegree[nxt] -= 1
            if indegree[nxt] == 0:
                heapq.heappush(pq, nxt)

if __name__ == "__main__":
    main()