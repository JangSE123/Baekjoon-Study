import sys
input = sys.stdin.readline

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    x = int(input())

    arr.sort()

    start = 0
    end = n - 1
    count = 0

    while start < end:
        s = arr[start] + arr[end]

        if s == x:
            count += 1
            start += 1
            end -= 1
        elif s < x:
            start += 1
        else:
            end -= 1

    print(count)

if __name__ == "__main__":
    main()