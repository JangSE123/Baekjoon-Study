def dfs(depth):
    if depth == M:
        print(*arr)
        return

    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = True
            arr.append(i)
            dfs(depth + 1)
            visited[i] = False
            arr.pop()

def main():
    global N, M, arr, visited
    N, M = map(int, input().split())
    arr = []
    visited = [False] * (N + 1)
    dfs(0)
    
if __name__ == "__main__":
    main()