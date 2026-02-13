import sys
from collections import deque

input = sys.stdin.readline

def bfs(start):
    global cnt
    queue = deque()
    
    visited[start] = True
    order[start] = cnt
    queue.append(start)
    
    while queue:
        cur = queue.popleft()
        
        for nxt in graph[cur]:
            if not visited[nxt]:
                cnt += 1
                visited[nxt] = True
                order[nxt] = cnt
                queue.append(nxt)
    
def main():
    global graph, visited, order, cnt
    
    N, M, R = map(int, input().split())
    
    graph = [[] for _ in range(N + 1)]
    visited = [False] * (N + 1)
    order = [0] * (N + 1)
    
    for _ in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
        
    for i in range(1, N + 1):
        graph[i].sort()
        
    cnt = 1
    
    bfs(R)
    
    for i in range(1, N + 1):
        print(order[i])
    
if __name__ == "__main__":
    main()