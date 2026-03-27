import sys

input = sys.stdin.readline

def main():
    N = int(input())

    r = [0] * N
    c = [0] * N
    for i in range(N):
        r[i], c[i] = map(int, input().split())

    dp = [[0] * N for _ in range(N)]

    for length in range(1, N):
        for i in range(N - length):
            j = i + length
            ri = r[i]
            cj = c[j]

            min_val = float('inf')

            for k in range(i, j):
                val = dp[i][k] + dp[k + 1][j] + ri * c[k] * cj
                if val < min_val:
                    min_val = val

            dp[i][j] = min_val

    print(dp[0][N - 1])

if __name__ == "__main__":
    main()