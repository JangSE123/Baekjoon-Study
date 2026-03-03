import sys
from collections import deque

input = sys.stdin.readline

dz = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dx = [0, 0, 0, 0, 1, -1]

def bfs(box, queue, H, N, M):
    while queue:
        z, y, x = queue.popleft()
        
        for i in range(6):
            nz = z + dz[i]
            ny = y + dy[i]
            nx = x + dx[i]
            
            if 0 <= nz < H and 0 <= ny < N and 0 <= nx < M:
                if box[nz][ny][nx] == 0:
                    box[nz][ny][nx] = box[z][y][x] + 1
                    queue.append((nz, ny, nx))
        

def main():
    M, N, H = map(int, input().split())
    
    box = []
    queue = deque()
    
    for h in range(H):
        layer = []
        for n in range(N):
            row = list(map(int, input().split()))
            for m in range(M):
                if row[m] == 1:
                    queue.append((h, n, m))
            layer.append(row)
        box.append(layer)
    
    bfs(box, queue, H, N, M)
    
    max_day = 0
    
    for h in range(H):
        for n in range(N):
            for m in range(M):
                if box[h][n][m] == 0:
                    print(-1)
                    return
                max_day = max(max_day, box[h][n][m])
    print(max_day - 1)
    
if __name__ == "__main__":
    main()