import sys
from collections import deque

input = sys.stdin.readline

dx = [-2, -2, -1, -1, 1, 1, 2, 2]
dy = [-1, 1, -2, 2, -2, 2, -1, 1]

def bfs(l, sx, sy, ex, ey):
    if sx == ex and sy == ey:
        return 0

    visited = [[False] * l for _ in range(l)]
    dist = [[0] * l for _ in range(l)]

    q = deque()
    q.append((sx, sy))
    visited[sx][sy] = True

    while q:
        x, y = q.popleft()

        for d in range(8):
            nx = x + dx[d]
            ny = y + dy[d]

            if 0 <= nx < l and 0 <= ny < l and not visited[nx][ny]:
                visited[nx][ny] = True
                dist[nx][ny] = dist[x][y] + 1

                if nx == ex and ny == ey:
                    return dist[nx][ny]

                q.append((nx, ny))

    return dist[ex][ey]

def main():
    T = int(input())
    for _ in range(T):
        l = int(input())
        sx, sy = map(int, input().split())
        ex, ey = map(int, input().split())

        print(bfs(l, sx, sy, ex, ey))

if __name__ == "__main__":
    main()