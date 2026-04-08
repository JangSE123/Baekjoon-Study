import sys

input = sys.stdin.readline

def lis_process(arr, n):
    lis = []
    prev = [-1] * n
    last_idx = [0] * n

    for i in range(n):
        left, right = 0, len(lis)

        while left < right:
            mid = (left + right) // 2
            if lis[mid] < arr[i]:
                left = mid + 1
            else:
                right = mid

        pos = right

        if pos == len(lis):
            lis.append(arr[i])
        else:
            lis[pos] = arr[i]

        last_idx[pos] = i
        prev[i] = last_idx[pos - 1] if pos > 0 else -1

    return len(lis), prev, last_idx

def trace(arr, prev, start):
    result = []
    while start != -1:
        result.append(arr[start])
        start = prev[start]
    return result[::-1]

def main():
    n = int(input())
    arr = list(map(int, input().split()))

    length, prev, last_idx = lis_process(arr, n)
    last = last_idx[length - 1]

    result = trace(arr, prev, last)

    print(length)
    print(*result)

if __name__ == "__main__":
    main()