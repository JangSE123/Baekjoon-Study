import sys
input = sys.stdin.readline

INF = int(1e9)

def floyd(dist, n):
    for i in range(n):
        for j in range(n):
            for k in range(n):
                if dist[j][k] > dist[j][i] + dist[i][k]:
                    dist[j][k] = dist[j][i] + dist[i][k]

def main():
    n = int(input())
    m = int(input())

    dist = [[INF] * n for _ in range(n)]

    for i in range(n):
        dist[i][i] = 0

    for _ in range(m):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        dist[a][b] = min(dist[a][b], c)

    floyd(dist, n)

    for i in range(n):
        for j in range(n):
            if dist[i][j] == INF:
                print(0, end=' ')
            else:
                print(dist[i][j], end=' ')
        print()

if __name__ == "__main__":
    main()