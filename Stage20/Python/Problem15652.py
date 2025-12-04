def dfs(depth, start):
    if depth == M:
        print(*arr)
        return

    for i in range(start, N + 1):
        arr.append(i)
        dfs(depth + 1, i)
        arr.pop()

def main():
    global N, M, arr
    N, M = map(int, input().split())
    arr = []
    dfs(0, 1)
    
if __name__ == "__main__":
    main()