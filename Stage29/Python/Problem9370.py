import sys
import heapq

input = sys.stdin.readline
INF = 10**15

def dijkstra(start, graph, n):
    dist = [INF] * (n + 1)
    pq = []

    dist[start] = 0
    heapq.heappush(pq, (0, start))

    while pq:
        cost, now = heapq.heappop(pq)

        if cost > dist[now]:
            continue

        for nxt, w in graph[now]:
            nd = cost + w

            if dist[nxt] > nd:
                dist[nxt] = nd
                heapq.heappush(pq, (nd, nxt))

    return dist

def main():
    T = int(input())

    for _ in range(T):
        n, m, t = map(int, input().split())
        s, g, h = map(int, input().split())

        graph = [[] for _ in range(n + 1)]
        gh_cost = 0

        for _ in range(m):
            a, b, d = map(int, input().split())

            graph[a].append((b, d))
            graph[b].append((a, d))

            if (a == g and b == h) or (a == h and b == g):
                gh_cost = d

        candidates = []
        for _ in range(t):
            candidates.append(int(input()))

        candidates.sort()

        distS = dijkstra(s, graph, n)
        distG = dijkstra(g, graph, n)
        distH = dijkstra(h, graph, n)

        for x in candidates:

            path1 = distS[g] + gh_cost + distH[x]
            path2 = distS[h] + gh_cost + distG[x]

            if distS[x] == path1 or distS[x] == path2:
                print(x, end=" ")

        print()

if __name__ == "__main__":
    main()