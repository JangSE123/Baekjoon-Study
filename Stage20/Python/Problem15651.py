def dfs(depth):
    if depth == M:
        print(*arr)
        return

    for i in range(1, N + 1):
        arr.append(i)
        dfs(depth + 1)
        arr.pop()

def main():
    global N, M, arr
    N, M = map(int, input().split())
    arr = []
    dfs(0)
    
if __name__ == "__main__":
    main()