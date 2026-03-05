import sys
from collections import deque

input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(N, M, graph):
    visited = [[[False] * 2 for _ in range(M)] for _ in range(N)]

    queue = deque()
    queue.append((0, 0, 1, 0))
    visited[0][0][0] = True

    while queue:
        x, y, dist, wall = queue.popleft()

        if x == N - 1 and y == M - 1:
            return dist

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue

            if graph[nx][ny] == 0 and not visited[nx][ny][wall]:
                visited[nx][ny][wall] = True
                queue.append((nx, ny, dist + 1, wall))

            if graph[nx][ny] == 1 and wall == 0 and not visited[nx][ny][1]:
                visited[nx][ny][1] = True
                queue.append((nx, ny, dist + 1, 1))

    return -1

def main():
    N, M = map(int, input().split())

    graph = []
    for _ in range(N):
        graph.append(list(map(int, input().strip())))

    print(bfs(N, M, graph))

if __name__ == "__main__":
    main()