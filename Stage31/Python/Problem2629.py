import sys

input = sys.stdin.readline

def main():
    N = int(input())
    weights = list(map(int, input().split()))

    dp = [False] * 15001
    dp[0] = True

    for w in weights:
        next_dp = [False] * 15001
        for i in range(15001):
            if not dp[i]:
                continue

            next_dp[i] = True
            if i + w <= 15000:
                next_dp[i + w] = True
            next_dp[abs(i - w)] = True

        dp = next_dp

    M = int(input())
    beads = list(map(int, input().split()))

    result = []
    for b in beads:
        if b > 15000:
            result.append('N')
        else:
            result.append('Y' if dp[b] else 'N')

    print(' '.join(result))


if __name__ == "__main__":
    main()