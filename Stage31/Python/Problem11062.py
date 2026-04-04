import sys

input = sys.stdin.readline

def main():
    T = int(input())

    for _ in range(T):
        N = int(input())
        cards = list(map(int, input().split()))
        total = sum(cards)

        dp = [[0] * N for _ in range(N)]

        for i in range(N):
            dp[i][i] = cards[i]

        for length in range(2, N + 1):
            for l in range(N - length + 1):
                r = l + length - 1

                dp[l][r] = max(cards[l] - dp[l + 1][r], cards[r] - dp[l][r - 1])

        result = (total + dp[0][N - 1]) // 2
        print(result)

if __name__ == "__main__":
    main()