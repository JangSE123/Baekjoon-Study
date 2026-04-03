import sys

input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    memory = list(map(int, input().split()))
    cost = list(map(int, input().split()))

    max_cost = sum(cost)
    dp = [0] * (max_cost + 1)

    for i in range(N):
        for c in range(max_cost, cost[i] - 1, -1):
            dp[c] = max(dp[c], dp[c - cost[i]] + memory[i])

    for c in range(max_cost + 1):
        if dp[c] >= M:
            print(c)
            return

if __name__ == "__main__":
    main()