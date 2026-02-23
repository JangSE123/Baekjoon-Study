import sys
from collections import deque

input = sys.stdin.readline

def bfs(N, M, maze):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    queue = deque()
    queue.append((0, 0))
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < M:
                if maze[nx][ny] == 1:
                    maze[nx][ny] = maze[x][y] + 1
                    queue.append((nx, ny))
    
    return maze[N-1][M-1]


def main():
    N, M = map(int, input().split())
    maze = [list(map(int, input().strip())) for _ in range(N)]
    
    result = bfs(N, M, maze)
    print(result)


if __name__ == "__main__":
    main()