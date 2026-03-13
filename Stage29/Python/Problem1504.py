import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start, graph, n):
    dist = [INF] * (n + 1)
    pq = []

    dist[start] = 0
    heapq.heappush(pq, (0, start))

    while pq:
        cost, now = heapq.heappop(pq)

        if cost > dist[now]:
            continue

        for next_node, next_cost in graph[now]:
            new_cost = cost + next_cost

            if new_cost < dist[next_node]:
                dist[next_node] = new_cost
                heapq.heappush(pq, (new_cost, next_node))

    return dist

def main():
    N, E = map(int, input().split())

    graph = [[] for _ in range(N + 1)]

    for _ in range(E):
        a, b, c = map(int, input().split())
        graph[a].append((b, c))
        graph[b].append((a, c))

    v1, v2 = map(int, input().split())

    dist1 = dijkstra(1, graph, N)
    distv1 = dijkstra(v1, graph, N)
    distv2 = dijkstra(v2, graph, N)

    path1 = dist1[v1] + distv1[v2] + distv2[N]
    path2 = dist1[v2] + distv2[v1] + distv1[N]

    result = min(path1, path2)

    if result >= INF:
        print(-1)
    else:
        print(result)

if __name__ == "__main__":
    main()