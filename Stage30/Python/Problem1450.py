import sys

input = sys.stdin.readline

def main():
    N, C = map(int, input().split())
    arr = list(map(int, input().split()))

    left = []
    right = []

    def dfs(start, end, s, result):
        if s > C:
            return
        if start == end:
            result.append(s)
            return
        
        dfs(start + 1, end, s, result)
        dfs(start + 1, end, s + arr[start], result)

    dfs(0, N // 2, 0, left)
    dfs(N // 2, N, 0, right)

    right.sort()

    from bisect import bisect_right

    count = 0

    for l in left:
        if l > C:
            continue
        remain = C - l
        count += bisect_right(right, remain)

    print(count)

if __name__ == "__main__":
    main()