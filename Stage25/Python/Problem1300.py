import sys
input = sys.stdin.readline

def main():
    N = int(input().strip())
    K = int(input().strip())

    left = 1
    right = N * N
    answer = 0

    while left <= right:
        mid = (left + right) // 2
        count = 0

        for i in range(1, N + 1):
            count += min(mid // i, N)

        if count >= K:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    print(answer)

if __name__ == "__main__":
    main()