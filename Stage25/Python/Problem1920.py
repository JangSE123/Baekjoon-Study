import sys
input = sys.stdin.readline

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return 1
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return 0

def main():
    N = int(input())
    arr = list(map(int, input().split()))
    arr.sort()

    M = int(input())
    targets = list(map(int, input().split()))

    for t in targets:
        print(binary_search(arr, t))


if __name__ == "__main__":
    main()