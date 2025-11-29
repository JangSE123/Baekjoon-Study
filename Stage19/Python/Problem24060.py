import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def merge_sort(left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(left, mid)
        merge_sort(mid + 1, right)
        merge(left, mid, right)

def merge(left, mid, right):
    global A, tmp, K, count, result

    i, j = left, mid + 1
    t = left

    while i <= mid and j <= right:
        if A[i] <= A[j]:
            tmp[t] = A[i]
            i += 1
        else:
            tmp[t] = A[j]
            j += 1
        t += 1
        count += 1
        if count == K:
            result = tmp[t - 1]

    while i <= mid:
        tmp[t] = A[i]
        i += 1
        t += 1
        count += 1
        if count == K:
            result = tmp[t - 1]

    while j <= right:
        tmp[t] = A[j]
        j += 1
        t += 1
        count += 1
        if count == K:
            result = tmp[t - 1]

    for x in range(left, right + 1):
        A[x] = tmp[x]


def main():
    global A, tmp, K, count, result
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    tmp = [0] * N
    count = 0
    result = -1

    merge_sort(0, N - 1)
    print(result)


if __name__ == "__main__":
    main()