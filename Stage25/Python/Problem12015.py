import sys
input = sys.stdin.readline

def main():
    N = int(input())
    arr = list(map(int, input().split()))

    lis = []

    for x in arr:
        left, right = 0, len(lis)

        while left < right:
            mid = (left + right) // 2
            if lis[mid] < x:
                left = mid + 1
            else:
                right = mid

        if left == len(lis):
            lis.append(x)
        else:
            lis[left] = x

    print(len(lis))

if __name__ == "__main__":
    main()