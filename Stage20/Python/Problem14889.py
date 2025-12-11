import sys
input = sys.stdin.readline

N = 0
S = []
visited = []
ans = int(1e9)

def calc_diff():
    start = 0
    link = 0

    for i in range(N):
        for j in range(N):
            if visited[i] and visited[j]:
                start += S[i][j]
            elif not visited[i] and not visited[j]:
                link += S[i][j]

    return abs(start - link)

def dfs(idx, count):
    global ans

    if count == N // 2:
        ans = min(ans, calc_diff())
        return

    for i in range(idx, N):
        if not visited[i]:
            visited[i] = True
            dfs(i + 1, count + 1)
            visited[i] = False

def main():
    global N, S, visited, ans
    N = int(input())
    S = [list(map(int, input().split())) for _ in range(N)]
    visited = [False] * N

    dfs(0, 0)
    print(ans)

if __name__ == "__main__":
    main()