import sys
sys.setrecursionlimit(10**7)

def main():
    input = sys.stdin.readline
    N = int(input())
    graph = [list(map(int, input().strip())) for _ in range(N)]
    visited = [[False] * N for _ in range(N)]
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    def dfs(x, y):
        visited[x][y] = True
        count = 1
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < N and 0 <= ny < N:
                if graph[nx][ny] == 1 and not visited[nx][ny]:
                    count += dfs(nx, ny)
        
        return count
    
    result = []
    
    for i in range(N):
        for j in range(N):
            if graph[i][j] == 1 and not visited[i][j]:
                result.append(dfs(i, j))
    
    result.sort()
    
    print(len(result))
    for r in result:
        print(r)


if __name__ == "__main__":
    main()