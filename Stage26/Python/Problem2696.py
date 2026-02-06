import sys
import heapq

input = sys.stdin.readline

def main():
    T = int(input())

    for _ in range(T):
        M = int(input())

        left = []
        right = []

        medians = []
        count = 0

        while count < M:
            nums = list(map(int, input().split()))
            for x in nums:
                count += 1

                if not left or x <= -left[0]:
                    heapq.heappush(left, -x)
                else:
                    heapq.heappush(right, x)

                if len(left) > len(right) + 1:
                    heapq.heappush(right, -heapq.heappop(left))
                elif len(right) > len(left):
                    heapq.heappush(left, -heapq.heappop(right))

                if count % 2 == 1:
                    medians.append(-left[0])

                if count == M:
                    break

        print(len(medians))
        for i in range(len(medians)):
            print(medians[i], end=' ')
            if (i + 1) % 10 == 0:
                print()
        print()

if __name__ == "__main__":
    main()