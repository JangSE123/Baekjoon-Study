import sys
import heapq

input = sys.stdin.readline

def main():
    V, E = map(int, input().split())
    K = int(input())

    graph = [[] for _ in range(V + 1)]

    for _ in range(E):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))

    INF = int(1e9)
    dist = [INF] * (V + 1)

    pq = []
    dist[K] = 0
    heapq.heappush(pq, (0, K))

    while pq:
        d, now = heapq.heappop(pq)

        if d > dist[now]:
            continue

        for next, w in graph[now]:
            cost = dist[now] + w

            if dist[next] > cost:
                dist[next] = cost
                heapq.heappush(pq, (cost, next))

    for i in range(1, V + 1):
        if dist[i] == INF:
            print("INF")
        else:
            print(dist[i])

if __name__ == "__main__":
    main()