import sys
from collections import deque

input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    
    graph = [[] for _ in range(N + 1)]
    indegree = [0] * (N + 1)
    
    for _ in range(M):
        A, B = map(int, input().split())
        graph[A].append(B)
        indegree[B] += 1
    
    q = deque()
    
    for i in range(1, N + 1):
        if indegree[i] == 0:
            q.append(i)
    
    while q:
        cur = q.popleft()
        print(cur, end=" ")
        
        for next in graph[cur]:
            indegree[next] -= 1
            if indegree[next] == 0:
                q.append(next)
    
if __name__ == "__main__":
    main()