import sys

input = sys.stdin.readline

def main():
    N, S = map(int, input().split())
    arr = list(map(int, input().split()))

    start = 0
    end = 0
    total = 0
    min_len = float('inf')

    while True:
        if total >= S:
            min_len = min(min_len, end - start)
            total -= arr[start]
            start += 1
        else:
            if end == N:
                break
            total += arr[end]
            end += 1

    if min_len == float('inf'):
        print(0)
    else:
        print(min_len)

if __name__ == "__main__":
    main()