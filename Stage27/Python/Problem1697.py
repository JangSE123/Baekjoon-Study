import sys
from collections import deque

input = sys.stdin.readline

def bfs(N, K):
    dist = [-1] * 100001
    queue = deque()
    
    queue.append(N)
    dist[N] = 0

    while True:
        x = queue.popleft()
        
        if x == K:
            return dist[x]
        
        for nx in (x - 1, x + 1, x * 2):
            if 0 <= nx <= 100000 and dist[nx] == -1:
                dist[nx] = dist[x] + 1
                queue.append(nx)

def main():
    N, K = map(int, input().split())
    print(bfs(N, K))

if __name__ == "__main__":
    main()