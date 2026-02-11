import sys
sys.setrecursionlimit(10**7)

input = sys.stdin.readline

def dfs(cur):
    global cnt
    visited[cur] = True
    order[cur] = cnt
    cnt += 1
    
    for nxt in graph[cur]:
        if not visited[nxt]:
            dfs(nxt)

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
        graph[i].sort(reverse=True)
        
    cnt = 1
    
    dfs(R)
    
    for i in range(1, N + 1):
        print(order[i])
    
if __name__ == "__main__":
    main()