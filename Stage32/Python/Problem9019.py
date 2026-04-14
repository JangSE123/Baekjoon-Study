import sys
from collections import deque

input = sys.stdin.readline

def bfs(A, B):
    visited = [False] * 10000
    prev = [-1] * 10000
    how = [''] * 10000
    
    q = deque([A])
    visited[A] = True
    
    while q:
        cur = q.popleft()
        if cur == B:
            break
        
        D = (cur * 2) % 10000
        if not visited[D]:
            visited[D] = True
            prev[D] = cur
            how[D] = 'D'
            q.append(D)
        
        S = 9999 if cur == 0 else cur - 1
        if not visited[S]:
            visited[S] = True
            prev[S] = cur
            how[S] = 'S'
            q.append(S)
        
        L = (cur % 1000) * 10 + cur // 1000
        if not visited[L]:
            visited[L] = True
            prev[L] = cur
            how[L] = 'L'
            q.append(L)
        
        R = (cur // 10) + (cur % 10) * 1000
        if not visited[R]:
            visited[R] = True
            prev[R] = cur
            how[R] = 'R'
            q.append(R)
    
    res = []
    cur = B
    while cur != A:
        res.append(how[cur])
        cur = prev[cur]
    
    return ''.join(reversed(res))

def main():
    T = int(input())
    
    for _ in range(T):
        A, B = map(int, input().split())
        print(bfs(A, B))
        
if __name__ == "__main__":
    main()