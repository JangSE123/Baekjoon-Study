import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(x, y, graph, visited, N, M):
    visited[x][y] = True
    
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        
        if 0 <= nx < N and 0 <= ny < M:
            if graph[nx][ny] == 1 and not visited[nx][ny]:
                dfs(nx, ny, graph, visited, N, M)

def main():
    T = int(input())
    
    for _ in range(T):
        M, N, K = map(int, input().split())
        
        graph = [[0] * M for _ in range(N)]
        visited = [[False] * M for _ in range(N)]
        
        for _ in range(K):
            y, x = map(int, input().split())
            graph[x][y] = 1
        
        count = 0
        
        for i in range(N):
            for j in range(M):
                if graph[i][j] == 1 and not visited[i][j]:
                    dfs(i, j, graph, visited, N, M)
                    count += 1
        
        print(count)

if __name__ == "__main__":
    main()