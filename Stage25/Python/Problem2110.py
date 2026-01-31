import sys
input = sys.stdin.readline

def can_install(dist, house, N, C):
    count = 1
    last = house[0]

    for i in range(1, N):
        if house[i] - last >= dist:
            count += 1
            last = house[i]

    return count >= C


def binary_search(house, N, C):
    left = 1
    right = house[-1] - house[0]
    answer = 0

    while left <= right:
        mid = (left + right) // 2

        if can_install(mid, house, N, C):
            answer = mid
            left = mid + 1
        else:
            right = mid - 1

    return answer


def main():
    N, C = map(int, input().split())
    house = [int(input()) for _ in range(N)]
    house.sort()

    print(binary_search(house, N, C))


if __name__ == "__main__":
    main()