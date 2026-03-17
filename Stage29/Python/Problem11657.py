import sys
input = sys.stdin.readline

def main():
    INF = int(1e18)

    N, M = map(int, input().split())
    edges = []

    for _ in range(M):
        A, B, C = map(int, input().split())
        edges.append((A, B, C))

    dist = [INF] * (N + 1)
    dist[1] = 0

    for _ in range(N - 1):
        for a, b, c in edges:
            if dist[a] == INF:
                continue
            if dist[b] > dist[a] + c:
                dist[b] = dist[a] + c

    for a, b, c in edges:
        if dist[a] == INF:
            continue
        if dist[b] > dist[a] + c:
            print(-1)
            return

    for i in range(2, N + 1):
        if dist[i] == INF:
            print(-1)
        else:
            print(dist[i])

if __name__ == "__main__":
    main()