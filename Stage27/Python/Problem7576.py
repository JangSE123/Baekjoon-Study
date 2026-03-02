import sys
from collections import deque

def main():
    input = sys.stdin.readline
    
    M, N = map(int, input().split())
    box = []
    queue = deque()
    
    for i in range(N):
        row = list(map(int, input().split()))
        box.append(row)
        for j in range(M):
            if row[j] == 1:
                queue.append((i, j))
    
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    
    while queue:
        x, y = queue.popleft()
        
        for d in range(4):
            nx = x + dx[d]
            ny = y + dy[d]
            
            if 0 <= nx < N and 0 <= ny < M:
                if box[nx][ny] == 0:
                    box[nx][ny] = box[x][y] + 1
                    queue.append((nx, ny))
    
    max_day = 0
    
    for i in range(N):
        for j in range(M):
            if box[i][j] == 0:
                print(-1)
                return
            max_day = max(max_day, box[i][j])
    
    print(max_day - 1)

if __name__ == "__main__":
    main()