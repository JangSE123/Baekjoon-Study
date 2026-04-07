import sys

input = sys.stdin.readline

def main():
    N = int(input())
    arr = list(map(int, input().split()))

    dp = [1] * N
    prev = [-1] * N

    max_len = 0
    max_idx = 0

    for i in range(N):
        for j in range(i):
            if arr[j] < arr[i] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                prev[i] = j
        if dp[i] > max_len:
            max_len = dp[i]
            max_idx = i

    result = []
    cur = max_idx
    while cur != -1:
        result.append(arr[cur])
        cur = prev[cur]

    result.reverse()

    print(max_len)
    print(*result)

if __name__ == "__main__":
    main()