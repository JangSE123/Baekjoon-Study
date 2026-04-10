import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

def main():
    N = int(input())
    W = int(input())

    event = [(0, 0)] * (W + 1)
    dp = [[-1] * (W + 1) for _ in range(W + 1)]
    path = [[0] * (W + 1) for _ in range(W + 1)]

    for i in range(1, W + 1):
        x, y = map(int, input().split())
        event[i] = (x, y)

    def dist(frm, to, type_):
        if frm == 0:
            if type_ == 1:
                x1, y1 = 1, 1
            else:
                x1, y1 = N, N
        else:
            x1, y1 = event[frm]

        x2, y2 = event[to]
        return abs(x1 - x2) + abs(y1 - y2)

    def solve(a, b):
        if a == W or b == W:
            return 0

        if dp[a][b] != -1:
            return dp[a][b]

        nxt = max(a, b) + 1

        case1 = solve(nxt, b) + dist(a, nxt, 1)
        case2 = solve(a, nxt) + dist(b, nxt, 2)

        if case1 < case2:
            path[a][b] = 1
            dp[a][b] = case1
        else:
            path[a][b] = 2
            dp[a][b] = case2

        return dp[a][b]

    def trace(a, b):
        if a == W or b == W:
            return

        nxt = max(a, b) + 1

        if path[a][b] == 1:
            print(1)
            trace(nxt, b)
        else:
            print(2)
            trace(a, nxt)

    print(solve(0, 0))
    trace(0, 0)

if __name__ == "__main__":
    main()